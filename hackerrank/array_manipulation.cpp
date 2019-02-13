/*
Starting with a 1-indexed array of zeros and a list of operations,
for each operation add a value to each of the array element between two given indices, inclusive. 
Once all operations have been performed, return the maximum value in your array.
The largest value is 10 after all operations are performed.
Function Description
Complete the function arrayManipulation in the editor below. 
It must return an integer, the maximum value in the resulting array.
arrayManipulation has the following parameters:
n - the number of elements in your array
queries - a two dimensional array of queries where each queries[i] contains three integers, a, b, and k.

Solution : For each element position check in which all intervals it lies in and then add the value for each interval
in the array position. O(mn)
*/
#include <bits/stdc++.h>

using namespace std;

// Complete the arrayManipulation function below.x
long arrayManipulation(long int n, vector<vector<long int> > queries) {
    long int size_of_queries = queries.size();
    if(size_of_queries==0){
        return 0;
    }
    long int *solution_array = new long int[n]();
    long int max_sum = 0;
    long int interval_sum = 0;
    for (long int i = 0; i < size_of_queries; ++i)
    {
        solution_array[queries[i][0]-1] += queries[i][2];
        solution_array[queries[i][1]] -= queries[i][2];
    }
    for (long int i = 0; i <n; ++i)
    {
        interval_sum += solution_array[i];
        max_sum = max(max_sum,interval_sum);
    }
    return max_sum;
}

int main()
{
    long int n,m;
    scanf("%ld",&n);
    scanf("%ld",&m);
    vector<vector<long int> > a(m);
    for (long int i = 0; i < m; ++i){
        a[i].resize(3);
        scanf("%ld",&a[i][0]);
        scanf("%ld",&a[i][1]);
        scanf("%ld",&a[i][2]);
    }
    long int max_sum = arrayManipulation(n,a);
    printf("%ld\n",max_sum);
    return 0;
}
