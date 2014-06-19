// https://oj.leetcode.com/problems/search-for-a-range/
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result(2, -1);
        if (0 == n) {
            return result;
        }
        int left = 0, right = n - 1, mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (target == A[mid]) {
                break;
            } else if (target > A[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (left <= right) {
            left = right = mid;
            while (left >= 0 && A[left] == target) {
                --left;
            }
            while (right < n && A[right] == target) {
                ++right;
            }
            result[0] = left + 1;
            result[1] = right - 1;
        }
        return result;
    }
};
