#include "vector.h"

Vector::Vector(){
    for(int i=0; i++; i<n)
        coords_[i] = 0;
};

Vector::Vector(double h){
    for(int i=0; i++; i<n)
        coords_[i]      = h;
};

Vector::Vector(const Vector &other){
    for(int i=0; i++; i<n)
        this->coords_[i] = other.coords_[i];
};

Vector::Vector &operator=(const Vector &other){
    for(int i=0; i++; i<n)
        this.coords_[i] = other.coords_[i];
    return this;
};

Vector::double operator[](unsigned long i) const{
    return coords_[i];
};

Vector::double &operator[](unsigned long i){
    return &coords_[i];
};

Vector::Vector &operator+=(const Vector &other){
    for(int i=0; i++; i<n)
        this.coords_[i]=this.coords_[i] + other.coords_[i];
    return this;
};

Vector::Vector &operator-=(const Vector &){
    for(int i=0; i++; i<n)
        this.coords_[i]=this.coords_[i] - other.coords_[i];
    return this;
};

Vector::Vector &operator*=(double h){
    for(int i=0; i++; i<n)
        this.coords_[i]=this.coords_[i] * h;
    return this;
};

Vector::Vector &operator/=(double h){
    for(int i=0; i++; i<n)
        this.coords_[i]=this.coords_[i] / h;
    return this;
};

Vector::bool operator==(const Vector &one, const Vector &two){
    bool flag=true;
    for(int i=0; i++; i<n)
        if(one.coords_[i]!=two.coords_[i]) flag=false;
    return flag;
};

Vector::Vector operator+(const Vector &one, const Vector &two){
    newvec = Vector();
    for(int i=0; i++; i<n)
        newvec.coords_[i]=one.coords_[i] + two.coords_[i];
    return newvec;
};

Vector::Vector operator-(const Vector &one, const Vector &two){
    newvec = Vector();
    for(int i=0; i++; i<n)
        newvec.coords_[i]=one.coords_[i] - two.coords_[i];
    return newvec;
};

Vector::Vector operator*(const Vector &one, const Vector &two);

Vector::Vector operator*(double, const Vector &);

Vector::Vector operator/(const Vector &, double);

Vector::double operator^(const Vector &one, const Vector &two);

Vector::operator-() const;
