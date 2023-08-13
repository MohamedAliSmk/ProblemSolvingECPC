#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int sumDigits(int num) {
    int sum = 0;
    while (num > 0) {
        // Extract the last digit using modulo 10
        int digit = num % 10;
        // Add the digit to the sum
        sum += digit;
        // Remove the last digit from the number
        num /= 10;
    }
    return sum;
}

int main() {
    int T;
    cin >> T;

    if (T < 1 || T > 100000) {
        return 1;
    }

    for (int t = 0; t < T; ++t) {
        long long L, R;
        cin >> L >> R;

        if (L < 1 || R < 1 || L > 1e9 || R > 1e9) {
            return 1;
        }
        int numofNotdelete =(R-L) +1   ;
        for (long long i = L; i <= R; ++i) {
        int sumofnum= sumDigits(i);
            if(sumofnum % 2 ==0){
                numofNotdelete--;
            }
        }
        
        cout << numofNotdelete<< endl; // Move to the next line after printing the range
    }

    return 0;
}
