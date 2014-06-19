// https://oj.leetcode.com/problems/unique-paths/
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (0 == m || 0 == n) {
            return 0;
        }
        vector<vector<int> > save_map(n, vector<int>(m, 0));
        return _index_path(0, 0, m, n, save_map);
    }
private:
    int _index_path(int x, int y, int m, int n, vector<vector<int> >& save_map) {
        if (save_map.at(x).at(y) > 0) {
            return save_map.at(x).at(y);
        }
        int result = 0;
        if (x == n - 1 || y == m - 1) {
            result = 1;
        } else {
            result = _index_path(x + 1, y, m, n, save_map) + 
                _index_path(x, y + 1, m, n, save_map);
        }
        save_map[x][y] = result;
        return result;
    }
};
