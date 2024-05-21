#include "Simulare.h"
#include "Service.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PisicaRepo repo{"Text.txt"};
    PisicaService service{ repo };
    PisicaGUI w{ service };
    w.show();
    return a.exec();
}
