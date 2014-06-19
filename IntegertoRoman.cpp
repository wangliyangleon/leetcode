// https://oj.leetcode.com/problems/integer-to-roman/
class Solution {
public:
    string intToRoman(int num) {
        std::string result = "";
        for (int i = 0; i < num / 1000; ++i) {
            result.append("M");
        }
        num %= 1000;
        if (num >= 900) {
            result.append("CM");
            num -= 900;
        } else if (num >= 500) {
            result.append("D");
            num -= 500;
        } else if (num >= 400) {
            result.append("CD");
            num -= 400;
        }
        for (int i = 0; i < num / 100; ++i) {
            result.append("C");
        }
        num %= 100;

        if (num >= 90) {
            result.append("XC");
            num -= 90;
        } else if (num >= 50) {
            result.append("L");
            num -= 50;
        } else if (num >= 40) {
            result.append("XL");
            num -= 40;
        }
        for (int i = 0; i < num / 10; ++i) {
            result.append("X");
        }
        num %= 10;

        if (num >= 9) {
            result.append("IX");
            num -= 9;
        } else if (num >= 5) {
            result.append("V");
            num -= 5;
        } else if (num >= 4) {
            result.append("IV");
            num -= 4;
        }
        for (int i = 0; i < num; ++i) {
            result.append("I");
        }

        return result;
    }
};
