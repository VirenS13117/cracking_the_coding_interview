#include <bits/stdc++.h>

using namespace std;

// Complete the findDigits function below.
int findDigits(int n) {
    int m = n;
    int count_divisors = 0;
    while(m!=0){
        int p = m%10;
        if(p!=0){
            if(n%p==0){
                count_divisors++;
            }
        }
        m = m/10;
        printf("m at each step %d\n",m);
    }
    return count_divisors;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = findDigits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
