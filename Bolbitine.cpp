#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int T;
    cin >> T;

    if (T < 1 || T > 1000) {
        return 1;
    }

    for (int t = 0; t < T; ++t) {
        int N, K;
        cin >> N;
        cin >> K;
        unordered_map<int, int> freq;

        if (N < 1 || N > 1000000 || K < 1 || K > 1000000000) {
            return 1;
        }

        vector<int> A(N);
 
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            ++freq[A[i]];
        }
    
        int Maxk = 0;
        int mink = 0; 
        
        for (int i = 0; i < N; ++i) {
            Maxk = max(Maxk, freq[A[i]]);
            mink = min(mink, freq[A[i]]);
        }
    
        for (int i = 0; i < N; ++i) {
            A[i] = Maxk - mink;
            A.insert(A.end(),1,Maxk);
        }
        
        cout << Maxk<< endl;
    }

    return 0;
}
