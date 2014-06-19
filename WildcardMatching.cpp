// https://oj.leetcode.com/problems/wildcard-matching/
class Solution {
 public:
     bool isMatch(const char *s, const char *p) {
         const char* star = NULL;  
         const char* ss = s; 
         while (0 != *s) {
             if (*s == *p || '?' == *p) {
                 ++s;
                 ++p;
                 continue;
             }
             if ('*' == *p) {
                 star = p++;
                 ss = s;
                 continue;
             }
             if (star != NULL) {
                 p = star + 1;
                 s = ++ss;
                 continue;
             }
             return false;
         }


         while (0 != *p) {
             if ('*' != *p) {
                 return false;
             }
             ++p;
         }
         return true;
     }
};
