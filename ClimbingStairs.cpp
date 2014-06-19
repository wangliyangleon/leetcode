// https://oj.leetcode.com/problems/climbing-stairs/
class Solution {
public:
    int climbStairs(int n) {
        int* rmap = new int[n + 1];
        memset(rmap, 0, (n + 1) * sizeof(int));
        rmap[0] = rmap[1] = 1;
        int ret = tryWay(n, rmap);
        delete [] rmap;
        return ret;
    }

private:
    int tryWay(int n, int* rmap) {
        if (n < 0) {
            return 0;
        }
        if (0 == rmap[n] > 0) {
            rmap[n] = tryWay(n - 1, rmap) + tryWay(n - 2, rmap);
        }
        return rmap[n];
    }
};
