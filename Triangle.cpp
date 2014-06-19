// https://oj.leetcode.com/problems/triangle/
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (0 == triangle.size()) {
            return 0;
        }
        std::vector<int> last_result_vec(triangle.size(), INT_MAX);
        std::vector<int> result_vec(triangle.size(), INT_MAX);
        last_result_vec[0] = triangle.at(0).at(0);
        for (int i = 1; i < triangle.size(); ++i) {
            for (int j = 0; j < triangle.at(i).size(); ++j) {
                if (0 == j) {
                    result_vec[j] = last_result_vec[0] + triangle.at(i).at(j);
                } else if (i == j) {
                    result_vec[j] = last_result_vec[j - 1] + triangle.at(i).at(j);
                } else {
                    result_vec[j] = std::min(last_result_vec[j - 1], last_result_vec[j]) + triangle.at(i).at(j);
                }
            }
            last_result_vec.swap(result_vec);
        }
        int result = INT_MAX;
        for (std::vector<int>::iterator iter = last_result_vec.begin();
                iter != last_result_vec.end(); ++iter) {
            if (*iter < result) {
                result = *iter;
            }
        }
        return result;
    }
};
