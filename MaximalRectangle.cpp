// https://oj.leetcode.com/problems/maximal-rectangle/
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // 01010011010111
        // 10100111010100
        // 11110111101111
        // 00101010101111
        if (0 == matrix.size() || 0 == matrix.at(0).size()) {
            return 0;
        }

        vector<vector<pair<int, int> > > ones_left_right_map(matrix.size(), vector<pair<int, int> >());
        for (int i = 0; i < matrix.size(); ++i) {
            int cur_one_len = 0;
            for (int j = 0; j < matrix.at(i).size(); ++j) {
                if ('0' == matrix.at(i).at(j)) {
                    cur_one_len = 0;
                    ones_left_right_map.at(i).push_back(pair<int, int>(0, 0));
                } else {
                    ones_left_right_map.at(i).push_back(pair<int, int>(++cur_one_len, 0));
                }
            }
        }

        for (int j = 0; j < matrix.at(0).size(); ++j) {
            int cur_one_len = 0;
            for (int i = 0; i < matrix.size(); ++i) {
                if ('0' == matrix.at(i).at(j)) {
                    cur_one_len = 0;
                } else {
                    ones_left_right_map.at(i).at(j).second = ++cur_one_len;
                }
            }
        }

        int max = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix.at(i).size(); ++j) {
                if ('1' == matrix.at(i).at(j)) {
                    // 1. try v
                    for (int k = 1; k <= ones_left_right_map.at(i).at(j).first; ++k) {
                        int v = i - 1;
                        while (v >= 0 && ones_left_right_map.at(v).at(j).first >= k) {
                            --v;
                        }
                        if ((i - v) * k > max) {
                            max = (i - v) * k;
                        }
                    }
                    // 2. try h
                    for (int k = 1; k <= ones_left_right_map.at(i).at(j).second; ++k) {
                        int h = j - 1;
                        while (h >= 0 && ones_left_right_map.at(i).at(h).second >= k) {
                            --h;
                        }
                        if ((j - h) * k > max) {
                            max = (j - h) * k;
                        }
                    }
                }
            }
        }
        return max;
    }
};
