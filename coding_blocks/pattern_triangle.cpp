#include<iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	int line_count = 1;
	int spaces = N-1;
	while(line_count<=N){
		int space_count = 1;
		while(space_count<=spaces){
			cout<<"\t";
			space_count++;
		}
		int value = line_count;
		int value_count = 1;
		while(value_count<=line_count){
			cout<<value<<"\t";
			value++;
			value_count++;
		}
		value -= 2;
		value_count=1;
		while(value_count<=line_count-1){
			cout<<value<<"\t";
			value--;
			value_count++;
		}
		cout<<endl;
		spaces--;
		line_count++;
	}
	
	return 0;
}