#ifndef PROCEDURES_H
#define PROCEDURES_H

struct complex {
    double a;
    double b;
};

struct round {
    double x;
    double y;
    double r;
};

struct vector {
    double x;
    double y;
};

void Task2Pointer(int *, int *);
void Task2Link(int &, int &);

void Task5Pointer(double *);
void Task5Link(double &);

void Task10Pointer(complex * cmpl);
void Task10Link(complex & cmpl);

void Task13Pointer(round *, vector *);
void Task13Link(round &, vector &);

#endif