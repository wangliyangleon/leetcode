// https://oj.leetcode.com/problems/combination-sum-ii/
class Solution {
public:
    struct num_item_t {
        num_item_t(int v) : val(v), cnt(1) {}
        int val;
        int cnt;
    };
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        if (0 == num.size()) {
            return vector<vector<int> >();
        }

        sort(num.begin(), num.end());
        vector<num_item_t> num_vec(1, num_item_t(num.at(0)));
        int cur_val = num.at(0);
        for (int i = 1; i < num.size(); ++i) {
            if (num.at(i) == cur_val) {
                ++(num_vec[num_vec.size() - 1].cnt);
            } else {
                num_vec.push_back(num_item_t(num.at(i)));
                cur_val = num.at(i);
            }
        }
        _result.clear();
        _tryNext(num_vec, target, 0, vector<int>(), 0, 0);
        return _result;
    }

private:
    void _tryNext(const vector<num_item_t> &num_vec, const int target, int cur_index, vector<int> cur_vec, int cur_sum, int cur_used) {
        if (target == cur_sum) {
            _result.push_back(cur_vec);
            return;
        }
        if (cur_sum > target) {
            return;
        }
        if (cur_used < num_vec.at(cur_index).cnt) {
            cur_vec.push_back(num_vec.at(cur_index).val);
            _tryNext(num_vec, target, cur_index, cur_vec, cur_sum + num_vec.at(cur_index).val, cur_used + 1);
            cur_vec.pop_back();
        }
        for (int i = cur_index + 1; i < num_vec.size(); ++i) {
            cur_vec.push_back(num_vec.at(i).val);
            _tryNext(num_vec, target, i, cur_vec, cur_sum + num_vec.at(i).val, 1);
            cur_vec.pop_back();
        }
    }
    vector<vector<int> > _result;
};
