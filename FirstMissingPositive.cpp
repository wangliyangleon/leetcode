// https://oj.leetcode.com/problems/first-missing-positive/
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if (0 == n) {
            return 1;
        }

        int temp = 0;
        for (int i = 0; i < n; ++i) {
            if ((A[i] <= n) && (A[i] > 0) && (A[i] != i + 1)) {
                temp = A[A[i] - 1];
                A[A[i] - 1] = A[i];
                A[i] = temp;

                if ((temp <= n) && (temp > 0) && (temp != i + 1) && (temp != A[temp - 1])) {
                    --i;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (i + 1 != A[i]) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
