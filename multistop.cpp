#include "multistop.h"
#include "ui_multistop.h"
#include <QDebug>

MultiStop::MultiStop(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MultiStop),
    isRunning(false)
{
    ui->setupUi(this);
    timer = new QTimer(this);
}

MultiStop::~MultiStop()
{
    delete ui;
}

void MultiStop::on_leftButton_clicked()
{
    if(isRunning) {
        this->stop();
    } else{
        this->start();
    }
}

void MultiStop::on_rightButton_clicked()
{
    if(isRunning){

    } else{

    }
}

void MultiStop::updateLCD()
{
    QTime now = QTime::currentTime();
    ui->lcdNumber->display(elapsed.addMSecs(startTime.msecsTo(now)).toString("hh:mm:ss.zzz"));
}

void MultiStop::start()
{
    isRunning = true;
    connect(timer, SIGNAL(timeout()), this, SLOT(updateLCD()));
    if(pauseTime.isNull()) {
        startTime.start();
        elapsed = QTime(0, 0, 0, 0);
    } else{
        startTime = startTime.addMSecs(pauseTime.elapsed());
    }
    timer->start(10);

    ui->leftButton->setText("Stop");
}

void MultiStop::stop()
{
    isRunning = false;
    timer->stop();
    disconnect(timer, SIGNAL(timeout()), this, SLOT(updateLCD()));
    pauseTime.start();

    ui->leftButton->setText("Start");
}
