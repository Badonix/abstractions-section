class Solution {
public:
    vector<string> letterCasePermutation(string s) {
       vector<string> answ; 
        dfs(s, 0, answ);
       return answ;
    }

    void dfs(string& s, int index, vector<string>& answ){
      if(index >= s.size()){
        answ.push_back(s);
        return;
      }

      if(s[index] >= '0' && s[index] <= '9'){
        dfs(s, index + 1, answ);
        return;
      }
      s[index] = toupper(s[index]);
      dfs(s, index + 1, answ);
      s[index] = tolower(s[index]);
    }
};
