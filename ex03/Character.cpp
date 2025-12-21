#include "Character.hpp"
#include "ICharacter.hpp"
#include <string>

Character::Character(std::string const &name): _name(name) {
    for (int i = 0; i < INVENTORY_LENGTH; i++) {
        this->_inventory[i] = NULL;
    }
}

Character::Character(): _name("default") {
    for (int i = 0; i < INVENTORY_LENGTH; i++) {
        this->_inventory[i] = NULL;
    }
}

Character::Character(Character const & other): _name(other._name) {
    for (int i = 0; i < INVENTORY_LENGTH; i++) {
        if (other._inventory[i])
            this->_inventory[i] = other._inventory[i]->clone(); // 複製を作成
        else
            this->_inventory[i] = NULL;
    }
}

// 代入演算子
Character & Character::operator=(Character const & other) {
    if (this!= &other) {
        this->_name = other._name;
        // 1. 既存のマテリアを削除（メモリリーク防止）
        for (int i = 0; i < INVENTORY_LENGTH; i++) {
            if (this->_inventory[i])
                delete this->_inventory[i];
            this->_inventory[i] = NULL;
        }
        // 2. 新しいマテリアを複製して代入
        for (int i = 0; i < INVENTORY_LENGTH; i++) {
            if (other._inventory[i])
                this->_inventory[i] = other._inventory[i]->clone();
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < INVENTORY_LENGTH; i++) {
        if (this->_inventory[i])
            delete this->_inventory[i];
    }
}

std::string const & Character::getName() const {
    return this->_name;
}

void Character::equip(AMateria* m) {
    if (!m) 
        return;

    for (int i = 0; i < INVENTORY_LENGTH; i++) {
        if (this->_inventory[i] == NULL) {
            this->_inventory[i] = m;
            return;
        }
    }
}

// deleteはしない
void Character::unequip(int idx) {
    if (idx >= 0 && idx < INVENTORY_LENGTH) {
        this->_inventory[idx] = NULL; // ポインタを外すだけ
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < INVENTORY_LENGTH && this->_inventory[idx]) {
        this->_inventory[idx]->use(target);
    }
}
