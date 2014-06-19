// https://oj.leetcode.com/problems/plus-one/
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> result;
        vector<int> result_r;
        int sign = 1, temp;
        for (vector<int>::reverse_iterator riter = digits.rbegin();
                riter != digits.rend(); ++riter) {
            temp = *riter + sign;
            sign = temp / 10;
            result_r.push_back(temp % 10);
        }
        if (1 == sign) {
            result_r.push_back(1);
        }
        for (int i = result_r.size() - 1; i >= 0; --i) {
            result.push_back(result_r.at(i));
        }
        return result;
    }
};
