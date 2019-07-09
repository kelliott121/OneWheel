#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QTimer>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QQueue>

#include "../../Shared/Data.h"

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void UpdateGains();
    void SerialRead();
    void on_btnGainPMinus001_clicked();
    void on_btnGainPMinus01_clicked();
    void on_btnGainPMinus10_clicked();
    void on_btnGainPMinus100_clicked();

    void on_btnGainPPlus001_clicked();
    void on_btnGainPPlus01_clicked();
    void on_btnGainPPlus10_clicked();
    void on_btnGainPPlus100_clicked();


    void on_btnGainIMinus001_clicked();
    void on_btnGainIMinus01_clicked();
    void on_btnGainIMinus10_clicked();
    void on_btnGainIMinus100_clicked();

    void on_btnGainIPlus001_clicked();
    void on_btnGainIPlus01_clicked();
    void on_btnGainIPlus10_clicked();
    void on_btnGainIPlus100_clicked();


    void on_btnGainDMinus001_clicked();
    void on_btnGainDMinus01_clicked();
    void on_btnGainDMinus10_clicked();
    void on_btnGainDMinus100_clicked();

    void on_btnGainDPlus001_clicked();
    void on_btnGainDPlus01_clicked();
    void on_btnGainDPlus10_clicked();
    void on_btnGainDPlus100_clicked();

    void on_cbClosedLoop_toggled(bool checked);

    void on_btnConnect_clicked();

private:
    //static constexpr uint32_t LOOP_TIME_MS = 1000;
    static constexpr uint32_t NUM_SAMPLES = 60 * (1000 / UPDATE_TIME_MS);
    //static constexpr uint32_t SAMPLE_RATE = 1000;
    //static constexpr uint32_t SAMPLES_PER_CYCLE = SAMPLE_RATE / LOOP_TIME_MS;
    void SerialWrite(QString data);
    void ProcessSerial(QByteArray data);

    Ui::MainWindow *ui;
    double GainP = 0;
    double GainI = 0;
    double GainD = 0;
    QSerialPort SerialPort;
    bool SerialConnected = false;
    QTimer ReadTimer;
    QLineSeries ControlTimeChartData;
    QLineSeries IdleTimeChartData;
    QLineSeries AngleChartData;
    QLineSeries OutPChartData;
    QLineSeries OutIChartData;
    QLineSeries OutDChartData;
    SharedData_t SharedData;
    uint32_t TimeSlice = 0;
};

#endif // MAINWINDOW_H
