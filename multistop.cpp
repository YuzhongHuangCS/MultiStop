#include "multistop.h"
#include "ui_multistop.h"

MultiStop::MultiStop(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MultiStop)
{
    ui->setupUi(this);
}

MultiStop::~MultiStop()
{
    delete ui;
}
