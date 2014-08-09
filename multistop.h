#ifndef MULTISTOP_H
#define MULTISTOP_H

#include "clock.h"
#include "timelistmodel.h"
#include <QApplication>
#include <QMainWindow>
#include <QTimer>

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
    void count();
    void reset();

    Ui::MultiStop* ui;

    bool isRunning;
    Clock clock;
    QTimer* timer;
    TimeListModel* model;
};

#endif // MULTISTOP_H
