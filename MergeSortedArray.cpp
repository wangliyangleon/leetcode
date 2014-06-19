// https://oj.leetcode.com/problems/merge-sorted-array/
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int edit_pos = m + n - 1;
        while ((m > 0) && (n > 0)) {
            if (A[m - 1] > B[n - 1]) {
                A[edit_pos--] = A[--m];
            } else {
                A[edit_pos--] = B[--n];
            }
        }
        while (n > 0) {
            A[edit_pos--] = B[--n];
        }
    }
};
