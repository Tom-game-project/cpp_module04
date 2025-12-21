#include "MateriaSource.hpp"
#include <iostream>

// --- Orthodox Canonical Form ---

MateriaSource::MateriaSource() {
    for (int i = 0; i < MATERIAS_LENGTH; i++) {
        _materias[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i = 0; i < MATERIAS_LENGTH; i++) {
        if (other._materias[i])
            _materias[i] = other._materias[i]->clone(); // ディープコピー
        else
            _materias[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this!= &other) {
        // 1. 既存の学習済みマテリアを破棄
        for (int i = 0; i < MATERIAS_LENGTH; i++) {
            if (_materias[i])
                delete _materias[i];
            _materias[i] = NULL;
        }
        // 2. 新しいマテリアを複製して保存
        for (int i = 0; i < MATERIAS_LENGTH; i++) {
            if (other._materias[i])
                _materias[i] = other._materias[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < MATERIAS_LENGTH; i++) {
        if (_materias[i])
            delete _materias[i];
    }
}

// --- 主要なメソッドの実装 ---

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) return;

    for (int i = 0; i < MATERIAS_LENGTH; i++) {
        if (_materias[i] == NULL) {
            _materias[i] = m; // ポインタを保存（所有権を受け取る）
            return;
        }
    }
    // 配列が満杯の場合の処理
    // 課題のmain例では new したものを直接渡しているため、
    // ここで保存できないとメモリリークする可能性がある。
    // そのため、保存できなかった場合はここで delete する実装が安全です。
    std::cout << "MateriaSource is full!" << std::endl;
    delete m; 
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < MATERIAS_LENGTH; i++) {
        if (_materias[i] && _materias[i]->getType() == type) {
            return _materias[i]->clone(); // 見つかったらクローンを返す
        }
    }
    return NULL;
}
