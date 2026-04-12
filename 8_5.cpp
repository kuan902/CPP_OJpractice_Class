#include<iostream>
using namespace std;
class Ternary {
private:
    int digits[100]; 
    int len;         

public:
    Ternary(int num = 0) {
        int i = 0;
        if (num == 0) {
            digits[0] = 0;
            len = 1;
            return;
        }
        while (num > 0) {
            digits[i++] = num % 3;
            num /= 3;
        }
        len = i;
    }
    int operator[](int index) const {
        return digits[index];
    }
    Ternary operator+(const Ternary& other) const {
        Ternary res;
        int carry = 0;
        int i = 0;
        int max_len = len > other.len ? len : other.len;

        while (i < max_len || carry > 0) {
            int sum = carry;
            if (i < len) sum += digits[i];
            if (i < other.len) sum += other.digits[i];

            res.digits[i] = sum % 3;
            carry = sum / 3;
            i++;
        }
        res.len = i;
        return res;
    }
    void display() const {
        for (int i = len - 1; i >= 0; i--) {
            cout << digits[i];
        }
        cout << endl;
    }
};
int main() {
	int num1, num2;
	cin >> num1 >> num2;
	Ternary t1(num1), t2(num2);
	cout << t1[0] << ' ' << t2[0] << '\n';
	t1.display();
	t2.display();
	Ternary t3 = t1 + t2;
	t3.display();
	t1.display();
	return 0;
}