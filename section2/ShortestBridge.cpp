class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
      queue<pair<int, int>> q;
      for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
          if(grid[i][j] == 1){
            mark(i, j, grid, q);
            return findBridge(q, grid);
          }
        }
      }
      return 0;
    }

    int findBridge(queue<pair<int, int>>& q, vector<vector<int>>& grid){
      int distance = 0;
      while(!q.empty()){
        int n = q.size();
        for(int i = 0; i < n; i++){
          pair<int, int> p = q.front(); q.pop();
          for(int di = -1; di <= 1; di++){
            for(int dj = -1; dj <= 1; dj++){
              if(abs(di) == abs(dj)) continue;
              int newI = di + p.first;
              int newJ = dj + p.second;
              if(!inBounds(newI, newJ, grid) || grid[newI][newJ] == 2) continue;

              if(grid[newI][newJ] == 1) return distance;
              if(grid[newI][newJ] == 0){
                q.push({newI, newJ});
                grid[newI][newJ] = 2;
              }
            }
          }
        }
        distance++;
      }

      return distance;
    }

    bool inBounds(int i, int j, vector<vector<int>>& grid){
      return i>= 0 && j < 0 && i < grid.size() && j < grid[0].size();
    }

    void mark(int i, int j, vector<vector<int>>& grid, queue<pair<int, int>>& q){
      if(!inBounds(i, j, grid) || grid[i][j] != 1) return; 
      grid[i][j] = 2;
      q.push({i, j});
      for(int di = -1; di <= 1; di++){
        for(int dj = -1; dj <= 1; dj++){
          if(abs(di) == abs(dj)) continue;
          mark(i+di, j+dj, grid, q);
        }
      }
    }
};
