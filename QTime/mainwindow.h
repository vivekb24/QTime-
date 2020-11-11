#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QDateTime>
#include <QTimer>
#include <QDebug>
#include <QTimeZone>

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
    void showTime();
    void on_timerStart_clicked();

    void on_localTime_clicked();



    void on_pushButton_3_clicked();

    void on_mSec_clicked();

private:
    Ui::MainWindow *ui;
    QTime m_time;
    QTimer *m_timer;
    QString text,strdateTime,localTime;
    QDateTime dateTime;
};

#endif // MAINWINDOW_H
