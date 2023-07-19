#include "operator.h"

Matrix::Matrix(){
    int k = 1;
    for (auto & i: matrix){
        for (int & j: i){
            j = k;
            k++;
        }
    }
}

int Matrix::returnN() {
    return n;
}

Matrix Matrix::operator*(Matrix &matrix1) {
    if (this->returnN() != matrix1.returnN()){
        throw std::invalid_argument("Different columns and rows in matrix. Cannot multiply them");
    }
    else{
        Matrix res;
        for (auto & i : res.matrix){
            for (int & j : i){
                j = 0;
            }
        }

        for (int i = 0; i < this->returnN(); i++){
            for (int j = 0; j < matrix1.returnN(); j++){
                for (int k = 0; k < this->returnN(); k++){
                    res.matrix[i][j] += matrix[i][k] * matrix1.matrix[k][j];
                }
            }
        }
        return res;
    }
}

Matrix Matrix::operator*=(int num){
    for (int i = 0; i < this->returnN(); i++){
        for (int j = 0; j < this->returnN(); j++){
            matrix[i][j] *= num;
        }
    }
    return *this;
}

Matrix Matrix::operator-(Matrix &matrix1) {
    if (this->returnN() != matrix1.returnN()){
        throw std::invalid_argument("Different size of matrix. Cannot subtract them");
    }
    else{
        Matrix res;
        for (auto & i : res.matrix){
            for (int & j : i){
                j = 0;
            }
        }

        for (int i = 0; i < this->returnN(); i++){
            for (int j = 0; j < this->returnN(); j++){
                res.matrix[i][j] = matrix[i][j] - matrix1.matrix[i][j];
            }
        }
        return res;
    }
}

Matrix Matrix::operator+(Matrix &matrix1) {
    if (this->returnN() != matrix1.returnN()){
        throw std::invalid_argument("Different size of matrix. Cannot add them");
    }
    else{
        Matrix res;
        for (auto & i : res.matrix){
            for (int & j : i){
                j = 0;
            }
        }

        for (int i = 0; i < this->returnN(); i++){
            for (int j = 0; j < this->returnN(); j++){
                res.matrix[i][j] = matrix[i][j] + matrix1.matrix[i][j];
            }
        }
        return res;
    }
}

bool Matrix::operator==(Matrix &matrix1) {
    if (this->returnN() != matrix1.returnN()){
        return false;
    }
    for (int i = 0; i < this->returnN(); i++){
        for (int j = 0; j < this->returnN(); j++){
            if (matrix[i][j] != matrix1.matrix[i][j]){
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(Matrix &matrix1) {
    if (this->returnN() != matrix1.returnN()){
        return true;
    }
    for (int i = 0; i < this->returnN(); i++){
        for (int j = 0; j < this->returnN(); j++){
            if (matrix[i][j] != matrix1.matrix[i][j]){
                return true;
            }
        }
    }
    return false;
}

void Matrix::printMatrix(){
    for (int i = 0; i < this->returnN(); i++){
        for (int j = 0; j < this->returnN(); j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}


Subset::Subset() {
    size = 10;
    for (int i = 0; i < size; i++){
        set.emplace_back(i);
    }
}

Subset::Subset(int s, std::vector<int> &arr) {
    this->size = s;
    this->set = arr;
}

Subset Subset::operator+(Subset &subset1){
    Subset res;
    res.set = std::vector<int> (this->size + subset1.size, 0);
    int cnt = 0;
    bool flag = false;
    for (int i = 0; i < this->size; i++){
        res.set[i] = set[i];
        cnt++;
    }
    for (int j = 0; j < subset1.size; j++){
        for (auto k: res.set){
            if (k == subset1.set[j]){
                flag = true;
                break;
            }
        }
        if (!flag){
            res.set[cnt] = subset1.set[j];
            cnt++;
        }
    }
    res.size = cnt + 1;
    return res;
}

void Subset::print() {
    for (auto i: this->set){
        std::cout << i << " ";
    }
    std::cout << "\n";
}

bool Subset::operator==(Subset &subset1) {
    if (this->size != subset1.size){
        return false;
    }
    for(int i = 0; i < this->size; i++){
        if (this->set[i] != subset1.set[i]){
            return false;
        }
    }
    return true;
}

bool Subset::operator!=(Subset &subset1) {
    if (this->size != subset1.size){
        return true;
    }
    for(int i = 0; i < this->size; i++){
        if (this->set[i] != subset1.set[i]){
            return true;
        }
    }
    return false;
}

Subset Subset::operator+=(int num){
    Subset res;
    res.set = std::vector<int> (this->size + 1, 0);
    int cnt = 0;
    bool flag = false;
    for (int i = 0; i < this->size; i++){
        res.set[i] = set[i];
        cnt++;
    }
    res.set[cnt] = num;
    res.size = this->size + 1;
    return res;
}

Subset Subset::operator-=(int num){
    Subset res;
    res.set = std::vector<int> (this->size - 1, 0);
    int cnt = 0;
    bool flag = false;
    for (int i = 0; i < this->size; i++){
        if (set[i] == num){
            continue;
        }
        cnt++;
        res.set[i] = set[i];
    }
    res.size = this->size - 1;
    return res;
}
