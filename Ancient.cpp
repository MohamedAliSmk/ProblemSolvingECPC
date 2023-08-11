#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    if (T < 1 || T > 1000) {
        return 1;
    }

    int Totalcost=0;
    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;

        if (N < 1 || N > 1000000) {
            return 1;
        }
        vector <int> A(N);
        int cost=0;
        for (int i=0 ; i< N ; ++i){
            cin >> A[i];
        
        
        while(A[i] != 1) {
            A[i]--;
            cost++;
        }
        
        }
        Totalcost+=cost;
    }
    cout<<Totalcost;

    return 0;
}
