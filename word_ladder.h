#ifndef ASSIGNMENTS_WL_WORD_LADDER_H_
#define ASSIGNMENTS_WL_WORD_LADDER_H_

// TODO

#include <string>
#include <set>
#include <iostream>
#include <iterator>
#include <queue>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <vector>

//methods for handling the dictionary
std::unordered_map<std::string,bool> LimitSearchRange(int length,std::set<std::string>& lexicon);
std::vector<std::string> GenearteValidWordSet(const std::string& word,std::unordered_map<std::string,bool>& searchRange);

//methods for BFS
std::vector<std::vector<std::string>> GetSolutions(const std::string& start, const std::string& end, std::set<std::string>& lexicon);
void PrintSolutionSets(std::vector<std::vector<std::string>>& solutions);

//helper methods
bool QuickCheck(const std::string& initial, const std::string &final, std::set<std::string>& lexicon);

#endif  // ASSIGNMENTS_WL_WORD_LADDER_H_

