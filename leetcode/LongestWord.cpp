class Solution {
public:
    struct TrieNode {
        TrieNode* child[26];
        bool wordEnd;

        TrieNode() {
            wordEnd = false;
            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };

    void insertKey(TrieNode* root, string s) {
        TrieNode* cur = root;
        for (auto c : s) {
            if (cur->child[c - 'a'] == nullptr) {
                TrieNode* newNode = new TrieNode();
                cur->child[c - 'a'] = newNode;
            }
            cur = cur->child[c - 'a'];
        }
        cur->wordEnd = true;
    }
    bool searchKey(TrieNode* root, string key) {
        TrieNode* cur = root;
        for (auto c : key) {
            if (cur->child[c - 'a'] == nullptr)
                return false;
            else if (cur->child[c - 'a'] != nullptr and
                     cur->child[c - 'a']->wordEnd == false) {
                return false;
            }
            cur = cur->child[c - 'a'];
        }

        return true;
    }
    string longestWord(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (auto s : words) {
            insertKey(root, s);
        }
        string res = "";
        for (int i = words.size() - 1; i >= 0; i--) {
            if (searchKey(root, words[i])) {
                if(words[i].size()>res.size()){
                    res=words[i];
                }
                else if(words[i].size()==res.size()){
                    res=words[i]>res?res:words[i];
                }
            }
        }

        return res;
    }
};
