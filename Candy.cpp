// https://oj.leetcode.com/problems/candy/
class Solution {
public:
    int candy(vector<int> &ratings) {
        //1555431
        //1211111
        //1114321
        //1214321
        if (0 == ratings.size()) {
            return 0;
        }
        int sum = 0;
        vector<int> left_vec(ratings.size(), 1);
        vector<int> right_vec(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings.at(i) > ratings.at(i - 1)) {
                left_vec[i] = left_vec.at(i - 1) + 1;
            }
        }
        for (int i = ratings.size() - 2; i >= 0; --i) {
            if (ratings.at(i) > ratings.at(i + 1)) {
                right_vec[i] = right_vec.at(i + 1) + 1;
            }
        }
        for (int i = 0; i < ratings.size(); ++i) {
            sum += max(left_vec.at(i), right_vec.at(i));
        }

        return sum;
    }
};
