#include<iostream>
#include<string>
using namespace std;
class BankAccount
{
    private:
    string id;
    double money;
    public:
    BankAccount()
    {}
        BankAccount(string account,double balance)
        {
            id=account;
            money=balance;
        }
        void deposit(double num)
        {
            money+=num;
        }
        bool withdraw(double num)
        {
            if(money>=num)
            {
                money-=num;
                return true;
            }
            return false;
        }
        string getID()
        {
            return id;
        }
        double getMoney()
        {
            return money;
        }

};
class Bank
{
    public:
    BankAccount accounts[100];
    int count=0;
    void addAccount(string id,double money)
    {
        accounts[count++]=BankAccount(id,money);
    }
    void getAllAccountsInfo()
    {
        for(int i=0;i<count;i++)
        {
            cout<<"账号: "<<accounts[i].getID()
            <<", 余额: "<<accounts[i].getMoney()<<endl;
        }
    }
    bool deleteAccount(string targetID)
    {
        for(int i=0;i<count;i++)
        {
            if(accounts[i].getID()==targetID)
            {
                for(int j=i;j<count-1;j++)
                {
                    accounts[j]=accounts[j+1];
                }
                count--;
                return true;
            }
        }
        return false;
    }
};
int main() {
	Bank bank;
	bank.addAccount("123456", 1000.0);
	bank.addAccount("789012", 2000.0);
	bank.getAllAccountsInfo(); // 输出所有账户信息
	for (auto& account : bank.accounts) {
		if (account.getID() == "123456") {
			account.deposit(500.0); // 向账号 123456 存款 500
			if (account.withdraw(200.0)) { // 从账号 123456 取款 200
				cout << "取款成功" << endl;
			}
			else {
				cout << "取款失败" << endl;
			}
			break;
		}
	}
	bank.getAllAccountsInfo(); // 再次输出所有账户信息
	if (bank.deleteAccount("789012")) { // 删除账号 789012
		cout << "账号删除成功" << endl;
	}
	else {
		cout << "账号删除失败" << endl;
	}
	bank.getAllAccountsInfo(); // 输出所有账户信息
	return 0;
}