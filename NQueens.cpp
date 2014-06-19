// https://oj.leetcode.com/problems/n-queens/
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        _result.clear();
        _empty_line.assign(n, '.');
        vector<string> cur_map;
        _try_level(cur_map, n);
        return _result;
    }

    void show() {
        for (vector<vector<string> >::const_iterator iter = _result.begin();
                iter != _result.end(); ++iter) {
            cout << "=========================================" << endl;
            for (vector<string>::const_iterator line_iter = iter->begin();
                    line_iter != iter->end(); ++line_iter)
            {
                cout << "\t" << *line_iter << endl;
            }
        }
    }

private:
    void _try_level(vector<string> cur_map, int n) {
        for (int i = 0; i < n; ++i) {
            string cur_line = (i > 0 ? _empty_line.substr(0, i) : "")
                + "Q" + ((i < n - 1) ? _empty_line.substr(i + 1, n - i - 1) : "");

            size_t cur_size = cur_map.size();
            bool enable = true;
            for (int j = 0; j < cur_size; ++j) {
                int gap = cur_size - j;
                if ('Q' == cur_map.at(j).at(i)) {
                    enable = false;
                    break;
                }
                if ((i - gap >= 0) && ('Q' == cur_map.at(j).at(i - gap))) {
                    enable = false;
                    break;
                }
                if ((i + gap < n) && ('Q' == cur_map.at(j).at(i + gap))) {
                    enable = false;
                    break;
                }
            }
            if (enable) {
                cur_map.push_back(cur_line);
                if (n == cur_map.size()) {
                    _result.push_back(cur_map);
                } else {
                    _try_level(cur_map, n);
                }
                cur_map.pop_back();
            }
        }
    }

    vector<vector<string> > _result;
    string _empty_line;
};
