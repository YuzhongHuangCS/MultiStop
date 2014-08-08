#ifndef MULTISTOP_H
#define MULTISTOP_H

#include "clock.h"

#include <QApplication>
#include <QMainWindow>
#include <QTimer>
#include <QTime>

namespace Ui {
class MultiStop;
}

class MultiStop : public QMainWindow
{
    Q_OBJECT

public:
    explicit MultiStop(QWidget *parent = 0);
    ~MultiStop();

private slots:
    void on_leftButton_clicked();

    void on_rightButton_clicked();

    void updateLCD();
private:
    void start();
    void stop();

    Ui::MultiStop* ui;

    QTimer* timer;
    bool isRunning;

    Clock startTime;
    QTime pauseTime;
    QTime test;
};

#endif // MULTISTOP_H
