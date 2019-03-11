static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

struct MyHashMapNode{
    int key;
    int val;
    MyHashMapNode *left, *right;
    
    MyHashMapNode(int k, int v):key(k),val(v),left(nullptr),right(nullptr){}
    ~MyHashMapNode(){
        if(left != nullptr) delete left;
        if(right != nullptr) delete right;
    }
};

class MyHashMapTree{
    private:
        MyHashMapNode* root;
    public:
        MyHashMapTree(): root(nullptr) {}
        ~MyHashMapTree(){
            if(root != nullptr){
                delete root;
            }
        }
    
        MyHashMapNode* Insert(int key, int val,MyHashMapNode *parent){
            MyHashMapNode* result = parent;
            
            if(parent == nullptr){
                result = new MyHashMapNode(key, val);
            }
            else if(key < parent->key){
                parent->left = Insert(key, val, parent->left);
            }
            else if(key > parent->key){
                parent->right = Insert(key, val, parent->right);
            }
            else{
                parent->val = val;
            }
            
            return result;
        }
        
        void Insert(int key, int val){
            root = Insert(key, val, root);
        }
    
        MyHashMapNode *Find(int key, MyHashMapNode *parent){
            MyHashMapNode *cur = parent;
            int curVal;
            
            while(cur != nullptr){
                curVal = cur->key;
                if(key < curVal){
                    cur = cur->left;
                }
                else if (key > curVal){
                    cur = cur->right;
                }
                else{
                    return cur;
                }
            }
            
            return nullptr;
        }
    
        MyHashMapNode *Find(int key){
            if(root != nullptr){
                return Find(key, root);
            }
            return nullptr;
        }
    
        MyHashMapNode* FindMin(MyHashMapNode* parent){
            MyHashMapNode *cur = parent;
            MyHashMapNode *left = nullptr;
            
            if(cur != nullptr){
                while( (left = cur->left) != nullptr){
                    cur = left;
                }
            }
            return cur;
        }
    
        MyHashMapNode* RemoveMin(MyHashMapNode* parent){
            if(parent == nullptr){
                return nullptr;
            }
            else if (parent->left != nullptr){
                parent->left = RemoveMin(parent->left);
                return parent;
            }
            else{
                MyHashMapNode* result = parent->right;
                
                parent->right = parent->left = nullptr;
                delete parent;
                return result;
            }
        }
        
        MyHashMapNode *Remove(int x,MyHashMapNode* parent){
            MyHashMapNode *cur = parent;
            MyHashMapNode *left = nullptr;
            MyHashMapNode *right = nullptr;
            
            int curVal;
            
            if(cur != nullptr){
                left = cur->left;
                right = cur->right;
                curVal = cur->key;
            }
            
            if(cur == nullptr){
                return nullptr;
            }
            else if ( x < curVal ){
                cur->left = Remove(x, left);
            }
            else if ( x > curVal){
                cur->right = Remove(x, right);
            }
            else if (left != nullptr && right != nullptr){
                MyHashMapNode* minNode = FindMin(right);
                cur->key = minNode->key;
                cur->val = minNode->val;
                cur->right = RemoveMin(right);
            }
            else{
                cur = (left != nullptr) ? left : right;
                parent->right = parent->left = nullptr;
                delete parent;
            }
            return cur;
        }
    
        bool Remove(int x){
            if(Find(x) == nullptr){
                return false;
            }
            root = Remove(x, root);
            return true;
        }
};


class MyHashMap {

private:
    MyHashMapTree tree;
    
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        tree.Insert(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto result = tree.Find(key);
        return result == nullptr ? -1 : result->val;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        tree.Remove(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */