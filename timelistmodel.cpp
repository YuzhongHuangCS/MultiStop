#include "timelistmodel.h"
#include <QDebug>

TimeListModel::TimeListModel(QObject *parent) :
    QAbstractTableModel(parent)
{
}

int TimeListModel::rowCount(const QModelIndex &parent) const
{
    return content.length();
}

int TimeListModel::columnCount(const QModelIndex &parent) const
{
    //hard code to 3
    return 3;
}

QVariant TimeListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()){
        return QVariant();
    }

    if (role == Qt::DisplayRole) {
        qDebug() << content.at(index.row()).at(index.column());
        return content.at(index.row()).at(index.column());
    } else {
        return QVariant();
    }
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
    //QStringList = clocks.last().
    QStringList current;
    if(content.isEmpty()){
        current.append(compare(*startTime, now));
        current.append("-");
        current.append("-");
    } else{
        current.append(compare(*startTime, now));
        current.append(compare(clocks.first(), now));
        current.append(compare(clocks.last(), now));
    }
    content.append(current);
    clocks.append(now);
    insertRow(content.length()-1);
}

bool TimeListModel::insertRow(int row, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row);
    endInsertRows();
    return true;
}

QString TimeListModel::compare(const QTime &first, const QTime &second)
{
    QTime zero(0, 0, 0, 0);
    return zero.addMSecs(first.msecsTo(second)).toString("hh:mm:ss.zzz");
}

void TimeListModel::clear()
{
    beginResetModel();
    clocks.clear();
    content.clear();
    endResetModel();
}
