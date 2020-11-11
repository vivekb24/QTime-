#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dateTime=QDateTime::currentDateTime();
    strdateTime=dateTime.toString("dd-MM-yyyy hh:mm:ss:zzz A");
    ui->ctimelabel->setText(strdateTime);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_timerStart_clicked()
{
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(showTime()));
    m_timer->start(1000);
}

void MainWindow::showTime()
{
    m_time = QTime::currentTime();
    text = m_time.toString("hh:mm:ss:AP");
    if ((m_time.second() % 2) == 0)
    {
        text[5] = ' ';
    }
    ui->time_label->setText(text);
    ui->statusBar->showMessage(text);
}
void MainWindow::on_localTime_clicked()
{
    m_time = QTime::currentTime();
    localTime=m_time.toString("hh:mm:ss:zzz A");
    ui->localTimelabel->setText(localTime);
}
void MainWindow::on_pushButton_3_clicked()
{
    QDateTime local(QDateTime::currentDateTime());
    qDebug() << "Local time is:" << local;

    QDateTime UTC(local);
    UTC.setTimeSpec(Qt::UTC);
    qDebug() << "UTC time is:" << UTC;
    QString utcTime =UTC.toString();
    ui->utcTimelabel->setText(utcTime);
}

void MainWindow::on_mSec_clicked()
{
    m_time = QTime::currentTime();
    int msecs= m_time.msecsSinceStartOfDay();
    ui->msecsSinceStartOfDaylabel->setText(QString::number(msecs));
}
