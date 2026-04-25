class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
      int sum = 0;
      for(int n : matchsticks) sum += n;
      if(sum % 4 != 0) return false;
      int target = sum / 4;

      int square[4];
      for(int i = 0; i < 4; i++) square[i] = 0;

      return dfs(matchsticks, square, target, 0);
    }

    bool dfs(vector<int>& matchsticks, int* square, int target, int index){
      if(index >= matchsticks.size()){
        for(int i = 0; i < 4; i++){
          if(square[i] != target) return false;
        }
        return true;
      }

      bool found_square = false;
      for(int i = 0; i < 4; i++){
        int curr_len = square[i];
        if(curr_len + matchsticks[index] > target) continue;
        square[i] += matchsticks[index];
        if(dfs(matchsticks, square, target, index+1)){
          found_square = true;
          break;
        }
        square[i] -= matchsticks[index];
      }

      return found_square;
    }
};
