#include "procedures.h"

void Task2Pointer(int * a, int * b){
    *a += *b;
}

void Task2Link(int & a, int & b){
    a += b;
}

void Task5Pointer(double * a){
    *a = (int)*a;
}

void Task5Link(double & a){
    a = (int)a;
}

void Task10Pointer(complex * cmpl){
    cmpl->b *= -1;
}

void Task10Link(complex & cmpl){
    cmpl.b *= -1;
}

void Task13Pointer(round * rnd, vector * vct){
    rnd->x += vct->x;
}

void Task13Link(round & rnd, vector & vct){
    rnd.x -= vct.x;
    rnd.y -= vct.y;
}