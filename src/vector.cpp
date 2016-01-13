#include "vector.h"

Vector::Vector(){
    unsigned int i;
    for(i = 0; i < n; i++)
        coords_[i] = 0;
}

Vector::Vector(double h){
    unsigned int i;
    for(i = 0; i < n; i++)
        coords_[i] = h;
}

Vector::Vector(const Vector &other){
    unsigned int i;
    for(i = 0; i < n; i++)
        coords_[i] = other.coords_[i];
}

Vector& Vector::operator=(const Vector &other) {
    unsigned int i;
    for(i = 0; i < n; i++)
        coords_[i] = other.coords_[i];
    return *this;
}

double Vector::operator[](unsigned long i) const {
    return coords_[i];
}

double & Vector::operator[](unsigned long i){
    return coords_[i];
}

Vector& Vector::operator+=(const Vector &other) {
    unsigned int i;
    for(i = 0; i < n; i++)
        coords_[i] += other.coords_[i];
    return *this;
}

Vector& Vector::operator-=(const Vector &other){
    unsigned int i;
    for(i = 0; i < n; i++)
        coords_[i] -= other.coords_[i];
    return *this;
}

Vector& Vector::operator*=(double h){
    unsigned int i;
    for(i = 0; i<n; i++)
        coords_[i] *= h;
    return *this;
}

Vector& Vector::operator/=(double h){
    unsigned int i;
    for(i = 0; i < n; i++)
        coords_[i] /= h;
    return *this;
}

bool operator==(const Vector &one, const Vector &two){
    bool flag=true;
    unsigned int i;
    for(i = 0; i < Vector::n; i++)
        if(one.coords_[i]!=two.coords_[i]) flag=false;
    return flag;
}

Vector operator+(const Vector &one, const Vector &two){
    return Vector(one)+=two;
}

Vector operator-(const Vector &one, const Vector &two){
    return Vector(one)-=two;
}

Vector operator*(const Vector &one, double h) {
    return Vector(one)*=h;
}

Vector operator*(double h, const Vector &one){
    return Vector(one)*=h;
}

Vector operator/(const Vector &one, double h){
    return Vector(one)/=h;
}

double operator^(const Vector &one, const Vector &two){
    double tmp = 0;
    unsigned int i;
    for(i = 0; i < Vector::n; i++){
        tmp += one.coords_[i]*two.coords_[i];
    }
    return tmp;
}

Vector Vector::operator-() const {
    return Vector(*this) *= -1;
}

bool operator!=(const Vector &one, const Vector &two){
    return !(one==two);
};