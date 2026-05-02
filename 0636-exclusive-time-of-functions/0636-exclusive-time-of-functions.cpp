class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n, 0);
        stack<int> st;
        int prevTime = 0;
        
        for (const string& log : logs) {
            int firstCol = log.find(':');
            int lastCol = log.find_last_of(':');
            
            int id = stoi(log.substr(0, firstCol));
            string type = log.substr(firstCol + 1, lastCol - firstCol - 1);
            int timestamp = stoi(log.substr(lastCol + 1));
            
            if (type == "start") {
                if (!st.empty()) {
                    result[st.top()] += timestamp - prevTime;
                }
                st.push(id);
                prevTime = timestamp;
            } else {
                result[st.top()] += timestamp - prevTime + 1;
                st.pop();
                prevTime = timestamp + 1;
            }
        }
        
        return result;
    }
};