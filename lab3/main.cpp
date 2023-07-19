#include <iostream>
#include "operator.h"
#include "vector"

int main(){

    Matrix matrix1;
    Matrix matrix2;
    Matrix result;

    result = matrix1 * matrix2;
    result.printMatrix();
    result = matrix1 *= 8;
    result.printMatrix();
    result = matrix1 - matrix2;
    result.printMatrix();
    result = matrix1 + matrix2;
    result.printMatrix();
    std::cout << (matrix1 == matrix2) << "\n";
    std::cout << (matrix1 != matrix2) << "\n";

    std::vector<int> v1(5);
    v1 = {1,3,5,7,9};
    std::vector<int> v2(5);
    v2 = {2,4,6,8,0};
    Subset subset1 (5, v1);
    Subset subset2 (5, v2);
    Subset res;
    res = subset1 + subset2;
    res.print();
    std::cout << (subset1 == subset2) << "\n";
    std::cout << (subset1 != subset2) << "\n";
    res = subset1 += 2;
    res.print();
    res = subset2 -= 2;
    res.print();

    return 0;
}
