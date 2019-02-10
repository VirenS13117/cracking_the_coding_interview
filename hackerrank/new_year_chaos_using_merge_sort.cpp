#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

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
// Complete the minimumBribes function below.
void minimumBribes(vector<int> q) {
    //2 1 5 3 4
    int q_size = q.size();
    if(q_size <= 1){
        printf("%d\n",0);
    }
    for(int i=0;i<q_size;i++){
        if(q[i]-i-1>2){
            printf("%s\n","Too chaotic");
            return;
        }
    }
    int sum_swaps = 0;
    mergesort(q,0,q_size - 1,sum_swaps);
    printf("%d\n",sum_swaps);
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split_string(q_temp_temp);

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

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
