#include<iostream>
using namespace std;
class Time
{
    private:
    int hour,minute,second;
    void norm()
    {
        if(second>=60) 
        {
            minute+=second/60;
            second%=60;
        }
        else if(second<0)
        {
            int borrow=(-second+59)/60;
            minute-=borrow;
            second+=borrow*60;
        }
        if(minute>=60)
        {
            hour+=minute/=60;
            minute%=60;
        }
        else if(minute<0)
        {
           int borrow=(-minute+59)/60;
            hour-=borrow;
            minute+=borrow*60;
        }
    }
    public:
    Time(int h=0,int m=0,int s=0):hour(h),minute(m),second(s) 
    {
        norm();
    }
    Time operator+(const Time& other) const{
        return Time(hour+other.hour,minute+other.minute,second+other.second);
    }
    Time operator-(const Time& other) const{
        return Time(hour-other.hour,minute-other.minute,second-other.second);
    }
     bool operator>(const Time& other) const {
        if (hour != other.hour) return hour > other.hour;
        if (minute != other.minute) return minute > other.minute;
        return second > other.second;
    }
    void display()
    const{
        cout<<hour<<":"<<minute<<":"<<second;
    }

};
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int h, m, s;
		cin >> h >> m >> s;
		Time time1(h, m, s);
		cin >> h >> m >> s;
		Time time2(h, m, s);
		(time1 + time2).display();
		cout << " ";
		if (time1 > time2)
		{
			(time1 - time2).display();
		}
		else
		{
			(time2 - time1).display();
		}
		cout << endl;
	}
}