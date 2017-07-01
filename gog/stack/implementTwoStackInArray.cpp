#include <iostream>
using namespace std;

#define max 2

class twoStacks{
	int top1, top2;
	public :
		int a[max];
		twoStacks(){
			top1 = -1;
			top2 = max;
		}
		bool push1(int x);
		bool push2(int x);
		int pop1();
		int pop2();
		void printStack();
};

bool twoStacks :: push1(int x){
	if(top1 +1 >= top2){
		cout << "Stack Overflow " << x<<endl;
		return false;
	}
	a[++top1] = x;
	return true;
}


bool twoStacks :: push2(int x){
	if(top2 <= top1+1){
		cout << "Stack 2 overflow " << x <<endl;
		return false;
	}
	//cout << "top before : " << top2 << ";;";
	
	top2--;
	a[top2] = x;
	//cout << top2 << "++";
	return true;
}

int twoStacks :: pop1(){
	if(top1 < 0) {
		cout << "Stack 1 Underflow : ";
		return INT_MIN;
	}
	int res = a[top1];
	top1--;
	return res;
}

int twoStacks :: pop2(){
	if(top2 >= max) {
		cout << "Stack 2 Underflow : ";
		return INT_MAX;
	}
	int res = a[top2];
	top2++;
	return res;
}

void twoStacks :: printStack(){
	for(int i=0;i<max;i++){
		cout << "Stack is : " << a[i] << " ";
	}
}

int main(){
	twoStacks S;

	 cout << "Pushing : " <<1 << endl;S.push1(1);
	// cout << "Pushing : " <<2 << endl;S.push1(2);
	// cout << "Pushing : " <<3 << endl;S.push1(3);
	cout << "Pushing : "<<2 << endl ;S.push2(2);
	cout << "Pushing : " <<3 << endl;S.push2(3);
	cout << "Pushing : " <<4 << endl;S.push2(4);
	S.printStack();
	cout << S.pop2() << endl;
	cout << S.pop2() << endl;
	cout << S.pop1() << endl;
	cout << S.pop1() << endl;
	cout << S.pop1() << endl;
	cout << S.pop1() << endl;
	cout << S.pop1() << endl;
	cout << S.pop2() << endl;
	cout << S.pop2() << endl;
	cout << S.pop2() << endl;
	S.printStack();

}