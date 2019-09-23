class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(max_pq.size() == 0 && min_pq.size() == 0){
            max_pq.push(num);
        }
        else if( num > max_pq.top()){
            min_pq.push(num);
        }
        else{
            max_pq.push(num);
        }
        
        if(max_pq.size() - min_pq.size() == 2){
            min_pq.push(max_pq.top());
            max_pq.pop();
        }
        
        if(min_pq.size() - max_pq.size() == 2){
            max_pq.push(min_pq.top());
            min_pq.pop();
        }
        
    }
    
    double findMedian() {
        double ans;
        if(min_pq.size() == max_pq.size()){
            ans = (double)(min_pq.top() + max_pq.top()) / 2.0;
        }
        if(min_pq.size() > max_pq.size()){
            ans = (double)min_pq.top();
        }
        if(min_pq.size() < max_pq.size()){
            ans = (double)max_pq.top();
        }
        
        return ans;
    }
    
private:
    priority_queue<int, vector<int>, less<int>> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */