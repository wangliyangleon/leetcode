// https://oj.leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int> &height) {
        int max_area = 0;
        // n ^ 2
        /*
           for (int i = 0; i < height.size(); ++i) {
           for (int j = 0; j < height.size(); ++j) {
           max_area = std::max(abs(height.at(i) - height.at(j)) * abs(i - j), max_area);
           }
           }
         */
        int left = 0, right = height.size() - 1;
        while (right > left) {
            if (height.at(left) > height .at(right)) {
                max_area = max(height.at(right) * (right - left), max_area);
                --right;
            } else {
                max_area = max(height.at(left) * (right - left), max_area);
                ++left;
            }
        }
        return max_area;
    }
};
