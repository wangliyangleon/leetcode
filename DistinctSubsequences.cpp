// https://oj.leetcode.com/problems/distinct-subsequences/
class Solution {
public:
    int numDistinct(string S, string T) {
        vector<vector<int> > result_map(S.length() + 1, vector<int>(T.length() + 1, -1));
        // result_map[0][0] = 1;
        return _numDistinctSub(S, S.length(), T, T.length(), result_map);
    }

private:
    int _numDistinctSub(string& S, int lenS, string& T, int lenT, vector<vector<int> >& result_map) {
        if (-1 != result_map[lenS][lenT]) {
            return result_map[lenS][lenT];
        }
        int result = -1;
        if (0 == lenS || 0 == lenT) {
            result = 0;
        } else {
            result = _numDistinctSub(S, lenS - 1, T, lenT, result_map) + 
                (S.at(lenS - 1) == T.at(lenT - 1) ? (lenT == 1 ? 1 : _numDistinctSub(S, lenS - 1, T, lenT - 1, result_map)) : 0);
        }
        result_map[lenS][lenT] = result;
        return result;
    }
};
