class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int n = s.length();
        int wordCount = words.size();
        int wordLen = words[0].length();
        int windowSize = wordCount * wordLen;

        unordered_map<string, int> wordFreq;
        for (const string& w : words) {
            wordFreq[w]++;
        }

        for (int i = 0; i < wordLen; ++i) {
            int left = i, right = i, count = 0;
            unordered_map<string, int> currentFreq;

            while (right + wordLen <= n) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordFreq.count(word)) {
                    currentFreq[word]++;
                    count++;

                    while (currentFreq[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        currentFreq[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    currentFreq.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};