#ifndef MULTISTOP_H
#define MULTISTOP_H

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

    QTime elapsed;
    QTime startTime;
    QTime pauseTime;
};

#endif // MULTISTOP_H
