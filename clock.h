#ifndef CLOCK_H
#define CLOCK_H

#include <QTime>

class Clock : public QTime
{
    // can't add Q_OBJECT marco here, because QTime is not in the QObject system
public:
    //didn't add explicit here, in order to use auto-type convert
    Clock();
    void run();
    void pause();
    void reset();
    QString now();
    QTime timePoint();

private:
    QTime startTime;
    QTime pauseTime;

    bool initialized;
};

#endif // CLOCK_H
