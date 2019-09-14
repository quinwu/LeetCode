struct Node{
    list<pair<int,int>>* pre;
    int freq;
    list<pair<int,int>>::iterator it;
};

class LFUCache {
private:
    int capacity;
    int minfreq;
    unordered_map<int, list<pair<int,int>>> freq_map;
    unordered_map<int, Node> cache;
    
public:
    LFUCache(int capacity,int minfreq = 1) {
        this->capacity = capacity;
        this->minfreq = minfreq;
    }
    
    void visit(Node& p){
        p.freq++;
        list<pair<int,int>>& dst = freq_map[p.freq];
        dst.splice(dst.begin(),*p.pre,p.it);
        if(p.pre->empty()){
            freq_map.erase(p.freq-1);
            if(minfreq == p.freq-1){
                minfreq++;
            }
        }
        p.pre = &dst;
        p.it = dst.begin();
    }
    
    int get(int key) {
        unordered_map<int,Node>::iterator item = cache.find(key);
        if(item == cache.end()){
            return -1;
        }
        
        Node& p = item->second;
        int value = p.it->second;
        visit(p);
        return value;
    }

    
    void put(int key, int value) {
        
        if(capacity == 0){
            return;
        }
        
        unordered_map<int,Node>::iterator item = cache.find(key);
        if(item == cache.end()){
            if(cache.size() == capacity){
                list<pair<int,int>>& min_list = freq_map[minfreq];
                cache.erase(min_list.back().first);
                min_list.pop_back();
                if(min_list.empty()){
                    minfreq++;
                }
            }
            
            int freq = 1;
            list<pair<int,int>>& l = freq_map[freq];
            l.push_front(pair<int,int>(key, value));
            minfreq = min(freq, minfreq);
            
            Node p = {&l, freq, l.begin()};
            cache.insert(make_pair(key,p));
        }
        else{
            Node& p = item->second;
            p.it->second = value;
            visit(p);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */