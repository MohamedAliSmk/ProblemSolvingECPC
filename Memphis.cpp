#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int countDigits(int num) {
    // Convert the number to a string
    string numStr = to_string(num);
    // Return the length of the string, which represents the number of digits
    return numStr.length();
}

int main() {
    int T;
    cin >> T;

    if (T < 1 || T > 1000) {
        return 1;
    }

    for (int t = 0; t < T; ++t) {
        long long L, R;
        cin >> L >> R;

        if (L < 1 || R < 1 || L > 1e17 || R > 1e17) {
            return 1;
        }
        int NumOfPeople =0  ;
        for (long long i = L; i <= R; ++i) {
            int numOfRelatives= countDigits(i);
            NumOfPeople +=numOfRelatives;
        }
        
        cout << NumOfPeople<< endl; // Move to the next line after printing the range
    }

    return 0;
}
