/*
It's New Year's Day and everyone's in line for the Wonderland rollercoaster ride!
There are a number of people queued up, and each person wears a sticker indicating their initial position 
in the queue. Initial positions increment by 1 from 1 at the front of the line to n at the back.
Any person in the queue can bribe the person directly in front of them to swap positions. 
If two people swap positions, they still wear the same sticker denoting their original places in line.
One person can bribe at most two others. For example, if n=8 and Person 5 bribes Person 4, 
the queue will look like this: 1,2,3,4,5,6,7,8.
Fascinated by this chaotic queue, you decide you must know the minimum number of bribes that took place 
to get the queue into its current state!

Function Description

Complete the function minimumBribes in the editor below. 
It must print an integer representing the minimum number of bribes necessary,
or Too chaotic if the line configuration is not possible.

minimumBribes has the following parameter(s):

q: an array of integers
Input Format

The first line contains an integer , the number of test cases.

Each of the next t pairs of lines are as follows: 
- The first line contains an integer , the number of people in the queue 
- The second line has n space-separated integers describing the final state of the queue.


Output Format

Print an integer denoting the minimum number of bribes needed to get the queue into its final state.
Print Too chaotic if the state is invalid, i.e. it requires a person to have bribed more than  people.


Solution : The problem reduces to finding the numbers greater than a particular element on its left side.
Since whenever an element is swapped by another element(call it swapping element) in its right 
a number greater than the swapped element comes to its left.
Most important point is no swapping element can go beyond 2 unit distance left from swapped element
Therefore we see element from position q[i]-2 to i.
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumBribes function below.
void minimumBribes(vector<int> q) {
    int q_size = q.size();
    if(q_size <= 1){
        printf("%d\n",0);
    }
    int sum_swaps=0;
    for(int i=0;i<q_size;i++){
        if(q[i]-i-1>2){
            printf("%s\n","Too chaotic");
            return;
        }
        for(int j=max(q[i]-2,0);j<i;j++){
            if(q[j]>q[i]){
                sum_swaps++;
            }
        }
    }
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
