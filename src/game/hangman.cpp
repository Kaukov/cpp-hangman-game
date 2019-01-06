#include <iostream>
#include <string>
#include <vector>

#include "../../include/hangman.hpp"

using namespace std;

Hangman::Hangman() {
  m_fileName = "../../words.txt";
}

Hangman::Hangman(string t_fileName) {
  m_fileName = t_fileName;
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

void Hangman::prinRules() const {
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
