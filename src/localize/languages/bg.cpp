#include <iostream>
#include <string>
#include <vector>

#include "../../../include/language.hpp"
#include "../../../include/bg.hpp"

using namespace std;

Bulgarian::Bulgarian() {
  m_gameRules = {
    "Първо правило: ...",
    "Второ правило: ...",
    "Трето правило: ..."
  };

  m_welcomeMessage = "Добре дошли в играта бесеница!";
}
