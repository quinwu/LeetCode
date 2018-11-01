class Solution {
public:
    bool isValid(string s) {
        stack<char> Stack;
        for(char ss : s){
            if (ss == '(' || ss =='[' || ss == '{'){
                Stack.push(ss);
            }
            else{
                if(Stack.empty()){
                    return false;
                }
                char c = Stack.top();
                Stack.pop();
                if(c == '(' && ss !=')'){
                    return false;
                }
                if(c == '[' && ss != ']'){
                    return false;
                }
                if(c =='{' && ss != '}'){
                    return false;
                }
            }
        }
        if(Stack.empty()){
            return true;
        }
        return false;
    }
};