// https://oj.leetcode.com/problems/word-ladder/
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<pair<string, int> > path;
        path.push(pair<string, int>(start, 1));
        unordered_set<string> used;
        used.insert(start);

        while (!path.empty()) {
            string cur_str = path.front().first;
            int cur_step = path.front().second;

            for (int i = 0; i < cur_str.length(); ++i) {
                string str_left = cur_str.substr(0, i);
                string str_right = cur_str.substr(i + 1, cur_str.length() - i - 1);
                for (char c = 'a'; c <= 'z'; ++c) {
                    // error : string cur_str_conv = cur_str.replace(i, 1, string(1, c));
                    string cur_str_conv = str_left + string(1, c) + str_right;
                    if (cur_str_conv == end) {
                        return cur_step + 1;
                    } else if ((dict.end() != dict.find(cur_str_conv)) && (used.end() == used.find(cur_str_conv))) {
                        path.push(pair<string, int>(cur_str_conv, cur_step + 1));
                        used.insert(cur_str_conv);
                    }
                }
            }
            path.pop();
        }
        return 0;
    }
};
