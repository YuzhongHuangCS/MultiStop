#include "clock.h"

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
    /* if call this function in pause status
     * you will get a wrong result
     * but in this program this will never happen
     */

    return QTime(0, 0, 0, 0).addMSecs(startTime.elapsed());
}
