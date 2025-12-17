#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

WrongCat::WrongCat(): WrongAnimal() {
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal() {
    *this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    if (this != &other) {
        WrongCat::operator=(other);
    }    
    return *this;
}

WrongCat::~WrongCat() {
}

void WrongCat::makeSound() {
    std::cout << "wnya- wnya-" << std::endl;
}
