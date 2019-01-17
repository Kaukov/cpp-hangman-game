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
  cout << getLocale().getLanguage().getYourWordMessage() << m_placeholder << endl;
  cout << endl;
  cout << getLocale().getLanguage().getRemainingAttemptsMessage() << m_allowedAttempts - m_attempts << endl;
  cout << getLocale().getLanguage().getEnterGuessMessage();
}

void Hangman::playGame() {
  string testInput;

  getLocale().getLanguage().displayWelcomeMessage();

  getLocale().getLanguage().displayRules();

  cout << endl;

  // cout << getLocale().getLanguage().getPressEnterMessage();

  // cin.get();

  // clearScreen();

  while (!getIsFinished()) {
    // clearScreen();

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

    if (!getIsFinished()) {
      clearScreen();
    } else {
      printEndGame();
    }
  }
}

bool Hangman::isCharContained(char t_letter) {
  return m_currentWord.find(t_letter) != string::npos;
}

void Hangman::correctGuess(char t_letter) {
  for (int i = 0; i < m_currentWord.length(); i++) {
    if (m_currentWord[i] == t_letter) {
      m_placeholder[i] = t_letter;
    }
  }

  if (m_placeholder == m_currentWord) {
    setIsFinished(true);
    setIsWon(true);
  }
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
    setIsFinished(true);
    setIsWon(false);
  }
}

void Hangman::printEndGame() {
  string playerStatus = m_attempts == m_allowedAttempts ? "lost" : "won";

  cout << "Game Over!" << endl;
  cout << "You " << playerStatus << "!" << endl;

  if (!getIsWon()) {
    cout << "Your word was: " << m_currentWord << endl;
  } else {
    cout << "It took you " << m_allowedAttempts - m_attempts << " attempts" << endl;
  }

  cout << endl;
}
