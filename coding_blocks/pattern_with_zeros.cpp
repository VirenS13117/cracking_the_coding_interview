#include<iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	int line_count = 1;
	while(line_count<=N){
		int sub_count = 1;
		int value = line_count;
		while(sub_count<=line_count){
			if(sub_count==1 || sub_count==line_count){
				cout<<value<<"\t";
			}
			else{
				cout<<0<<"\t";
			}
			sub_count++;
		}
		value++;
		line_count++;
		cout<<"\n";
	}

	return 0;
}