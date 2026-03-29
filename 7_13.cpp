#include <iostream>
#include <cmath>
using namespace std;

// 点类 Point
class Point {
private:
    int x, y;
public:
    Point() : x(0), y(0) {}
    Point(int x_, int y_) : x(x_), y(y_) {}
    
    // 获取坐标
    int getX() const { return x; }
    int getY() const { return y; }
};

// 矩形类 Rectangle
class Rectangle {
private:
    Point p1, p4;  // 对角顶点：点1、点4
    Point p2, p3;  // 推导顶点：点2、点3
public:
    // 构造函数：根据点1和点4初始化矩形
    Rectangle(Point p1_, Point p4_) : p1(p1_), p4(p4_) {
        // 点2：与点1纵坐标相同，与点4横坐标相同
        p2 = Point(p4.getX(), p1.getY());
        // 点3：与点4纵坐标相同，与点1横坐标相同
        p3 = Point(p1.getX(), p4.getY());
    }
    
    // 输出四个点坐标
    void printPoints() const {
        cout << "1:(" << p1.getX() << "," << p1.getY() << ")" << endl;
        cout << "2:(" << p2.getX() << "," << p2.getY() << ")" << endl;
        cout << "3:(" << p3.getX() << "," << p3.getY() << ")" << endl;
        cout << "4:(" << p4.getX() << "," << p4.getY() << ")" << endl;
    }
    
    // 计算面积
    int getArea() const {
        int width = abs(p4.getX() - p1.getX());
        int height = abs(p1.getY() - p4.getY());
        return width * height;
    }
};

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x1, y1, x4, y4;
        cin >> x1 >> y1 >> x4 >> y4;
        Point p1(x1, y1);
        Point p4(x4, y4);
        Rectangle rect(p1, p4);
        rect.printPoints();
        cout << rect.getArea() << endl;
    }
    return 0;
}