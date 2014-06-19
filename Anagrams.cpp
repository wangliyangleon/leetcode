// https://oj.leetcode.com/problems/anagrams/
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> result;
        if (strs.size() < 2) {
            return result;
        }
        unordered_map<string, vector<string> > sorted_str_map;
        for (vector<string>::iterator iter = strs.begin();
                iter != strs.end(); ++iter) {
            string ori_str = *iter;
            sort(ori_str.begin(), ori_str.end());

            unordered_map<string, vector<string> >::iterator map_iter = sorted_str_map.find(ori_str);
            if (sorted_str_map.end() == map_iter) {
                sorted_str_map.insert(std::pair<string, vector<string> >(ori_str, vector<string>(1, *iter)));
            } else {
                map_iter->second.push_back(*iter);
            }
        }

        for (unordered_map<string, vector<string> >::iterator iter = sorted_str_map.begin();
                iter != sorted_str_map.end(); ++iter) {
            if (iter->second.size() > 1) {
                result.insert(result.end(), iter->second.begin(), iter->second.end());
            }
        }
        return result;
    }

private:

};
