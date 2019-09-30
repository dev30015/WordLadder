/*

  == Explanation and rational of testing ==

  Explain and justify how you approached testing, the degree
   to which you're certain you have covered all possibilities,
   and why you think your tests are that thorough.

To test the correctness of the program, the outputs are compared with the output of the solution
from smaller sets to larger sets. There are 2 types of solutions:

1) No solution
  --> edge cases were covered (such as invalid inputs)
  --> essentially it does not have any solution
  --> words not in the dictionary

2) A list of solutions
  --> Solutions are increasing from the first to the last solution
  --> Test the expansion of new nodes in ascending order leads to path output in ascending order,
expansion were tested in the correct ordering

The sample test (one -> three) represents the typical edge cases where there is no solution.
The sample test (start -> final) demonstrated the characteristic of a list of solutions, where nodes
were expanded correctly and all solutions were also found.

To show that expansion order is correct:
1) (add->new) is correct
2) (code->test) is correct
3) (start->final) is correct
4) (latten->lesson) is correct
...
...
Since the first all follows the pattern, and the code strictly follows a manual sort method before
returning an adjacent list. We can conclude that the expansion order is correct

To show that all possible solutions are expanded:
All adjacent nodes will be enqueue other than the ones that were evaluated in the previous level,
this means that the new path will expand every possibility of the adjacent nodes This shows it will
reach to the maximum possible solutions.

*/

#include <vector>

#include "assignments/wl/lexicon.h"
#include "assignments/wl/word_ladder.h"
#include "catch.h"

TEST_CASE("one -> three") {
  auto lexicon = GetLexicon("assignments/wl/words.txt");
  std::vector<std::vector<std::string>> solutions = {};
  REQUIRE(GetSolutions("one", "three", lexicon) == solutions);
}

TEST_CASE("one -> null ") {
  auto lexicon = GetLexicon("assignments/wl/words.txt");
  std::vector<std::vector<std::string>> solutions = {};
  REQUIRE(GetSolutions("one", "", lexicon) == solutions);
}

TEST_CASE("null -> one ") {
  auto lexicon = GetLexicon("assignments/wl/words.txt");
  std::vector<std::vector<std::string>> solutions = {};
  REQUIRE(GetSolutions("", "one", lexicon) == solutions);
}

TEST_CASE("end -> end") {
  auto lexicon = GetLexicon("assignments/wl/words.txt");
  std::vector<std::vector<std::string>> solutions = {{"end"}};
  REQUIRE(GetSolutions("end", "end", lexicon) == solutions);
}

TEST_CASE("a -> b") {
  auto lexicon = GetLexicon("assignments/wl/words.txt");
  std::vector<std::vector<std::string>> solutions = {};
  REQUIRE(GetSolutions("a", "b", lexicon) == solutions);
}

TEST_CASE("ok -> k") {
  auto lexicon = GetLexicon("assignments/wl/words.txt");
  std::vector<std::vector<std::string>> solutions = {};
  REQUIRE(GetSolutions("ok", "k", lexicon) == solutions);
}

TEST_CASE("news -> new") {
  auto lexicon = GetLexicon("assignments/wl/words.txt");
  std::vector<std::vector<std::string>> solutions = {};
  REQUIRE(GetSolutions("news", "new", lexicon) == solutions);
}

TEST_CASE("plus -> minus") {
  auto lexicon = GetLexicon("assignments/wl/words.txt");
  std::vector<std::vector<std::string>> solutions = {};
  REQUIRE(GetSolutions("plus", "minus", lexicon) == solutions);
}

TEST_CASE("add -> new") {
  auto lexicon = GetLexicon("assignments/wl/words.txt");
  std::vector<std::vector<std::string>> solutions = {{"add", "aid", "ait", "nit", "net", "new"},
                                                     {"add", "aid", "fid", "fed", "few", "new"},
                                                     {"add", "aid", "mid", "med", "mew", "new"}};
  REQUIRE(GetSolutions("add", "new", lexicon) == solutions);
}

TEST_CASE("infinite -> solutions") {
  auto lexicon = GetLexicon("assignments/wl/words.txt");
  std::vector<std::vector<std::string>> solutions = {};
  REQUIRE(GetSolutions("infinite", "solutions", lexicon) == solutions);
}

TEST_CASE("code -> test") {
  auto lexicon = GetLexicon("assignments/wl/words.txt");
  std::vector<std::vector<std::string>> solutions = {
      {"code", "cods", "coss", "cost", "tost", "test"},
      {"code", "cods", "coss", "toss", "tost", "test"},
      {"code", "cods", "tods", "toss", "tost", "test"},
      {"code", "cole", "colt", "cost", "tost", "test"},
      {"code", "core", "tore", "tort", "tost", "test"},
      {"code", "lode", "lose", "lost", "lest", "test"},
      {"code", "lode", "lose", "lost", "tost", "test"},
  };
  REQUIRE(GetSolutions("code", "test", lexicon) == solutions);
}

TEST_CASE("work -> play") {
  auto lexicon = GetLexicon("assignments/wl/words.txt");
  std::vector<std::vector<std::string>> solutions = {
      {"work", "fork", "form", "foam", "flam", "flay", "play"},
      {"work", "pork", "perk", "peak", "pean", "plan", "play"},
      {"work", "pork", "perk", "peak", "peat", "plat", "play"},
      {"work", "pork", "perk", "pert", "peat", "plat", "play"},
      {"work", "pork", "porn", "pirn", "pian", "plan", "play"},
      {"work", "pork", "port", "pert", "peat", "plat", "play"},
      {"work", "word", "wood", "pood", "plod", "ploy", "play"},
      {"work", "worm", "form", "foam", "flam", "flay", "play"},
      {"work", "worn", "porn", "pirn", "pian", "plan", "play"},
      {"work", "wort", "bort", "boat", "blat", "plat", "play"},
      {"work", "wort", "port", "pert", "peat", "plat", "play"},
      {"work", "wort", "wert", "pert", "peat", "plat", "play"},
  };
  REQUIRE(GetSolutions("work", "play", lexicon) == solutions);
}
TEST_CASE("math -> work") {
  auto lexicon = GetLexicon("assignments/wl/words.txt");
  std::vector<std::vector<std::string>> solutions = {
      {"math", "mach", "mack", "mark", "wark", "work"},
      {"math", "mach", "mack", "wack", "wark", "work"},
      {"math", "mash", "mask", "mark", "wark", "work"},
      {"math", "mate", "mare", "mark", "wark", "work"},
      {"math", "mate", "mare", "more", "wore", "work"},
      {"math", "mate", "mare", "ware", "wark", "work"},
      {"math", "mate", "mare", "ware", "wore", "work"},
      {"math", "mate", "mote", "more", "wore", "work"},
      {"math", "mats", "mars", "mark", "wark", "work"},
      {"math", "mats", "mars", "wars", "wark", "work"},
      {"math", "mats", "wats", "wars", "wark", "work"},
      {"math", "matt", "mart", "mark", "wark", "work"},
      {"math", "matt", "mart", "mort", "wort", "work"},
      {"math", "matt", "mart", "wart", "wark", "work"},
      {"math", "matt", "mart", "wart", "wort", "work"},
      {"math", "matt", "mott", "mort", "wort", "work"},
      {"math", "matt", "watt", "wart", "wark", "work"},
      {"math", "matt", "watt", "wart", "wort", "work"},
      {"math", "moth", "mote", "more", "wore", "work"},
      {"math", "moth", "mott", "mort", "wort", "work"},
  };
  REQUIRE(GetSolutions("math", "work", lexicon) == solutions);
}

TEST_CASE("sleep -> awake") {
  auto lexicon = GetLexicon("assignments/wl/words.txt");
  std::vector<std::vector<std::string>> solutions = {
      {"sleep", "sheep", "sheen", "shewn", "shawn", "sharn", "share", "sware", "aware", "awake"},
      {"sleep", "sheep", "sheer", "shier", "shirr", "shire", "share", "sware", "aware", "awake"}};
  REQUIRE(GetSolutions("sleep", "awake", lexicon) == solutions);
}

TEST_CASE("study -> maths") {
  auto lexicon = GetLexicon("assignments/wl/words.txt");
  std::vector<std::vector<std::string>> solutions = {
      {"study", "studs", "scuds", "scuts", "scots", "soots", "moots", "motts", "matts", "maths"},
      {"study", "studs", "scuds", "scuts", "scots", "soots", "moots", "motts", "moths", "maths"},
      {"study", "studs", "stuns", "shuns", "shuls", "sauls", "mauls", "mauts", "matts", "maths"},
  };
  REQUIRE(GetSolutions("study", "maths", lexicon) == solutions);
}

TEST_CASE("lapse -> sleep") {
  auto lexicon = GetLexicon("assignments/wl/words.txt");
  std::vector<std::vector<std::string>> solutions = {};
  REQUIRE(GetSolutions("lapse", "sleep", lexicon) == solutions);
}

TEST_CASE("books -> light") {
  auto lexicon = GetLexicon("assignments/wl/words.txt");
  std::vector<std::vector<std::string>> solutions = {
      {"books", "bocks", "socks", "sicks", "sinks", "sinhs", "sighs", "sight", "light"},
      {"books", "bonks", "bones", "bines", "sines", "sinhs", "sighs", "sight", "light"},
      {"books", "bonks", "bones", "sones", "sines", "sinhs", "sighs", "sight", "light"},
      {"books", "bonks", "bongs", "songs", "sings", "sinhs", "sighs", "sight", "light"},
      {"books", "bonks", "konks", "kinks", "sinks", "sinhs", "sighs", "sight", "light"},
      {"books", "bonks", "monks", "minks", "sinks", "sinhs", "sighs", "sight", "light"},
      {"books", "bonks", "wonks", "winks", "sinks", "sinhs", "sighs", "sight", "light"},
      {"books", "kooks", "konks", "kinks", "sinks", "sinhs", "sighs", "sight", "light"},
      {"books", "sooks", "socks", "sicks", "sinks", "sinhs", "sighs", "sight", "light"},
  };
  REQUIRE(GetSolutions("books", "light", lexicon) == solutions);
}

TEST_CASE("latten -> lesson") {
  auto lexicon = GetLexicon("assignments/wl/words.txt");
  std::vector<std::vector<std::string>> solutions = {
      {"latten", "batten", "batter", "better", "beater", "beaker", "leaker", "leaser", "lesser",
       "lessen", "lesson"},
      {"latten", "batten", "batter", "better", "beater", "beaker", "leaker", "leaser", "lesser",
       "lessor", "lesson"},
      {"latten", "batten", "batter", "better", "beater", "beaver", "leaver", "leaser", "lesser",
       "lessen", "lesson"},
      {"latten", "batten", "batter", "better", "beater", "beaver", "leaver", "leaser", "lesser",
       "lessor", "lesson"},
      {"latten", "latter", "batter", "better", "beater", "beaker", "leaker", "leaser", "lesser",
       "lessen", "lesson"},
      {"latten", "latter", "batter", "better", "beater", "beaker", "leaker", "leaser", "lesser",
       "lessor", "lesson"},
      {"latten", "latter", "batter", "better", "beater", "beaver", "leaver", "leaser", "lesser",
       "lessen", "lesson"},
      {"latten", "latter", "batter", "better", "beater", "beaver", "leaver", "leaser", "lesser",
       "lessor", "lesson"},
      {"latten", "latter", "letter", "better", "beater", "beaker", "leaker", "leaser", "lesser",
       "lessen", "lesson"},
      {"latten", "latter", "letter", "better", "beater", "beaker", "leaker", "leaser", "lesser",
       "lessor", "lesson"},
      {"latten", "latter", "letter", "better", "beater", "beaver", "leaver", "leaser", "lesser",
       "lessen", "lesson"},
      {"latten", "latter", "letter", "better", "beater", "beaver", "leaver", "leaser", "lesser",
       "lessor", "lesson"},
      {"latten", "latter", "letter", "tetter", "tenter", "tenser", "teaser", "leaser", "lesser",
       "lessen", "lesson"},
      {"latten", "latter", "letter", "tetter", "tenter", "tenser", "teaser", "leaser", "lesser",
       "lessor", "lesson"},
      {"latten", "latter", "tatter", "tetter", "tenter", "tenser", "teaser", "leaser", "lesser",
       "lessen", "lesson"},
      {"latten", "latter", "tatter", "tetter", "tenter", "tenser", "teaser", "leaser", "lesser",
       "lessor", "lesson"},
      {"latten", "ratten", "ratton", "ration", "nation", "notion", "lotion", "logion", "legion",
       "lesion", "lesson"}};
  REQUIRE(GetSolutions("latten", "lesson", lexicon) == solutions);
}

TEST_CASE("express -> overcome") {
  auto lexicon = GetLexicon("assignments/wl/words.txt");
  std::vector<std::vector<std::string>> solutions = {};
  REQUIRE(GetSolutions("express", "overcome", lexicon) == solutions);
}

TEST_CASE("graph -> ideas") {
  auto lexicon = GetLexicon("assignments/wl/words.txt");
  std::vector<std::vector<std::string>> solutions = {{"graph", "grape", "gripe", "grime", "glime",
                                                      "glims", "glias", "glial", "ilial", "ileal",
                                                      "ideal", "ideas"}};
  REQUIRE(GetSolutions("graph", "ideas", lexicon) == solutions);
}

TEST_CASE("computer -> overcome") {
  auto lexicon = GetLexicon("assignments/wl/words.txt");
  std::vector<std::vector<std::string>> solutions = {};
  REQUIRE(GetSolutions("computer", "overcome", lexicon) == solutions);
}

TEST_CASE("start -> final") {
  auto lexicon = GetLexicon("assignments/wl/words.txt");
  std::vector<std::vector<std::string>> solutions = {
      {"start", "stars", "sears", "bears", "beads", "bends", "benes", "bines", "vines", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "bears", "beads", "bends", "binds", "bines", "vines", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "bears", "beads", "bends", "binds", "kinds", "kinas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "bears", "beads", "bends", "binds", "minds", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "bears", "beads", "bends", "mends", "minds", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "bears", "beads", "meads", "mends", "minds", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "bears", "beats", "bents", "benes", "bines", "vines", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "bears", "beats", "bents", "bints", "bines", "vines", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "bears", "beats", "bents", "bints", "mints", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "bears", "beats", "bents", "bints", "pints", "pinas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "dears", "deads", "meads", "mends", "minds", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "hears", "heads", "meads", "mends", "minds", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "hears", "heats", "hents", "hints", "mints", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "hears", "heats", "hents", "hints", "pints", "pinas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "lears", "leads", "lends", "lenes", "lines", "vines", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "lears", "leads", "lends", "lenos", "linos", "vinos", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "lears", "leads", "lends", "mends", "minds", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "lears", "leads", "meads", "mends", "minds", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "pears", "peaks", "pecks", "picks", "picas", "pinas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "pears", "peaks", "pecks", "picks", "pinks", "pinas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "rears", "reads", "meads", "mends", "minds", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "rears", "reads", "rends", "mends", "minds", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "rears", "reads", "rends", "rinds", "kinds", "kinas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "rears", "reads", "rends", "rinds", "minds", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "seals", "meals", "meads", "mends", "minds", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "seals", "sials", "vials", "virls", "vires", "vines", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "seals", "veals", "vials", "virls", "vires", "vines", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "seats", "beats", "bents", "benes", "bines", "vines", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "seats", "beats", "bents", "bints", "bines", "vines", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "seats", "beats", "bents", "bints", "mints", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "seats", "beats", "bents", "bints", "pints", "pinas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "seats", "heats", "hents", "hints", "mints", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "seats", "heats", "hents", "hints", "pints", "pinas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "seats", "meats", "meads", "mends", "minds", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "seats", "meats", "melts", "milts", "mints", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "seats", "sexts", "sexes", "sixes", "sines", "vines", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "seats", "teats", "tents", "tints", "mints", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "seats", "teats", "tents", "tints", "pints", "pinas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "seats", "teats", "tents", "tints", "tines", "vines", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "seers", "seeds", "meeds", "mends", "minds", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "seers", "seeds", "sends", "mends", "minds", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "tears", "teats", "tents", "tints", "mints", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "tears", "teats", "tents", "tints", "pints", "pinas", "vinas",
       "vinal", "final"},
      {"start", "stars", "sears", "tears", "teats", "tents", "tints", "tines", "vines", "vinas",
       "vinal", "final"},
      {"start", "stars", "soars", "soaks", "socks", "mocks", "micks", "micas", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "soars", "soaks", "socks", "mocks", "micks", "minks", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "soars", "soaks", "socks", "mocks", "monks", "minks", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "soars", "soaks", "socks", "mocks", "monks", "monas", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "soars", "soaks", "socks", "pocks", "picks", "picas", "pinas", "vinas",
       "vinal", "final"},
      {"start", "stars", "soars", "soaks", "socks", "pocks", "picks", "pinks", "pinas", "vinas",
       "vinal", "final"},
      {"start", "stars", "soars", "soaks", "socks", "sicks", "kicks", "kinks", "kinas", "vinas",
       "vinal", "final"},
      {"start", "stars", "soars", "soaks", "socks", "sicks", "micks", "micas", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "soars", "soaks", "socks", "sicks", "micks", "minks", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "soars", "soaks", "socks", "sicks", "picks", "picas", "pinas", "vinas",
       "vinal", "final"},
      {"start", "stars", "soars", "soaks", "socks", "sicks", "picks", "pinks", "pinas", "vinas",
       "vinal", "final"},
      {"start", "stars", "soars", "soaks", "socks", "sicks", "sices", "sines", "vines", "vinas",
       "vinal", "final"},
      {"start", "stars", "soars", "soaks", "socks", "sicks", "sices", "vices", "vines", "vinas",
       "vinal", "final"},
      {"start", "stars", "soars", "soaks", "socks", "sicks", "sinks", "kinks", "kinas", "vinas",
       "vinal", "final"},
      {"start", "stars", "soars", "soaks", "socks", "sicks", "sinks", "minks", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "soars", "soaks", "socks", "sicks", "sinks", "pinks", "pinas", "vinas",
       "vinal", "final"},
      {"start", "stars", "soars", "soaks", "socks", "sicks", "sinks", "sines", "vines", "vinas",
       "vinal", "final"},
      {"start", "stars", "soars", "soaks", "sooks", "kooks", "konks", "kinks", "kinas", "vinas",
       "vinal", "final"},
      {"start", "stars", "stats", "seats", "beats", "bents", "benes", "bines", "vines", "vinas",
       "vinal", "final"},
      {"start", "stars", "stats", "seats", "beats", "bents", "bints", "bines", "vines", "vinas",
       "vinal", "final"},
      {"start", "stars", "stats", "seats", "beats", "bents", "bints", "mints", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "stats", "seats", "beats", "bents", "bints", "pints", "pinas", "vinas",
       "vinal", "final"},
      {"start", "stars", "stats", "seats", "heats", "hents", "hints", "mints", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "stats", "seats", "heats", "hents", "hints", "pints", "pinas", "vinas",
       "vinal", "final"},
      {"start", "stars", "stats", "seats", "meats", "meads", "mends", "minds", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "stats", "seats", "meats", "melts", "milts", "mints", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "stats", "seats", "sexts", "sexes", "sixes", "sines", "vines", "vinas",
       "vinal", "final"},
      {"start", "stars", "stats", "seats", "teats", "tents", "tints", "mints", "minas", "vinas",
       "vinal", "final"},
      {"start", "stars", "stats", "seats", "teats", "tents", "tints", "pints", "pinas", "vinas",
       "vinal", "final"},
      {"start", "stars", "stats", "seats", "teats", "tents", "tints", "tines", "vines", "vinas",
       "vinal", "final"},
  };
  REQUIRE(GetSolutions("start", "final", lexicon) == solutions);
}
