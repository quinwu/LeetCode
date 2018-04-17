class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mapp;
        mapp.insert(make_pair<char,int>('I',1));
        mapp.insert(make_pair<char,int>('V',5));
        mapp.insert(make_pair<char,int>('X',10));
        mapp.insert(make_pair<char,int>('L',50));
        mapp.insert(make_pair<char,int>('C',100));
        mapp.insert(make_pair<char,int>('D',500));
        mapp.insert(make_pair<char,int>('M',1000));
        
        int sum =mapp[s[s.length()-1]];
        for (int i = s.length()-2 ; i >= 0 ; i --){
            if(mapp[s[i]] < mapp[s[i+1]]){
                sum -= mapp[s[i]];
            }
            else{
                sum += mapp[s[i]];
            }
        }
        
        return sum;
        
    }
};