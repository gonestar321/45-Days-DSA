class Solution {
public:
    string simplifyPath(string path) {
                vector<string> stack; 
        string result;
        stringstream ss(path); 
        string token;

        while (getline(ss, token, '/')) {
            if (token == "." || token.empty()) {
                continue;
            } else if (token == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                stack.push_back(token);
            }
        }
        for (const string& dir : stack) {
            result += "/" + dir;
        }
        return result.empty() ? "/" : result;

    }
};