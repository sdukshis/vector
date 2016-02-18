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
        coords_[i] = coords_[i] * a;
    }
    return *this;
}

Vector &Vector::operator/=(double a) {
    for (unsigned int i = 0; i < n; ++i) {
        coords_[i] = coords_[i] / a;
    }
    return *this;
}

bool operator==(const Vector &op1, const Vector &op2) {
    for (unsigned int i = 0; i < Vector::n; ++i) {
        if (op1.coords_[i] != op2.coords_[i]) { return false; }
    }
    return true;
}

Vector operator+(const Vector &op1, const Vector &op2) {
    Vector op3;
    for (unsigned int i = 0; i < Vector::n; ++i) {
        op3.coords_[i] = op1.coords_[i] + op2.coords_[i];
    }
    return op3;
}

Vector operator-(const Vector &op1, const Vector &op2) {
    Vector op3(op1);
    return op3 -= op2;
}

Vector operator*(const Vector &op, double a) {
    Vector op1(op);
    return op1 *= a;
}

Vector operator/(const Vector &op1, double a) {
    Vector op(op1);
    return op /= a;
}

double operator^(const Vector &op1, const Vector &op2) {
    double res = 0;
    for (unsigned int i = 0; i < Vector::n; ++i) {
        res += op1.coords_[i] * op2.coords_[i];
    }
    return res;
}

Vector Vector::operator-() const {
    Vector op;
    for (unsigned int i = 0; i < n; ++i) {
        op.coords_[i] = (-1) * coords_[i];
    }
}

bool operator!=(const Vector &op1, const Vector &op2) {
    //if (op1 == op2) { return false; }
    //return true;
    return !(op1 == op2 );
}
