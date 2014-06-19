// https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cur_len = 0, max_len = 0, cur_begin = 0;
        unordered_map<char, int> uniq_map;
        for (int i = 0; i < s.length(); ++i) {
            unordered_map<char, int>::iterator map_iter = uniq_map.find(s.at(i));
            if (map_iter == uniq_map.end()) {
                ++cur_len;
            } else {
                if (cur_len > max_len) {
                    max_len = cur_len;
                }
                cur_len -= (map_iter->second - cur_begin);
                for (int j = cur_begin; j <= map_iter->second; ++j) {
                    uniq_map.erase(s.at(j)); 
                }   
                cur_begin = map_iter->second + 1;
            }   
            uniq_map.insert(pair<char, int>(s.at(i), i));
        }   
        if (cur_len > max_len) {
            max_len = cur_len; 
        }   
        return max_len;
    }   
}; 
