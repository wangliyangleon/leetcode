// https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (0 == n) {
            return 0;
        }
        int new_cnt = 1, edit_pos = 1, read_pos = 1;
        for (; read_pos < n; ++read_pos) {
            if (A[read_pos] != A[edit_pos - 1]) {
                A[edit_pos++] = A[read_pos];
                new_cnt++;
            }
        }
        return new_cnt;
    }
};
