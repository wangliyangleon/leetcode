// https://oj.leetcode.com/problems/permutation-sequence/
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> jx_vec(10, 1);
        vector<bool> used_vec(10, false);
        int tmp = 1;
        for (int i = 2; i < 10; ++i) {
            tmp *= i;
            jx_vec[i] = tmp;
        }

        string result = "";
        --k;
        for (int i = 1; i <= n; ++i) {
            int rank = k / jx_vec.at(n - i);
            int index = 1;
            for (int j = 1; j < 10; ++j) {
                if (!used_vec.at(j)) {
                    if (0 == rank) {
                        index = j;
                        used_vec[index] = true;
                        break;
                    }
                    --rank;
                }
            }
            result += (index + '0');
            k %= jx_vec.at(n - i);
        }
        return result;
    }
};
