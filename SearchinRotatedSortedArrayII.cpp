// https://oj.leetcode.com/problems/search-in-rotated-sorted-array-ii/
class Solution {
public:
    bool search(int A[], int n, int target) {
        if (0 == n) {
            return -1;
        }
        int pivot = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (A[i] > A[i + 1]) {
                pivot = i + 1;
                break;
            }
        }
        return max(_search(A, 0, pivot - 1, target), _search(A, pivot, n - 1, target)) >= 0;
    }
private:
    int _search(int A[], int left, int right, int target) {
        int mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (target == A[mid]) {
                return mid;
            } else if (target > A[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
