class Solution {
public:
         // index  target
    int cache[205][10005];
    // cache[i][t] = {-1, 0, 1}
    bool canPartition(vector<int>& nums) {
      int sum = 0;
      for(int n : nums) sum += n;
      if(sum % 2 == 1) return false;
      int target = sum / 2;
      for(int i = 0; i < 205; i++){
        for(int j = 0; j < 10005; j++){
          cache[i][j] = -1;
        }
      }
      return solve(nums, target, 0);
    }

    bool solve(vector<int>& nums, int target, int index){
      if(target == 0) return true;
      if(index >= nums.size() || target < 0) return false;
      if(cache[index][target] != -1) {
        return cache[index][target] == 1 ? true : false;
      }
      bool answ = solve(nums, target - nums[index], index + 1) || solve(nums, target, index+1);
      cache[index][target] = answ ? 1 : 0;
      return answ;
    }
    // (index, target)
    // [1, 1, 1, 1, 1]
};
