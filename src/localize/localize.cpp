#include <iostream>
#include <string>
#include <vector>

#include "../../include/localize.hpp"

// Languages
#include "../../include/bg.hpp"
#include "../../include/en.hpp"

using namespace std;

Localize::Localize () { }

void Localize::setLanguage(int t_languageId) {
  switch (t_languageId) {
    case 1:
      m_Language = English();
      break;

    case 2:
      m_Language = Bulgarian();
      break;

    default:
      m_Language = English();
      break;
  }
}

Language Localize::getLanguage() {
  return m_Language;
}
