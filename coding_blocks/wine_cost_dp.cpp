#include<iostream>
using namespace std;

int bottom_up(int *wines, int N){
	int sol[100][100];
	int day = N;
	for (int i = N-1; i>=0; i--)
	{
		day = N;
		for(int j=0;j<N;j++){
			if(i>j){
				sol[i][j]=0;
			}
			else{
				sol[i][j] = max(sol[i+1][j]+wines[i]*day, sol[i][j-1]+wines[j]*day);
				day--;
			}
		}
	}

	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<sol[i][j]<<"\t";
		}
		cout<<endl;
	}
	return sol[0][N-1];
}

int top_bottom(int *wines, int left_index, int right_index, int N, int sol[][100], int day){
	if(left_index>right_index){
		sol[left_index][right_index]=0;
		return sol[left_index][right_index];
	}
	if(sol[left_index][right_index]==-1){
		int left_cost = wines[left_index]*day + top_bottom(wines, left_index+1, right_index, N, sol, day+1);
		int right_cost = wines[right_index]*day + top_bottom(wines, left_index, right_index-1, N, sol, day+1);
		sol[left_index][right_index] = max(left_cost,right_cost);
	}
	return sol[left_index][right_index];
}

int recursive_wine_cost(int *wines, int left_index, int right_index, int day){
	if(left_index>right_index){
		return 0;
	}
	int left_cost = wines[left_index]*day + recursive_wine_cost(wines, left_index+1, right_index, day+1);
	int right_cost = wines[right_index]*day + recursive_wine_cost(wines, left_index, right_index-1, day+1);
	return max(left_cost,right_cost);
}

int main(){
	int wines[1000];
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>wines[i];
	}
	int sol[100][100];
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			sol[i][j] = -1;
		}
	}
	cout<<recursive_wine_cost(wines,0,N-1,1)<<endl;
	cout<<top_bottom(wines,0,N-1,N,sol,1)<<endl;
	cout<<bottom_up(wines,N)<<endl;
	// for(int i=0;i<=N;i++){
	// 	for(int j=0;j<=N;j++){
	// 		cout<<sol[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	return 0;
}