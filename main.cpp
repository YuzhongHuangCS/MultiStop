#include "multistop.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MultiStop w;
    w.show();

    return a.exec();
}
