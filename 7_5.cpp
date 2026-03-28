#include<iostream>
using namespace std;

class Product
{
    private:
    static double discount;
    static double sum;
    static int total_num;
    
    public:
    Product(int quantity,float price)
    {
        float real_price=price*(1-discount);
        if(quantity>=10)
        {
            real_price*=0.98;
        }
        sum+=real_price*quantity;
        total_num+=quantity;
    }
    static void display()
    {
        float avg=sum/total_num;
        cout<<sum<<" "<<avg<<endl;
    }
    static void setDiscount(float d)
    {
        discount=d;
    }
    static void resetSum()
    {
        sum=0;
    }
    static void resetTotalNum()
    {
        total_num=0;
    }
};

double Product::discount=0.0f;
double Product::sum=0.0f;
int Product::total_num=0;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		float discount;
		cin >> discount;
		Product::setDiscount(discount);
		Product::resetSum();
		Product::resetTotalNum();
		int m;
		cin >> m;
		while (m--)
		{
			int quantity;
			cin >> quantity;
			float price;
			cin >> price;
			Product(quantity, price);
		}
		Product::display();
	}
}