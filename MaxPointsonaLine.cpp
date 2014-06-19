// https://oj.leetcode.com/problems/max-points-on-a-line/
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:

#define POINT2LONGLONG(__POINT__) (*(long long*)(&(__POINT__)))
#define LONGLONG2POINT(__LL__) (*(Point*)(&(__LL__)))

    int maxPoints(vector<Point> &points) {
        if (0 == points.size()) {
            return 0;
        }
        _point_map.clear();

        for (int i = 0; i < points.size(); ++i) {
            std::unordered_map<long long, int>::iterator iter = _point_map.find(POINT2LONGLONG(points.at(i)));
            if (_point_map.end() == iter) {
                _point_map.insert(std::pair<long long, int>(POINT2LONGLONG(points.at(i)), 1));
            } else {
                ++iter->second;
            }
        }

        int gys = 0, tx = 0, ty = 0, result = 0, main_cnt = 0;
        long long key;
        for (std::unordered_map<long long, int>::iterator point_iter = _point_map.begin();
                point_iter != _point_map.end(); ++point_iter) {
            _line_map.clear();
            main_cnt = point_iter->second;
            result = std::max(result, main_cnt);
            Point main_point = LONGLONG2POINT(point_iter->first);

            std::unordered_map<long long, int>::iterator iter = point_iter;
            for (++iter; iter != _point_map.end(); ++iter) {
                tx = LONGLONG2POINT(iter->first).x - main_point.x;
                ty = LONGLONG2POINT(iter->first).y - main_point.y;
                if (0 == tx) {
                    key = 0;
                } else if (0 == ty) {
                    key = (long long)INT_MAX;
                } else {
                    gys = _get_gys((tx > 0 ? tx : -tx), (ty > 0 ? ty : -ty));
                    if (tx < 0) {
                        tx = -tx;
                        ty = -ty;
                    }
                    Point temp_point(tx / gys, ty / gys);
                    key = POINT2LONGLONG(temp_point);
                }
                std::unordered_map<long long, int>::iterator line_iter = _line_map.find(key);
                if (line_iter == _line_map.end()) {
                    _line_map.insert(std::pair<long long, int>(key, iter->second));
                    result = std::max(result, iter->second + main_cnt);
                } else {
                    line_iter->second += iter->second;
                    result = std::max(result, line_iter->second + main_cnt);
                }
            }

        }
        return result;
    }

private:
    int _get_gys(int x, int y) {
        int t;
        if (x < y) {
            t = x;
            x = y;
            y = t;
        }
        if (0 == x % y) {
            return y;
        } else {
            return _get_gys(y, x % y);
        }
    }
    std::unordered_map<long long, int> _line_map;
    std::unordered_map<long long, int> _point_map;
};
