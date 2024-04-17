#include "keys-and-rooms.hpp"

bool KeysAndRooms::canVisitAllRooms(const std::vector<std::vector<int>> &rooms) const {
  int visited_count = 1;
  std::vector<bool> visited(rooms.size(), false);
  std::queue<int> keys;

  visited[0] = true;
  for (int i = 0; i < rooms[0].size(); ++i) {
    keys.push(rooms[0][i]);
  }

  while (!keys.empty()) {
    int key = keys.front();
    if (!visited[key]) {
      visited[key] = true;
      visited_count += 1;
    }
    keys.pop();
    std::vector<int> room = rooms[key];
    for (const int key_in_room : room) {
      if (!visited[key_in_room]) {
        keys.push(key_in_room);
      }
    }
  }

  return visited_count == rooms.size();
}
