#include <iostream>

#include "../../include/word.hpp"

using namespace std;

void Word::setWord(string t_word) {
  m_currentWord = t_word;

  setPlaceholder();
}

void Word::setPlaceholder() {
  string placeholder;

  for (int i = 0; i < m_currentWord.length(); i++) {
    if (isAllowedChar(m_currentWord[i])) {
      placeholder += "*";
    } else {
      placeholder += m_currentWord[i];
    }
  }

  m_placeholder = placeholder;
}

bool Word::isAllowedChar(char t_symbol) {
  bool isAllowedEnglish = t_symbol >= 'a' && t_symbol <= 'z';
  // bool isAllowedBulgarian = t_symbol >= 'а' && t_symbol <= 'я'; // Needs implementation for CP1251

  return isAllowedEnglish;
}

void Word::updatePlaceholder(int t_index, char t_letter) {
  m_placeholder[t_index] = t_letter;
}

void Word::setCorrectGuess(char t_letter) {
  for (int i = 0; i < m_currentWord.length(); i++) {
    if (m_currentWord[i] == t_letter) {
      updatePlaceholder(i, t_letter);
    }
  }
}

bool Word::isCharContained(char t_letter) {
  return m_currentWord.find(t_letter) != string::npos;
}
