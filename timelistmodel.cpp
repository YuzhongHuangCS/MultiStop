#include "timelistmodel.h"
#include <QDebug>

TimeListModel::TimeListModel(QObject *parent) :
    QAbstractTableModel(parent)
{
}

int TimeListModel::rowCount(const QModelIndex &parent) const
{
    return clocks.length();
}

int TimeListModel::columnCount(const QModelIndex &parent) const
{
    //hard code to 3
    return 3;
}

QVariant TimeListModel::data(const QModelIndex &index, int role) const
{
    qDebug() << index;
    if (!index.isValid())
        return QVariant();

    if (index.row() >= 50)
        return QVariant();

    if (index.column() >= 50)
        return QVariant();

    if (role == Qt::DisplayRole)
        return "data";
    else
        return QVariant();
}

QVariant TimeListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) {
        return QVariant();
    }
    if (orientation == Qt::Horizontal) {
        switch(section){
            case 0:
                return "总时间";
                break;
            case 1:
                return "加时";
                break;
            case 2:
                return "单圈时间";
                break;
        }
    } else {
        return QString("No.%1").arg(section + 1);
    }
}

void TimeListModel::addRow(const QTime &now)
{
    clocks.append(now);
    //QStringList = clocks.last().
    qDebug() << clocks;
}

QString TimeListModel::compare(const QTime &first, const QTime &second)
{
    QTime zero(0, 0, 0, 0);
    return zero.addMSecs(first.msecsTo(second)).toString("hh:mm:ss.zzz");
}
