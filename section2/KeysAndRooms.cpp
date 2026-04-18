class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
      queue<int> q;
      q.push(0);
      vector<bool> visited(rooms.size(), false);
      visited[0] = true;

      while(!q.empty()){
        int curr_room = q.front(); q.pop();
        for(int n : rooms[curr_room]){
          if(visited[n]) continue;
          q.push(n);
          visited[n] = true;
        }
      }

      for(bool was_visited : visited){
        if(!was_visited) return false;
      }
      return true;
    }
};
