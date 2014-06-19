// https://oj.leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        stack<char> left_stack;
        for (string::iterator iter = s.begin(); iter != s.end(); ++iter) {
            switch (*iter) {
                case '(':
                case '[':
                case '{':
                    left_stack.push(*iter);
                    break;
                case ')':
                    if (left_stack.empty() || ('(' != left_stack.top())) {
                        return false;
                    }
                    left_stack.pop();
                    break;
                case ']':
                    if (left_stack.empty() || ('[' != left_stack.top())) {
                        return false;
                    }
                    left_stack.pop();
                    break;
                case '}':
                    if (left_stack.empty() || ('{' != left_stack.top())) {
                        return false;
                    }
                    left_stack.pop();
                    break;
                default:
                    break;
            }
        }
        return left_stack.empty();
    }
};
