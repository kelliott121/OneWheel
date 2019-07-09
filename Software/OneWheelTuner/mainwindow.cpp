#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSerialPortInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(MainWindow::ui->btnGainPMinus001, SIGNAL(clicked()), this, SLOT(UpdateGains()));
    connect(MainWindow::ui->btnGainPMinus01, SIGNAL(clicked()), this, SLOT(UpdateGains()));
    connect(MainWindow::ui->btnGainPMinus10, SIGNAL(clicked()), this, SLOT(UpdateGains()));
    connect(MainWindow::ui->btnGainPMinus100, SIGNAL(clicked()), this, SLOT(UpdateGains()));

    connect(MainWindow::ui->btnGainPPlus001, SIGNAL(clicked()), this, SLOT(UpdateGains()));
    connect(MainWindow::ui->btnGainPPlus01, SIGNAL(clicked()), this, SLOT(UpdateGains()));
    connect(MainWindow::ui->btnGainPPlus10, SIGNAL(clicked()), this, SLOT(UpdateGains()));
    connect(MainWindow::ui->btnGainPPlus100, SIGNAL(clicked()), this, SLOT(UpdateGains()));

    connect(MainWindow::ui->btnGainIMinus001, SIGNAL(clicked()), this, SLOT(UpdateGains()));
    connect(MainWindow::ui->btnGainIMinus01, SIGNAL(clicked()), this, SLOT(UpdateGains()));
    connect(MainWindow::ui->btnGainIMinus10, SIGNAL(clicked()), this, SLOT(UpdateGains()));
    connect(MainWindow::ui->btnGainIMinus100, SIGNAL(clicked()), this, SLOT(UpdateGains()));

    connect(MainWindow::ui->btnGainIPlus001, SIGNAL(clicked()), this, SLOT(UpdateGains()));
    connect(MainWindow::ui->btnGainIPlus01, SIGNAL(clicked()), this, SLOT(UpdateGains()));
    connect(MainWindow::ui->btnGainIPlus10, SIGNAL(clicked()), this, SLOT(UpdateGains()));
    connect(MainWindow::ui->btnGainIPlus100, SIGNAL(clicked()), this, SLOT(UpdateGains()));

    connect(MainWindow::ui->btnGainDMinus001, SIGNAL(clicked()), this, SLOT(UpdateGains()));
    connect(MainWindow::ui->btnGainDMinus01, SIGNAL(clicked()), this, SLOT(UpdateGains()));
    connect(MainWindow::ui->btnGainDMinus10, SIGNAL(clicked()), this, SLOT(UpdateGains()));
    connect(MainWindow::ui->btnGainDMinus100, SIGNAL(clicked()), this, SLOT(UpdateGains()));

    connect(MainWindow::ui->btnGainDPlus001, SIGNAL(clicked()), this, SLOT(UpdateGains()));
    connect(MainWindow::ui->btnGainDPlus01, SIGNAL(clicked()), this, SLOT(UpdateGains()));
    connect(MainWindow::ui->btnGainDPlus10, SIGNAL(clicked()), this, SLOT(UpdateGains()));
    connect(MainWindow::ui->btnGainDPlus100, SIGNAL(clicked()), this, SLOT(UpdateGains()));

    connect(&ReadTimer, SIGNAL(timeout()), this, SLOT(SerialRead()));

    const auto ports = QSerialPortInfo::availablePorts();
    for (const auto &port : ports)
    {
        MainWindow::ui->cmbPort->addItem(port.portName());
    }

    ReadTimer.setInterval(UPDATE_TIME_MS/2);
    ReadTimer.start();

    for (uint32_t i = 0; i < NUM_SAMPLES; i++)
    {
        ControlTimeChartData.append(i, 0);
        IdleTimeChartData.append(i, 0);
        AngleChartData.append(i, 0);
        OutPChartData.append(i, 0);
        OutIChartData.append(i, 0);
        OutDChartData.append(i, 0);
    }

    QChart *controlTimeChart = new QChart();
    controlTimeChart->legend()->hide();
    controlTimeChart->addSeries(&ControlTimeChartData);
    controlTimeChart->createDefaultAxes();
    controlTimeChart->setTitle("Control Timer Data");
    MainWindow::ui->grphControlTime->setChart(controlTimeChart);
    MainWindow::ui->grphControlTime->setRenderHint(QPainter::Antialiasing);
    controlTimeChart->axes(Qt::Vertical).back()->setRange(0, 10000);

    QChart *idleTimeChart = new QChart();
    idleTimeChart->legend()->hide();
    idleTimeChart->addSeries(&IdleTimeChartData);
    idleTimeChart->createDefaultAxes();
    idleTimeChart->setTitle("Idle Timer Data");
    MainWindow::ui->grphIdleTime->setChart(idleTimeChart);
    MainWindow::ui->grphIdleTime->setRenderHint(QPainter::Antialiasing);
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
    outchart->axes(Qt::Vertical).back()->setRange(-500, 500);
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

void MainWindow::on_btnGainPMinus001_clicked()
{
    GainP -= 0.01;
    SerialWrite(QString("setgain p %1").arg(GainP));
}

void MainWindow::on_btnGainPMinus01_clicked()
{
    GainP -= 0.1;
    SerialWrite(QString("setgain p %1").arg(GainP));
}

void MainWindow::on_btnGainPMinus10_clicked()
{
    GainP -= 1.0;
    SerialWrite(QString("setgain p %1").arg(GainP));
}

void MainWindow::on_btnGainPMinus100_clicked()
{
    GainP -= 10.0;
    SerialWrite(QString("setgain p %1").arg(GainP));
}

void MainWindow::on_btnGainPPlus001_clicked()
{
    GainP += 0.01;
    SerialWrite(QString("setgain p %1").arg(GainP));
}

void MainWindow::on_btnGainPPlus01_clicked()
{
    GainP += 0.1;
    SerialWrite(QString("setgain p %1").arg(GainP));
}

void MainWindow::on_btnGainPPlus10_clicked()
{
    GainP += 1.0;
    SerialWrite(QString("setgain p %1").arg(GainP));
}

void MainWindow::on_btnGainPPlus100_clicked()
{
    GainP += 10.0;
    SerialWrite(QString("setgain p %1").arg(GainP));
}

void MainWindow::on_btnGainIMinus001_clicked()
{
    GainI -= 0.01;
    SerialWrite(QString("setgain i %1").arg(GainI));
}

void MainWindow::on_btnGainIMinus01_clicked()
{
    GainI -= 0.1;
    SerialWrite(QString("setgain i %1").arg(GainI));
}

void MainWindow::on_btnGainIMinus10_clicked()
{
    GainI -= 1.0;
    SerialWrite(QString("setgain i %1").arg(GainI));
}

void MainWindow::on_btnGainIMinus100_clicked()
{
    GainI -= 10.0;
    SerialWrite(QString("setgain i %1").arg(GainI));
}

void MainWindow::on_btnGainIPlus001_clicked()
{
    GainI += 0.01;
    SerialWrite(QString("setgain i %1").arg(GainI));
}

void MainWindow::on_btnGainIPlus01_clicked()
{
    GainI += 0.1;
    SerialWrite(QString("setgain i %1").arg(GainI));
}

void MainWindow::on_btnGainIPlus10_clicked()
{
    GainI += 1.0;
    SerialWrite(QString("setgain i %1").arg(GainI));
}

void MainWindow::on_btnGainIPlus100_clicked()
{
    GainI += 10.0;
    SerialWrite(QString("setgain i %1").arg(GainI));
}

void MainWindow::on_btnGainDMinus001_clicked()
{
    GainD -= 0.01;
    SerialWrite(QString("setgain d %1").arg(GainD));
}

void MainWindow::on_btnGainDMinus01_clicked()
{
    GainD -= 0.1;
    SerialWrite(QString("setgain d %1").arg(GainD));
}

void MainWindow::on_btnGainDMinus10_clicked()
{
    GainD -= 1.0;
    SerialWrite(QString("setgain d %1").arg(GainD));
}

void MainWindow::on_btnGainDMinus100_clicked()
{
    GainD -= 10.0;
    SerialWrite(QString("setgain d %1").arg(GainD));
}

void MainWindow::on_btnGainDPlus001_clicked()
{
    GainD += 0.01;
    SerialWrite(QString("setgain d %1").arg(GainD));
}

void MainWindow::on_btnGainDPlus01_clicked()
{
    GainD += 0.1;
    SerialWrite(QString("setgain d %1").arg(GainD));
}

void MainWindow::on_btnGainDPlus10_clicked()
{
    GainD += 1.0;
    SerialWrite(QString("setgain d %1").arg(GainD));
}

void MainWindow::on_btnGainDPlus100_clicked()
{
    GainD += 10.0;
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
            MainWindow::ui->txtSerial->append(inputText.trimmed());
        }
    }
}

void MainWindow::ProcessSerial(QByteArray data)
{
    SharedData = *reinterpret_cast<SharedData_t*>(data.data());

    //qDebug() << "Angle: " << SharedData.angle;
    //qDebug() << "ControlTimer: " << SharedData.controlLoopTimer;
    //qDebug() << "IdleTimer: " << SharedData.idleLoopTimer;
    AngleChartData.replace(static_cast<int>(TimeSlice), TimeSlice, SharedData.angle);
    OutPChartData.replace(static_cast<int>(TimeSlice), TimeSlice, SharedData.output.p);
    OutIChartData.replace(static_cast<int>(TimeSlice), TimeSlice, SharedData.output.i);
    OutDChartData.replace(static_cast<int>(TimeSlice), TimeSlice, SharedData.output.d);

    //const double controlUtilization = (static_cast<double>(SharedData.controlLoopTimer))/static_cast<double>(LOOP_TIME_MS);
    ControlTimeChartData.replace(static_cast<int>(TimeSlice), TimeSlice, SharedData.controlLoopTimer);
    //const double idleUtilization = (static_cast<double>(SharedData.idleLoopTimer))/static_cast<double>(LOOP_TIME_MS);
    IdleTimeChartData.replace(static_cast<int>(TimeSlice), TimeSlice, SharedData.idleLoopTimer);

    TimeSlice = (TimeSlice + 1) % NUM_SAMPLES;
}

void MainWindow::SerialWrite(QString data)
{
    MainWindow::ui->txtSerial->append("<font color=\"Red\">" + data + "</font>");
    SerialPort.write(data.toUtf8());
}
