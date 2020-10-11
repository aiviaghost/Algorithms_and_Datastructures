#include <bits/stdc++.h>

using namespace std;

/*
* Time complexity: O(1) for both "Find" and "Union".
* Note that creating a UF for N items is O(N).
*
* Implementation of the pseudo code from the wikipedia article about the datastructure. 
* (Can be found at https://en.wikipedia.org/wiki/Disjoint-set_data_structure)
*/

struct Union_Find {
    vector<int> repr, sz;

    Union_Find(int n) {
        repr.resize(n);
        sz.resize(n, 1);
        for (int i = 1; i < n; i++) {
            repr[i] = i;
        }
    }

    auto Find(int a) -> int {
        if (a != repr[a]) {
            repr[a] = Find(repr[a]);
        }
        return repr[a];
    }

    auto Union(int a, int b) -> void {
        a = Find(a);
        b = Find(b);
        if (a == b) {
            return;
        }
        if (sz[b] > sz[a]) {
            swap(a, b);
        }
        repr[b] = a;
        sz[a] += sz[b];
    }

    auto size(int a) -> int {
        return sz[Find(a)];
    }
};

auto main() -> int {
    cin.tie(0)->sync_with_stdio(0);

    // Example:
    Union_Find UF(10);
    
    UF.Union(2, 5);

    cout << (UF.Find(2) == UF.Find(5) ? "true" : "false") << "\n";
    cout << (UF.Find(2) == UF.Find(3) ? "true" : "false") << "\n";
}
