#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode *child[26];
    bool word;
    TrieNode(char ch) {
        for (int i = 0; i < 26; ++i)
            child[i] = nullptr;
        word = false;
    }
};
class Trie {
public:
    Trie() {
        root = new TrieNode(' ');
    }
    ~Trie() {
        delete root;
    }
    
    void insert(string word) {
        TrieNode *curr = root;
        for (char ch: word) {
            if (curr->child[ch - 'a'] == nullptr)
                curr->child[ch - 'a'] = new TrieNode(ch - 'a');
            curr = curr->child[ch - 'a'];
        }
        curr->word = true;
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        for (char ch: word) {
            if (curr->child[ch - 'a'] == nullptr)
                return false;
            curr = curr->child[ch - 'a'];
        }
        return curr->word;
    }

    // return true if there is a word that has a prefix
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for (char ch: prefix) {
            if (curr->child[ch - 'a'] == nullptr)
                return false;
            curr = curr->child[ch - 'a'];
        }
        return true;
    }
private:
    TrieNode *root;
};