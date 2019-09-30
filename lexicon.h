#ifndef ASSIGNMENTS_WL_LEXICON_H_
#define ASSIGNMENTS_WL_LEXICON_H_

#include <set>
// Later on in semester we will learn about exceptions. But for now, we just exit on failure.
void Error(const std::string& message);

std::set<std::string> GetLexicon(const std::string& filename);

#endif  // ASSIGNMENTS_WL_LEXICON_H_
