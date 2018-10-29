class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length() < b.length()){
            swap(a,b);
        }
        
        //default len(a) > len(b)
        for(int i = 0 ; i < b.length() ; i++){
            a[a.length() - i -1] = (a[a.length() - i -1] - '0') + (b[b.length()-1-i] - '0') + '0';
        }
        
        
        for(int i = a.length() -1 ; i >= 1; i --){
            if(a[i] > '1'){
                a[i-1] = (a[i-1] - '0') + (a[i] - '0') / 2 + '0';
                a[i] = (a[i] - '0') % 2 + '0';
            }
        }
        
        while(a[0] > '1'){
            char prefix = (a[0] - '0') / 2 + '0';
            a[0] = (a[0] - '0') % 2 + '0';
            a = prefix + a;
        }
        return a;
    }
};