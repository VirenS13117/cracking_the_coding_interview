#include<iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	int spaces = N+1;
	int line_count = 1;
	int begin = 2;
	int end = 2*N-2;
	while(line_count<=N){
		int count = 1;
		int sub_count = 1;
		while(sub_count<=2*N-1){
			if(sub_count>=begin && sub_count<=end){
				cout<<"\t";
			}
			else{
				cout<<count<<"\t";
			}
			if(sub_count<N){
				count++;
			}
			else{
				count--;
			}
			sub_count++;
		}
		begin++;
		end--;
		cout<<endl;
		line_count++;
	}
	return 0;
}