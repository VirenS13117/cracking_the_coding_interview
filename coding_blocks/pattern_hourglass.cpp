#include<iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	int line_count = 1;
	int spaces = 0;
	while(line_count<=N){
		int value = N-line_count+1;
		int space_count = 1;
		while(space_count<=spaces){
			cout<<"  ";
			space_count++;
		}
		while(value>=0){
			cout<<value<<" ";
			value--;
		}
		value = 1;
		while(value<=N-line_count+1){
			cout<<value<<" ";
			value++;
		}
		cout<<endl;
		line_count++;
		spaces++;
	}
	int space_count = 1;
	while(space_count<=spaces){
		cout<<"  ";
		space_count++;
	}
	cout<<0<<endl;
	line_count = 1;
	spaces = N- line_count;
	while(line_count<=N){
		int value = line_count;
		int space_count = 1;
		while(space_count<=spaces){
			cout<<"  ";
			space_count++;
		}
		while(value>=0){
			cout<<value<<" ";
			value--;
		}
		value = 1;
		while(value<=line_count){
			cout<<value<<" ";
			value++;
		}
		cout<<endl;
		line_count++;
		spaces--;
	}
	return 0;
}