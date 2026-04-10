class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
      int answer = 0;
      for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
          if(grid[i][j] != 0){
            int curr = fish(grid, i, j);
            answer = max(answer, curr);
          }
        }
      }
      return answer;
    }

    int fish(vector<vector<int>>& grid, int i, int j){
      if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0){
        return 0;
      }

      int curr_fish = grid[i][j];
      grid[i][j] = 0;

      for(int di = -1; di <= 1; di++){
        for(int dj = -1; dj <= 1; dj++){
          if(abs(di) + abs(dj) == 2) continue;
          int new_i = di + i;
          int new_j = dj + j;
          curr_fish += fish(grid, new_i, new_j);
        }
      }

      return curr_fish;
    }
};



/*
 *
 * n! = n * (n-1)!
 *
 *
 *
 * print(fact(5)); 5 * fact(4); 4 * fact(3);
 *
 *
 *
 *
 *
 *
 */
