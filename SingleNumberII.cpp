// https://oj.leetcode.com/problems/single-number-ii/
class Solution {
public:
    int singleNumber(int A[], int n) {
        int one = 0, two = 0, xthree = 0;
        for (int i = 0; i < n; ++i) {
            two |= (one & A[i]);
            one ^= A[i];
            xthree = ~(one & two);
            one &= xthree;
            two &= xthree;
        }
        return one;
    }
};
