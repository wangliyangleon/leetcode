// https://oj.leetcode.com/problems/simplify-path/
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> dir_stack;
        string cur_dir = "";

        for (string::const_iterator iter = path.begin();
                iter != path.end(); ++iter) {
            if ('/' == *iter) {
                if ((cur_dir.length() > 0) && ("." != cur_dir)) {
                    if (".." == cur_dir) {
                        if ((!dir_stack.empty())/* && (".." != dir_stack.top()) */) {
                            dir_stack.pop();
                        } /* else {
                             dir_stack.push(cur_dir);
                             } */
                    } else {
                        dir_stack.push(cur_dir);
                    }
                }
                cur_dir = "";
            } else {
                cur_dir += string(1, *iter);
            }
        }
        if ((cur_dir.length() > 0) && ("." != cur_dir)) {
            if (".." == cur_dir) {
                if ((!dir_stack.empty())/* && (".." != dir_stack.top()) */) {
                    dir_stack.pop();
                } /* else {
                     dir_stack.push(cur_dir);
                     } */
            } else {
                dir_stack.push(cur_dir);
            }
        }

        string result = "";
        while (!dir_stack.empty()) {
            result = ("/" + dir_stack.top()) + result;
            dir_stack.pop();
        }
        return result.length() > 0 ? result : "/";
    }
};
