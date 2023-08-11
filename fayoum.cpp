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
    vector <int> A(i);
    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;

        if (N < 1 || N > 1000000) {
            return 1;
        }
        cnt_one=0;
        cnt_neg_one=0;
        cnt_zero=0;

        for (int i =0 ; i<N ;++i){
        cin >> A(i);
        A.sort(A.begin(),A.end())
        cnt_one=A.count(1);
        cnt_neg_one=A.count(-1);
        cnt_zero=A.count(0);

        if (cnt_zero % 2 != 0){
            cnt_one+=1;
        }

        if(cnt_one>cnt_neg_one){
                cout<<"Chess";
            }else if(cnt_one < cnt_neg_one) {
                cout<<"Lol";
            }else{
                cout<<"Go deploying";
            }
        }
    }

    return 0;
}
