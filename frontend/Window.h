#ifndef PROJEKTCPP_WINDOW_H
#define PROJEKTCPP_WINDOW_H

#include <QWidget>
#include <QPainter>
#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>

#include<unistd.h>

#include "../backend/Disease.h"
#include "../backend/Simulation.h"


class Window : public QMainWindow{
public:
    explicit Window(QWidget *parent = nullptr);
    ~Window() override = default;
    void simulate();
private:
    void paintEvent(QPaintEvent* event) override;
    static Qt::GlobalColor chooseColor(Person);
private:
    Simulation simulation = Simulation(Board(Disease(1, 1, 1, 1)), 40, 100);
};


#endif //PROJEKTCPP_WINDOW_H
