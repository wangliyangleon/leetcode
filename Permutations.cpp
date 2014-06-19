// https://oj.leetcode.com/problems/permutations/
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        result.push_back(num);
        int pmt_cnt = 1;
        for (int i = 2; i <= num.size(); ++i) {
            pmt_cnt *= i;
        }
        for (int i = 0; i < pmt_cnt - 1; ++i) {
            nextPermutation(num);
            result.push_back(num);
        }
        return result;
    }

private:
    void nextPermutation(vector<int>& pmt) {
        int size = pmt.size();
        if (2 > size) {
            return;
        }

        int pos_left = 0, pos_right = 0;
        for (pos_left = size - 2; pos_left >= 0; --pos_left) {
            if (pmt[pos_left] < pmt[pos_left + 1]) {
                break;
            }
        }
        if (pos_left < 0) {
            std::reverse(pmt.begin(), pmt.end());
        } else {
            for (pos_right = size - 1; pos_right > pos_left; --pos_right) {
                if (pmt[pos_right] > pmt[pos_left]) {
                    break;
                }
            }
            std::swap(pmt[pos_left], pmt[pos_right]);
            std::reverse(pmt.begin() + pos_left + 1, pmt.end());
        }
    }
};
