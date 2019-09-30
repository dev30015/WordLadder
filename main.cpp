#include <iostream>
#include <string>
#include <vector>

#include "assignments/wl/lexicon.h"
#include "assignments/wl/word_ladder.h"

int main() {
  auto lexicon = GetLexicon("assignments/wl/words.txt");

  std::string initial_word;
  std::string final_word;
  std::cout << "Enter start word (RETURN to quit): ";
  getline(std::cin, initial_word);

  // exit if user has pressed ENTER
  if (initial_word.empty()) {
    return 0;
  }
  std::cout << "Enter destination word: ";
  std::cin >> final_word;

  if (!QuickCheck(initial_word, final_word, lexicon)) {
    std::cout << "No ladder found." << std::endl;
    return 0;
  }
  std::vector<std::vector<std::string>> solutions = GetSolutions(initial_word, final_word, lexicon);
  PrintSolutionSets(solutions);
  return 0;
}
