#include<iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	int line_count = 1;
	int spaces = 2*N-1;
	while(line_count<N+1){
		int value = N;
		int space_count = 1;
		int value_count = 1;

		while(value_count<=line_count){
			cout<<value<<" ";
			value--;
			value_count++;
		}

		while(space_count<=spaces){
			cout<<"  ";
			space_count++;
		}
		
		value += 1;
		value_count = 1;
		while(value_count<=line_count){
			cout<<value<<" ";
			value++;
			value_count++;
		}
		cout<<endl;
		line_count++;
		spaces -= 2;
	}
	int val = N;
	int count = 1;
	while(val>0){
		cout<<val<<" ";
		val--;
	}
	cout<<0<<" ";
	val += 1;
	count = 1;
	while(val<=N){
		cout<<val<<" ";
		val++;
	}
	cout<<endl;
	line_count = 1;
	spaces += 2;
	while(line_count<=N){
		int value = N;
		int space_count = 1;
		int value_count = 1;

		while(value_count<=N-line_count+1){
			cout<<value<<" ";
			value--;
			value_count++;
		}

		while(space_count<=spaces){
			cout<<"  ";
			space_count++;
		}
		
		value += 1;
		value_count = 1;
		while(value_count<=N-line_count+1){
			cout<<value<<" ";
			value++;
			value_count++;
		}
		cout<<endl;
		line_count++;
		spaces += 2;
	}
	return 0;
}