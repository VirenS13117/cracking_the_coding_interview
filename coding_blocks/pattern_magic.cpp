/*
5
*	*	*	*	*	*	*	*	*
*	*	*	*		*	*	*	*
*	*	*				*	*	*
*	*						*	*				
*	*		*	*
*	*	*	*	*

*/
#include<iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	int line_count = 1;
	int begin = N, end = N-2;
	while(line_count<N+1){
		int sub_count = 0;
		while(sub_count<2*N-1){
			if(sub_count>=begin && sub_count<=end){
				cout<<" ";
			}
			else{
				cout<<"*";
			}
			sub_count++;
		}
		cout<<endl;
		begin--;
		end++;
		line_count++;
	}
	line_count -= 2;
	begin += 2;
	end -= 2;
	while(line_count>=1){
		int sub_count = 0;
		while(sub_count<2*N-1){
			if(sub_count>=begin && sub_count<=end){
				cout<<" ";
			}
			else{
				cout<<"*";
			}
			sub_count++;
		}
		cout<<endl;
		begin++;
		end--;
		line_count--;
	}
	return 0;
}