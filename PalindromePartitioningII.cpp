// https://oj.leetcode.com/problems/palindrome-partitioning-ii/
class Solution {
public:
    int minCut(string s) {
        if (s.length() <= 1) {
            return 0;
        }
        vector<vector<int> > min_cut_vec(s.length(), vector<int>(s.length(), -1));
        // get all palin
        for (int i = 0; i < s.length(); ++i) {
            min_cut_vec[i][i] = 0;
            for (int j = i - 1, k = i + 1; j >= 0 && k < s.length(); --j, ++k) {
                if (s.at(j) == s.at(k)) {
                    min_cut_vec[j][k] = 0;
                } else {
                    break;
                }
            }
            for (int j = i, k = i + 1; j >= 0 && k < s.length(); --j, ++k) {
                if (s.at(j) == s.at(k)) {
                    min_cut_vec[j][k] = 0;
                } else {
                    break;
                }
            }
        }
        return _minCutRange(s, 0, s.length() - 1, min_cut_vec);
    }

private:
    int _minCutRange(const string& s, int start, int end, vector<vector<int> >& min_cut_vec) {
        if (-1 == min_cut_vec.at(start).at(end)) {
            int min_cut = INT_MAX;
            for (int i = start + 1; i <= end; ++i) {
                if (0 == min_cut_vec.at(i).at(end)) {
                    int cur_cut = _minCutRange(s, start, i - 1, min_cut_vec) + 1;
                    min_cut = min(cur_cut, min_cut);
                }
            }
            min_cut_vec[start][end] = min_cut;
        }
        return min_cut_vec.at(start).at(end);
    }
};
