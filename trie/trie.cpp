#include <iostream>
using namespace std;

// Trie Node Definition
struct TrieNode {
    TrieNode* children[26];  // For 'a' to 'z'
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};

// Trie Class
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the trie
    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';  // Only lowercase letters
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    // Search a word in the trie
    bool search(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->children[index])
                return false;
            node = node->children[index];
        }
        return node->isEndOfWord;
    }

    // Check if any word in the trie starts with the given prefix
    bool startsWith(const string& prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (!node->children[index])
                return false;
            node = node->children[index];
        }
        return true;
    }

    // Destructor to free memory
    ~Trie() {
        freeMemory(root);
    }

private:
    void freeMemory(TrieNode* node) {
        if (!node) return;
        for (int i = 0; i < 26; ++i)
            freeMemory(node->children[i]);
        delete node;
    }
};

// Test the Trie
int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");
    trie.insert("ball");

    cout << boolalpha;
    cout << "Search 'apple': " << trie.search("apple") << endl;   // true
    cout << "Search 'app': " << trie.search("app") << endl;       // true
    cout << "Search 'bat': " << trie.search("bat") << endl;       // true
    cout << "Search 'ball': " << trie.search("ball") << endl;     // true
    cout << "Search 'cat': " << trie.search("cat") << endl;       // false

    cout << "Prefix 'ap': " << trie.startsWith("ap") << endl;     // true
    cout << "Prefix 'ba': " << trie.startsWith("ba") << endl;     // true
    cout << "Prefix 'ca': " << trie.startsWith("ca") << endl;     // false

    return 0;
}
