#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    // Corner case
    if (n <= 1)
        return false;
  
    // Check from 2 to sqrt(n)
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
  
    return true;
}

int countPrimeFactors(int n) {
    int count = 0;
    while (n % 2 == 0) {
        count++;
        n /= 2;
    }

    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            count++;
            n /= i;
        }
    }

    if (n > 2)
        count++;
    return count;
}

int main() {
    int Q;
    cin >> Q;

    if (Q < 1 || Q > 100000) {
        return 1;
    }

    for (int q = 0; q < Q; ++q) {
        int l, r, X;
        cin >> l >> r >> X;

        if (l < 1 || l > r || r > 100000 || X < 1 || X > 16) {
            return 1;
        }
        
        int count = 0;
        for (int i = l; i <= r; ++i) {
            if (countPrimeFactors(i) == X) {
                ++count;
            }
        }
        cout << count << endl;
    }

    return 0;
}
