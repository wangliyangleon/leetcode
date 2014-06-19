// https://oj.leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> result;
        int index = 0;
        std::unordered_map<int, int> index_map;
        for (vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); ++iter) {
            index_map.insert(std::pair<int, int>(*iter, index++));
        }
        index = 0;

        for (vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); ++iter) {
            std::unordered_map<int, int>::iterator index_iter = index_map.find(target - *iter);
            if ((index_iter != index_map.end()) && (index != index_iter->second)) {
                if (index < index_iter->second) {
                    result.push_back(index + 1);
                    result.push_back(index_iter->second + 1);
                    return result;
                } else {
                    result.push_back(index_iter->second + 1);
                    result.push_back(index + 1);
                }
            }
            index++;
        }
        return result;
    }
};
