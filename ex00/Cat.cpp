#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

Cat::Cat(): Animal() {
    this->type = "Cat";
}

Cat::Cat(const Cat &other): Animal() {
    *this = other;
}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        Cat::operator=(other);
    }    
    return *this;
}

Cat::~Cat() {
}

void Cat::makeSound() const {
    std::cout << "nya- nya-" << std::endl;
}
