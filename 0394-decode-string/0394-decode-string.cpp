class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> resultStack;
        string currentString = "";
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                counts.push(k);
                resultStack.push(currentString);
                currentString = "";
                k = 0;
            } else if (c == ']') {
                string temp = currentString;
                currentString = resultStack.top();
                resultStack.pop();
                int repeatTimes = counts.top();
                counts.pop();
                while (repeatTimes--) {
                    currentString += temp;
                }
            } else {
                currentString += c;
            }
        }

        return currentString;
    }
};