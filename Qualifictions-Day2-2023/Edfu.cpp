#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    if (T < 1 || T > 10) {
        return 1;
    }

    for (int t = 0; t < T; ++t) {
        string N;
        cin >> N;

        if (N.empty() || N.length() > 100000) {
            return 1;
        }

        int originalNumber = stoi(N);
        int smallestMultiple = -1;

        // Iterate through all possible positions to insert digits
        for (int i = 0; i <= N.length(); ++i) {
            // Try inserting digits (0 to 9) at position i
            for (char digit = '0'; digit <= '9'; ++digit) {
                string modifiedN = N;
                modifiedN.insert(i, 1, digit);

                // Convert the modified string to an integer
                int num = stoi(modifiedN);

                // Check if the modified number is a multiple of 11 and different from the original
                if (num != originalNumber && num % 11 == 0) {
                    // If the current multiple is smaller than the previous one (or the first one found)
                    if (smallestMultiple == -1 || num < smallestMultiple) {
                        smallestMultiple = num;
                    }
                }
            }
        }

        // Output the smallest multiple of 11 for the current test case
        cout << smallestMultiple << endl;
    }

    return 0;
}
