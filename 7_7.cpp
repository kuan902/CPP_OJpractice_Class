/*#include<iostream>
using namespace std;
class BigNumber
{
    private:
    long int num1;
    long int num2;
    public:
    BigNumber(long int a,long int b)
    {
        num1=a;
        num2=b;
    }
    long int add()
    {
        long int sum=num1+num2;
        return sum;
    }
    long long int multiply()
    {
        long long int mul=num1*num2;
        return mul;
    }
};
int main() {
	long int num1, num2;
	while (cin >> num1 >> num2) {
		BigNumber bn(num1, num2);
		cout << bn.add() << " ";
		cout << bn.multiply() << endl;
	}
	return 0;
}*/




#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
class BigNumber
{
    private:
    string num1;
    string num2;
    string addStrings(string a,string b)
    {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string res;
        int carry=0;
        int maxLen=max(a.size(),b.size());
        for(int i=0;i<maxLen||carry;i++)
        {
            if(i<a.size()) carry+=a[i]-'0';
            if(i<b.size()) carry+=b[i]-'0';
            res.push_back(carry%10+'0');
            carry/=10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    string multiplyStrings(string a,string b)
    {
        if(a=="0"||b=="0") return "0";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string res(a.size() + b.size(), '0');
        for (int i = 0; i < a.size(); ++i) {
            int carry = 0;
            for (int j = 0; j < b.size() || carry; ++j) {
                int product = (res[i+j] - '0') + (a[i] - '0') * (j < b.size() ? (b[j] - '0') : 0) + carry;
                res[i+j] = product % 10 + '0';
                carry = product / 10;
            }
        }
        reverse(res.begin(), res.end());
        size_t start = res.find_first_not_of('0');
        if (start == string::npos) return "0";
        return res.substr(start);
    }
    public:
    BigNumber(string n1,string n2):num1(n1),num2(n2) {}
    string add()
    {
        return addStrings(num1,num2);
    }
    string multiply()
    {
        return multiplyStrings(num1,num2);
    }
};
int main() {
	string num1, num2;
	while (cin >> num1 >> num2) {
		BigNumber bn(num1, num2);
		cout << bn.add() << " ";
		cout << bn.multiply() << endl;
	}
	return 0;
}