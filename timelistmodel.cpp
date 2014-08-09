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
    if (role != Qt::DisplayRole) {
        return QVariant();
    }
    if (!index.isValid()){
        return QVariant();
    }

    return content.at(index.row()).at(index.column());
}

QVariant TimeListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) {
        return QVariant();
    }
    if (orientation == Qt::Horizontal) {
        if((section >= 0) && (section <= 2)){
            return headers[section];
        } else{
            return QVariant();
        }
    } else {
        return QString("No.%1").arg(section + 1);
    }
}

void TimeListModel::addRow(const QTime &timePoint)
{
    //QStringList = clocks.last().
    QStringList current;
    if(content.isEmpty()){
        current.append(timePoint.toString("hh:mm:ss.zzz"));
        current.append("-");
        current.append("-");
    } else{
        current.append(timePoint.toString("hh:mm:ss.zzz"));
        current.append(compare(clocks.first(), timePoint));
        current.append(compare(clocks.last(), timePoint));
    }

    /* abort use of insertRows stuff
     * since I can't pass the to-insert data into the function
     * note that content.length() is exactly the new row-id
     */
    beginInsertRows(QModelIndex(), content.length(), content.length());

    content.append(current);
    clocks.append(timePoint);

    endInsertRows();
}

QString TimeListModel::compare(const QTime &first, const QTime &second)
{

    return QTime(0, 0, 0, 0).addMSecs(first.msecsTo(second)).toString("hh:mm:ss.zzz");
}

void TimeListModel::clear()
{
    beginResetModel();
    clocks.clear();
    content.clear();
    endResetModel();
}
