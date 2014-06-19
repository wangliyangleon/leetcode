// https://oj.leetcode.com/problems/combinations/
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        _result.clear();
        if (0 == n || 0 == k || k > n) {
            return _result;
        }
        try_next(vector<int>(), n, k);
        return _result;
    }

private:

    void try_next(vector<int> cur_vec, int n, int k) {
        if (cur_vec.size() == k) {
            _result.push_back(cur_vec);
        } else {
            int start = cur_vec.size() == 0 ? 1 : cur_vec.at(cur_vec.size() - 1) + 1;
            for (int i = start; i <= n; ++i) {
                cur_vec.push_back(i);
                try_next(cur_vec, n, k);
                cur_vec.pop_back();
            }
        }
    }
    vector<vector<int> > _result;
};
