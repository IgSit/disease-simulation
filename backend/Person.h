#ifndef PROJEKTCPP_PERSON_H
#define PROJEKTCPP_PERSON_H

#include <random>

#include "State.h"
#include "Disease.h"

class Person {
public:
    explicit Person(Disease disease);
    ~Person() = default;
    bool get_infected();
    bool die();
    bool recover();
    bool vaccinate();
    State get_state();
    void set_state(State);
    bool can_be_infected();
private:
    State state;
    int age;
    float infection_probability;
    float death_probability;
    float recovery_probability;
    float vaccination_probability;
private:
    [[nodiscard]] static double get_random_number(double, double);
    [[nodiscard]] float calc_infection_prob(Disease disease) const;
    [[nodiscard]] float calc_death_prob(Disease disease) const;
    [[nodiscard]] float calc_recovery_prob(Disease disease) const;
    [[nodiscard]] float calc_vaccination_prob(Disease disease) const;
};


#endif //PROJEKTCPP_PERSON_H
