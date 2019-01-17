#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <locale>

#include "../../include/dictionary.hpp"

using namespace std;

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

  cout << "WORD: " << m_words[index] << endl;

  m_currentWord = m_words[index];
}
