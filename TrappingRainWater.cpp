// https://oj.leetcode.com/problems/trapping-rain-water/
class Solution {
public:
    int trap(int A[], int n) {
        if (0 == n) {
            return 0;
        }
        vector<int> before_height(1, A[0]);
        vector<int> after_height(n, A[n - 1]);
        int result = 0, cur_val = 0;
        for (int i = 1; i < n; ++i) {
            if (A[i] <= before_height.at(i - 1)) {
                before_height.push_back(before_height.at(i - 1));
            } else {
                before_height.push_back(A[i]);
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (A[i] <= after_height.at(i + 1)) {
                after_height[i] = after_height.at(i + 1);
            } else {
                after_height[i] = A[i];
            }
        }
        for (int i = 0; i < n; ++i) {
            cur_val = min(before_height.at(i), after_height.at(i)) - A[i];
            result += (cur_val > 0 ? cur_val : 0);
        }
        return result;
    }
};
