// https://oj.leetcode.com/problems/combination-sum/
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        _result.clear();
        sort(candidates.begin(), candidates.end());
        tryNext(vector<int>(), 0, candidates, 0, target);
        return _result;
    }   
private:
    void tryNext(vector<int> cur_comb, int cur_sum, vector<int> &candidates, int cur_index, int target) {
        if (cur_sum == target) {
            _result.push_back(cur_comb);
        } else if (cur_sum > target) {
            return;
        } else {
            for (int i = cur_index; i < candidates.size(); ++i) {
                cur_comb.push_back(candidates.at(i));
                tryNext(cur_comb, cur_sum + candidates.at(i), candidates, i, target);
                cur_comb.pop_back();
            }   
        }   
    }   
    vector<vector<int> > _result;
};  
