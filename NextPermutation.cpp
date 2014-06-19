// https://oj.leetcode.com/problems/next-permutation/
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (2 > num.size()) {
            return;
        }
        int index_post = num.size() - 1;
        int index_pre = num.size() - 2;
        for (; index_post >= 1; --index_post, --index_pre) {
            if (num.at(index_pre) < num.at(index_post)) {
                break;
            }
        }
        if (0 == index_post) {
            sort(num.begin(), num.end());
        } else {
            for (index_post = num.size() - 1; index_post > index_pre; --index_post) {
                if (num.at(index_pre) < num.at(index_post)) {
                    break;
                }
            }
            int temp = num.at(index_pre);
            num[index_pre] = num.at(index_post);
            num[index_post] = temp;
            reverse(num.begin() + index_pre + 1, num.end());
        }
    }
};
