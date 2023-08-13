#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <climits>
using namespace std;

// Function to calculate the XOR of two integers
int xorInt(int a, int b) {
    return a ^ b;
}

int main() {
    int T;
    cin >> T;

    if (T < 1 || T > 10) {
        return 1;
    }

    for (int t = 0; t < T; ++t) {
        int N, M;
        cin >> N >> M;

        if (N < 1 || M < 1 || N > 100000 || M > 100000) {
            return 1;
        }

        vector<int> A(N), B(M);

        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            if (A[i] > 1000) {
                return 1;
            }
        }

        unordered_set<int> xorSet;

        for (int i = 0; i < M; ++i) {
            cin >> B[i];
            if (B[i] > 1000000000) {
                return 1;
            }
        }

        // Compute the prefix XOR array for B
        vector<int> prefixXOR(M + 1, 0);
        for (int i = 0; i < M; ++i) {
            prefixXOR[i + 1] = xorInt(prefixXOR[i], B[i]);
        }

        int minOperations = INT_MAX;

        // Try each XOR value from the set and count operations
        for (int i = 0; i < M; ++i) {
            for (int j = i; j < M; ++j) {
                int x = xorInt(prefixXOR[j + 1], prefixXOR[i]);
                xorSet.insert(x);
            }
        }

        for (const int& x : xorSet) {
            int operations = 0;
            for (int i = 0; i < N; ++i) {
                int diff = xorInt(A[i], x);
                if (diff > A[i]) {
                    operations = -1; // Not possible
                    break;
                }
                while (diff > 0) {
                    diff &= (diff - 1); // Count set bits
                    operations++;
                }
            }
            if (operations != -1) {
                minOperations = min(minOperations, operations);
            }
        }

        if (minOperations == INT_MAX) {
            cout << -1 << endl;
        } else {
            cout << minOperations << endl;
        }
    }

    return 0;
}
// the last test case not correct ,i'm sorry -_-