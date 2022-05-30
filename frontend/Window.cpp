#include <QPushButton>
#include <QGridLayout>
#include "Window.h"

Window::Window(QWidget *parent) : QWidget(parent) {
    auto* button = new QPushButton(tr("Ready"));
    auto *mainLayout = new QGridLayout;
    mainLayout->addWidget(button,0,0);
}
