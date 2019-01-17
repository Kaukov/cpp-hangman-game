#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <locale>

#include "../../include/hangman.hpp"
#include "../../include/language.hpp"

#ifdef __unix__
#define CLEAR_CMD "clear"
#elif defined(_WIN32) || defined(_WIN64)
#define CLEAR_CMD "cls"
#endif

using namespace std;

const string WELCOME_MESSAGE =  "Welcome to Hangman!";
const vector<string> GAME_RULES = {
  "1. Have fun!",
  "2. Complete the game :)"
};

Hangman::Hangman() {
  m_fileName = "words.txt";
  m_Locale = Localize();
}

Hangman::Hangman(string t_fileName) {
  m_fileName = t_fileName;
  m_Locale = Localize();
}

void Hangman::initialize() {
  fillWords();

  m_currentWord = getRandomWord();

  setPlaceholder();
}

void Hangman::run() {
  initialize();

  playGame();
}

void Hangman::printGameScreen() {
  cout << "Your word:" << endl;
  cout << m_placeholder << endl;
  cout << endl;
  cout << "Remaining attempts: " << m_allowedAttempts - m_attempts << endl;
  cout << "Enter a guess: ";
}

void Hangman::playGame() {
  string testInput;

  clearScreen();

  // Language -> print welcome message + rules
  // printWelcome();
  // printRules();

  cout << "Press Enter to continue...";

  cin.get();

  clearScreen();

  int i = 0;

  while (!getIsFinished()) {
    clearScreen();

    printGameScreen();

    cin >> testInput;

    if (testInput.length() != 1) {
      cout << "This is not allowed!";
    } else {
      const char *validInput = testInput.c_str();

      m_userInput = *validInput;
    }

    if (!isAllowedChar(m_userInput)) {
      // clearScreen();

      // cout << "That character is not allowed!" << endl;
      // cout << "Press Enter to return to the game" << endl;

      // cin.get();

      // clearScreen();
      continue;
    } else if (isCharContained(m_userInput)) {
      correctGuess(m_userInput);
    } else {
      failAttempt();
    }
  }
}

bool Hangman::isCharContained(char t_letter) {
  return m_currentWord.find(t_letter) != string::npos;
}

bool Hangman::getIsFinished() const {
  return m_isFinished;
}

void Hangman::correctGuess(char t_letter) {
  for (int i = 0; i < m_currentWord.length(); i++) {
    if (m_currentWord[i] == t_letter) {
      m_placeholder[i] = t_letter;
    }
  }

  if (m_placeholder == m_currentWord) {
    m_isFinished = true;
  }
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
  m_Locale.setLanguage(t_languageId);
}

void Hangman::setIsFinished(bool t_isFinished) {
  m_isFinished = t_isFinished;
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
    if(!word.empty()) {
      m_words.push_back(wordToLower(word));
    }
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

bool Hangman::isAllowedChar(char t_symbol) {
  return t_symbol >= 'a' && t_symbol <= 'z';
}

void Hangman::setPlaceholder() {
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

void Hangman::clearScreen() {
  system(CLEAR_CMD);
}

void Hangman::failAttempt() {
  m_attempts++;

  if (m_attempts == m_allowedAttempts) {
    m_isFinished = true;
  }
}
