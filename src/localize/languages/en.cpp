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

  m_yourWordMessage = "Your word: ";

  m_remainingAttemptsMessage = "Remaining attempts: ";

  m_enterGuessMessage = "Enter a letter: ";

  m_pressEnterMessage = "Press Enter to continue...";
}
