class Solution {
public:
    
    bool check(char c){
        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
            return true;
        }
        return false;
    }
    
    void toLowCase(string& str){
        for(string::iterator it = str.begin(), end = str.end(); it != end; it ++){
            if( (*it) >= 'A' && (*it) <= 'Z'){
                *it += 32;
            }
        }
    }
    
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string, int> Count;
        string::iterator start = paragraph.begin();
        bool word = true;
        for(string::iterator it = paragraph.begin(), end = paragraph.end(); it != end; it ++){
            if(!check(*it)){
                if(word){
                    string str = string(start,it);
                    toLowCase(str);
                    Count[str] ++;
                    word = false;
                }      
            }
            else{
                if(!word){
                    start = it;
                }
                word = true;
            }
        }
        
        if(word){
            string str = string(start,paragraph.end());
            toLowCase(str);
            Count[str] ++;
            word = false;
        }
        
        
        int maxx = -1;
        string ans = "";
        for(auto it = Count.begin(), end = Count.end(); it != end; it ++){
            if((*it).second > maxx){
                bool flag = false;
                for(int j = 0 ; j < banned.size() ; j++){
                    if((*it).first == banned[j]){
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    maxx = (*it).second;
                    ans = (*it).first;
                }
            }
        }
        return ans;
    }
};