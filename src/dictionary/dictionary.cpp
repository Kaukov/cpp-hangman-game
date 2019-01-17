#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "../../include/dictionary.hpp"

using namespace std;

Dictionary::Dictionary() {
  //
}

void Dictionary::setFileName(string t_fileName) {
  m_fileName = t_fileName;

  fillWords();
}

string Dictionary::wordToLower(string t_word) {
  locale loc;
  string wordToLower;

  for (string::size_type i = 0; i < t_word.length(); i++) {
    wordToLower += tolower(t_word[i], loc);
  }

  return wordToLower;
}

bool Dictionary::isAllowedChar(char t_symbol) {
  return t_symbol >= 'a' && t_symbol <= 'z';
}

bool Dictionary::isCharContained(char t_letter) {
  return m_currentWord.find(t_letter) != string::npos;
}

string Dictionary::getRandomWord() {
  srand(time(nullptr));

  cout << "Words: " << m_words.size() << endl;
  return "-----";

  int index = rand() % m_words.size() + 1;

  return m_words[index];
}

void Dictionary::fillCorrectGuess(char t_letter) {
  for (int i = 0; i < m_currentWord.length(); i++) {
    if (m_currentWord[i] == t_letter) {
      m_placeholder[i] = t_letter;
    }
  }
}

void Dictionary::fillWords() {
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
