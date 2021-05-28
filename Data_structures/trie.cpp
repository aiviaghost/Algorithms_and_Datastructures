#include <bits/stdc++.h>

using namespace std;

/*
* Time complexity: O(k), k = word.length().
* This applies to "insert" and "contains".
* 
* This code is from Bjarki Ágúst Guðmundsson's competititve
* programming course (can be found at https://algo.is).
* I first learned about tries from his course and that is why I use his implementation.
* I often change this code to find partial matches, find differences between words, etc.
*/

struct Node {
    Node* children[26]; // size of possible different children, i.e a-z => 26, 0-9 => 10
    bool is_end = false;

    Node () {
        memset(children, 0, sizeof(children));
    }
};

auto insert(Node* trie, const char* word) -> void {
    if (*word) {
        if (!trie->children[*word - 'a']) {// use *word - '0' if digits 0-9 is used
            trie->children[*word - 'a'] = new Node();
        }
        insert(trie->children[*word - 'a'], word + 1);
    }
    else {
        trie->is_end = true;
    }
}

auto contains(Node* trie, const char* word) -> bool {
    if (*word) {
        if (!trie->children[*word - 'a']) {
            return false;
        }
        return contains(trie->children[*word - 'a'], word + 1);
    }
    else {
        return trie->is_end;
    }
}
 
auto main() -> int {
    // example:
    Node* trie = new Node();

    vector<string> words{"root", "router", "ring", "hello", "hi"};
    for (string w : words) {
        insert(trie, w.c_str());
    }

    cout << "Write a word and see if it is in the trie: \n";
    string test;
    while (getline(cin, test)) {
        cout << (contains(trie, test.c_str()) ? "Found!" : "Not found!") << "\n";
    }
}
