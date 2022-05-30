#ifndef PROJEKTCPP_STATE_H
#define PROJEKTCPP_STATE_H


enum State {
    HEALTHY = 'H', CONVALESCENT = 'C', VACCINATED = 'V', SICK = 'S', DEAD = 'D'
};

static const char* toString(State state) {
    switch (state) {
        case HEALTHY: return "H";
        case CONVALESCENT: return "C";
        case VACCINATED: return "V";
        case SICK: return "S";
        case DEAD: return "D";
    }
}


#endif //PROJEKTCPP_STATE_H
