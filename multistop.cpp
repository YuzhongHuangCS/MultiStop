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
    startTime.start();

    model = new TimeListModel();
    model->startTime = &startTime;
    ui->tableView->setModel(model);
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
        this->count();
    } else{
        this->reset();
    }
}

void MultiStop::updateLCD()
{
    ui->lcdNumber->display(TimeListModel::compare(startTime, QTime::currentTime()));
}

void MultiStop::start()
{
    isRunning = true;
    connect(timer, SIGNAL(timeout()), this, SLOT(updateLCD()));
    if(pauseTime.isNull()) {
        startTime.start();
    } else{
        startTime = startTime.addMSecs(pauseTime.elapsed());
    }
    timer->start(10);

    ui->leftButton->setText("Stop");
    ui->rightButton->setText("Count");
}

void MultiStop::stop()
{
    isRunning = false;
    timer->stop();
    disconnect(timer, SIGNAL(timeout()), this, SLOT(updateLCD()));
    pauseTime.start();

    ui->leftButton->setText("Start");
    ui->rightButton->setText("Reset");
}

void MultiStop::count()
{
    model->addRow(QTime::currentTime());
}

void MultiStop::reset()
{
    startTime.start();
    pauseTime = QTime();
    updateLCD();
    model->clear();
}
