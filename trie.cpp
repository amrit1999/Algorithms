class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string &s) {
        TrieNode* curr = root;
        for (int i = s.size() - 1; i >= 0; --i) {
            int index = s[i] - 'a';
            if (!curr->children[index]) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }

    bool searchWord(string &s) {
        TrieNode* curr = root;
        for (int i = s.size() - 1; i >= 0; --i) {
            int index = s[i] - 'a';
            if (!curr->children[index]) {
                return false;
            }
            curr = curr->children[index];
            if (curr->isEndOfWord) {
                return true;
            }
        }
        return curr->isEndOfWord;
    }
};
