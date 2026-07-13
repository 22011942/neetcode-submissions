class Solution {
public:
    bool isValid(string s) {
        
        std::stack<char> brackets;

        for (const auto & c : s) {
            if (brackets.empty()) {
                brackets.push(c);
                continue;
            }

            if (brackets.top() == '(' && c == ')') {
                brackets.pop();
                continue;
            }

            if (brackets.top() == '{' && c == '}') {
                brackets.pop();
                continue;
            }

            if (brackets.top() == '[' && c == ']') {
                brackets.pop();
                continue;
            }

            brackets.push(c);

        }

        return brackets.empty();
    }
};
