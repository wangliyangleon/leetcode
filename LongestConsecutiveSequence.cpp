// https://oj.leetcode.com/problems/longest-consecutive-sequence/
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if (0 == num.size()) {
            return 0;
        }
        unordered_set<int> numset;
        for (vector<int>::iterator iter = num.begin(); iter != num.end(); ++iter) {
            numset.insert(*iter);
        }
        unordered_set<int>::iterator iter = numset.begin();
        int result = 0, cur_val = 0, find_val_right = 0, find_val_left = 0, cur_len = 0;
        while (iter != numset.end()) {
            cur_val = *iter;
            numset.erase(cur_val);
            cur_len = 1;
            find_val_right = cur_val + 1;
            while (numset.find(find_val_right) != numset.end()) {
                numset.erase(find_val_right++);
                cur_len++;
            }
            find_val_left = cur_val - 1;
            while (numset.find(find_val_left) != numset.end()) {
                numset.erase(find_val_left--);
                cur_len++;
            }
            if (cur_len > result) {
                result = cur_len;
            }
            iter = numset.begin();
        }
        return result;
    }
};
