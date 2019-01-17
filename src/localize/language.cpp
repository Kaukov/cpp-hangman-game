#include <iostream>

#include "../../include/language.hpp"

using namespace std;

Language::Language() { }

void Language::displayRules() {
  for (const string rule : m_gameRules) {
    displayMessage(rule);
  }
}
