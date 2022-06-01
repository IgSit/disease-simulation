#include "Window.h"

Window::Window(QWidget *parent) : QMainWindow(parent) {
    int contagiousness = 1, fatality = 1, cure_difficulty = 5, vaccine_aversion = 4;
    int vaccine_invention_speed = 4, simulation_length = 100;

    Disease disease = *(new Disease(contagiousness, fatality, cure_difficulty, vaccine_aversion));
    Board board = *(new Board(disease));
    simulation = *(new Simulation(board, vaccine_invention_speed, simulation_length));

    auto* button = new QPushButton(tr("Step"));
    const QSize BUTTON_SIZE = QSize(100, 50);
    button->setMinimumSize(BUTTON_SIZE);
    connect(button, &QPushButton::released, this, &Window::simulate);
    button->show();
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

void Window::simulate() {
        update();
        simulation.simulate();
}
