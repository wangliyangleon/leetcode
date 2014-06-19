// https://oj.leetcode.com/problems/minimum-path-sum/
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (0 == grid.size() || 0 == grid.at(0).size()) {
            return 0;
        }
        vector<vector<int> > save_map(grid.size(), vector<int>(grid.at(0).size(), -1));
        return _minPathSum(0, 0, grid, save_map);
    }
private:
    int _minPathSum(int startx, int starty, vector<vector<int> > &grid, vector<vector<int> >& save_map) {
        if (save_map.at(startx).at(starty) >= 0) {
            return save_map.at(startx).at(starty);
        }
        int result = 0;
        if (startx == grid.size() - 1) {
            for (int i = starty; i < grid.at(0).size(); ++i) {
                result += grid.at(startx).at(i);
            }
        } else if (starty == grid.at(0).size() - 1) {
            for (int i = startx; i < grid.size(); ++i) {
                result += grid.at(i).at(starty);
            }
        } else {
            result = min(_minPathSum(startx + 1, starty, grid, save_map),
                    _minPathSum(startx, starty + 1, grid, save_map));
            result += grid.at(startx).at(starty);
        }
        save_map[startx][starty] = result;
        return result;
    }
};
