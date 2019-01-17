#include <iostream>
#include <string>
#include <vector>

#include "../../../include/language.hpp"
#include "../../../include/en.hpp"

using namespace std;

English::English() {
  m_gameRules = {
    "First rule: ...",
    "Second rule: ...",
    "Third rule: ..."
  };

  m_welcomeMessage = "Welcome to Hangman!";
}
