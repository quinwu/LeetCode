static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

struct MyHashSetNode{
    int val;
    MyHashSetNode *left, *right;
    
    MyHashSetNode(int v):val(v),left(nullptr),right(nullptr){}
    ~MyHashSetNode(){
        if(left != nullptr) delete left;
        if(right != nullptr) delete right;
    }
};

class MyHashSetTree{
    private:
        MyHashSetNode* root;
    public:
        MyHashSetTree(): root(nullptr) {}
        ~MyHashSetTree(){
            if(root != nullptr){
                delete root;
            }
        }
    
        MyHashSetNode* Insert(int x, MyHashSetNode *parent){
            MyHashSetNode* result = parent;
            
            if(parent == nullptr){
                result = new MyHashSetNode(x);
            }
            else if( x < parent->val){
                parent->left = Insert(x, parent->left);
            }
            else if(x > parent->val){
                parent->right = Insert(x, parent->right);
            }
            else{
                return nullptr;
            }
            
            return result;
        }
        
        bool Insert(int x){
            if(Find(x) != nullptr){
                return false;
            }
            root = Insert(x, root);
            return true;
        }
    
        MyHashSetNode *Find(int x, MyHashSetNode *parent){
            MyHashSetNode *cur = parent;
            int curVal;
            
            while(cur != nullptr){
                curVal = cur->val;
                if(x < curVal){
                    cur = cur->left;
                }
                else if (x > curVal){
                    cur = cur->right;
                }
                else{
                    return cur;
                }
            }
            
            return nullptr;
        }
    
        MyHashSetNode *Find(int x){
            if(root != nullptr){
                return Find(x, root);
            }
            return nullptr;
        }
    
        MyHashSetNode* FindMin(MyHashSetNode* parent){
            MyHashSetNode *cur = parent;
            MyHashSetNode *left = nullptr;
            
            if(cur != nullptr){
                while( (left = cur->left) != nullptr){
                    cur = left;
                }
            }
            return cur;
        }
    
        MyHashSetNode* RemoveMin(MyHashSetNode* parent){
            if(parent == nullptr){
                return nullptr;
            }
            else if (parent->left != nullptr){
                parent->left = RemoveMin(parent->left);
                return parent;
            }
            else{
                MyHashSetNode* result = parent->right;
                
                parent->right = parent->left = nullptr;
                delete parent;
                return result;
            }
        }
        
        MyHashSetNode *Remove(int x,MyHashSetNode* parent){
            MyHashSetNode *cur = parent;
            MyHashSetNode *left = nullptr;
            MyHashSetNode *right = nullptr;
            
            int curVal;
            
            if(cur != nullptr){
                left = cur->left;
                right = cur->right;
                curVal = cur->val;
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
                cur->val = FindMin(right)->val;
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


class MyHashSet {

private:
    MyHashSetTree tree;
    
public:
    /** Initialize your data structure here. */
    
    MyHashSet() {
        
    }
    
    void add(int key) {
        tree.Insert(key);
    }
    
    void remove(int key) {
        tree.Remove(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return tree.Find(key) != nullptr;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */