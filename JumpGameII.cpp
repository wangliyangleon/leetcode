// https://oj.leetcode.com/problems/jump-game-ii/
class Solution {
public:
    int jump(int A[], int n) {
        if (n < 2) {
            return 0;
        }
        int max_index = 0, cur_max_step = 0, cur_step = 0, step_cnt = 0;
        while (max_index < n - 1) {
            cur_step = step_cnt;
            cur_max_step = max_index;
            while (cur_step <= cur_max_step) {
                max_index = max(max_index, cur_step + A[cur_step]);
                ++cur_step; 
            }   
            ++step_cnt;
        }   
        return step_cnt;
    }   
};  
