#include <iostream>
using namespace std;

// Naive algorithm

int countInRangeNaive(int arr[], int n, int k, int j){
	int count = 0;
	for(int i=0; i<n; i++){
		if(arr[i] >= k && arr[i]<=j){
			count++;
		}
	}
	return count;
}

// Efficient Approach


int findUpperBound(int arr[], int len, int x){
	int start = 0;
	int end = len-1;
	while(start <= end){
		int mid = (start+end)/2;
		// if(arr[mid] == x){
		// 	start = mid + 1;
		// }else 
		if(arr[mid] <= x){
			start = mid+1;
			//cout << "start : "<< start<< " ";

		}else {
			end = mid-1;
			//cout << "end : "<< end << " ";

		}
	}
	return end;
}


int findLowerBound(int arr[], int len, int x){
	int start = 0; int end = len-1;
	while(start<=end){
		int mid = (start+end)/2;
		if(arr[mid] < x){
			start = mid+1;
		//	cout << "start : "<< start<< " ";
		}else{
			end = mid-1;
			//cout << "end : "<< end << " ";
		}
	}
	return start;
}

int countInRangeBinary(int arr[], int len, int x, int y){
	sort(arr, arr+len);
	int res= findUpperBound(arr, len, y) - findLowerBound(arr, len, x) + 1;
	return res;
}


int main(){
	int arr[] = {  1, 3, 4, 9, 10, 3 };
    //int arr[] = {2,2,3,3,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i=9 , j=12;
    cout << countInRangeBinary(arr, n, i, j);
    // sort(arr , arr+n);
    // cout << findUpperBound(arr, n, 1);
    // cout << findLowerBound(arr, n, 1);



}