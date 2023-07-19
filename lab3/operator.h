#ifndef OPERATOR
#define OPERATOR

#include "iostream"
#include "vector"

class Matrix{
private:
    static const int n = 3;
    int matrix[n][n]{};
public:
    Matrix();
    static int returnN();
    Matrix operator*(Matrix & matrix1);
    Matrix operator*=(int num);
    Matrix operator-(Matrix & matrix1);
    Matrix operator+(Matrix & matrix1);
    bool operator==(Matrix & matrix1);
    bool operator!=(Matrix & matrix1);
    void printMatrix();
};

class Subset{
private:
    int size;
    std::vector<int> set;
public:
    Subset();
    Subset(int s, std::vector<int> & arr);
    Subset operator+(Subset & subset1);
    bool operator==(Subset & subset1);
    bool operator!=(Subset & subset1);
    Subset operator+=(int num);
    Subset operator-=(int num);
    void print();
};

#endif