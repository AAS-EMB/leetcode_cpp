class LRUCache {
public:
    using Lru = list<pair<int, int>>;
    using Cache = unordered_map<int, Lru::iterator>;

    LRUCache(int capacity) : capacity_{capacity} { }
    
    int get(int key) {
        if (cache_.find(key) == cache_.end())
            return -1;
        
        auto it = cache_[key];
        auto value = it->second;

        lru_.erase(it);
        lru_.push_back({ key, value });
        cache_[key] = prev(lru_.end());

        return value;
    }
    
    void put(int key, int value) {
        if (cache_.find(key) not_eq cache_.end())
        {
            lru_.erase(cache_[key]);
        }
        else if (lru_.size() == capacity_)
        {
            auto expired = lru_.front().first;
            lru_.pop_front();
            cache_.erase(expired);
        }

        lru_.push_back({ key, value });
        cache_[key] = prev(lru_.end());
    }

private:
    const int capacity_;
    Lru lru_;
    Cache cache_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */