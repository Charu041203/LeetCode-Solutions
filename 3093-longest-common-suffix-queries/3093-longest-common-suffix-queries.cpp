#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct TrieNode {
    TrieNode* children[26];
    int bestIndex;

    TrieNode(int index) {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        bestIndex = index;
    }
};

class Solution {
private:
    void clear(TrieNode* node) {
        if (!node) return;
        for (int i = 0; i < 26; ++i) {
            if (node->children[i]) {
                clear(node->children[i]);
            }
        }
        delete node;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int baseIndex = 0;
        for (int i = 1; i < wordsContainer.size(); ++i) {
            if (wordsContainer[i].length() < wordsContainer[baseIndex].length()) {
                baseIndex = i;
            }
        }

        TrieNode* root = new TrieNode(baseIndex);

        for (int i = 0; i < wordsContainer.size(); ++i) {
            string w = wordsContainer[i];
            TrieNode* curr = root;
            
            for (int j = w.length() - 1; j >= 0; --j) {
                int idx = w[j] - 'a';
                if (!curr->children[idx]) {
                    curr->children[idx] = new TrieNode(i);
                }
                curr = curr->children[idx];
                
                int currBest = curr->bestIndex;
                if (w.length() < wordsContainer[currBest].length()) {
                    curr->bestIndex = i;
                }
            }
        }

        vector<int> ans;
        ans.reserve(wordsQuery.size());

        for (const string& q : wordsQuery) {
            TrieNode* curr = root;
            int lastValidBest = root->bestIndex;
            
            for (int j = q.length() - 1; j >= 0; --j) {
                int idx = q[j] - 'a';
                if (!curr->children[idx]) {
                    break;
                }
                curr = curr->children[idx];
                lastValidBest = curr->bestIndex;
            }
            ans.push_back(lastValidBest);
        }

        clear(root);
        return ans;
    }
};