#ifndef VECTOR_H
#define VECTOR_H

class Vector {
public:
      const static unsigned long n = 3;
  
    Vector();

    explicit Vector(double x);

    Vector(const Vector &q);

    Vector &operator=(const Vector &q);

    double operator[](unsigned long i) const;

    double &operator[](unsigned long i);

    Vector &operator+=(const Vector &q);

    Vector &operator-=(const Vector &q);

    Vector &operator*=(double x);

    Vector &operator/=(double x);

    friend bool operator==(const Vector &r, const Vector &w);

    friend Vector operator+(const Vector &r, const Vector &w);

    friend Vector operator-(const Vector &r, const Vector &w);

    friend Vector operator*(const Vector &r, double x);

    friend Vector operator*(double x, const Vector &r);

    friend Vector operator/(const Vector &r, double x);

    friend double operator^(const Vector &r, const Vector &w);

    Vector operator-() const;

private:
    double coords_[n];
}; // class Vector

bool operator!=(const Vector &r, const Vector &w);

#endif // VECTOR_H

