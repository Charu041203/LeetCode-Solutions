class Solution {
public:
    bool isMatch(string s, string p) {
        int sIdx = 0, pIdx = 0, lastWildcardIdx = -1, sNextToMatch = -1;
        int sLen = s.length(), pLen = p.length();

        while (sIdx < sLen) {
            if (pIdx < pLen && (p[pIdx] == '?' || p[pIdx] == s[sIdx])) {
                sIdx++;
                pIdx++;
            } else if (pIdx < pLen && p[pIdx] == '*') {
                lastWildcardIdx = pIdx;
                sNextToMatch = sIdx;
                pIdx++;
            } else if (lastWildcardIdx != -1) {
                pIdx = lastWildcardIdx + 1;
                sNextToMatch++;
                sIdx = sNextToMatch;
            } else {
                return false;
            }
        }

        while (pIdx < pLen && p[pIdx] == '*') {
            pIdx++;
        }

        return pIdx == pLen;
    }
};