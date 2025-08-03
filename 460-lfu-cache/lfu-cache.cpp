class LFUCache {
private:
    int capacity;
    int minFreq;

    // key -> (value, frequency)
    unordered_map<int, pair<int, int>> keyToValFreq;

    // frequency -> list of keys with that frequency (to handle eviction order)
    unordered_map<int, list<int>> freqToKeys;

    // key -> iterator in freqToKeys list, to remove keys in O(1)
    unordered_map<int, list<int>::iterator> keyToIter;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        auto it = keyToValFreq.find(key);
        if (it == keyToValFreq.end()) return -1;

        int val = it->second.first;
        int freq = it->second.second;

        // Remove key from current freq list
        freqToKeys[freq].erase(keyToIter[key]);

        // If this frequency list is empty and freq was minimum freq, update minFreq
        if (freqToKeys[freq].empty()) {
            freqToKeys.erase(freq);
            if (minFreq == freq) minFreq++;
        }

        // Insert key into freq+1 list at front (most recently used in that freq)
        freqToKeys[freq + 1].push_front(key);
        keyToIter[key] = freqToKeys[freq + 1].begin();

        // Update frequency for the key
        keyToValFreq[key].second = freq + 1;

        return val;
    }

    void put(int key, int value) {
        if (capacity <= 0) return;

        // If key already exists, update value and frequency via get()
        if (keyToValFreq.find(key) != keyToValFreq.end()) {
            keyToValFreq[key].first = value;
            get(key); // update frequency
            return;
        }

        // If cache is full, evict least frequently used key
        if ((int)keyToValFreq.size() == capacity) {
            // key to evict = least frequent key's last element (least recently used)
            int keyToEvict = freqToKeys[minFreq].back();
            freqToKeys[minFreq].pop_back();

            if (freqToKeys[minFreq].empty()) {
                freqToKeys.erase(minFreq);
            }

            keyToValFreq.erase(keyToEvict);
            keyToIter.erase(keyToEvict);
        }

        // Insert new key with frequency 1
        keyToValFreq[key] = {value, 1};
        freqToKeys[1].push_front(key);
        keyToIter[key] = freqToKeys[1].begin();
        minFreq = 1;  // reset min frequency to 1 for new key
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */