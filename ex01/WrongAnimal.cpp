#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal(): type("WrongAnimal") {
    
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
    *this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    if (this == &other) {
    } else {
        this->type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {

}


std::string WrongAnimal::getType() const {
    return this->type;
}

void WrongAnimal::makeSound() const {
    std::cout << "wanimal wanimal" << std::endl;
}
