#include "Animal.hpp"
#include <string>

Animal::Animal(): type("Animal") {
    
}

Animal::Animal(const Animal &other) {
    *this = other;
}

Animal &Animal::operator=(const Animal &other) {
    if (this == &other) {
    } else {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal() {

}

std::string Animal::getType() const{
    return this->type;
}

