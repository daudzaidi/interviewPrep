#include <iostream>
#include <unordered_map>
using namespace std;

int countWords(string s[], int n){
	unordered_map<string, int> map;
	int cnt = 0;
	for(int i=0;i<n;i++){
		map[s[i]] += 1;
	}
	for(auto it=map.begin(); it != map.end(); it++){
		if(it->second == 2)
			cnt++;
	}
	return cnt;
}


int main(){
	string s[] = {"one", "two", "three", "three", "two"};
	int len = sizeof(s)/sizeof(s[0]);
	cout << countWords(s, len);
}

