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

vector<string> split_string(string);

// Complete the arrayManipulation function below.
bool comparator(vector<int> i1, vector<int> i2){
    return i1[0] < i2[0];
}

long arrayManipulation(int n, vector<vector<int>> queries) {
    int size_of_queries = queries.size();
    if(size_of_queries==0){
        return 0;
    }
    long max_sum = 0;
    for(int i=0;i<n;i++){
        long element_val=0;
        for(int j=0;j<size_of_queries;j++){
            if(i>=queries[j][0]-1 && i<=queries[j][1]-1){
                element_val += queries[j][2];
            }
        }
        max_sum = max(max_sum,element_val);
    }
    return max_sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

    fout << result << "\n";

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
