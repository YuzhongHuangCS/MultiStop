#include "clock.h"

Clock::Clock()
    :QTime()
{
}

void Clock::run()
{
    if(pauseTime.isNull()){
        startTime = QTime::currentTime();
    } else{
        startTime = startTime.addMSecs(pauseTime.elapsed());
    }
}

void Clock::pause()
{
    pauseTime.start();
}

QString Clock::now()
{
    return timePoint().toString("hh:mm:ss.zzz");
}

void Clock::reset()
{
    startTime = QTime();
    pauseTime = QTime();
}

QTime Clock::timePoint()
{
    QTime zero(0, 0, 0, 0);
    return zero.addMSecs(startTime.elapsed());
}
