#include <stdio.h>
#include "vector.h"
#include <iostream>

Vector::Vector() {
    for(unsigned long i = 0; i < n; i++) {
        coords_[i] = 0;
    }
}

Vector::Vector(double a) {
    for(unsigned long i = 0; i < n; i++) {
        coords_[i] = a;
    }
}

Vector::Vector(const Vector &B) {
    for(unsigned long i = 0; i < n; i++) {
        coords_[i] = B.coords_[i];
    }
}

Vector & Vector::operator=(const Vector &B) {
    for(unsigned long i = 0; i < n; i++) {
        coords_[i] = B.coords_[i];
    }
    return *this;
}

double Vector::operator[](unsigned long i) const {
    return coords_[i];
}

double & Vector::operator[](unsigned long i) {
    return coords_[i];
}

Vector & Vector::operator+=(const Vector &B) {
    for(unsigned long i = 0; i < n; i++) {
        coords_[i] += B.coords_[i];
    }
    return *this;
}

Vector & Vector::operator-=(const Vector &B) {
    for(unsigned long i = 0; i < n; i++) {
        coords_[i] -= B.coords_[i];
    }
    return *this;
}

Vector & Vector::operator*=(double B) {
    for(unsigned long i = 0; i < n; i++) {
        coords_[i] *= B;
    }
    return *this;
}

Vector & Vector::operator/=(double B) {
    if (B == 0) {
        printf("error, division 0");
        *this;
    }
    for(unsigned long i = 0; i < n; i++) {
        coords_[i] /= B;
    }
    return *this;
}

bool operator==(const Vector &left, const Vector &right) {
    for(unsigned long i = 0; i < Vector::n; i++) {
        if (left.coords_[i] != right.coords_[i]) {
            return false;
        }
    }
    return true;
}

Vector operator+(const Vector &left, const Vector &right) {
    Vector res;
    for(unsigned long i = 0; i < Vector::n; i++) {
        res.coords_[i] = left.coords_[i] + right.coords_[i];
    }
    return res;
}

Vector operator-(const Vector &left, const Vector &right) {
    Vector res;
    for(unsigned long i = 0; i < Vector::n; i++) {
        res.coords_[i] = left.coords_[i] - right.coords_[i];
    }
    return res;
}

Vector operator*(const Vector &left, double A) {
    Vector res;
    for(unsigned long i = 0; i < Vector::n; i++) {
        res.coords_[i] = left.coords_[i] * A;
    }
    return res;
}

Vector operator*(double A, const Vector &right) {
    Vector res;
    for(unsigned long i = 0; i < Vector::n; i++) {
        res.coords_[i] = A * right.coords_[i];
    }
    return res;
}

Vector operator/(const Vector &left, double A) {
    if (A == 0) {
        printf("error, division 0\n");
    }
    Vector res;
    for(unsigned long i = 0; i < Vector::n; i++) {
        res.coords_[i] = left.coords_[i]/A;
    }
    return res;
}

double operator^(const Vector &left, const Vector &right) {
    double dot = 0;
    for(unsigned long i = 0; i < Vector::n; i++) {
        dot = dot + left.coords_[i]*right.coords_[i];
    }
    return dot;
}

Vector Vector::operator-() const {
    Vector res;
    for(unsigned long i = 0; i < n; i++) {
        res[i] = -1*coords_[i];
    }
    return res;
}

bool operator!=(const Vector &left, const Vector &right) {
    if (left == right) {
        return false;
    }
    return true;
}

