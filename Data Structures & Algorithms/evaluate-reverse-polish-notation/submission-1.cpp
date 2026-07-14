class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        std::stack<int> RPN;

        int first, second;

        for (const auto & token : tokens) {

            

            if (token == "+") {
                first = RPN.top();
                RPN.pop();
                second = RPN.top();
                RPN.pop();

                RPN.push(second + first);
                continue;
            }

            if (token == "-") {
                first = RPN.top();
                RPN.pop();
                second = RPN.top();
                RPN.pop();

                RPN.push(second - first);
                continue;
            }

            if (token == "*") {
                first = RPN.top();
                RPN.pop();
                second = RPN.top();
                RPN.pop();

                RPN.push(second * first);
                continue;
            }

            if (token == "/") {
                first = RPN.top();
                RPN.pop();
                second = RPN.top();
                RPN.pop();

                RPN.push(second / first);
                continue; 
            }

            
            RPN.push(std::stoi(token));
        }

        return RPN.top();
    }
};
