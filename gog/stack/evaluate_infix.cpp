#include <iostream>
#include <stack>

using namespace std;

bool isOperand(char n){
	if(n >= '0' && n <= '9'){
		return true;
	}
	return false;
}

bool isOperator(char n){
	if(n == '+' || n == '*' || n == '/' || n == '-'){
		return true;
	}
	return false;
}


int operate(char operand1, char operand2, char operater){
	if(operater == '+'){
		return (int) operand1 + (int) operand2;
	}else if( operater == '-'){
		return (int) operand1 - (int) operand2;
	}else if(operater == '*'){
		return (int) operand1 * (int) operand2;
	} else if(operater == '/'){
		return (int) operand1 / (int) operand2;
	}
	return -1;
}

int evaluatePostfixExpression(string expr){
	stack<int> S;
	for(int i=0;i<expr.size();i++){
		if(expr[i] == ',') continue;
		if(isOperand(expr[i])){
			int num = 0;
			while(i<expr.size() && isOperand(expr[i])){
				num = num*10 + (expr[i]-'0');
				i++;
			}
			i--;
			S.push(num);
			cout << "Pushing : "<< expr[i]<<S.top()<<endl;
		}else if (isOperator(expr[i])){
			int operand1  = S.top();
			S.pop();
			int operand2 = S.top();
			S.pop();

			cout << "Operating : " << operand1 << " with " << operand2 << endl;

			int res = operate(operand1, operand2, expr[i]);
			S.push(res);
		}
	}

	return S.top();
}	


int main(){
	string expr;
	getline(cin, expr);
	cout << "++++"<<evaluatePostfixExpression(expr) << " ";


}
