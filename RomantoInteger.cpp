// https://oj.leetcode.com/problems/roman-to-integer/
class Solution {
public:
    int romanToInt(string s) {
        int result = 0, v_cur = 0, v_next = 0, v_save = 0;
        for (int i = 0; i < s.length() - 1; ++i) {
            v_cur = getInt(s.at(i));
            v_save += v_cur;
            if (i == s.length() - 1) {
                result += v_save;
                break;
            }
            v_next = getInt(s.at(i + 1));
            if (v_next < v_cur) {
                result += v_save;
                v_save = 0;
            } else if (v_next > v_cur) {
                result -= v_save;
                v_save = 0;
            }
        }
        if (s.length() > 0) {
            v_save += getInt(s.at(s.length() - 1));
            result += v_save;
        }
        return result;
    }

private:
    int getInt(char c) {
        switch (c) {
            case 'I':
                return 1;
                break;
            case 'V':
                return 5;
                break;
            case 'X':
                return 10;
                break;
            case 'L':
                return 50;
                break;
            case 'C':
                return 100;
                break;
            case 'D':
                return 500;
                break;
            case 'M':
                return 1000;
                break;
            default:
                return 0;
        }
    }
};
