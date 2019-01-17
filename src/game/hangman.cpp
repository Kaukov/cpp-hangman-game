#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <locale>

#include "../../include/hangman.hpp"
#include "../../include/localize.hpp"
#include "../../include/language.hpp"
#include "../../include/dictionary.hpp"
#include "../../include/word.hpp"

#ifdef __unix__
#define CLEAR_CMD "clear"
#elif defined(_WIN32) || defined(_WIN64)
#define CLEAR_CMD "cls"
#endif

using namespace std;

Hangman::Hangman(string t_fileName) {
  m_Locale = Localize();
  m_Dictionary = Dictionary();

  getDictionary().setFileName(t_fileName);
}

void Hangman::printGameScreen() {
  cout << getLocale().getLanguage().getYourWordMessage() << m_placeholder << endl;
  cout << endl;
  cout << getLocale().getLanguage().getRemainingAttemptsMessage() << m_allowedAttempts - m_attempts << endl;
  cout << getLocale().getLanguage().getEnterGuessMessage();
}

void Hangman::play() {
  string testInput;

  m_currentWord = getDictionary().getRandomWord();

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

    if (!getDictionary().isAllowedChar(m_userInput)) {
      // clearScreen();

      // cout << "That character is not allowed!" << endl;
      // cout << "Press Enter to return to the game" << endl;

      // cin.get();

      // clearScreen();
      continue;
    } else if (getDictionary().isCharContained(m_userInput)) {
      correctGuess(m_userInput);
    } else {
      failAttempt();
    }

    cout << endl;
    cout << "--------------------" << endl;
    cout << endl;

    // clearScreen();
  }
}

void Hangman::correctGuess(char t_letter) {
  getDictionary().fillCorrectGuess(t_letter);

  if (getDictionary().isWordComplete()) {
    m_isFinished = true;
  }
}

void Hangman::setAllowedAttempts(int t_allowedAttempts) {
  m_allowedAttempts = t_allowedAttempts;
}

void Hangman::setLanguage(int t_languageId) {
  getLocale().setLanguage(t_languageId);
}

void Hangman::setIsFinished(bool t_isFinished) {
  m_isFinished = t_isFinished;
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
