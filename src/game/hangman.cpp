#include <iostream>

#include "../../include/hangman.hpp"

#ifdef __unix__
#define CLEAR_CMD "clear"
#elif defined(_WIN32) || defined(_WIN64)
#define CLEAR_CMD "cls"
#endif

using namespace std;

Hangman::Hangman(string t_fileName) {
  m_fileName = t_fileName;
}

void Hangman::setLanguage(int t_languageId) {
  getLocale().setLanguage(t_languageId);
}

void Hangman::printGameScreen() {
  cout << getLocale().getLanguage().getYourWordMessage() << getWord().getPlaceholder() << endl;
  cout << endl;
  cout << getLocale().getLanguage().getRemainingAttemptsMessage() << m_allowedAttempts - m_attempts << endl;
  cout << getLocale().getLanguage().getEnterGuessMessage();
}

void Hangman::play() {
  string testInput;

  clearScreen();

  getDictionary().initialize(m_fileName);

  getWord().setWord(getDictionary().pickRandomWord());

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

    if (!getWord().isAllowedChar(m_userInput)) {
      // clearScreen();

      // cout << "That character is not allowed!" << endl;
      // cout << "Press Enter to return to the game" << endl;

      // cin.get();

      // clearScreen();
      continue;
    } else if (getWord().isCharContained(m_userInput)) {
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

void Hangman::correctGuess(char t_letter) {
  getWord().setCorrectGuess(t_letter);

  if (getWord().getPlaceholder() == getWord().getFullWord()) {
    setIsFinished(true);
    setIsWon(true);
  }
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
    cout << "Your word was: " << getWord().getFullWord() << endl;
  } else {
    cout << "It took you " << m_attempts << " attempts" << endl;
  }

  cout << endl;
}
