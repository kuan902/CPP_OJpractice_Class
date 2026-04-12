#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
class RMB {
private:
    int yuan;   
    int jiao;    
    int fen;     
    bool mark;   
    void normalize(int totalFen) {
        if (totalFen < 0) {
            mark = true;
            totalFen = -totalFen;
        } else {
            mark = false;
        }
        fen = totalFen % 10;
        totalFen /= 10;
        jiao = totalFen % 10;
        yuan = totalFen / 10;
    }
    int toTotalFen() const {
        int total = yuan * 100 + jiao * 10 + fen;
        return mark ? -total : total;
    }

public:
    RMB() : yuan(0), jiao(0), fen(0), mark(false) {}

    RMB(int y, int j, int f, bool m = false) {
        int total = y * 100 + j * 10 + f;
        normalize(m ? -total : total);
    }
    RMB(double amount) {
        int total = static_cast<int>(round(amount * 100));
        normalize(total);
    }
    RMB(const RMB& other) = default;
    friend istream& operator>>(istream& is, RMB& rmb) {
        int y, j, f;
        is >> y >> j >> f;
        rmb.normalize(y * 100 + j * 10 + f);
        return is;
    }
    friend ostream& operator<<(ostream& os, const RMB& rmb) {
        double amount = rmb.toTotalFen() / 100.0;
        os << fixed << setprecision(2) << amount;
        return os;
    }
    RMB operator+(const RMB& other) const {
        int total = this->toTotalFen() + other.toTotalFen();
        return RMB(total / 100.0);
    }
    RMB operator+(double num) const {
        return *this + RMB(num);
    }
    friend RMB operator+(double num, const RMB& rmb) {
        return rmb + RMB(num);
    }
    RMB operator-(const RMB& other) const {
        int total = this->toTotalFen() - other.toTotalFen();
        return RMB(total / 100.0);
    }
    RMB operator-(double num) const {
        return *this - RMB(num);
    }
    friend RMB operator-(double num, const RMB& rmb) {
        return RMB(num) - rmb;
    }
};
int main()
{
	RMB a, b;
	double c;
	cout.setf(cout.showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);
	cin >> a;
	cin >> b;
	cin >> c;
	cout << RMB(a + c) << endl;
	cout << RMB(b - a) << endl;
	cout << RMB(2.18 + a) << endl;
	return 0;
}