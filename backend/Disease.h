#ifndef PROJEKTCPP_DISEASE_H
#define PROJEKTCPP_DISEASE_H


class Disease {
public:
    Disease(int contagiousness, int fatality, int cure_difficulty, int vaccine_aversion);
    ~Disease() = default;
public:
    int contagiousness;
    int fatality;
    int cure_difficulty;
    int vaccine_aversion;
};


#endif //PROJEKTCPP_DISEASE_H
