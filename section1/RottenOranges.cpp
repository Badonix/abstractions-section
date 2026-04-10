class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      queue<pair<int, int>> q;
      int fresh_oranges = 0;
      for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
          if(grid[i][j] == 1) fresh_oranges++;
          if(grid[i][j] == 2) q.push({i, j});
        }
      }

      int timer = 0;

      while(!q.empty()){
        int n = q.size();
        for(int i = 0; i < n; i++){
          pair<int, int> p = q.front();
          q.pop();

          for(int di = -1; di <= 1; di++){
            for(int dj = -1; dj <= 1; dj++){
              if(abs(di) + abs(dj) == 2 || di == 0 && dj == 0) continue;
              int new_i = p.first + di;
              int new_j = p.second + dj;

              if(new_i < 0 || new_j < 0 || new_i >= grid.size() || new_j >= grid[0].size()) continue;
              if(grid[new_i][new_j] != 1) continue;

              q.push({new_i, new_j});
              grid[new_i][new_j] = 0;
              fresh_oranges--;
            }
          }
        }

        timer++;
      }

      if(fresh_oranges != 0) return -1;
      return timer - 1;
    }
};
