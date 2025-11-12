#ifndef ENCLOSURE_H
#define ENCLOSURE_H

#include "Animal.h"

class Enclosure {
private:
    Animal** animals;
    int capacity;
    int currentCount;
public:
    Enclosure(int capacity);
    ~Enclosure();
    bool addAnimal(Animal* a);
    void displayAnimals();
};

#endif
