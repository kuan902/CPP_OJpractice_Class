#include <iostream>
#include <iomanip>
using namespace std;

class Complex {
private:
    double real; 
    double imag; 

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return Complex(r, i);
    }
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0) {
            cerr << "Error: Division by zero!" << endl;
            return Complex(0, 0);
        }
        double r = (real * other.real + imag * other.imag) / denominator;
        double i = (imag * other.real - real * other.imag) / denominator;
        return Complex(r, i);
    }

    friend ostream& operator<<(ostream& os, const Complex& c) {
        
        os << fixed << setprecision(2);
        if (c.imag >= 0) {
            os << c.real << "+" << c.imag << "i";
        } else {
            os << c.real << c.imag << "i";
        }
        return os;
    }
};

int main() {
    double r1, i1, r2, i2;
    while (cin >> r1 >> i1 >> r2 >> i2) {
        Complex c1(r1, i1);
        Complex c2(r2, i2);
        
        Complex add = c1 + c2;
        Complex sub = c1 - c2;
        Complex mul = c1 * c2;
        Complex div = c1 / c2;
        
        cout << add << " " << sub << " " << mul << " " << div << endl;
    }
    return 0;
}