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

int main(){
	int N,M, a[10000];
	cin>>N;
	for (int i = 0; i < N; i++)
	{
		cin>>a[i];
	}
	sort(a,a+N);
	cin>>M;
	int last_value = INT_MIN;
	for (int i = 0; i < N; i++)
	{
		if(is_present(a,N,M-a[i],i) && a[i]>last_value){
			cout<<a[i]<<" and "<<M-a[i]<<endl;
			last_value = a[i];
		}
	}
	return 0;
}