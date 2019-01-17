#include <iostream>

#include "../../include/localize.hpp"

// Languages
#include "../../include/bg.hpp"
#include "../../include/en.hpp"

using namespace std;

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
