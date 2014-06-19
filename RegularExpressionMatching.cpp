// https://oj.leetcode.com/problems/regular-expression-matching/
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        size_t slen = strlen(s);
        size_t plen = strlen(p);
        vector<vector<int> > match_map(slen + 1, vector<int>(plen + 1, -1));
        return isPartMatch(s, p, 0, 0, match_map);
    }

private:
    bool isPartMatch(const char *s, const char* p, size_t spos, size_t ppos, vector<vector<int> >& match_map) {
        if (-1 == match_map.at(spos).at(ppos)) {
            const char* curs = s + spos;
            const char* curp = p + ppos;
            if ((0 == *curs) && (0 == *curp)) {
                match_map[spos][ppos] = 1;
            } else if (0 == *curp) {
                match_map[spos][ppos] = 0;
            } else {
                if ('*' == *curp) {
                    match_map[spos][ppos] = 0;
                    char pre_char = *(p + ppos - 1);
                    if (0 != *curs) {
                        for (size_t tmp_spos = spos; (pre_char == *(s + tmp_spos)) || ('.' == pre_char);
                                ++tmp_spos) {
                            if (isPartMatch(s, p, tmp_spos + 1, ppos + 1, match_map)) {
                                match_map[spos][ppos] = 1;
                                break;
                            }
                            if (0 == *(s + tmp_spos + 1)) {
                                break;
                            }
                        }
                    }
                } else {
                    if ('*' == *(curp + 1)) {
                        if (isPartMatch(s, p, spos, ppos + 2, match_map)) {
                            match_map[spos][ppos] = 1;
                        } else {
                            match_map[spos][ppos] = (isPartMatch(s, p, spos, ppos + 1, match_map) ? 1 : 0);
                        }
                    } else {
                        if (0 == *curs) {
                            match_map[spos][ppos] = 0;
                        } else if (*curs == *curp || '.' == *curp) {
                            match_map[spos][ppos] = (isPartMatch(s, p, spos + 1, ppos + 1, match_map) ? 1 : 0);
                        } else {
                            match_map[spos][ppos] = 0;
                        } 
                    }
                }
            }
        }
        return (1 == match_map.at(spos).at(ppos));
    }
};
