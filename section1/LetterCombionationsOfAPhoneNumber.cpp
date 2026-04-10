class Solution {
public:
    vector<string> letterCombinations(string digits) {
      unordered_map<char, string> m = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
      };
      vector<string> answ;
      string curr = "";
      backtrack(digits, curr, 0, m, answ);
      return answ;
    }

    void backtrack(string& digits, string& curr, int index, unordered_map<char, string>& m, vector<string>& answ){
      if(digits.size() == curr.size()){
        answ.push_back(curr);
        return;
      }

      char curr_char = digits[index];
      for(char c : m[curr_char]){
        curr.push_back(c);
        backtrack(digits, curr, index+1, m, answ);
        curr.pop_back();
      }
    }
}
