#include<iostream>
#include<cstring>
using namespace std;
class STR
{
    private:
    char *p;
    public:
    STR(char* s)
    {
        p=new char[strlen(s)+1];
        strcpy(p,s);
    }
    void move(char &t1, char &t2)
    {
        char temp=t1;
        t1=t2;
        t2=temp;
    }
    void fun()
    {
        int len=strlen(p);
        int left=0;
        int right=len-1;
        while(left<right)
        {
            while(left<right&&!((p[left]>='0')&&(p[left]<='9')))
            {
                left++;
            }
            while(left<right&&!(p[right]>='a'&&p[right]<='z'))
            {
                right--;
            }
            if(left<right)
            {
                move(p[left],p[right]);
                left++;
                right--;
            }
        }
    }
    ~STR()
    {
        delete[] p;

    }
    void print()
    {
        cout<<p<<endl;
    }
    
};
int main() {
	char input[100];
	while (cin.getline(input, 100)) {
		STR s = STR(input);
		s.fun();
		s.print();
	}
	return 0;
}