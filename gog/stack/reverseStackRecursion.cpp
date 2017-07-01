#include <iostream>
#include <stack>

using namespace std;
stack<int> S;

void printStack(){
	while(!S.empty()){
		cout << S.top() << " ";
		S.pop();
	}
	cout << endl;
}

void insertAtBottom(int top){

	if(S.size() > 0){
		int temp = S.top();
		S.pop();
		insertAtBottom(top);
		S.push(temp);
	}else{
		S.push(top);
	}

}


void reverse(){
	if(S.size() > 0){
		int top = S.top();
		S.pop();
		reverse();
		insertAtBottom(top);		
	}
}

int main(){

	S.push(1);
	S.push(2);
	S.push(3);
	S.push(4);
	S.push(10);
	S.push(8);

	reverse();

	printStack();
}