/*
Flatland is a country with a number of cities, some of which have space stations. 
Cities are numbered consecutively and each has a road of  length connecting it to the next city.
It is not a circular route, so the first city doesn't connect with the last city. 
Determine the maximum distance from any city to it's nearest space station.
For example, there are n=3 cities and m=1 of them has a space station, city .
They occur consecutively along a route. City 2 is 2-1=1 unit away and city 3 is 3-1=2 units away. 
City 1 is 0 units from its nearest space station as one is located there. The maximum distance is 2.

Function Description
Complete the flatlandSpaceStations function in the editor below. 
It should return an integer that represents the maximum distance any city is from a space station.

flatlandSpaceStations has the following parameter(s):
n: the number of cities
c: an integer array that contains the indices of cities with a space station, 1-based indexing
Input Format

The first line consists of two space-separated integers, n and m. 
The second line contains m space-separated integers, the indices of each city having a space-station. 
These values are unordered and unique.

Constraints
1<=n<=10^5

There will be at least 1 city with a space station.
No city has more than one space station.
Output Format

Print an integer denoting the maximum distance that an astronaut in a Flatland city would need to travel 
to reach the nearest space station.

Sample Input 0
5 2
0 4
Sample Output 0
2

Solution : We do not really need to assign all the 0 values to the space station city. 
We just need to observe that between two space sations the middle city would be farthest from both of them.
So we do the following:
a. sort the space stations
b. see the maximum values the end cities are getting
c. compare it with maximum values a middle city between two cities is getting
d. return the greater between the two.
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the flatlandSpaceStations function below.
int flatlandSpaceStations(int n, vector<int> c) {
    int c_size = c.size();
    sort(c.begin(), c.end());
    int max_dist = 0;
    int edge_dist = max(c[0], n - c[c_size-1] - 1);
    for (int i = 0; i < c_size-1; ++i)
    {
        max_dist = (max_dist > (c[i+1]-c[i]))?max_dist:(c[i+1]-c[i]);
    }
    return max(edge_dist,max_dist/2);
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(m);

    for (int i = 0; i < m; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = flatlandSpaceStations(n, c);

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
