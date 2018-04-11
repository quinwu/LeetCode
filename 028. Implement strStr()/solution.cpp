class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0){
            return 0;
        }
        for (int i = 0 ; i < haystack.size() ; i ++){
            bool flag = false;
            if (haystack[i] == needle[0]){
                flag = true;
                for (int j = 1; j < needle.size() ; j ++){
                    if (i+j >= haystack.size() || haystack[i+j] != needle[j] ){
                        flag = false;
                    }
                }
            }
            if(flag){
                return i;
            }
        }
        return -1;
    }
};