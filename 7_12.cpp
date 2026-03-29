#include<iostream>
using namespace std;
class CBank;
class JBank;
class GBank;

class CBank
{
    private:
    double balance;
    public:
    CBank(double A):balance(A) {}
    friend double getNum(const CBank& c,const JBank& j,const GBank& g);
};
class JBank
{
    private:
    double balance;
    public:
    JBank(double B):balance(B) {}
    friend double getNum(const CBank& c,const JBank& j,const GBank& g);

};
class GBank
{
    private:
    double balance;
    public:
    GBank(double C):balance(C) {}
    friend double getNum(const CBank& c,const JBank& j,const GBank& g);
};
double getNum(const CBank& c,const JBank& j,const GBank& g)
{
    return c.balance+j.balance+g.balance;
}

int main()
{
    int A,B,C;
    while(cin>>A>>B>>C)
    {
        CBank cb(A);
        JBank jb(B);
        GBank gb(C);
        cout<<getNum(cb,jb,gb)<<endl;
    }
}