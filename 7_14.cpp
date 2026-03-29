#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class LetterConverter {
private:
    string str; // 存储待转换的字符串
public:
    LetterConverter(const string& s) : str(s) {}
    
    // 声明友元转换函数
    friend void toUpper(LetterConverter& obj);
    
    // 输出字符串
    void print() const {
        cout << str << endl;
    }
};

// 友元函数：将小写字母转为大写
void toUpper(LetterConverter& obj) {
    for (char& c : obj.str) {
        if (islower(c)) {
            c = toupper(c);
        }
    }
}

int main() {
    string s;
    // 读取整行输入（包含空格）
    getline(cin, s);
    LetterConverter obj(s);
    toUpper(obj); // 调用友元函数转换
    obj.print();  // 输出结果
    return 0;
}