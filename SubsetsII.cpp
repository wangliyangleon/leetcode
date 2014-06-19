// https://oj.leetcode.com/problems/subsets-ii/
class Solution {
public:
    struct item_t {
        int val;
        int num;
    };

    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        _result.clear();
        if (S.size() == 0) {
            return _result;
        }

        sort(S.begin(), S.end());
        vector<item_t> items;
        int cur_val = S.at(0), cur_num = 1;
        for (int i = 1; i < S.size(); ++i) {
            if (S.at(i) != cur_val) {
                item_t item;
                item.val = cur_val;
                item.num = cur_num;
                items.push_back(item);
                cur_val = S.at(i);
                cur_num = 1;
            } else {
                ++cur_num;
            }
        }
        item_t item;
        item.val = cur_val;
        item.num = cur_num;
        items.push_back(item);

        _tryNext(items, vector<int>(), 0);
        return _result;
    }

private:
    void _tryNext(vector<item_t>& items, vector<int> cur_result, int cur_index) {
        _result.push_back(cur_result);
        for (int i = cur_index; i < items.size(); ++i) {
            item_t& item = items.at(i);
            for (int j = 1; j <= item.num; ++j) {
                for (int k = 0; k < j; ++k) {
                    cur_result.push_back(item.val);
                }
                _tryNext(items, cur_result, i + 1);
                for (int k = 0; k < j; ++k) {
                    cur_result.pop_back();
                }
            }
        }
    }
    vector<vector<int> > _result;
};
