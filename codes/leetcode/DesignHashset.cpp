class MyHashSet
{
public:
    /** Initialize your data structure here. */
    int totalBuckets;
    vector<vector<int>> buckets;

    MyHashSet()
    {
        totalBuckets = 223;
        buckets = vector<vector<int>>(totalBuckets, vector<int>{});
    }

    int hash(int key)
    {
        return key % totalBuckets;
    }

    void add(int key)
    {
        int index = hash(key);
        if (find(buckets[index].begin(), buckets[index].end(), key) == buckets[index].end())
            buckets[index].push_back(key);
    }

    void remove(int key)
    {
        int index = hash(key);
        if (find(buckets[index].begin(), buckets[index].end(), key) != buckets[index].end())
            buckets[index].erase(find(buckets[index].begin(), buckets[index].end(), key));
    }

    bool contains(int key)
    {
        int index = hash(key);
        if (find(buckets[index].begin(), buckets[index].end(), key) == buckets[index].end())
            return false;
        return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
