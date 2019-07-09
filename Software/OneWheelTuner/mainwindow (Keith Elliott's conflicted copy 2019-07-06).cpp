#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSerialPortInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(MainWindow::ui->btnGainPMinus, SIGNAL(clicked()), this, SLOT(UpdateGains()));
    connect(MainWindow::ui->btnGainPPlus, SIGNAL(clicked()), this, SLOT(UpdateGains()));
    connect(MainWindow::ui->btnGainIMinus, SIGNAL(clicked()), this, SLOT(UpdateGains()));
    connect(MainWindow::ui->btnGainIPlus, SIGNAL(clicked()), this, SLOT(UpdateGains()));
    connect(MainWindow::ui->btnGainDMinus, SIGNAL(clicked()), this, SLOT(UpdateGains()));
    connect(MainWindow::ui->btnGainDPlus, SIGNAL(clicked()), this, SLOT(UpdateGains()));
    connect(&ReadTimer, SIGNAL(timeout()), this, SLOT(SerialRead()));

    const auto ports = QSerialPortInfo::availablePorts();
    for (const auto &port : ports)
    {
        MainWindow::ui->cmbPort->addItem(port.portName());
    }

    ReadTimer.setInterval(LOOP_TIME_MS*10);
    ReadTimer.start();

    for (uint32_t i = 0; i < NUM_SAMPLES; i++)
    {
        ControlTimeChartData.append(i/1000000.0, 0);
        IdleTimeChartData.append(i/1000000.0, 0);
        AngleChartData.append(i, 0);
        OutPChartData.append(i, 0);
        OutIChartData.append(i, 0);
        OutDChartData.append(i, 0);
    }

    QChart *controlTimeChart = new QChart();
    controlTimeChart->legend()->hide();
    controlTimeChart->addSeries(&ControlTimeChartData);
    controlTimeChart->createDefaultAxes();
    controlTimeChart->setTitle("Angle Data");
    MainWindow::ui->grphAngleData->setChart(controlTimeChart);
    MainWindow::ui->grphAngleData->setRenderHint(QPainter::Antialiasing);
    controlTimeChart->axes(Qt::Vertical).back()->setRange(0, 10000);

    QChart *idleTimeChart = new QChart();
    idleTimeChart->legend()->hide();
    idleTimeChart->addSeries(&IdleTimeChartData);
    idleTimeChart->createDefaultAxes();
    idleTimeChart->setTitle("Angle Data");
    MainWindow::ui->grphAngleData->setChart(idleTimeChart);
    MainWindow::ui->grphAngleData->setRenderHint(QPainter::Antialiasing);
    idleTimeChart->axes(Qt::Vertical).back()->setRange(0, 10000);

    QChart *angleChart = new QChart();
    angleChart->legend()->hide();
    angleChart->addSeries(&AngleChartData);
    angleChart->createDefaultAxes();
    angleChart->setTitle("Angle Data");
    MainWindow::ui->grphAngleData->setChart(angleChart);
    MainWindow::ui->grphAngleData->setRenderHint(QPainter::Antialiasing);
    angleChart->axes(Qt::Vertical).back()->setRange(-20, 20);

    QChart *outchart = new QChart();
    outchart->legend()->hide();
    outchart->addSeries(&OutPChartData);
    outchart->addSeries(&OutIChartData);
    outchart->addSeries(&OutDChartData);
    outchart->createDefaultAxes();
    outchart->setTitle("Output Data");
    MainWindow::ui->grphPIDData->setChart(outchart);
    MainWindow::ui->grphPIDData->setRenderHint(QPainter::Antialiasing);
    outchart->axes(Qt::Vertical).back()->setRange(-100, 100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateGains()
{
    MainWindow::ui->lblGainPValue->setNum(GainP);
    MainWindow::ui->lblGainIValue->setNum(GainI);
    MainWindow::ui->lblGainDValue->setNum(GainD);
}

void MainWindow::on_btnGainPMinus_clicked()
{
    GainP -= 0.1;
    SerialWrite(QString("setgain p %1").arg(GainP));
}

void MainWindow::on_btnGainPPlus_clicked()
{
    GainP += 0.1;
    SerialWrite(QString("setgain p %1").arg(GainP));
}

void MainWindow::on_btnGainIMinus_clicked()
{
    GainI -= 0.1;
    SerialWrite(QString("setgain i %1").arg(GainI));
}

void MainWindow::on_btnGainIPlus_clicked()
{
    GainI += 0.1;
    SerialWrite(QString("setgain i %1").arg(GainI));
}

void MainWindow::on_btnGainDMinus_clicked()
{
    GainD -= 0.1;
    SerialWrite(QString("setgain d %1").arg(GainD));
}

void MainWindow::on_btnGainDPlus_clicked()
{
    GainD += 0.1;
    SerialWrite(QString("setgain d %1").arg(GainD));
}

void MainWindow::on_cbClosedLoop_toggled(bool checked)
{
    if (checked)
    {
        SerialWrite("setloop closed");
    }
    else
    {
        SerialWrite("setloop open");
    }
}

void MainWindow::on_btnConnect_clicked()
{
    if (SerialConnected)
    {
        SerialPort.close();
        MainWindow::ui->lblStatusValue->setText("Disconnected");
        MainWindow::ui->btnConnect->setText("Connect");
        SerialConnected = false;
    }
    else
    {
        SerialPort.setPortName(MainWindow::ui->cmbPort->currentText());
        SerialPort.setBaudRate(115200);
        SerialPort.open(QIODevice::ReadWrite);
        SerialPort.flush();
        MainWindow::ui->lblStatusValue->setText("Connected");
        MainWindow::ui->btnConnect->setText("Disconnect");
        SerialConnected = true;
    }
}

void MainWindow::SerialRead()
{
    if (SerialConnected && SerialPort.bytesAvailable())
    {
        auto inputArray = SerialPort.readLine();
        const QString inputText(inputArray);
        if (inputText.startsWith("p:"))
        {
            ProcessSerial(inputArray.remove(0, 2));
        }
        else
        {
            MainWindow::ui->txtSerial->append(inputText);
        }
    }
}

void MainWindow::ProcessSerial(QByteArray data)
{
    SharedData = *reinterpret_cast<SharedData_t*>(data.data());

    qDebug() << "Angle: " << SharedData.angle << '\n';
    AngleChartData.replace(static_cast<int>(TimeSlice), TimeSlice/1000000.0, SharedData.angle);
    OutPChartData.replace(static_cast<int>(TimeSlice), TimeSlice/1000000.0, SharedData.output.p);
    OutIChartData.replace(static_cast<int>(TimeSlice), TimeSlice/1000000.0, SharedData.output.i);
    OutDChartData.replace(static_cast<int>(TimeSlice), TimeSlice/1000000.0, SharedData.output.d);

    const double controlUtilization = (static_cast<double>(SharedData.controlLoopTimer))/static_cast<double>(LOOP_TIME_MS);
    ControlTimeChartData.replace(static_cast<int>(TimeSlice), TimeSlice/1000000.0, controlUtilization);
    const double idleUtilization = (static_cast<double>(SharedData.idleLoopTimer))/static_cast<double>(LOOP_TIME_MS);
    IdleTimeChartData.replace(static_cast<int>(TimeSlice), TimeSlice/1000000.0, idleUtilization);

    TimeSlice = (TimeSlice + 1) % NUM_SAMPLES;
}

void MainWindow::SerialWrite(QString data)
{
    MainWindow::ui->txtSerial->append("<font color=\"Red\">" + data + "</font>");
    SerialPort.write(data.toUtf8());
}
