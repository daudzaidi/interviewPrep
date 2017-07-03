#include <iostream>
using namespace std;

#define max 1000

class Stack {
	int top;
	int arr[max];
	public : 
		Stack(){
			top = -1;
		}
		void push(int x);
		int pop();
		int isEmpty();
};


void Stack :: push(int x){
	if(top >= max){
		cout << "Stack Over flow";
		//return false;
		abort();
	}
	arr[++top] = x;
	
}

int Stack :: pop(){
	if(top < 0){
		cout << "Stack under flow" << top<< endl;
		return INT_MIN; 
	}
	int res = arr[top];
	top--;
	return res;
}

int Stack :: isEmpty(){
	if(top == -1){
		return true;
	}
	return false;
}

// int Stack :: isFull(){
// 	if(top == max-1){
// 		return true;
// 	}
// 	return false;
// }


class specialStack : public Stack
{
	Stack min;
public:
	int pop();
	void push(int x);
	int getMin();
	
};

void specialStack :: push(int x){
	if(isEmpty()){
		Stack :: push(x);
		min.push(x);
	}else{
		Stack :: push(x);
		int y = min.pop();
		min.push(y);
		if(x < y){
			min.push(x);
		}else{
			min.push(y);
		}
	}
}


int specialStack :: pop(){
	int res = Stack :: pop();
	//cout << res << endl;
	min.pop();
	return res;
}

int specialStack :: getMin(){
	int res =  min.pop();
	min.push(res);
	return res;
}

int main(){

	specialStack S;
	S.push(11);
	S.push(2);
	S.push(3);
	S.push(10);
	cout << S.pop()<<endl;
	cout << S.pop()<<endl;
	cout << S.pop()<<endl;
	cout << S.getMin()<<endl;

}