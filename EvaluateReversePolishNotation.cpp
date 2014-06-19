// https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if (0 == tokens.size()) {
            return 0;
        }
        stack<int> param_stack;
        int ret = 0, param1 = 0, param2 = 0;
        for (vector<string>::iterator iter = tokens.begin();
                iter != tokens.end(); ++iter) {
            if (*iter == "+") {
                param1 = param_stack.top();
                param_stack.pop();
                param2 = param_stack.top();
                param_stack.pop();
                ret = param1 + param2;
                param_stack.push(ret);
            } else if (*iter == "-") {
                param1 = param_stack.top();
                param_stack.pop();
                param2 = param_stack.top();
                param_stack.pop();
                ret = param2 - param1;
                param_stack.push(ret);
            } else if (*iter == "*") {
                param1 = param_stack.top();
                param_stack.pop();
                param2 = param_stack.top();
                param_stack.pop();
                ret = param1 * param2;
                param_stack.push(ret);
            } else if (*iter == "/") {
                param1 = param_stack.top();
                param_stack.pop();
                param2 = param_stack.top();
                param_stack.pop();
                ret = param2 / param1;
                param_stack.push(ret);
            } else {
                ret = atoi(iter->c_str());
                param_stack.push(ret);
            }
        }
        return param_stack.top();
    }
};
