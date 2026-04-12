#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class MyString {
private:
    char* str;      
    int asciiSum;       

    void calcAsciiSum() {
        asciiSum = 0;
        int len = strlen(str);
        for (int i = 0; i < len; ++i) {
            asciiSum += static_cast<unsigned char>(str[i]);
        }
    }

public:
    MyString(const char* s = "") {
        int len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
        calcAsciiSum();
    }

    MyString(const MyString& other) {
        int len = strlen(other.str);
        str = new char[len + 1];
        strcpy(str, other.str);
        asciiSum = other.asciiSum;
    }

    MyString& operator=(const MyString& other) {
        if (this == &other) return *this;
        delete[] str;
        int len = strlen(other.str);
        str = new char[len + 1];
        strcpy(str, other.str);
        asciiSum = other.asciiSum;
        return *this;
    }

    ~MyString() {
        delete[] str;
        str = nullptr;
    }

    bool operator<(const MyString& other) const {
        return this->asciiSum < other.asciiSum;
    }

    const char* c_str() const {
        return str;
    }

    int getAsciiSum() const {
        return asciiSum;
    }
};

void insertionSort(MyString arr[], int n) {
    for (int i = 1; i < n; ++i) {
        MyString key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        int n;  
        cin >> n;
        cin.ignore();

        MyString* arr = new MyString[n];
        for (int i = 0; i < n; ++i) {
            char buf[1024];
            cin >> buf;
            arr[i] = MyString(buf);
        }

        insertionSort(arr, n);

        for (int i = 0; i < n; ++i) {
            if (i > 0) cout << " ";
            cout << arr[i].c_str();
        }
        cout << endl;

        delete[] arr;
    }

    return 0;
}