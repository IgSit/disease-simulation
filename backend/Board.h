#ifndef PROJEKTCPP_BOARD_H
#define PROJEKTCPP_BOARD_H


#include "Person.h"

class Board {
public:
    explicit Board(Disease disease);
    ~Board() = default;
    [[nodiscard]] int get_size() const;
    Person* operator[](std::size_t);
    const Person* operator[](std::size_t) const;
private:
    Person** grid;
    int size = 100;
};


#endif //PROJEKTCPP_BOARD_H
