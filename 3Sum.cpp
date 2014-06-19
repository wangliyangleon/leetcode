// https://oj.leetcode.com/problems/3sum/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int target = 0;
        vector<vector<int> > result;
        if (num.size() < 3) {
            return result;
        }
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size() - 2; ++i) {
            if ((i > 0) && (num.at(i - 1) == num.at(i))) {
                continue;
            }
            int k1 = i + 1, k2 = num.size() - 1, remain = target - num.at(i), tmp_remain = 0;
            while (k1 < k2) {
                if ((k1 - i > 1) && (num.at(k1 - 1) == num.at(k1))) {
                    ++k1;
                    continue;
                }
                tmp_remain = num.at(k1) + num.at(k2);
                if (tmp_remain == remain) {
                    vector<int> cur_result;
                    cur_result.push_back(num.at(i));
                    cur_result.push_back(num.at(k1));
                    cur_result.push_back(num.at(k2));
                    result.push_back(cur_result);
                    k1++;
                    k2--;
                } else if (tmp_remain > remain) {
                    k2--; 
                } else {
                    k1++;
                }   
            }   
        }   
        return result;
    }

private:
};
