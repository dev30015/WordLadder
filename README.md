```cpp
// Return a vector of solutions
std::vector<std::vector<std::string>>
GetSolutions(const std::string& start, const std::string& end, std::set<std::string>& lexicon) {
  // limit the search range to minimize time complexity
  int dictionary_size = start.size();
  auto search_range = LimitSearchRange(dictionary_size, lexicon);

  std::vector<std::vector<std::string>> solutions;

  // edge case handling
  if (start.empty() || end.empty()) {
    return solutions;
  }

  std::queue<std::vector<std::string>> queue;

  std::unordered_map<std::string, bool> all_prev_level_nodes;
  std::set<std::string> curr_level_set;

  std::vector<std::string> path;
  path.push_back(start);
  queue.push(path);

  all_prev_level_nodes.try_emplace(start, true);
  std::queue<std::string> itr;
  int curr_length = path.size();
  int shortest_length = 0;

  while (!queue.empty()) {
    // printing out the state of the queue
    std::vector curr_path = queue.front();
    std::string curr_node = curr_path.back();

    int new_length = curr_path.size();

    // early exit
    if (new_length > shortest_length && shortest_length != 0) {
      return solutions;
    }

    queue.pop();

    // goal state reached
    if (curr_node.compare(end) == 0) {
      shortest_length = curr_path.size();
      solutions.push_back(curr_path);
    }

    // keep expanding
    auto adj_list = GenearteValidWordSet(curr_node, search_range);

    // reset state when level is changed
    if (new_length > curr_length) {
      // insert to the previous level sets
      for (auto e : curr_level_set) {
        all_prev_level_nodes.try_emplace(e, true);
      }
      // refresh the current set
      std::set<std::string> curr_level_set;

      // utility: delete used words from the dictionary (i.e. search range)
      for (auto it = all_prev_level_nodes.begin(); it != all_prev_level_nodes.end(); ++it) {
        std::unordered_map<std::string, bool>::const_iterator check = search_range.find(it->first);
        if (check != search_range.end()) {
          search_range.erase(it->first);
        }
      }
      curr_length = new_length;
    }

    for (auto curr_node : adj_list) {
      std::unordered_map<std::string, bool>::const_iterator check =
          all_prev_level_nodes.find(curr_node);
      if (check == all_prev_level_nodes.end()) {
        std::vector<std::string> new_path = curr_path;
        new_path.push_back(curr_node);
        queue.push(new_path);
        curr_level_set.insert(curr_node);
      }
    }
  }
  return solutions;
}

```
