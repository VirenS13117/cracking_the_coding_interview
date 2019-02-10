/*A left rotation operation on an array shifts each of the array's elements  unit to the left. 
For example, if  left rotations are performed on array , then the array would become .
Given an array a of n integers and a number, d , perform  left rotations on the array. 
Return the updated array to be printed as a single line of space-separated integers.

Function Description

Complete the function rotLeft in the editor below. It should return the resulting array of integers.
rotLeft has the following parameter(s):
An array of integers a.
An integer d, the number of rotations.
Input Format

The first line contains two space-separated integers n and d, the size of a and the number of left rotations you must perform. 
The second line contains n space-separated integers a[i].

Constraints
1<=n<=10^5
1<=d<=n
1<=a[i]<=10^6

Output Format

Print a single line of n space-separated integers denoting the final state of the array after performing d left rotations.

Sample Input
5 4
1 2 3 4 5

Sample Output
5 1 2 3 4
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void swap(int &first, int &second){
    int temp = second;
    second = first;
    first = temp;
}

void rotate(vector<int> &a, int first, int second){
    while(first<second){
        swap(a[first],a[second]);
        first++;
        second--;
    }
}

vector<int> rotLeft(vector<int> a, int d) {
    int array_size = a.size();
    if(array_size <= 1){
        return a;
    }
    int rot = d%array_size;
    int position_of_first_element = array_size - rot;
    rotate(a,0,array_size-1);
    rotate(a,0,position_of_first_element-1);
    rotate(a,position_of_first_element,array_size-1);
    return a;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    vector<int> result = rotLeft(a, d);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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