#include <iostream>
using namespace std;

class Matrix {
private:
    int rows;      
    int cols;       
    int** data;    

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int;
        }
    }
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
                        for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    Matrix& operator=(const Matrix& other) {
        if (this == &other) return *this;
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
        rows = other.rows;
        cols = other.cols;
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
        return *this;
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr; 
    }

    int getRows() const { return rows; }

    int getCols() const { return cols; }

   int* operator[](int i){
        if (i < 0 || i >= rows) {
            cerr << "Index out of bounds!" << endl;
            exit(1);
        }
        return data[i];
    }

    const int* operator[](int i) const {
        if (i < 0 || i >= rows) {
            cerr << "Index out of bounds!" << endl;
            exit(1);
        }
        return data[i];
    }
    friend ostream& operator<<(ostream& os, const Matrix& m) {
        for (int i = 0; i < m.rows; ++i) {
            for (int j = 0; j < m.cols; ++j) {
                if (j > 0) os << " ";
                os << m.data[i][j];
            }
            os << endl; 
        }
        return os;
    }

    friend Matrix operator+(const Matrix& m1, const Matrix& m2) {
        if (m1.rows != m2.rows || m1.cols != m2.cols) {
            cerr << "Matrix addition error: dimensions mismatch!" << endl;
            exit(1);
        }
        Matrix res(m1.rows, m1.cols);
        for (int i = 0; i < m1.rows; ++i) {
            for (int j = 0; j < m1.cols; ++j) {
                res.data[i][j] = m1.data[i][j] + m2.data[i][j];
            }
        }
        return res;
    }

    friend Matrix operator*(const Matrix& m1, const Matrix& m2) {
        if (m1.cols != m2.rows) {
            cerr << "Matrix multiplication error: dimensions mismatch!" << endl;
            exit(1);
        }
        Matrix res(m1.rows, m2.cols);
        for (int i = 0; i < m1.rows; ++i) {
            for (int j = 0; j < m2.cols; ++j) {
                res.data[i][j] = 0;
                for (int k = 0; k < m1.cols; ++k) {
                    res.data[i][j] += m1.data[i][k] * m2.data[k][j];
                }
            }
        }
        return res;
    }
};
int main() {
	int a, b;
	cin >> a >> b;
	Matrix m1(a, b), m2(a, b), m3(b, a);
	int i, j;
	for (i = 0; i < m1.getRows(); i++)
		for (j = 0; j < m1.getCols(); j++)
			cin >> m1[i][j];
	for (i = 0; i < m2.getRows(); i++)
		for (j = 0; j < m2.getCols(); j++)
			cin >> m2[i][j];
	for (i = 0; i < m3.getRows(); i++)
		for (j = 0; j < m3.getCols(); j++)
			cin >> m3[i][j];
	cout << "Matrix M1:" << endl;
	cout << m1;
	cout << "Matrix M2:" << endl;
	cout << m2;
	cout << "Matrix M3:" << endl;
	cout << m3;
	cout << "Result of Matrix Addition:" << endl;
	cout << m1 + m2;
	cout << "Result of Matrix Multiplication:" << endl;
	cout << m1 * m3;
	return 0;
}
