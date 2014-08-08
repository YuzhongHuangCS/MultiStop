#ifndef TIMELISTMODEL_H
#define TIMELISTMODEL_H

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

    void addRow(const QTime& now);

    static QString compare(const QTime& first, const QTime& second);
private:
    QList<QTime> clocks;
    QList<QStringList> content;

};

#endif // TIMELISTMODEL_H
