// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
class MyLinkedList {

private:
    int length;
    ListNode* head;
    ListNode* tail;

    
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        length = 0;
        head = NULL;
        tail = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 || index >= length){
            return -1;
        }
        
        ListNode* cur = head;
        int cnt = 0;
        cout << "index: " << index << endl;
        while( cnt < index){
            cur = cur->next;
            cnt ++;
        }
        return cur->val;
    }

    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* q = new ListNode(val);
        q->next = head;
        head = q;
        if(length == 0){
            tail = head;
        }
        length ++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        
        ListNode* q = new ListNode(val);
        tail->next = q;
        tail = q;
        length ++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > length || index < 0){
            return;
        }
        if(index == 0){
            addAtHead(val);
        }
        else{
            ListNode* newnode = new ListNode(val);
            int cnt = 0;
            ListNode* pre = head;
            ListNode* cur = head;
            while( cnt < index){
                pre = cur;
                cur = cur->next;
                cnt ++;
            }
            pre->next = newnode;
            newnode->next = cur;
            if(index == length){
                tail = newnode;
            }
            length++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < 0 || index >= length){
            return;
        }
        if(index == 0){
            head = head->next;
        }
        else{
            ListNode* pre = head;
            ListNode* cur = head;
            int cnt = 0;
            while(cnt < index){
                pre = cur;
                cur = cur->next;
                cnt ++;
            }
            pre->next = cur->next;
            if(index == length - 1){
                tail = pre;
            }
        }
        length--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */