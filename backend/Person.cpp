#include "Person.h"

float Person::calc_infection_prob(Disease disease) const {
    return (float) ((age / 100) ^ 2 * disease.contagiousness);
}

float Person::calc_death_prob(Disease disease) const {
    return (float) ((age / 100) ^ 3 * disease.fatality);
}

float Person::calc_recovery_prob(Disease disease) const {
    return (float) ((age / 100) ^ 2 / disease.cure_difficulty);
}

float Person::calc_vaccination_prob(Disease disease) const {
    return (float) ((age / 100) ^ 3 / disease.vaccine_aversion);
}

double Person::get_random_number(double a, double b) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(a, b);
    return dist(mt);
}

Person::Person(Disease disease) {
    state = HEALTHY;
    age = (int) get_random_number(1, 100);
    infection_probability = calc_infection_prob(disease);
    death_probability = calc_death_prob(disease);
    recovery_probability = calc_recovery_prob(disease);
    vaccination_probability = calc_vaccination_prob(disease);
}

bool Person::get_infected() {
    if (get_random_number(0.0, 1.0) < infection_probability) {
        state = SICK;
        return true;
    }
    return false;
}

bool Person::die() {
    if (get_random_number(0.0, 1.0) < death_probability) {
        state = DEAD;
        return true;
    }
    return false;
}

bool Person::recover() {
    if (get_random_number(0.0, 1.0) < recovery_probability) {
        state = CONVALESCENT;
        infection_probability /= 10;
        death_probability /= 25;
        recovery_probability = std::min(1.5f * recovery_probability, 1.0f);
        vaccination_probability /= 2;
        return true;
    }
    return false;
}

bool Person::vaccinate() {
    if (get_random_number(0.0, 1.0) < vaccination_probability) {
        state = VACCINATED;
        infection_probability /= 50;
        death_probability /= 25;
        recovery_probability = std::min(2.0f * recovery_probability, 1.0f);
        vaccination_probability /= 5;
        return true;
    }
    return false;
}

State Person::get_state() {
    return state;
}

void Person::set_state(State s) {
    this->state = s;
}

bool Person::can_be_infected() {
    return state != DEAD && state != SICK;
}
