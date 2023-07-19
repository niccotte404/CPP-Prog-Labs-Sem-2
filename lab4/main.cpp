#include <iostream>
#include <memory>
#include <vector>
#include "virtual.h"

using namespace std;

int main() {

    vector<unique_ptr<Interface>> figures;
    cout << "Do you want create your own figure? y/n" << endl;
    char c, f;
    cin >> c;
    if (c == 'y'){
        cout << "Select yor figure:\n1. Line Segment\n2. Trapezoid\n1/2" << endl;
        cin >> f;
        cout << "Enter coordinates:" << endl;
        if (f == '1'){
            Vector2D point1{};
            Vector2D point2{};
            cin >> point1.x >> point1.y;
            cin >> point2.x >> point2.y;
            figures.emplace_back(make_unique<LineSegment>(point1, point2));
        }
        else if (f == '2'){
            Vector2D point1{};
            Vector2D point2{};
            Vector2D point3{};
            Vector2D point4{};
            cin >> point1.x >> point1.y;
            cin >> point2.x >> point2.y;
            cin >> point3.x >> point3.y;
            cin >> point4.x >> point4.y;
            figures.emplace_back(make_unique<Trapezoid>(point1, point2, point3, point4));
        }
    }
    else if (c =='n'){
        LineSegment lineSegment;
        Trapezoid trapezoid;
        figures.emplace_back(make_unique<LineSegment>());
        figures.emplace_back(make_unique<Trapezoid>());
    }

    for (const auto &i: figures){
        cout << i->classname() << " ";
    }

    cout << endl;
    double sumSquare = 0;
    for (const auto &i: figures){
        sumSquare += i->Square();
    }
    cout << sumSquare << endl;

    Vector2D vectorM1{};
    double massCentre;
    double massSm = 0;
    double massRsm = 0;
    for (const auto &i: figures){
        cin >> vectorM1.x >> vectorM1.y;
        massRsm += i->Mass() * vectorM1.x + i->Mass() * vectorM1.y;
        massSm += i->Mass();
    }
    massCentre = massRsm / massSm;
    cout << massCentre << endl;

    for (const auto &i: figures){
        cout << i->size() << " ";
    }

    cout << endl;
    for (int i = 0; i < figures.size(); i++) {
        for (int j = 0; j < figures.size() - 1; j++) {
            if (figures[j + 1]->Mass() < figures[j]->Mass()) {
                swap(figures[j], figures[j + 1]);
            }
        }
    }
    for (const auto &i: figures){
        cout << i->Mass() << " ";
    }

    return 0;
}
