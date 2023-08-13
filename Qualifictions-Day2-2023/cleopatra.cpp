#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    int T;
    cin >> T;

    if (T < 1 || T > 1000) {
        return 1;
    }

    for (int t = 0; t < T; ++t) {
        int N, D;
        cin >> N >> D;

        if (N < 1 || N > 1000000 || D < 1 || D > 1000000000) {
            return 1;
        }

        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            if (A[i] < 1 || A[i] > 1000000000) {
                return 1;
            }
        }

        int Q;
        cin >> Q;
        vector<tuple<int, int>> Q_pairs;
        for (int i = 0; i < Q; ++i) {
            int x, y;
            cin >> x >> y;
            if (x < 1 || y < 1 || x > N || y > N) {
                return 1;
            }
            Q_pairs.emplace_back(x, y); // Store the pair (x, y) in the vector Q_pairs
        }

        for (int i = 0; i < Q; ++i) {
            int x, y;
            tie(x, y) = Q_pairs[i];

            if (abs(A[x - 1] - A[y - 1]) <= D) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}


    //in standared output should be (YES , YES , NO) ,this code print (YES , NO ,NO)