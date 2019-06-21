#include<bits/stdc++.h>
using namespace std;

bool is_present(int a[], int size, int element, int begin){
	for (int i = begin+1; i < size; ++i)
	{
		if(a[i]==element){
			return true;
		}
	}
	return false;
}

void target_sum_pair(int a[], int size, int begin, int target, int current){
	int last_value = INT_MIN;
	for (int i = begin+1; i < size; i++)
	{
		if(is_present(a,size,target-a[i],i) && a[i]>last_value){
			cout<<current<<", "<<a[i]<<" and "<<target-a[i]<<endl;
			last_value = a[i];
		}
	}
}

int main(){
	int N,M, a[10000];
	cin>>N;
	for (int i = 0; i < N; i++)
	{
		cin>>a[i];
	}
	sort(a,a+N);
	cin>>M;
	for (int i = 0; i < N; i++)
	{
		target_sum_pair(a,N,i,M-a[i],a[i]);
	}
	return 0;
}