#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    if (T < 1 || T > 100000) {
        return 1;
    }

    for (int t = 0; t < T; ++t) {
        string N;
        cin >> N;

        if (N.empty() || N.length() > 1000000) {
            return 1;
        }

        int num = stoi(N);

        if ( num % 3 == 0){
            cout <<"Yes"<<endl;
        }else{
            cout <<"NO"<<endl;
        }
        
    }

    return 0;
}
