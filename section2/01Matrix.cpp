class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
      queue<pair<int, int>> q;
      for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
          if(grid[i][j] == 1) grid[i][j] = -1;
          if(grid[i][j] == 0) q.push({i, j});
        }
      }

      int distance = 1;
      while(!q.empty()){
        int n = q.size();
        for(int i = 0; i < n; i++){
          pair<int,int> p = q.front(); q.pop(); 
          for(int di = -1; di <= 1; di++){
            for(int dj = -1; dj <= 1; dj++){
              if(abs(di) == abs(dj)) continue;
              int new_i = p.first + di;
              int new_j = p.second + dj;
              if(new_i < 0 || new_j < 0 || new_i >= grid.size() || new_j >= grid[0].size() || grid[new_i][new_j] != -1){
                continue;
              }
              grid[new_i][new_j] = distance;
              q.push({new_i, new_j});
            }
          }
        }
        distance++;
      }

      return grid;
    }
};
