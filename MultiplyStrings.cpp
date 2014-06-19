// https://oj.leetcode.com/problems/multiply-strings/
class Solution {
public:
    string multiply(string num1, string num2) {
        int sign = 0;
        string mul_result = "0", result = "0";
        for (int i = num1.size() - 1; i >= 0; --i) {
            sign = 0;
            result = "";
            for (int j = num2.size() - 1; j >= 0; --j) {
                int cur_val = (num1.at(i) - '0') * (num2.at(j) - '0') + sign;
                result = string(1, cur_val % 10 + '0') + result;
                sign = cur_val / 10;
            }
            if (sign > 0) {
                result = string(1, sign + '0') + result;
            }
            result += string(num1.size() - 1 - i, '0');
            mul_result = add(mul_result, result);
        }   
        int index = 0;
        for (index = 0; (index < mul_result.size()) && ('0' == mul_result.at(index)); ++index) {
        }
        return mul_result.size() == index ? "0" : mul_result.substr(index, mul_result.size() - index);
    }   

    string add(string num1, string num2) {
        string result = ""; 
        int sign = 0; 
        int i = num1.length() - 1, j = num2.length() - 1;
        for (; i >= 0 && j >= 0; --i, --j) {
            int cur_val = num1.at(i) - '0' + num2.at(j) - '0' + sign;
            result = string(1, cur_val % 10 + '0') + result;
            sign = cur_val / 10;
        }   
        for (; i >= 0; --i) {
            int cur_val = num1.at(i) - '0' + sign;
            result = string(1, cur_val % 10 + '0') + result;
            sign = cur_val / 10;
        }
        for (; j >= 0; --j) {
            int cur_val = num2.at(j) - '0' + sign;
            result = string(1, cur_val % 10 + '0') + result;
            sign = cur_val / 10;
        }
        if (sign > 0) {
            result = string(1, sign + '0') + result;
        }
        return result;
    }
};
