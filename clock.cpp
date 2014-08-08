#include "clock.h"

Clock::Clock()
{
}

Clock::Clock(const QTime& now)
    :QTime(now)
{
}

QString Clock::elapsed(const Clock &from)
{
    /* It is different from QTime::secsTo.
     * It take a early time as parm, and calculate the eplased time from that point,
     * return in QString. It is more convenient in MulitStop
     */
    int elapsedHour = this->hour() - from.hour();
    int elapsedMinute = this->minute() - from.minute();
    int elapsedSecond = this->second() - from.second();
    int elapsedMsec = (this->msec() - from.msec())/10;

    if(elapsedMsec < 0) {
        elapsedMsec += 100;
        elapsedSecond--;
    }
    if(elapsedSecond < 0) {
        elapsedSecond += 60;
        elapsedMinute--;
    }
    if(elapsedMinute < 0) {
        elapsedMinute += 60;
        elapsedHour--;
    }

    return QString("%1:%2:%3.%4").arg(
                QString::number(elapsedHour).rightJustified(2, '0'),
                QString::number(elapsedMinute).rightJustified(2, '0'),
                QString::number(elapsedSecond).rightJustified(2, '0'),
                QString::number(elapsedMsec).rightJustified(2, '0')
                );
}
