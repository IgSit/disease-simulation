#ifndef PROJEKTCPP_SIMULATION_H
#define PROJEKTCPP_SIMULATION_H


#include "Board.h"

class Simulation {
public:
    explicit Simulation(Board board, int vaccine_invention_speed, int simulation_length);
    ~Simulation() = default;
    void simulate();
    Board get_board();
private:
    Board board;
    int vaccine_invention_speed;
    int simulation_length;
private:
    void start_disease(int cases);
    [[nodiscard]] bool invent_vaccine() const;
    static float rand_float();
    static int rand_switch();
};


#endif //PROJEKTCPP_SIMULATION_H
