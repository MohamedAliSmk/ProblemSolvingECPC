#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;

    if (T < 1 || T > 100000) {
        return 1;
    }

    for (int t = 0; t < T; ++t) {
        int A,B,C;
        cin >> A >> B >> C;

        if (A < 1 || B < 1 || C < 1 || A > 1000000 || B > 1000000 || C > 1000000 ) {
            return 1;
        }
        vector <int> prices(C);
        for (int i=0; i<C ;++i){
            prices[i]+=A*(i+1);
            if (prices[i] >= B){
                prices[i] -=B;
            }
        }
        cout << accumulate(prices.begin(), prices.end(), 0) <<endl;
        
    }

    return 0;
}
