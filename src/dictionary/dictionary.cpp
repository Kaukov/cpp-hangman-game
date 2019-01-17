#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <locale>

#include "../../include/dictionary.hpp"

using namespace std;

Dictionary::Dictionary() { }

void Dictionary::initialize(string t_fileName) {
  m_fileName = t_fileName;

  fillDictionary();
  pickRandomWord();
}

void Dictionary::fillDictionary() {
  ifstream file;
  string word;

  file.open(m_fileName);

  if (!file) {
    cout << "Unable to open file: " << m_fileName << endl;
    exit(1);
  }

  while(getline(file, word)) {
    if(!word.empty()) {
      m_words.push_back(wordToLower(word));
    }
  }

  file.close();
}

string Dictionary::wordToLower(string word) {
  locale loc;
  string wordToLower;

  for (string::size_type i = 0; i < word.length(); i++) {
    wordToLower += tolower(word[i], loc);
  }

  return wordToLower;
}

void Dictionary::pickRandomWord() {
  srand(time(nullptr));

  int index = rand() % m_words.size() + 1;

  m_currentWord = m_words[index];

  setPlaceholder();
}

bool Dictionary::isAllowedChar(char t_symbol) {
  return t_symbol >= 'a' && t_symbol <= 'z';
}

void Dictionary::setPlaceholder() {
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

void Dictionary::setCorrectGuess(char t_letter) {
  for (int i = 0; i < m_currentWord.length(); i++) {
    if (m_currentWord[i] == t_letter) {
      m_placeholder[i] = t_letter;
    }
  }
}

bool Dictionary::isCharContained(char t_letter) {
  return m_currentWord.find(t_letter) != string::npos;
}
