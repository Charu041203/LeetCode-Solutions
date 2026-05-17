class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string current = "";
        path += "/";
        
        for (char c : path) {
            if (c == '/') {
                if (current == "..") {
                    if (!stack.empty()) {
                        stack.pop_back();
                    }
                } else if (current != "" && current != ".") {
                    stack.push_back(current);
                }
                current = "";
            } else {
                current += c;
            }
        }
        
        string result = "";
        for (const string& dir : stack) {
            result += "/" + dir;
        }
        
        return result.empty() ? "/" : result;
    }
};