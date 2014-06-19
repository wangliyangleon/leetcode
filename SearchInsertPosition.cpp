// https://oj.leetcode.com/problems/search-insert-position/
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (0 == n) {
            return 0;
        }
        if (target <= A[0]) {
            return 0;
        }
        if (target > A[n - 1]) {
            return n;
        }
        if (target == A[n - 1]) {
            return n - 1;
        }

        int left = 0, right = n, mid = left + (right - left) / 2;
        while ((A[mid] < target) || (A[mid - 1] >= target)) {
            if (A[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
            mid = left + (right - left) / 2;
        }
        return mid;
    }
};
