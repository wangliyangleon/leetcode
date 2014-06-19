// https://oj.leetcode.com/problems/largest-rectangle-in-histogram/
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> height_stack;
        height.push_back(0);
        int max_area = 0;
        for (int i = 0; i < height.size();) {
            if (height_stack.empty() || height.at(i) >= height.at(height_stack.top())) {
                height_stack.push(i++);
            } else {
                int curh = height.at(height_stack.top());
                height_stack.pop();
                max_area = max(max_area, curh * (height_stack.empty() ? i : i - height_stack.top() - 1));
            }
        }   
        return max_area;
    }   
};  
