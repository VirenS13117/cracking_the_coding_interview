#include<iostream>
using namespace std;
#define ll long long int
#define m 1000000007

ll pow_fun(ll base, ll exp){
	if(exp==0){
		return 1;
	}
	if(exp%2){
		return (base%m * pow_fun(base,exp-1)%m)%m;
	}
	else{
		return (pow_fun((base*base)%m, exp/2)%m)%m;
	}
}
int main(){
	ll N;
	cin>>N;
	cout<<pow_fun(N,m-2)<<endl;;
	return 0;
}