#include "Simulation.h"

#include <cmath>

Simulation::Simulation(Board board, int vaccine_invention_speed, int simulation_length) : board(board) {
    this->vaccine_invention_speed = vaccine_invention_speed;
    this->simulation_length = simulation_length;
    start_disease(20);
}

void Simulation::simulate() {
    if (!vaccine_invented) vaccine_invented = invent_vaccine();

    for (int i = 1; i < board.get_size() - 1; ++i) {
        for (int j = 1; j < board.get_size() - 1; ++j) {

            if (board[i][j].can_be_infected()) {
                if (vaccine_invented) {
                    if (!board[i][j].vaccinate())
                        get_infected(i, j);
                }
                else get_infected(i, j);
            }

            else if (board[i][j].get_state() == State::SICK) {
                if (!board[i][j].recover())
                    board[i][j].die();
            }
        }
    }
    day++;
}

void Simulation::start_disease(int cases) {
    int radius = 10;
    int center_x = rand() % (board.get_size() - 40) + 20;
    int center_y = rand() % (board.get_size() - 40) + 20;
    for (int i = 0; i < cases; ++i) {
        int x =  (int) std::roundf((float) rand_switch() * rand_float() * (float) radius) + center_x;
        int y = (int) std::roundf((float) rand_switch() * rand_float() * (float) radius) + center_y;
        board[x][y].set_state(SICK);
    }
}

bool Simulation::invent_vaccine() const {
    if (rand_float() * (float) vaccine_invention_speed * (float) day / (float) simulation_length > 0.5) return true;
    return false;
}

float Simulation::rand_float() {
    return float(rand())/float((RAND_MAX));
}

int Simulation::rand_switch() {
    if (rand_float() < 0.5) return -1;
    return 1;
}

Board Simulation::get_board() {
    return board;
}

int Simulation::get_simulation_length() const {
    return simulation_length;
}

void Simulation::get_infected(int i, int j) {
    int cords[] = {i, j - 1,
                   i - 1, j,
                   i, j + 1,
                   i + 1, j};
    for (int q = 0; q < 8; q+=2) {
        int x = cords[q];
        int y = cords[q + 1];
        if (board[x][y].get_state() == SICK)
            board[i][j].get_infected();
    }
}
