#ifndef CLOCK_H
#define CLOCK_H

#include <QTime>

class Clock : public QTime
{
    Q_OBJECT
public:
    explicit Clock(QObject *parent = 0);

signals:

public slots:

};

#endif // CLOCK_H
