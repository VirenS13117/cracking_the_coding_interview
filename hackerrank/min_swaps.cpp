/*
You are given an unordered array consisting of consecutive integers in [1, 2, 3, ..., n] without any duplicates. 
You are allowed to swap any two elements. You need to find the minimum number of swaps required to sort the array
in ascending order.
For example, given the array [7,1,3,2,4,5,6] we perform the following steps:

i   arr                         swap (indices)
0   [7, 1, 3, 2, 4, 5, 6]   swap (0,3)
1   [2, 1, 3, 7, 4, 5, 6]   swap (0,1)
2   [1, 2, 3, 7, 4, 5, 6]   swap (3,4)
3   [1, 2, 3, 4, 7, 5, 6]   swap (4,5)
4   [1, 2, 3, 4, 5, 7, 6]   swap (5,6)
5   [1, 2, 3, 4, 5, 6, 7]

It took 5 swaps to sort the array.
Function Description
Complete the function minimumSwaps in the editor below. 
It must return an integer representing the minimum number of swaps to sort the array.

minimumSwaps has the following parameter(s):
arr: an unordered array of integers
Input Format

The first line contains an integer,n , the size of arr. 
The second line contains n space-separated integers arr[i].

Constraints
1<=n<=10^5
1<=arr[i]<=n

Output Format
Return the minimum number of swaps to sort the given array.

Solution : Here the trick is simple as the numbers range from 1 to n and array size is also n.
So for each element there is an appropraite position arr[i]-1 for an element arr[i].
We recursively search for correct order for each position.
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void swap_fn(int &a, int &b){
    int c = b;
    b = a;
    a = c;
}
// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
    int arr_size = arr.size();
    if(arr_size<=1){
        return 0;
    }
    int min_swaps = 0;
    for(int i=0;i<arr_size;i++){
        while(arr[i]-1 != i){
            swap_fn(arr[i],arr[arr[i]-1]);
            min_swaps++;
        }
    }
    return min_swaps;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = minimumSwaps(arr);

    fout << res << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
