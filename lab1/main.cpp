#include <iostream>
#include "procedures.h"

using namespace std;

int main() {

    int a1 = 4, b1 = 8;
    double a2 = 5.2, b2 = 8.4, x1 = 2.8, x2 = 7.3, y1 = 9.1, y2 = 0.8, r = 1.69;

    complex cmpl{};
    round rnd{};
    vector vct{};

    cmpl.a = a2;
    cmpl.b = b2;

    rnd.x = x1;
    rnd.y = y1;
    rnd.r = r;

    vct.x = x2;
    vct.y = y2;

    Task2Pointer(&a1, &b1);
    cout << a1 << " " << b1 << endl;
    Task2Link(a1, b1);
    cout << a1 << " " << b1 << endl;

    Task5Pointer(&a2);
    cout << a2 << endl;
    Task5Link(b2);
    cout << b2 << endl;

    Task10Pointer(&cmpl);
    cout << cmpl.a << " " << cmpl.b << "i" << endl;
    Task10Link(cmpl);
    cout << cmpl.a << " " << cmpl.b << "i" << endl;

    Task13Pointer(&rnd, &vct);
    cout << rnd.x << " " << rnd.y << endl;
    Task13Link(rnd, vct);
    cout << rnd.x << " " << rnd.y << endl;

    return 0;
}
