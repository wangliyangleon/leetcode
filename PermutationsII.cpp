// https://oj.leetcode.com/problems/permutations-ii/
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        if (num.size() == 0) {
            return result;
        } else if (num.size() < 2) {
            result.push_back(num);
            return result;
        }

        sort(num.begin(), num.end());
        result.push_back(num);
        while (nextPermutation(num)) {
            result.push_back(num);
        }
        return result;
    }

private:
    bool nextPermutation(vector<int> &num) {
        int index_pre = num.size() - 2, index_post = num.size() - 1;
        for (; index_post > 0; --index_pre, --index_post) {
            if (num.at(index_post) > num.at(index_pre)) {
                break;
            }
        }
        if (0 == index_post) {
            return false;
        }
        for (index_post = num.size() - 1; index_post > index_pre; --index_post) {
            if (num.at(index_post) > num.at(index_pre)) {
                break;
            }
        }
        int t = num.at(index_post);
        num[index_post] = num.at(index_pre);
        num[index_pre] = t;
        reverse(num.begin() + index_pre + 1, num.end());
        return true;
    }
};
