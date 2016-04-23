#include "vector.h"

Vector::Vector() {
    for (unsigned int i = 0; i < n; ++i) {
        coords_[i] = 0;
    }
}

Vector::Vector(double a) {
    for (unsigned int i = 0; i < n; ++i) {
        coords_[i] = a;
    }
}

Vector::Vector(const Vector &op) {
    for (unsigned int i = 0; i < n; ++i) {
        coords_[i] = op.coords_[i];
    }
}

Vector &Vector::operator=(const Vector &op) {
    for (unsigned int i = 0; i < n; ++i) {
        coords_[i] = op.coords_[i];
    }
    return *this;
}

double Vector::operator[](unsigned long i) const {
    return coords_[i];
}

double &Vector::operator[](unsigned long i) {
    return coords_[i];
}

Vector &Vector::operator+=(const Vector &op) {
    for (unsigned int i = 0; i < n; ++i) {
        coords_[i] += op.coords_[i];
    }
    return *this;
}


Vector &Vector::operator-=(const Vector &op) {
    for (unsigned int i = 0; i < n; ++i) {
        coords_[i] -= op.coords_[i];
    }
    return *this;
}

Vector &Vector::operator*=(double a) {
    for (unsigned int i = 0; i < n; ++i) {
        coords_[i] *= a;
    }
    return *this;
}

Vector &Vector::operator/=(double a) {
    for (unsigned int i = 0; i < n; ++i) {
        coords_[i] /= a;
    }
    return *this;
}

bool operator==(const Vector &op1, const Vector &op2) {
    for (unsigned int i = 0; i < Vector::n; i++) {
        if (op1.coords_[i] != op2.coords_[i]) {
            return false; }
    }
    return true;
}

Vector operator+(const Vector &op1, const Vector &op2) {
    return Vector(op1)+=op2;
}

Vector operator-(const Vector &op1, const Vector &op2) {
    return Vector(op1)-=op2;
}

Vector operator*(const Vector &op, double a) {
    return Vector(op) *= a;
}
Vector operator*(double a, const Vector &op){
    return Vector(op) *= a;
}

Vector operator/(const Vector &op1, double a) {
    return Vector(op1) /= a;
}

double operator^(const Vector &op1, const Vector &op2) {
    double res = 0;
    for (unsigned int i = 0; i < Vector::n; ++i) {
        res += op1.coords_[i] * op2.coords_[i];
    }
    return res;
}

Vector Vector::operator-() const {
    return Vector(*this) *= -1;
}

bool operator!=(const Vector &op1, const Vector &op2) {
    return !(op1 == op2);

}
