#include <bits/stdc++.h>

using namespace std;

/*
* Also known as extended Euclidean algorithm.
* computes the modular multiplicative inverse of y such that (y * inverse(y, mod)) % mod = 1.
* used instead of division when doing calculations under a given modulus.
* returns -1 if no inverse exists.
*/

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;

ll inverse (ll y, ll mod) {
    ll t = 0, new_t = 1, r = mod, new_r = y;

    while (new_r != 0) {
        ll q = r / new_r;
        
        ll temp_t = t;
        t = new_t;
        new_t = temp_t - q * new_t;

        ll temp_r = r;
        r = new_r;
        new_r = temp_r - q * new_r;
    }

    if (r > 1) {
        return -1;
    }
    else if (t < 0) {
        return t + mod;
    }
    else {
        return t;
    }
}

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    const ll mod = 1e9 + 7;
    ll y = 10;
    ll inv = inverse(y, mod);

    cout <<  "y = " << y << endl;
    cout << "inverse(y, mod) = " << inv << endl;
    cout << "(y * inverse(y, mod)) % mod = " << (y * inv) % mod << endl;
}
