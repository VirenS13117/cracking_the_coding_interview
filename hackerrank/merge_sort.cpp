/*
Count inversions with merge sort
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> merge_arrays(vector<int>first_array, vector<int>second_array, int &sum_swaps){
    int first_size = first_array.size();
    int second_size = second_array.size();
    vector<int> result;
    int first_index = 0;
    int second_index = 0;
    while((first_index < first_size) && (second_index < second_size)){
        if(first_array[first_index] <= second_array[second_index]){
            result.push_back(first_array[first_index]);
            first_index++;
        }
        else{
            sum_swaps += first_size - first_index;  
            result.push_back(second_array[second_index]);
            second_index++;
        }
    }
    while(first_index < first_size){
        result.push_back(first_array[first_index]);
        first_index++;
    }
    while(second_index < second_size){
        result.push_back(second_array[second_index]);
        second_index++;
    }
    return result;
}

vector<int> mergesort(vector<int> a, int begin, int end, int &sum_swaps){
    vector<int>result;
    if(begin==end){
        result.push_back(a[begin]);
    }
   
    if(begin<end){
        int mid = (begin + end)/2;
        vector<int>first = mergesort(a, begin,mid,sum_swaps);
        vector<int>second = mergesort(a, mid+1,end,sum_swaps);
        result = merge_arrays(first,second,sum_swaps);
    }
    return result;
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    int sum_swaps = 0;
    for (int i = 0; i < n; ++i)scanf("%d",&a[i]);
    vector<int>result = mergesort(a,0,n-1,sum_swaps);
    for (int i = 0; i < n; ++i)printf("%d ",result[i]);
    printf("\n");
    printf("%d\n",sum_swaps);
    return 0;
}
