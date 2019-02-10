#include <bits/stdc++.h>
using namespace std;

void swap_fun(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int bubble_sort(vector<int> a){
    int sum_swaps = 0;
    int size_array = a.size();
    bool swap=false;
    for (int i = 0; i < size_array-1; ++i)
    {
        swap = false;
        for (int j = 0; j < size_array-i-1; j++)
        {
            if(a[j]>a[j+1]){
                swap_fun(a[j],a[j+1]);
                sum_swaps++;
                swap=true;
            }
        }
        if(swap=false){
            break;
        }
    }
    return sum_swaps;
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)scanf("%d",&a[i]);
    int sum_swaps = bubble_sort(a);
    printf("%d\n",sum_swaps);
    return 0;
}
