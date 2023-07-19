#include <iostream>
#include "template.h"

using namespace std;

int main() {

    ArrayElement elem1 = ArrayElement(1, 100);
    ArrayElement elem2 = ArrayElement(2, 200);
    ArrayElement elem3 = ArrayElement(3, 300);

    Array<2, ArrayElement> array;

    array.AddToArray(elem1);
    array.AddToArray(elem2);
//    array.AddToArray(elem3);

    ArrayElement gotElem = array.GetArrayElement(1);
    cout << gotElem.GetId() << endl;
//    ArrayElement gotElem2 = array.GetArrayElement(4);
//    cout << gotElem2.GetId() << endl;

    int a = 8, b = 14;
    int minAB = minimum<int>(a, b);
    cout << minAB << endl;

    return 0;
}
