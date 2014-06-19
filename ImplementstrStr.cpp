// https://oj.leetcode.com/problems/implement-strstr/
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (NULL == haystack) {
            return NULL;
        }
        if (NULL == needle || 0 == strlen(needle)) {
            return haystack;
        }
        size_t hs_len = strlen(haystack);
        size_t nd_len = strlen(needle);
        if (nd_len > hs_len) {
            return NULL;
        }

        // get next vector
        vector<size_t> next_vec(nd_len, 0);
        size_t last_next = 0;
        for (size_t i = 1; i < nd_len; ++i) {
            last_next = next_vec.at(i - 1);
            next_vec[i] = (needle[i] == needle[last_next] ? last_next + 1 : 0);
        }

        // check
        size_t cur_len = 0, cur_index = 0;
        while (cur_index < hs_len) {
            // cout << haystack + cur_index << endl;
            // cout << needle + cur_len << endl;
            if (haystack[cur_index] == needle[cur_len]) {
                ++cur_index;
                ++cur_len;
                if (nd_len == cur_len) {
                    break;
                }
            } else {
                if (0 == cur_len || 0 == next_vec.at(cur_len - 1)) {
                    cur_index += (0 == cur_len ? 1 : 0);
                    cur_len = 0;
                } else {
                    cur_len = next_vec.at(cur_len - 1);
                }
            }
        }
        return (nd_len == cur_len ? haystack + cur_index - cur_len : NULL);
    }
};
