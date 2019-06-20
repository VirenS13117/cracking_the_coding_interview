#include<iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	int line_count = 1;
	int max = 1;
	int stars = N-1;
	while(line_count<=N){
		int value = 1;
		while(value<=max){
			cout<<value;
			value++;
		}
		int star_count = 1;
		while(star_count<=stars){
			cout<<"*";
			star_count++;
		}
		cout<<endl;
		max++;
		stars--;
		line_count++;
	}
	return 0;
}