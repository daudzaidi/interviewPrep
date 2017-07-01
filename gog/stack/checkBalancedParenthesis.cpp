#include <iostream>
#include <stack>
using namespace std;

bool matchPairParenthesis(char startingParenthesis, char closingParenthesis){
	if(startingParenthesis == '(' && closingParenthesis == ')'){
		return true;
	}else if(startingParenthesis == '[' && closingParenthesis == ']'){
		return true;
	}else if(startingParenthesis == '{' && closingParenthesis == '}'){
		return true;
	}
	return false;
}


bool checkBalancedParenthesis(string expression){
	stack<char> S;
	for(int i=0;i<expression.size();i++){
		if(expression[i] == '{' || expression[i] == '(' || expression[i] == '[' ){
			S.push(expression[i]);
		}else if(expression[i] == '}' || expression[i] == ')' || expression[i] == ']'){
			if(matchPairParenthesis(S.top(), expression[i])){
				//cout << "Parenthesis matched : "<< expression[i] << " : "<< S.top()<< endl;
				S.pop();
			}else{
				return false;
			}
		}
	}

	if(S.empty()){
		return true;
	}else{
		return false;
	}
	
}


int main(){
	string expression;
	getline(cin , expression);
	cout << checkBalancedParenthesis(expression);
}
