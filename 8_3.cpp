#include<iostream>
using namespace std;
class Date
{
    private:
    int month;
    int year;
    int day;
    bool isLeap(int y) const{
        return (y%4==0&&y%100!=0)||(y%400==0);
    }
    int GetDaysInMonth(int y,int m)
    const{
        int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
        if(m==2&&isLeap(y))
        {
            return 29;
        }
        return days[m-1];
    }
    public:
    Date(int y=0,int m=0,int d=0) :year(y),month(m),day(d) {}
    Date& operator=(const Date& other)
    {
        if(this==&other) return *this;
        year=other.year;    
        month=other.month;
        day=other.day;
        return *this;
    }
    int NthDay() const{
        int res=0;
        for(int i=1;i<month;i++)
        {
            res+=GetDaysInMonth(year,i);
        }
        res+=day;
        return res;
    }
    Date operator+(int n) const{
        Date res=*this;
        res.day+=n;
        while(res.day>GetDaysInMonth(res.year,res.month))
        {
            res.day-=GetDaysInMonth(res.year,res.month);
            res.month++;
            if(res.month>12)
            {
                res.month=1;
                res.year++;
            }
        }
        return res;
    }
    friend ostream& operator<<(ostream& os,const Date& d);
};
ostream& operator<<(ostream& os,const Date& d)
{
    os<<d.year<<" "<<d.month<<" "<<d.day;
    return os;
}

int main() 
{
	int year, month, day;
	while (cin >> year >> month >> day) {
		Date d(year, month, day);
		cout << d.NthDay() << endl;
		d = d + 1039;
		cout << d << endl;
	}
	return 0;
}