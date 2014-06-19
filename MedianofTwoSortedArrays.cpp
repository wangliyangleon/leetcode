// https://oj.leetcode.com/problems/median-of-two-sorted-arrays/
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int astart = 0, aend = m - 1, bstart = 0, bend = n - 1;
        while ((astart <= aend) && (bstart <= bend) &&
                ((astart != aend) || (bstart != bend))) {
            if (A[astart] < B[bstart]) {
                ++astart;
            } else {
                ++bstart;
            }

            if (A[aend] > B[bend]) {
                --aend;
            } else {
                --bend;
            }
        }

        if ((astart == aend) && (bstart == bend)) {
            return (A[astart] + B[bstart]) / 2.0;
        } else if (astart > aend) {
            return (0 == (bend - bstart) % 2) ? B[(bend + bstart) / 2] :
                ((B[(bend + bstart) / 2] + B[(bend + bstart) / 2 + 1]) / 2.0);
        } else {
            return (0 == (aend - astart) % 2) ? A[(aend + astart) / 2] :
                ((A[(aend + astart) / 2] + A[(aend + astart) / 2 + 1]) / 2.0);
        }
    }
};
