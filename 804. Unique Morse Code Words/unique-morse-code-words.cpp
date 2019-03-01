class Solution {
public:
    
    void init(vector<string>& Morse){
        Morse.push_back(".-");
        Morse.push_back("-...");
        Morse.push_back("-.-.");
        Morse.push_back("-..");
        Morse.push_back(".");
        Morse.push_back("..-.");
        Morse.push_back("--.");
        Morse.push_back("....");
        Morse.push_back("..");
        Morse.push_back(".---");
        Morse.push_back("-.-");
        Morse.push_back(".-..");
        Morse.push_back("--");
        Morse.push_back("-.");
        Morse.push_back("---");
        Morse.push_back(".--.");
        Morse.push_back("--.-");
        Morse.push_back(".-.");
        Morse.push_back("...");
        Morse.push_back("-");
        Morse.push_back("..-");
        Morse.push_back("...-");
        Morse.push_back(".--");
        Morse.push_back("-..-");
        Morse.push_back("-.--");
        Morse.push_back("--..");
    }
    
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> Morse;
        init(Morse);
        
        set<string> Set;
        for(int i = 0 ; i < words.size(); i++){
            string morse = "";
            for(int j = 0; j < words[i].length() ; j++){
                morse += Morse[words[i][j] - 'a'];
            }
            cout << morse << endl;
            Set.insert(morse);
        }
        return Set.size();
    }
};