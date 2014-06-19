// https://oj.leetcode.com/problems/edit-distance/
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int> > result_map(word1.length() + 1, vector<int>(word2.length() + 1, -1));
        return getMinDis(word1, word1.length(), word2, word2.length(), result_map);
    }

private:
    int getMinDis(string& word1, int len1, string& word2, int len2, vector<vector<int> >& result_map) {
        if (-1 != result_map[len1][len2]) {
            return result_map[len1][len2];
        }
        int result = -1;
        if (0 == len1) {
            result = len2;
        } else if (0 == len2) {
            result = len1;
        } else {
            int dis_i = getMinDis(word1, len1, word2, len2 - 1, result_map) + 1;
            int dis_d = getMinDis(word1, len1 - 1, word2, len2, result_map) + 1;
            int dis_r = getMinDis(word1, len1 - 1, word2, len2 - 1, result_map) +
                (word1.at(len1 - 1) == word2.at(len2 - 1) ? 0 : 1);
            result = min(min(dis_i, dis_d), dis_r);
        }
        result_map[len1][len2] = result;
        return result;
    }
};
