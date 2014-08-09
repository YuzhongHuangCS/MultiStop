#include "multistop.h"

int main(int argc, char *argv[])
{
    QSharedPointer<QApplication> app = (QSharedPointer<QApplication>) new QApplication(argc, argv);
    QSharedPointer<MultiStop> widget = (QSharedPointer<MultiStop>) new MultiStop();

    widget->show();
    return app->exec();
}
