// https://oj.leetcode.com/problems/generate-parentheses/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        _result.clear();
        if (0 == n) {
            return _result;
        }
        _try_fill("(", n, 1, 0);
        return _result;
    }
private:

    void _try_fill(string str, int n, int lc, int rc) {
        if ((lc > n) || (rc > lc)) {
            return;
        }
        if (str.length() == 2 * n) {
            _result.push_back(str);
        } else {
            _try_fill(str + "(", n, lc + 1, rc);
            _try_fill(str + ")", n, lc, rc + 1);
        }
    }
    vector<string> _result;
};
