// https://oj.leetcode.com/problems/remove-element/
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if (0 == n) {
            return 0;
        }
        int new_cnt = 0, edit_pos = 0, read_pos = 0;
        for (; read_pos < n; ++read_pos) {
            if (A[read_pos] != elem) {
                A[edit_pos++] = A[read_pos];
                new_cnt++;
            }
        }
        return new_cnt;
    }
};
