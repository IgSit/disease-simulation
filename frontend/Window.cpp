#include "Window.h"

Window::Window(QWidget *parent) : QMainWindow(parent) {
    Disease disease = *(new Disease(1, 1, 1, 1));
    Board board = *(new Board(disease));
    simulation = *(new Simulation(board, 50, 100));
}

void Window::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setBrush(Qt::SolidPattern);
    int size = simulation.get_board().get_size();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            painter.setBrush(chooseColor(simulation.get_board()[i][j]));
            painter.drawRect(10 * i, 10 * j, 10, 10);
        }
    }
}

Qt::GlobalColor Window::chooseColor(Person person) {
    switch (person.get_state()) {
        case HEALTHY: return Qt::darkGreen;
        case CONVALESCENT: return Qt::green;
        case VACCINATED: return Qt::darkBlue;
        case SICK: return Qt::yellow;
        case DEAD: return Qt::red;
    }
}
