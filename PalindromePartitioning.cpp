// https://oj.leetcode.com/problems/palindrome-partitioning/
class Solution {
public:
    vector<vector<string> > partition(string s) {
        _result.clear();
        if (0 == s.length()) {
            return _result;
        }
        vector<vector<int> > palin_index_len(s.length(), vector<int>());
        int idx_before = 0, idx_after = 0;
        for (int i = 0; i < s.length(); ++i) {
            idx_before = idx_after = i;
            while (idx_before >= 0 && idx_after < s.length() && s.at(idx_before) == s.at(idx_after)) {
                palin_index_len.at(idx_before).push_back(idx_after - idx_before + 1);
                --idx_before;
                ++idx_after;
            }

            idx_before = i;
            idx_after = i + 1;
            while (idx_before >= 0 && idx_after < s.length() && s.at(idx_before) == s.at(idx_after)) {
                palin_index_len.at(idx_before).push_back(idx_after - idx_before + 1);
                --idx_before;
                ++idx_after;
            }
        }

        tryNext(palin_index_len, 0, vector<string>(), s);
        return _result;
    }

private:

    void tryNext(vector<vector<int> >& palin_index_len, int cur_index, vector<string> path, string& s) {
        if (cur_index >= s.length()) {
            _result.push_back(path);
        } else {
            for (int i = 0; i < palin_index_len.at(cur_index).size(); ++i) {
                path.push_back(s.substr(cur_index, palin_index_len.at(cur_index).at(i)));
                tryNext(palin_index_len, cur_index + palin_index_len.at(cur_index).at(i), path, s);
                path.pop_back();
            }
        }
    }
    vector<vector<string> > _result;
};
