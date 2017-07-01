#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void stockSpanNaiveMethod(int arr[], int len){
	int span ;
	vector<int> spans;
	for(int i=0;i<len;i++){
		span = 1;
		for(int j=i; j>=0;j--){
			if(arr[j] < arr[i]){
				span++;
			}
		}
		spans.push_back(span);
	}

	for(int i=0;i<spans.size();i++)
		cout << spans[i]<< " ";
		cout << endl;

}

/*
	My own algo: 
*/

// void stockSpanUsingStackMyAlgo(int arr[], int len){
// 	stack<int> S;
// 	vector<int> res;
// 	S.push(arr[0]); int span;
// 	for(int i=0;i<len ;i++){
// 		span = 1;
// 		if(!S.empty()){
// 			int ele = S.top();
// 			S.top();
// 			if(ele > arr[i]){
// 				res.push_back(span);
// 				S.push(ele);
// 			}else{
// 				while(ele < arr[i]){

// 					cout << "here : "<< span<<ele;
// 					if(S.empty()) break;
// 					span++;

// 					ele = S.top();
// 					S.pop();
// 					cout<<"||"<<ele<<"||";
					
// 				}
// 				res.push_back(span);
// 			}
// 		}

// 		S.push(arr[i]);
// 	}

// 		for(int i=0;i<res.size();i++)
// 		cout << res[i]<< " ";
// 		cout << endl;
// }

void stockSpanUsingStackGog(int arr[], int len){
	stack<int> S;
	vector<int> res;
	S.push(0);
	res.push_back(1);
	int temp;
	for(int i=1;i<len;i++){
		temp =1;
		if(!S.empty()){
			while(arr[S.top()] < arr[i] && !S.empty()){
				S.pop();
			}
			temp = i - S.top();
			res.push_back(temp);
		}

		S.push(i);
	}
		for(int i=0;i<res.size();i++)
		cout << res[i]<< " ";
		cout << endl;
}

int main(){
	int arr[] = {10, 4, 5, 90, 120, 80};
	int len = sizeof(arr)/sizeof(arr[0]);
	//stockSpanNaiveMethod(arr, len);

	stockSpanUsingStackGog(arr, len);
}