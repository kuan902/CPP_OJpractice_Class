#include<iostream>
#include<string>
using namespace std;
class ID
{
    private:
    string oldid,newid;
    public:
    ID(string str)
    {
        oldid=str;
        newid="";
    }
    void change()
    {
        newid=oldid.substr(0,6)+"19"+oldid.substr(6);
        int weight[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
        char code[11]={'1','0','X','9','8','7','6','5','4','3','2'};
        int S=0;
        for(int i=0;i<17;i++)
        {
            S+=(newid[i]-'0')*weight[i];
        }
        int Y=S%11;
        newid+=code[Y];
    }
    string getNewID()
    {
        return newid;
    }
};
int main() {
	string str; 
    while (cin >> str) {
		ID myID(str); 
        myID.change();
		cout << myID.getNewID() << endl;
	}
	return 0;
}