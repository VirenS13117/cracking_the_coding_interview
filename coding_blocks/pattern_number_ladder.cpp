#include<iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	int value = 1;
	int line_count = 1;
	while(line_count<=N){
		int sub_count = 1;
		while(sub_count<=line_count){
			cout<<value<<"\t";
			sub_count++;
			value++;
		}
		cout<<endl;
		line_count++;
	}
	return 0;
}