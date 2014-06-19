// https://oj.leetcode.com/problems/unique-paths-ii/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        return _uniquePaths(obstacleGrid.at(0).size(), obstacleGrid.size(), obstacleGrid);
    }

private:
    int _uniquePaths(int m, int n, vector<vector<int> > &obstacleGrid) {
        if (0 == m || 0 == n) {
            return 0;
        }
        vector<vector<int> > save_map(n, vector<int>(m, -1));
        return _index_path(0, 0, m, n, save_map, obstacleGrid);
    }

    int _index_path(int x, int y, int m, int n, vector<vector<int> >& save_map, vector<vector<int> > &obstacleGrid) {
        if (save_map.at(x).at(y) >= 0) {
            return save_map.at(x).at(y);
        }
        int result = 0;
        if (1 == obstacleGrid.at(x).at(y)) {
            result = 0;
        } else if (x == n - 1 && y == m - 1) {
            result = 1;
        } else {
            result = (x == n - 1 ? 0 : _index_path(x + 1, y, m, n, save_map, obstacleGrid)) + 
                (y == m - 1 ? 0 : _index_path(x, y + 1, m, n, save_map, obstacleGrid));
        }
        save_map[x][y] = result;
        return result;
    }
};
