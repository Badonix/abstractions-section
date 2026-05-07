#include "pairs.h"
#include <vector>

using namespace std;


void rec(int curr_pairs, vector<vector<bool>>& grid, vector<bool>& used, int& max_pairs){

  max_pairs = max(curr_pairs, max_pairs);

  for(int i = 0; i < grid.size(); i++){
    if(used[i]) continue;
    for(int j = i + 1; j < grid.size(); j++){
      if(used[j] || !grid[i][j]) continue;
      used[i] = true;
      used[j] = true;
      rec(curr_pairs + 1, grid, used, max_pairs);
      used[i] = false;
      used[j] = false;
    }
  }
}

int maxPairs(vector<vector<bool>> &likes) {
  int max_pairs = 0;
  vector<vector<bool>> grid(likes.size(), vector<bool>(likes.size(), false));

  for(int i = 0; i < likes.size(); i++){
    for(int j = 0; j < likes.size(); j++){
      if(likes[i][j] && likes[j][i]) {
        grid[i][j] = grid[j][i] = true;
      }
    }
  }

  vector<bool> used(likes.size(), false);

  rec(0, grid, used, max_pairs);

  return max_pairs;
}

/*
 *    [0, 2] -> true
 *    [2, 0] -> false
 * 0 1 2 3 4 5
 *
 * 0 0 1 1 1 0 |0
 * 0 1 0 0 1 0 |1
 * 0 0 1 1 1 0 |2
 * 0 1 0 0 1 0 |3
 * 0 0 0 1 1 0 |4
 *
 *
 *
 *
 *
 */
