class LRUCache{
public:
    LRUCache(int capacity) {
        maxSize = capacity;
    }

    int get(int key) {
        if(m.find(key) == m.end())
            return -1;
        cache.splice(cache.begin(), cache, m[key]);
        return m[key]->second;
    }

    void set(int key, int value) {
        if(m.find(key) == m.end()) {
            pair<int, int> tmp = make_pair(key, value);
            if(m.size() == maxSize) {
                m.erase(cache.back().first);
                cache.pop_back();
            }
            cache.push_front(tmp);
            m[key] = cache.begin();
        }
        else {
            m[key]->second = value;
            cache.splice(cache.begin(), cache, m[key]);
        }
    }
private:
    int maxSize;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> cache;
};
