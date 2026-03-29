#include<iostream>
using namespace std;
const int MAX_SIZE=100;
class SStack
{
	private:
	int data[MAX_SIZE];
	int top_idx;
	public:
	SStack():top_idx(-1) {}
	void push(int num)
	{
		int temp[MAX_SIZE];
		int temp_top=-1;
		while(top_idx>=0&&data[top_idx]>num)
		{
			temp[++temp_top]=data[top_idx--];
		}
		data[++top_idx]=num;
		while (temp_top >= 0) 
		{
            data[++top_idx] = temp[temp_top--];
        }
	}
	void pop()
	{
		if(top_idx>=0)
		{
			top_idx--;
		}
	}
	int top()
	{
		return data[top_idx];
	}
	bool isEmpty()
	{
		return top_idx==-1;
	}
};
int main() {
	SStack stack = SStack();
	int n;
	int num;
	while (cin >> n) {
		for (int i = 0; i < n; ++i) {
			cin >> num;
			stack.push(num);
		}
		while (!stack.isEmpty()) {
			cout << stack.top() << " ";
			stack.pop();
		}
		cout << endl;
	}
	return 0;
}