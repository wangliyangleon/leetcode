// https://oj.leetcode.com/problems/word-break/
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<int> flag_vec(s.length(), -1);
        bool result = false;
        for (size_t i = 0; i < s.length(); ++i) {
            if (dict.end() != dict.find(s.substr(0, i + 1))) {
                result = true;
                flag_vec[i] = 1;
            } else {
                result = _try_step(s, i, flag_vec, dict);
            }
        }
        return result;
    }

private:
    bool _try_step(const string& s, size_t index, vector<int>& flag_vec, const unordered_set<string> &dict) {
        if (-1 == flag_vec.at(index)) {
            int result = 0;
            if (0 == index) {
                result = ((dict.end() == dict.find(s.substr(0, 1))) ? 0 : 1);
            } else {
                for (int i = index - 1; i >= 0; --i) {
                    if ((1 == flag_vec.at(i)) && (dict.end() != dict.find(s.substr(i + 1, index - i)))) {
                        result = 1;
                        break;
                    }
                }
            }
            flag_vec[index] = result;
        }
        return (1 == flag_vec.at(index));
    }
};
