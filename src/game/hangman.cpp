#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <locale>

#include "../../include/hangman.hpp"

using namespace std;

Hangman::Hangman() {
  m_fileName = "words.txt";

  initialize();
}

Hangman::Hangman(string t_fileName) {
  m_fileName = t_fileName;

  initialize();
}

void Hangman::initialize() {
  vector<string> gameRules = {
    "1. Have fun!",
    "2. Complete the game!"
  };

  string welcomeMessage = "Welcome to Hangman!";

  setWelcomeMessage(welcomeMessage);
  setGameRules(gameRules);

  printWelcome();
  printRules();

  fillWords();

  m_currentWord = getRandomWord();
}

bool Hangman::getIsFinished() const {
  return m_isFinished;
}

void Hangman::setAllowedAttempts(int t_allowedAttempts) {
  m_allowedAttempts = t_allowedAttempts;
}

int Hangman::getAllowedAttempts() const {
  return m_allowedAttempts;
}

int Hangman::getAttempts() const {
  return m_attempts;
}

void Hangman::setLanguage(int t_languageId) {
  m_languageId = t_languageId;
}

int Hangman::getLanguage() const {
  return m_languageId;
}

void Hangman::printWelcome() const {
  cout << m_welcomeMessage << endl;
}

void Hangman::printRules() const {
  for (const string & rule : m_gameRules) {
    cout << rule << endl;
  }
}

void Hangman::setIsFinished(bool t_isFinished) {
  m_isFinished = t_isFinished;
}

void Hangman::setWelcomeMessage(string t_welcomeMessage) {
  m_welcomeMessage = t_welcomeMessage;
}

void Hangman::setGameRules(vector<string> t_gameRules) {
  m_gameRules = t_gameRules;
}

void Hangman::fillWords() {
  ifstream file;
  string word;

  file.open(m_fileName);

  if (!file) {
    cout << "Unable to open file: " << m_fileName << endl;
    exit(1);
  }

  while(getline(file, word)) {
    m_words.push_back(wordToLower(word));
  }

  file.close();
}

string Hangman::getRandomWord() const {
  srand(time(nullptr));

  int index = rand() % m_words.size() + 1;

  return m_words[index];
}

string Hangman::wordToLower(string word) {
  locale loc;
  string wordToLower;

  for (string::size_type i = 0; i < word.length(); i++) {
    wordToLower += tolower(word[i], loc);
  }

  return wordToLower;
}
