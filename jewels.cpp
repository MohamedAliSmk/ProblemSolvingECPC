#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N < 1 || N > 100000) {
        cout << "NO" << endl;
        return 1;
    }

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];

        if (A[i] < 1 || A[i] > 1000000) {
            cout << "NO" << endl;
            return 1;
        }
    }

    int Q;
    cin >> Q;

    if (Q < 1 || Q > 100000) {
        cout << "NO" << endl;
        return 1;
    }

    unordered_map<int, int> frequency;

    for (int i = 0; i < N; ++i) {
        ++frequency[A[i]];
    }

    for (int q = 0; q < Q; ++q) {
        int L, R, X, Z;
        cin >> L >> R >> X >> Z;

        if (L < 1 || L > R || R > N || X < 1 || X > Z || Z > N) {
            cout << "NO" << endl;
            return 1;
        }

        unordered_set<int> distinctFrequencies;

        for (int i = L - 1; i < R; ++i) {
            int freq = frequency[A[i]];
            if (freq == X || freq == X + 1 || freq == Z) {
                distinctFrequencies.insert(freq);
            }
        }

        if (distinctFrequencies.size() >= 3) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
