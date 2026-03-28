#include<iostream>
#include<cmath>
using namespace std;
class Fraction
{
    private:
    int numerator;
    int denominator;
    int gcd(int a, int b) 
    {
        return b == 0 ? a : gcd(b, a % b);
    }
    public:
    Fraction(int a,int b)
    {
        numerator=a;
        denominator=b;
        int g=gcd(abs(numerator),abs(denominator));
        numerator/=g;
        denominator/=g;
        if(denominator<0)
        {
            numerator=-numerator;
            denominator=-denominator;
        }
    }
    void print()
    {
        cout<<numerator<<"/"<<denominator<<endl;
    }

};
int main() {
    int numerator, denominator;
    while (cin >> numerator >> denominator)
    {
	Fraction myFraction(numerator, denominator);
	myFraction.print();
    }
    return 0;
}