// https://oj.leetcode.com/problems/3sum-closest/
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if (3 > num.size()) {
            return 0;
        }
        sort(num.begin(), num.end());
        vector<int> num_max3;
        int cur_num = num.at(0), cur_cnt = 1;
        num_max3.push_back(cur_num);
        for (int i = 1; i < num.size(); ++i) {
            if (cur_num != num.at(i)) {
                cur_cnt = 0;
            } else if (cur_cnt >= 3) {
                continue;
            }
            num_max3.push_back(num.at(i));
            ++cur_cnt;
        }
        int idx_before = 0, idx_after = 0, cur_sum = 0;
        int result = num_max3.at(0) + num_max3.at(1) + num_max3.at(2);
        for (int i = 0; i < num_max3.size() - 2; ++i) {
            idx_before = i + 1;
            idx_after = num_max3.size() - 1;
            while (idx_before < idx_after) {
                cur_sum = num_max3.at(i) + num_max3.at(idx_before) + num_max3.at(idx_after);
                if (cur_sum > target) {
                    --idx_after;
                } else if (cur_sum < target) {
                    ++idx_before;
                } else {
                    return target;
                }
                if (abs(cur_sum - target) < abs(result - target)) {
                    result = cur_sum;
                }
            }
        }
        return result;
    }
};
