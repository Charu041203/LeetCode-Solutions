class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        for (const string& s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                long b = st.top(); st.pop();
                long a = st.top(); st.pop();
                if (s == "+") st.push(a + b);
                else if (s == "-") st.push(a - b);
                else if (s == "*") st.push(a * b);
                else st.push(a / b);
            } else {
                st.push(stoi(s));
            }
        }
        return (int)st.top();
    }
};