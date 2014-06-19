// https://oj.leetcode.com/problems/word-ladder-ii/
class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        if (start == end) {
            return vector<vector<string>>(1, vector<string>(1, start));
        }
        vector<vector<string>> result;
        unordered_map<string, vector<string>> pre_map;
        unordered_set<string> level_string_set[2];
        unordered_set<string>* pset_cur = level_string_set;
        unordered_set<string>* pset_last = level_string_set + 1;

        pset_cur->insert(start);
        for (unordered_set<string>::iterator iter = dict.begin();
                iter != dict.end(); ++iter) {
            pre_map.insert(pair<string, vector<string>>(*iter, vector<string>()));
        }
        for (;;) {
            unordered_set<string>* pset_tmp = pset_cur;
            pset_cur = pset_last;
            pset_last = pset_tmp;
            pset_cur->clear();

            // erase last level strings
            for (unordered_set<string>::const_iterator iter = pset_last->begin();
                    iter != pset_last->end(); ++iter) {
                dict.erase(*iter);
            }
            for (unordered_set<string>::const_iterator iter = pset_last->begin();
                    iter != pset_last->end(); ++iter) {
                for (int i = 0; i < iter->length(); ++i) {
                    string left = (i > 0 ? iter->substr(0, i) : "");
                    string right = (i < iter->length() - 1 ? iter->substr(i + 1, iter->length() - 1 - i) : "");
                    for (char c = 'a'; c <= 'z'; ++c) {
                        string cur_str_conv = left + string(1, c) + right;
                        if ((c != iter->at(i)) && (dict.end() != dict.find(cur_str_conv) || (cur_str_conv == end))) {
                            pset_cur->insert(cur_str_conv);
                            unordered_map<string, vector<string>>::iterator citer = pre_map.find(cur_str_conv);
                            if (citer != pre_map.end()) {
                                citer->second.push_back(*iter);
                            }
                        }
                    }
                }
            }

            if (0 == pset_cur->size()) {
                return result;
            }
            if (pset_cur->end() != pset_cur->find(end)) {
                break;
            }
        }

        /// get min len
        queue<pair<string, vector<string> > > str_path_que;
        str_path_que.push(pair<string, vector<string>>(end, vector<string>(1, end)));
        while (!str_path_que.empty()) { 
            string cur_str = str_path_que.front().first;
            vector<string> cur_path = str_path_que.front().second;
            str_path_que.pop();
            unordered_map<string, vector<string>>::const_iterator fiter = pre_map.find(cur_str);
            if (0 == fiter->second.size()) {
                reverse(cur_path.begin(), cur_path.end());
                result.push_back(cur_path);
            } else {
                const vector<string>& conv_strings = fiter->second;
                for (vector<string>::const_iterator iter = conv_strings.begin();
                        iter != conv_strings.end(); ++iter) {
                    cur_path.push_back(*iter);
                    str_path_que.push(pair<string, vector<string>>(*iter, cur_path));
                    cur_path.pop_back();
                }
            }
        }

        return result;
    }
};
