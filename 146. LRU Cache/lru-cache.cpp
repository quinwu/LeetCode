class LRUCache {
    
private:
    int capacity;
    list<pair<int,int>> L;
    unordered_map<int, list<pair<int,int>>::iterator> MAP;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        int value = 0;
        unordered_map<int, list<pair<int,int>>::iterator>:: iterator itm = MAP.find(key);
        if(itm == MAP.end()){
            return -1;
        }
        
        list<pair<int, int>>::iterator itq = itm->second;
        value = (itq)->second;
        put((itq)->first, (itq)->second);
        return value;
        
    }
    
    void put(int key, int value) {
        unordered_map<int,list<pair<int,int>>::iterator>::iterator itm = MAP.find(key);
        
        if(itm == MAP.end()){
            if(L.size() == capacity){
                std:pair<int,int> p = L.back();
                itm = MAP.find(p.first);
                if(itm != MAP.end()){
                    MAP.erase(itm);
                }
                L.pop_back();
            }
            L.push_front(pair<int,int>(key, value));
            MAP[key] = L.begin();
        }
        else{
            list<pair<int,int>>::iterator it = itm->second;
            L.erase(it);
            L.push_front(pair<int,int>(key, value));
            MAP[key] = L.begin();
        }
        
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */