// https://oj.leetcode.com/problems/jump-game/
class Solution {
public:
    bool canJump(int A[], int n) {
        if (1 >= n) {
            return true;
        }

        if (A[0] >= (n - 1)) {
            return true;
        }
        int cur_step = A[0];
        for (int i = 1; i < n; ++i) {
            if (0 == cur_step) {
                return false;
            }
            cur_step = max(cur_step - 1, A[i]);
        }
        return true;
    }
};
