#include <iostream>
#include <iomanip>
#include <cstdlib> 
using namespace std;

class Fract {
private:
    int num; 
    int den; 
    int gcd(int a, int b) const {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    void simplify() {
        if (den == 0) return; 
        if (den < 0) {
            num = -num;
            den = -den;
        }
        int g = gcd(num, den);
        if (g != 0) {
            num /= g;
            den /= g;
        }
    }

public:
    Fract(int n = 0, int m = 1) : num(n), den(m) {
        simplify();
    }
    operator double() const {
        if (num == 0) {
            return 0.0; // 避免输出-0.00000
        }
        return static_cast<double>(num) / den;
    }
    void show() const {
        if (num == 0) {
            cout << "0";
            return;
        }
        if (den == 1) {
            cout << num;
            return;
        }
        cout << num << "/" << den;
    }

    // 重载乘法运算符
    Fract operator*(const Fract& other) const {
        int new_num = this->num * other.num;
        int new_den = this->den * other.den;
        return Fract(new_num, new_den); 
    }
};

int main()
{
    int n, m, p, q;
    while (cin >> n >> m >> q >> p)
    {
        Fract f1(n, m), f2(q, p);
        cout << setiosflags(ios::fixed) << setprecision(5) << (double)f1 << " ";
        f1.show();
        cout << " " << setiosflags(ios::fixed) << setprecision(5) << (double)f2 << " ";
        f2.show();
        Fract fr = f1 * f2;
        cout << " ";
        fr.show();
        cout << endl;
    }
}