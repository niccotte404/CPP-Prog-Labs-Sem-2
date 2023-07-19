#include <iostream>
#include "algo.h"
#include "vector"
#include "list"
#include "set"

using namespace std;

int main() {

    set<int> set = { -2, -1, 1, 2, 3, 4 };
    cout << OneOf(set.begin(), set.end(), [](int num) { return num % 2 == 0; }) << endl;

    vector<int> vector = { -2, -3, -4, -5, 8 };
    cout << AnyOf(vector.begin(), vector.end(), [](int num) { return num > 0; }) << endl;

    list<int> list = { 1, 2, 4, 2, 1 };
    cout << IsPalindrome(list.begin(), list.end(), [](int num) { return num % 11 == 0; }) << endl;

    return 0;
}
