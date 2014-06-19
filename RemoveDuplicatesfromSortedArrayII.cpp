// https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (0 == n) {
            return 0;
        }
        const int MAX_CNT = 2;
        int new_cnt = 1, edit_pos = 1, read_pos = 1, cur_cnt = 1;
        for (; read_pos < n; ++read_pos) {
            if (A[read_pos] != A[edit_pos - 1]) {
                cur_cnt = 1;
                A[edit_pos++] = A[read_pos];
                ++new_cnt;
            } else if (cur_cnt < MAX_CNT) {
                ++cur_cnt;
                A[edit_pos++] = A[read_pos];
                ++new_cnt;
            }
        }
        return new_cnt;
    }
};
