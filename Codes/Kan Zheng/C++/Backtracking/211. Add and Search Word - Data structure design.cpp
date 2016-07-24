class TrieNode {
public:
    TrieNode() : isWord(0), next() {}
    bool isWord;
    TrieNode* next[26];
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode;
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* p = root;
        for(int i = 0; i < word.size(); i++) {
            if(!p->next[word[i] - 'a']) {
                p->next[word[i] - 'a'] = new TrieNode;
            }
            p = p->next[word[i] - 'a'];
        }
        p->isWord = 1;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchHelper(word, root, 0);
    }
    
private:
    
    bool searchHelper(string& word, TrieNode*& p, int k) {
        if(p == NULL) {
            return false;
        }
        if(k == word.size()) {
            return p->isWord;
        }
        
        if(word[k] == '.') {
            for(int i = 0; i < 26; i++) {
                if(searchHelper(word, p->next[i], k+1)) {
                    return true;
                }
            }
            return false;
        }else {
            return searchHelper(word, p->next[word[k] - 'a'], k+1);
        }
    }

    TrieNode* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
