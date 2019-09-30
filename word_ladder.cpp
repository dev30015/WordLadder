#include "assignments/wl/word_ladder.h"

// Detects weather a word is transformable or not at the very early stage
// by comparing the string length of the word
// True if the length of both words are equal or otherwise false
bool QuickCheck(const std::string& initial,
                const std::string& final,
                std::set<std::string>& lexicon) {
  int size1 = initial.length();
  int size2 = final.length();

  if (size1 != size2) {
    return false;
  }

  // either the initial word is invalid or the final word is invalid
  bool t1_valid = false;
  bool t2_valid = false;

  // check if initial word or the final word is valid from the dictionary
  for (auto l : lexicon) {
    if (initial.compare(l) == 0) {
      t1_valid = true;
    }

    if (final.compare(l) == 0) {
      t2_valid = true;
    }

    // early check & early exit on average has faster performance
    if (t1_valid && t2_valid) {
      return true;
    }
  }
  return false;
}

// Limits the search range by the length
// For example, provide 4 returns only length of 4 word from the dictionary
std::unordered_map<std::string, bool> LimitSearchRange(int length, std::set<std::string>& lexicon) {
  std::unordered_map<std::string, bool> umap;
  for (auto l : lexicon) {
    int len = l.length();
    if (len == length) {
      umap.try_emplace(l, true);
    }
  }
  return umap;
}

// Generate valid word set
std::vector<std::string> GenearteValidWordSet(const std::string& word,
                                              std::unordered_map<std::string, bool>& search_range) {
  std::vector<std::string> valid_words;
  std::string test_word;
  std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
  int length = word.size();
  for (int i = 0; i < length; i++) {
    test_word = word;
    for (size_t j = 0; j < alphabet.size(); ++j) {
      char c = alphabet[j];
      std::string s(1, c);
      test_word.replace(i, 1, s);

      std::unordered_map<std::string, bool>::const_iterator kitr = search_range.find(test_word);
      // contains item
      if (kitr != search_range.end()) {
        valid_words.push_back(test_word);
      }
    }
  }

  // sort all the valid words in ascending order
  sort(valid_words.begin(), valid_words.end());
  return valid_words;
}

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

// Outputs the solution
void PrintSolutionSets(std::vector<std::vector<std::string>>& solutions) {
  if (solutions.size() == 0) {
    std::cout << "No ladder found." << std::endl;
    return;
  }

  std::cout << "Found ladder: ";

  auto path = solutions.back();
  if (solutions.size() == 1 && path.size() == 1) {
    auto word_name = path.back();
    std::cout << word_name << " ";
  }

  for (auto curr_solution : solutions) {
    for (auto word : curr_solution) {
      std::cout << word << " ";
    }
    std::cout << std::endl;
  }

  return;
}
