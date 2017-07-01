#include <iostream>
#include <stack>
using namespace std;


// Naive method : Using two loops

void ngeUsingTwoLoops(int arr[], int len){
	int nge ;
	for(int i=0;i<len;i++){
		//cout << "===="<< arr[i];
		nge=-1;
		for(int j=i+1; j< len; j++){
			if(arr[i] < arr[j]){
				nge = arr[j];
				break;
			}
		}
			cout << "NGE for " <<arr[i] << " is : " << nge<< endl;
	}

}


void ngeUsingStack(int arr[], int len){
	//cout << "hii";
	int nge;
	stack<int> S;
	S.push(arr[0]);

	for(int i=1;i<len;i++){
	//	cout << i<<endl;
			nge = arr[i];
			if(!S.empty()){
				 
				 int k = S.top();
				 S.pop();
				
				
				while(k < nge ){
					cout << k << " --> "<<nge<<endl;
					if(S.empty()) {
						break;
					}
					k = S.top();
					S.pop();
				}

				if(k>nge){
					S.push(k);
				}

			}
		S.push(nge);
	}

	while(!S.empty()){
		cout << S.top() << " --> -1"<< endl;
		S.pop();
	}
}


int main(){
	int arr[] = {11, 13, 21, 3, 1, 0,77};
	int len = sizeof(arr)/sizeof(arr[0]);
	
	//ngeUsingTwoLoops(arr, len);
	ngeUsingStack(arr, len);


}