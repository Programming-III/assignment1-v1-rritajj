#include <iostream>
#include <string>
#include "Animal.h"
#include "Mammal.h"
#include "Bird.h"
#include "Reptile.h"
#include "Enclosure.h"
#include "Visitor.h"

Animal::Animal( std::string& name, int age, bool isHungry)
    : name(name), age(age), isHungry(isHungry) {}

Animal::~Animal() {}

 std::string& Animal::getName()  { return name; }

int Animal::getAge()  { return age; }

bool Animal::getIsHungry()  { return isHungry; }

void Animal::setHungry(bool hungry) { isHungry = hungry; }

void Animal::display()  {
    std::cout << name << " (Age: " << age << ", " << (isHungry ? "Hungry" : "Not Hungry") << ")";
}

void Animal::feed() {
    if (isHungry) {
        isHungry = false;
        std::cout << name << " has been fed." << std::endl;
    } else {
        std::cout << name << " is not hungry." << std::endl;
    }
}

Mammal::Mammal( std::string& name, int age, bool isHungry, std::string& furColor)
    : Animal(name, age, isHungry), furColor(furColor) {}

Mammal::~Mammal() {}

void Mammal::display()  {
    std::cout << getName() << " (Age: " << getAge() << ", " << (getIsHungry() ? "Hungry" : "Not Hungry") << ")";
}

Bird::Bird( std::string& name, int age, bool isHungry, float wingSpan)
    : Animal(name, age, isHungry), wingSpan(wingSpan) {}

Bird::~Bird() {}

void Bird::display()  {
    std::cout << getName() << "(Age: " << getAge() << ", " << (getIsHungry() ? "Hungry" : "Not Hungry") << ")";
}

Reptile::Reptile( std::string& name, int age, bool isHungry, bool isVenomous)
    : Animal(name, age, isHungry), isVenomous(isVenomous) {}

Reptile::~Reptile() {}

bool Reptile::getIsVenomous()  { return isVenomous; }

void Reptile::display()  {
    std::cout << getName() << "(Age: " << getAge() << ", " << (isVenomous ? "Venomous" : "Not Venomous") << ", " << (getIsHungry() ? "Hungry" : "Not Hungry") << ")";
}

Enclosure::Enclosure(int capacity)
    : capacity(capacity), currentCount(0) {
    animals = new Animal*[capacity];
    for (int i = 0; i < capacity; ++i) animals[i] = nullptr;
}

Enclosure::~Enclosure() {
    for (int i = 0; i < currentCount; ++i) {
        delete animals[i];
    }
    delete[] animals;
}

bool Enclosure::addAnimal(Animal* a) {
    if (currentCount >= capacity) return false;
    animals[currentCount++] = a;
    return true;
}

void Enclosure::displayAnimals()  {
    for (int i = 0; i < currentCount; ++i) {
        animals[i]->display();
        if (i < currentCount - 1) std::cout << " ";
    }
}

Visitor::Visitor( std::string& name, int ticketsBought)
    : visitorName(name), ticketsBought(ticketsBought) {}

void Visitor::displayInfo()  {
    std::cout << "Visitor Info:\n";
    std::cout << "Name: " << visitorName << "\n";
    std::cout << "Tickets Bought: " << ticketsBought << "\n";
}

int main() {
    Enclosure enclosure1(5);

    enclosure1.addAnimal(new Mammal("Lion", 5, true, "Golden"));
    enclosure1.addAnimal(new Bird("Parrot", 2, false, 0.25f));
    enclosure1.addAnimal(new Reptile("Snake", 3, true, true));

    std::cout << "Enclosure 1 Animals: ";
    enclosure1.displayAnimals();
    std::cout << std::endl;

    Visitor visitor("Sarah Ali", 3);
    visitor.displayInfo();

    return 0;
}
