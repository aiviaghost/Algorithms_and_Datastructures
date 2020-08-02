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
    vector<int> rank, parent;

    Union_Find(int n) {
        rank.resize(n);
        parent.resize(n);
        for (int i = 1; i < n; i++) {
            parent[i] = i;
        }
    }

    auto Find(int x) -> int {
        if (parent[x] == x) {
            return x;
        }
        else {
            parent[x] = Find(parent[x]);
            return parent[x];
        }
    }

    auto Union(int x, int y) -> void {
        int x_root = Find(x);
        int y_root = Find(y);
        if (rank[x_root] > rank[y_root]) {
            parent[y_root] = x_root;
        }
        else if (rank[x_root] < rank[y_root]) {
            parent[x_root] = y_root;
        }
        else if (x_root != y_root) {
            parent[y_root] = x_root;
            rank[x_root] = rank[x_root] + 1;
        }
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
