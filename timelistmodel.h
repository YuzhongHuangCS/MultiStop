#ifndef TIMELISTMODEL_H
#define TIMELISTMODEL_H

#include "clock.h"
#include <QAbstractTableModel>
#include <QTime>

class TimeListModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit TimeListModel(QObject *parent = 0);
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;

    virtual bool insertRow (int row, const QModelIndex & parent = QModelIndex());

    void addRow(const QTime& timePoint);
    static QString compare(const QTime& first, const QTime& second);
    void clear();

private:
    QList<QTime> clocks;
    QList<QStringList> content;

};

#endif // TIMELISTMODEL_H
