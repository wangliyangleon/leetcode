// https://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
 public:
     vector<string> letterCombinations(string digits) {
         const int LETTER_COMB_CNT = 10;
         string strs[LETTER_COMB_CNT] = {
             "",
             "",
             "abc",
             "def",
             "ghi",
             "jkl",
             "mno",
             "pqrs",
             "tuv",
             "wxyz"
         };
         vector<string> result;
         vector<string> result_tmp;
         vector<string> strs_vec;
         vector<int> length_vec;
         for (int i = 0; i < digits.size(); ++i) {
             if ((digits.at(i) >= '0') && (digits.at(i) <= '9') && (strs[digits.at(i) - '0'].size() > 0)) {
                 strs_vec.push_back(strs[digits.at(i) - '0']);
             }
         }
         if (0 == strs_vec.size()) {
             result.push_back("");
             return result;
         }

         for (int i = 0; i < strs_vec.at(0).size(); ++i) {
             result.push_back(string(1, strs_vec.at(0).at(i)));
         }
         for (int i = 1; i < strs_vec.size(); ++i) {
             result.swap(result_tmp);
             result.clear();
             for (int j = 0; j < result_tmp.size(); ++j) {
                 string cur_str = result_tmp.at(j);
                 for (int k = 0; k < strs_vec.at(i).size(); ++k) {
                     result.push_back(cur_str + string(1, strs_vec.at(i).at(k)));
                 }
             }
         }
         return result;
     }
};
