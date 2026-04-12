#include<iostream>
using namespace std;
class Array
{
    private:
    int row;
    int col;
    int** data;
    public:
    Array():row(0),col(0),data(nullptr){}
    Array& operator=(const Array& other) {
    if (this == &other) return *this;

    if (data != nullptr) {
        for (int i = 0; i < row; i++) delete[] data[i];
        delete[] data;
    }

    row = other.row;
    col = other.col;

    data = new int*[row];
    for (int i = 0; i < row; i++) {
        data[i] = new int[col];
        for (int j = 0; j < col; j++) {
            data[i][j] = other.data[i][j];
        }
    }
    return *this;
}
    ~Array()
    {
        if(data!=nullptr)
        {
            for(int i=0;i<row;i++)
            {
                delete[] data[i];
            }
            delete[] data;
        }
    }
    void input_array1(int r,int c)
    {
        row=r;
        col=c;
        data=new int*[row];
        for(int i=0;i<row;i++)
        {
            data[i]=new int[col];
            for(int j=0;j<col;j++)
            {
                cin>>data[i][j];
            }
        }
    }
    void input_array2(int r,int c)
    {
        row=r;
        col=c;
        data=new int*[row];
        for(int i=0;i<row;i++)
        {
            data[i]=new int[col];
            for(int j=0;j<col;j++)
            {
                cin>>data[i][j];
            }
        }
    }
    Array operator+(const Array& other) const{
        Array res;
        res.row=row;
        res.col=col;
        res.data=new int*[res.row];
        for(int i=0;i<res.row;i++)
        {
            res.data[i]=new int[res.col];
            for(int j=0;j<res.col;j++)
            {
                res.data[i][j]=data[i][j]+other.data[i][j];
            }
        }
        return res;
    }
    friend Array operator-(const Array& a,const Array& b);
    void show() const{
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                    cout<<data[i][j]<<" ";
            }
        }
    }
};
Array operator-(const Array& a,const Array& b)
{
    Array res;
    res.row=a.row;
    res.col=a.col;
    res.data=new int*[res.row];
    for(int i=0;i<res.row;i++)
    {
        res.data[i]=new int[res.col];
        for(int j=0;j<res.col;j++)
        {
            res.data[i][j]=a.data[i][j]-b.data[i][j];
        }
    }
    return res;
};
int main() {
	Array rr, aa, p3;
	int a, b, c, d;
	while (cin >> a >> b >> c >> d) {
		rr.input_array1(a, b);
		aa.input_array2(c, d);
		p3 = rr + aa;
		cout << "Addition result:";
		p3.show();
		cout << " ";
		p3 = rr - aa;
		cout << "Subtraction result:";
		p3.show();
		cout << endl;
	}
	return 0;
}