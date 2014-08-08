#ifndef MULTISTOP_H
#define MULTISTOP_H

#include <QMainWindow>

namespace Ui {
class MultiStop;
}

class MultiStop : public QMainWindow
{
    Q_OBJECT

public:
    explicit MultiStop(QWidget *parent = 0);
    ~MultiStop();

private:
    Ui::MultiStop *ui;
};

#endif // MULTISTOP_H
