#include <QApplication>
#include "frontend/Window.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Window window;
    window.resize(700, 500);
    window.show();
    return QApplication::exec();
}
