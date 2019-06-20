#include<iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	int line_count = 1;
	int max = N;
	int stars = -1;
	while(line_count<=N){
		int value = 1;
		while(value<=max){
			cout<<value<<" ";
			value++;
		}
		int star_count = 1;
		while(star_count<=stars){
			cout<<"* ";
			star_count++;
		}
		cout<<endl;
		max--;
		stars += 2;
		line_count++;
	}
	return 0;
}