#ifndef CLOCK_H
#define CLOCK_H

#include <QTime>

class Clock : public QTime
{
    // can't add Q_OBJECT marco here, because QTime is not in the QObject system
public:
    /*use default constructor here, due to the same reason,
     * it needn't add to the GObject tree
     */

    void run();
    void pause();
    void reset();
    QString now();
    QTime timePoint();

private:
    QTime startTime;
    QTime pauseTime;
};

#endif // CLOCK_H
