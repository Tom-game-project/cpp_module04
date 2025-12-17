#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

Dog::Dog(): Animal() {
    this->type = "Dog";
}

Dog::Dog(const Dog &other): Animal() {
    *this = other;
}

Dog &Dog::operator=(const Dog &other) {
    if (this != &other) {
        Dog::operator=(other);
    }    
    return *this;
}

Dog::~Dog() {
}

void Dog::makeSound() const{
    std::cout << "wan wan" << std::endl;
}
