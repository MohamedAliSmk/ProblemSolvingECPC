#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>
using namespace std;

void insertingchar(string &S, int &maxFrequency) {
    char c = S[0]; 
    S.insert(0, 1, c);
    maxFrequency++;
}

int main() {
    int T;
    cin >> T;

    if (T < 1 || T > 1000) {
        return 1;
    }

    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;

        if (N < 1 || N > 1000000) {
            return 1;
        }
        int targetCount = (N / 2) +1;
        string S;
        cin >> S;

        for (char &c : S) {
            c = tolower(c);
        }

        unordered_map<char, int> frequency;
        int maxFrequency = 0;

        // Count the frequency of each character
        for (char c : S) {
            ++frequency[c];
            if (frequency[c] > maxFrequency) {
                maxFrequency = frequency[c];
            }
        }

        // Calculate the number of operations needed to make the string beautiful
        int operations = 0;
        operations = targetCount - maxFrequency;
        while (maxFrequency < targetCount) {
            insertingchar(S, maxFrequency);
            operations++;
        }

        cout << operations << endl;
    }

    return 0;
}
