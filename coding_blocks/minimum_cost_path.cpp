/*
Finding	Minimum-Cost	Path	in	a	2-D
Matrix
Problem :	Given a	cost matrix	Cost[][] where Cost[i][j] denotes the Cost of visiting cell
with coordinates(i,j), find	a min-cost path	to reach a cell(x,y) from cell(0,0)	under
the	condition that you can only	travel one step	right or one step down.
*/

#include<iostream>
using namespace std;

int bottom_up(int cost[100][100], int N){
	int sol[N][N];
	sol[0][0]=cost[0][0];
	for(int i=1;i<N;i++){
		sol[i][0] = sol[i-1][0] + cost[i][0];
		sol[0][i] = sol[0][i-1] + cost[0][i];
	}
	for(int i=1;i<N;i++){
		for(int j=1;j<N;j++){
			sol[i][j] = cost[i][j] + min(sol[i][j-1],sol[i-1][j]);
		}
	}
	return sol[N-1][N-1];
}

int top_down(int cost[100][100], int i, int j, int sol[100][100]){
	if(i<0 || j<0){
		return 0;
	}
	if(sol[i][j]!=-1){
		return sol[i][j];
	}
	if(i==0 && j==0){
		sol[i][j] = cost[i][j];
		return sol[i][j];
	}
	if(i==0){
		sol[i][j] = cost[i][j]+top_down(cost,i,j-1,sol);
		return sol[i][j];
	}
	if(j==0){
		sol[i][j] = cost[i][j]+top_down(cost,i-1,j,sol);
		return 	sol[i][j];
	}
	sol[i][j] = cost[i][j] + min(top_down(cost,i-1,j,sol), top_down(cost,i,j-1,sol));
	return sol[i][j];
}

int recursive_cost(int cost[100][100], int i, int j){
	if(i<0 || j<0){
		return 0;
	}
	if(i==0 && j==0){
		return cost[i][j];
	}
	if(i==0){
		return cost[i][j]+recursive_cost(cost,i,j-1);
	}
	if(j==0){
		return cost[i][j]+recursive_cost(cost,i-1,j);
	}
	return cost[i][j] + min(recursive_cost(cost,i-1,j), recursive_cost(cost,i,j-1));
}

int main(){
	int cost[100][100];//={{1,2,1},{3,2,1},{1,0,1}};
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>cost[i][j];	
		}
	}
	int sol[100][100]={0};
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			sol[i][j]=-1;
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<cost[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<recursive_cost(cost,N-1,N-1)<<endl;
	cout<<top_down(cost,N-1,N-1,sol)<<endl;
	cout<<bottom_up(cost,N)<<endl;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<sol[i][j]<<"\t";
		}
		cout<<endl;
	}
	return 0;	
}