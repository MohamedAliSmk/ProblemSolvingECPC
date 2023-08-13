#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;

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

        vector<int> A(N);
        int cnt_one = 0;
        int cnt_neg_one = 0;
        int cnt_zero = 0;
        
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            if (A[i] == 1) {
                cnt_one++;
            } else if (A[i] == -1) {
                cnt_neg_one++;
            } else if (A[i] == 0) {
                cnt_zero++;
            }
        }
        if (cnt_zero % 2 != 0) {
                cnt_one++;
                }
        cout<<"cnt_zero: "<<cnt_zero<<endl<<"cnt_one: "<<cnt_one<<endl<<"cnt_neg_one: "<<cnt_neg_one<<endl;

        if (cnt_one > cnt_neg_one) {
            cout << "Chess" << endl;
        } else if (cnt_one < cnt_neg_one) {
            cout << "Lol" << endl;
        } else {
            cout << "Go deploying" << endl;
        }
    }

    return 0;
}
