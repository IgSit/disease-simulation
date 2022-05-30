#include "Board.h"

Board::Board(Disease disease){
    auto** tmp = (Person**) malloc(sizeof(Person*) * size);
    for (int i = 0; i < size; ++i) {
        tmp[i] = (Person*) malloc(sizeof(Person) * size);
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            tmp[i][j] = Person(disease);
        }
    }
    grid = tmp;
}

int Board::get_size() const {
    return size;
}

Person *Board::operator[](std::size_t index) {
    return grid[index];
}

const Person *Board::operator[](std::size_t index) const {
    return grid[index];
}
