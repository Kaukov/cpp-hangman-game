#include <iostream>

#include "../../include/language.hpp"

using namespace std;

Language::Language() { }

void Language::displayRules() {
  for (string rule : m_gameRules) {
    displayMessage(rule);
  }
}
