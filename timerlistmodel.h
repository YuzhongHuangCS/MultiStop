#ifndef TIMERLISTMODEL_H
#define TIMERLISTMODEL_H

#include <QAbstractListModel>

class TimerListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit TimerListModel(QObject *parent = 0);

signals:

public slots:

private:


};

#endif // TIMERLISTMODEL_H
