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
    model = new TimeListModel(this);
    ui->tableView->setModel(model);
}

MultiStop::~MultiStop()
{
    delete ui;
    delete timer;
    delete model;
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
    ui->lcdNumber->display(clock.now());
}

void MultiStop::start()
{
    isRunning = true;

    clock.run();
    connect(timer, SIGNAL(timeout()), this, SLOT(updateLCD()));
    timer->start(10);

    ui->leftButton->setText("Stop");
    ui->rightButton->setText("Count");
}

void MultiStop::stop()
{
    isRunning = false;

    clock.pause();
    timer->stop();
    disconnect(timer, SIGNAL(timeout()), this, SLOT(updateLCD()));

    ui->leftButton->setText("Start");
    ui->rightButton->setText("Reset");
}

void MultiStop::count()
{
    model->addRow(clock.timePoint());
}

void MultiStop::reset()
{
    clock.reset();
    updateLCD();
    model->clear();
}
