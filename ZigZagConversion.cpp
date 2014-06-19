// https://oj.leetcode.com/problems/zigzag-conversion/
class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows < 2) {
            return s;
        }
        string result = "";
        int blocksize = nRows + (nRows - 2);
        int blockcnt = s.length() / blocksize + 1;
        int index = 0;

        // top
        for (int i = 0; i < blockcnt; ++i) {
            index = i * blocksize;
            if (index < s.length()) {
                result += string(1, s.at(index));
            }
        }

        // mid
        for (int i = 0; i < nRows - 2; ++i) {
            for (int j = 0; j < blockcnt; ++j) {
                index = j * blocksize + i + 1;
                if (index < s.length()) {
                    result += string(1, s.at(index));
                }   
                index = j * blocksize + 2 * nRows - 3 - i;
                if (index < s.length()) {
                    result += string(1, s.at(index));
                }   
            }   
        }

        // tail
        for (int i = 0; i < blockcnt; ++i) {
            index = i * blocksize + nRows - 1;
            if (index < s.length()) {
                result += string(1, s.at(index));
            }
        }

        return result;
    }
};
