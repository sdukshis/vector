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

Vector &Vector::operator=(const Vector &B) {
    for(unsigned long i = 0; i < n; i++) {
        coords_[i] = B.coords_[i];
    }
    return *this;
}

double Vector::operator[](unsigned long i) const {
    return coords_[i];
}

double &Vector::operator[](unsigned long i) {
    return coords_[i];
}

Vector &Vector::operator+=(const Vector &B) {
    for(unsigned long i = 0; i < n; i++) {
        coords_[i] += B.coords_[i];
    }
    return *this;
}

Vector &Vector::operator-=(const Vector &B) {
    for(unsigned long i = 0; i < n; i++) {
        coords_[i] -= B.coords_[i];
    }
    return *this;
}

Vector &Vector::operator*=(double B) {
    for(unsigned long i = 0; i < n; i++) {
        coords_[i] *= B;
    }
    return *this;
}

Vector &Vector::operator/=(double B) {
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
    return Vector(left) += right;
}

Vector operator-(const Vector &left, const Vector &right) {
    return Vector(left) -= right;
}

Vector operator*(const Vector &left, double A) {
    return Vector(left) *= A;
}

Vector operator*(double A, const Vector &right) {
    return right * A;
}

Vector operator/(const Vector &left, double A) {
    return Vector(left) /= A;
}

double operator^(const Vector &left, const Vector &right) {
    double dot = 0;
    for(unsigned long i = 0; i < Vector::n; i++) {
        dot += left.coords_[i]*right.coords_[i];
    }
    return dot;
}

Vector Vector::operator-() const {
    return Vector(*this) *= -1;
}

bool operator!=(const Vector &left, const Vector &right) {
    return !(left == right);
}
