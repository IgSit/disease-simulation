#include "Disease.h"

Disease::Disease(int contagiousness, int fatality, int cure_difficulty, int vaccine_aversion) {
    this->contagiousness = contagiousness;
    this->fatality = fatality;
    this->cure_difficulty = cure_difficulty;
    this->vaccine_aversion = vaccine_aversion;
}
