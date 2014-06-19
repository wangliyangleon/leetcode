// https://oj.leetcode.com/problems/substring-with-concatenation-of-all-words/
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> result;
        if (0 == L.size()) {
            return result;
        }

        unordered_map<string, int> strls_map;
        size_t len_sum = L.size() * L.at(0).length();
        for (vector<string>::const_iterator iter = L.begin(); 
                iter != L.end(); ++iter) {
            unordered_map<string, int>::iterator siter = strls_map.find(*iter);
            if (strls_map.end() == siter) {
                strls_map.insert(pair<string, int>(*iter, 1));
            } else {
                ++siter->second;
            }
        }

        size_t rest_cnt = L.size(), start_index = 0, check_index = 0;
        unordered_map<string, int> got_map;
        for (; start_index < S.length();) {
            if (start_index > S.length() - len_sum) {
                break;
            }
            bool reset = false;
            for (; check_index < S.length(); check_index += L.at(0).length()) {
                string cur_str = S.substr(check_index, L.at(0).length());
                unordered_map<string, int>::iterator siter = strls_map.find(cur_str);
                if (strls_map.end() == siter) {
                    reset = true;
                    break;
                }
                unordered_map<string, int>::iterator iter = got_map.find(cur_str);
                if (got_map.end() == iter) {
                    --rest_cnt;
                    got_map.insert(pair<string, int>(cur_str, 1));
                } else if (iter->second < siter->second) {
                    --rest_cnt;
                    ++iter->second;
                } else {
                    ++iter->second;
                    break;
                }
                if (0 == rest_cnt) {
                    result.push_back(start_index);
                    break;
                }
            }
            if (reset) {
                got_map.clear();
                rest_cnt = L.size();
                check_index = ++start_index;
            } else {
                string cur_str = S.substr(start_index, L.at(0).length());
                start_index += L.at(0).length();
                check_index += L.at(0).length();
                if (check_index <= (S.length() - L.at(0).length())) {
                    unordered_map<string, int>::iterator iter = got_map.find(cur_str);
                    unordered_map<string, int>::iterator siter = strls_map.find(cur_str);
                    if (iter->second <= siter->second) {
                        ++rest_cnt;
                    }
                    --iter->second;
                }
            }
        }
        return result;
    }
};
