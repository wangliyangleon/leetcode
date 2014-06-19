// https://oj.leetcode.com/problems/subsets/
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        _result.clear();
        _tryNext(S, vector<int>(), 0);
        return _result;
    }

private:
    void _tryNext(vector<int> &S, vector<int> cur_comb, int cur_index) {
        _result.push_back(cur_comb);
        for (int i = cur_index; i < S.size(); ++i) {
            cur_comb.push_back(S.at(i));
            _tryNext(S, cur_comb, i + 1);
            cur_comb.pop_back();
        }
    }
    vector<vector<int> > _result;
};
