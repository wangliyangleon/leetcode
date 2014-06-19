// https://oj.leetcode.com/problems/lru-cache/
class LRUCache{
public:

    struct cache_unit_t {
        int key;
        int value;
        cache_unit_t* before;
        cache_unit_t* next;
    };

    LRUCache(int capacity) {
        _capacity = capacity;
        _cur_size = 0;
        _cache_unit_list_head = NULL;
        _cache_unit_list_tail = NULL;
    }

    int get(int key) {
        if (0 == _capacity) {
            return -1;
        }

        std::unordered_map<int, cache_unit_t*>::const_iterator iter =
            _iter_map.find(key);
        if (_iter_map.end() == iter) {
            return -1;
        }
        cache_unit_t* p_touched_unit = iter->second;

        if (NULL != p_touched_unit->before) {
            p_touched_unit->before->next = p_touched_unit->next;
            if (NULL != p_touched_unit->next) {
                p_touched_unit->next->before = p_touched_unit->before;
            } else {
                _cache_unit_list_tail = p_touched_unit->before;
            }
            p_touched_unit->before = NULL;
            _cache_unit_list_head->before = p_touched_unit;
            p_touched_unit->next = _cache_unit_list_head;
            _cache_unit_list_head = p_touched_unit;
        }
        return p_touched_unit->value;

    }

    void set(int key, int value) {
        if (0 == _capacity) {
            return;
        }

        std::unordered_map<int, cache_unit_t*>::const_iterator iter =
            _iter_map.find(key);
        if (_iter_map.end() == iter) {
            cache_unit_t* p_new_unit = new cache_unit_t();
            p_new_unit->key = key;
            p_new_unit->value = value;
            p_new_unit->before = NULL;
            p_new_unit->next = _cache_unit_list_head;
            if (NULL != _cache_unit_list_head) {
                _cache_unit_list_head->before = p_new_unit;
            }
            _cache_unit_list_head = p_new_unit;
            _iter_map.insert(std::pair<int, cache_unit_t*>(key, p_new_unit));
            if (NULL == _cache_unit_list_tail) {
                _cache_unit_list_tail = p_new_unit;
                ++_cur_size;
            } else if (_capacity == _cur_size) {
                cache_unit_t* p_delete = _cache_unit_list_tail;
                _cache_unit_list_tail = p_delete->before;
                _cache_unit_list_tail->next = NULL;
                _iter_map.erase(p_delete->key);
                delete p_delete;
            } else {
                ++_cur_size;
            }
        }
        else {
            cache_unit_t* p_touched_unit = iter->second;
            p_touched_unit->value = value;
            if (NULL != p_touched_unit->before) {
                p_touched_unit->before->next = p_touched_unit->next;
                if (NULL != p_touched_unit->next) {
                    p_touched_unit->next->before = p_touched_unit->before;
                } else {
                    _cache_unit_list_tail = p_touched_unit->before;
                }
                _cache_unit_list_head->before = p_touched_unit;
                p_touched_unit->before = NULL;
                p_touched_unit->next = _cache_unit_list_head;
                _cache_unit_list_head = p_touched_unit;
            }


        }

    }

private:

    int _capacity;
    int _cur_size;
    cache_unit_t* _cache_unit_list_head;
    cache_unit_t* _cache_unit_list_tail;
    std::unordered_map<int, cache_unit_t*> _iter_map;
};
