// https://oj.leetcode.com/problems/sort-colors/
class Solution {
public:
    void sortColors(int A[], int n) {
        int redcnt = 0, whitecnt = 0, bluecnt = 0;
        for (int i = 0; i < n; ++i) {
            switch (A[i]) {
                case 0:
                    ++redcnt;
                    break;
                case 1:
                    ++whitecnt;
                    break;
                case 2:
                    ++bluecnt;
                    break;
                default:
                    break;
            }
        }

        int index = 0;
        while (redcnt--) {
            A[index++] = 0;
        }
        while (whitecnt--) {
            A[index++] = 1;
        }
        while (bluecnt--) {
            A[index++] = 2;
        }
    }
};
