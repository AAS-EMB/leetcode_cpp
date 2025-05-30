class RandomizedSet {
public:
    RandomizedSet() { }
    
    bool insert(int val) {
        if (has_value(val))
            return false;

        store_.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (not has_value(val))
            return false;

        auto it = find(store_.begin(), store_.end(), val);
        store_.erase(it);
        return true;
    }
    
    int getRandom() {
        return store_[rand() % store_.size()];
    }

private:
    vector<int> store_;

    bool has_value(int val) {
        return find_if(store_.begin(), store_.end(), [&](auto item) {
            return item == val;
        }) not_eq store_.end();
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */