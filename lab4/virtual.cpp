#include "virtual.h"
#include "cmath"
#include "typeinfo"

const double ro = 8700;

LineSegment::LineSegment(){
    point1.x = 0;
    point1.y = 0;
    point2.x = 1;
    point2.y = 1;
}

LineSegment::LineSegment(Vector2D coord1, Vector2D coord2) {
    point1 = coord1;
    point2 = coord2;
}

void LineSegment::InitFromDiag(Vector2D coord1, Vector2D coord2) {
    point1 = coord1;
    point2 = coord2;
}

double LineSegment::Square() {
    return sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2)) * 0;
}

double LineSegment::Perimeter() {
    return sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
}

const char* LineSegment::classname() {
    return typeid(this).name();
}

unsigned int LineSegment::size() {
    return sizeof(LineSegment);
}

double LineSegment::Mass() {
    return this->Square() * ro;
}

Vector2D LineSegment::Position() {
    return point1;
}

bool LineSegment::operator==(IPhysObj & obj){
    if (this->Mass() == obj.Mass()){
        return true;
    }
    else{
        return false;
    }
}

bool LineSegment::operator<(IPhysObj & obj){
    if (this->Mass() < obj.Mass()){
        return true;
    }
    else{
        return false;
    }
}

LineSegment::~LineSegment() = default;

Trapezoid::Trapezoid(){
    point1.x = 0;
    point1.y = 0;
    point2.x = 4;
    point2.y = 0;
    point3.x = 3;
    point3.y = 2;
    point4.x = 1;
    point4.y = 2;
}

Trapezoid::Trapezoid(Vector2D coord1, Vector2D coord2, Vector2D coord3, Vector2D coord4) : Vector2D() {
    point1 = coord1;
    point2 = coord2;
    point3 = coord3;
    point4 = coord4;
}

double Trapezoid::Square() {
    double line1 = sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
    double height = sqrt(pow(point3.x - point1.x, 2) + pow(point3.y - point1.y, 2));
    return (line1 * height) / 2;
}

double Trapezoid::Perimeter() {
    double line1 = sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
    double line2 = sqrt(pow(point3.x - point2.x, 2) + pow(point3.y - point2.y, 2));
    double line3 = sqrt(pow(point4.x - point3.x, 2) + pow(point4.y - point3.y, 2));
    double line4 = sqrt(pow(point1.x - point4.x, 2) + pow(point1.y - point4.y, 2));
    return line1 + line2 + line3 + line4;
}

const char *Trapezoid::classname() {
    return typeid(this).name();
}

unsigned int Trapezoid::size() {
    return sizeof(Trapezoid);
}

double Trapezoid::Mass() {
    return this->Square() * ro;
}

Vector2D Trapezoid::Position() {
    return point1;
}

bool Trapezoid::operator==(IPhysObj & obj){
    if (this->Mass() == obj.Mass()){
        return true;
    }
    else{
        return false;
    }
}

bool Trapezoid::operator<(IPhysObj & obj){
    if (this->Mass() < obj.Mass()){
        return true;
    }
    else{
        return false;
    }
}

void Trapezoid::InitFromDiag(Vector2D coord1, Vector2D coord2) {}

Trapezoid::~Trapezoid() = default;
