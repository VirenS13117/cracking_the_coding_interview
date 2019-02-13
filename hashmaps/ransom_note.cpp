#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool ransom_note(vector<string> magazine, vector<string> ransom) {
    map<string, int> my_map;
    for(int i=0;i<magazine.size();i++){
        if(my_map.find(magazine[i])==my_map.end()){
            my_map.emplace(magazine[i],1);
        }
        else{
            my_map[magazine[i]]++;
        }
    }
    for(int i=0;i<ransom.size();i++){
        if(my_map.find(ransom[i])==my_map.end()){
            return false;
        }
        else{
            if(my_map[ransom[i]]==0){
                return false;
            }
            my_map[ransom[i]]--;
        }
    }
    return true;
    
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
