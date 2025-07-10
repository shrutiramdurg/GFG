class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    string word;

    TrieNode() {
        isEnd = false;
        word = "";
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
    }
};

class Solution {
public:
    string longestString(vector<string> &words) {
        TrieNode* root = new TrieNode();

        // Insert all words into the Trie
        for (const string &w : words) {
            TrieNode* node = root;
            for (char c : w) {
                int idx = c - 'a';
                if (!node->children[idx])
                    node->children[idx] = new TrieNode();
                node = node->children[idx];
            }
            node->isEnd = true;
            node->word = w;
        }

        // BFS to find the longest word with all prefixes present
        string ans = "";
        queue<TrieNode*> q;
        q.push(root);

        while (!q.empty()) {
            TrieNode* curr = q.front(); q.pop();
            for (int i = 25; i >= 0; --i) { // reversed for lexicographical order
                TrieNode* child = curr->children[i];
                if (child && child->isEnd) {
                    q.push(child);
                    if (child->word.length() > ans.length() || 
                       (child->word.length() == ans.length() && child->word < ans)) {
                        ans = child->word;
                    }
                }
            }
        }

        return ans;
    }
};
