#include<iostream>
#include<cmath>
using namespace std;
class point {
private:
    double x, y;
public:
    point(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
    double getX() const { return x; }
    double getY() const { return y; }
};

class triangle {
private:
    point a, b, c, m; 
    double area2(const point& p1, const point& p2, const point& p3) const {
        return fabs(
            (p2.getX() - p1.getX()) * (p3.getY() - p1.getY()) -
            (p2.getY() - p1.getY()) * (p3.getX() - p1.getX())
        );
    }

public:
    triangle(const point& a_, const point& b_, const point& c_, const point& m_)
        : a(a_), b(b_), c(c_), m(m_) {}
    bool judge() const {
        double s_total = area2(a, b, c);
        double s1 = area2(m, a, b);
        double s2 = area2(m, b, c);
        double s3 = area2(m, c, a);
        const double eps = 1e-8;
        return fabs(s1 + s2 + s3 - s_total) < eps &&
               s1 > eps && s2 > eps && s3 > eps;
    }
};
int main() {
	double x1, y1, x2, y2, x3, y3;
	double x, y;
	while (cin >> x1 >> y1) {
		cin >> x2 >> y2;
		cin >> x3 >> y3;
		cin >> x >> y;
		point a(x1, y1);
		point b(x2, y2);
		point c(x3, y3);
		point m(x, y);
		triangle t(a, b, c, m);
		if (t.judge()) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}