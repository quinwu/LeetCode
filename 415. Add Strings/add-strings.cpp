class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        if(len1 < len2){
            swap(num1, num2);
            swap(len1,len2);
        }
        // default len(num1) >= len(num2)
        for(int i = 0 ; i < len2 ; i++){
            num1[len1-i-1] = (num1[len1-i-1] - '0') + (num2[len2-i-1] - '0') + '0';
        }
        
        for(int i = len1-1 ; i >=1 ; i--){
            if(num1[i] > '9'){
                num1[i-1] = (num1[i-1] - '0') + (num1[i] - '0') / 10 + '0';
                num1[i] = (num1[i] - '0') % 10 + '0';
            }
        }
        
        if(num1[0] > '9'){
            char prefix = (num1[0] - '0') / 10 + '0';
            num1[0] = (num1[0] - '0') % 10 +'0';
            num1 = prefix + num1;
        }
        return num1;
    }
};