#include <iostream>
#include <string>

#include "../include/main.hpp"
#include "../include/hangman.hpp"

using namespace std;

int main() {
  // TODO
  // Handle repeated answers (wrong and right)
  // Localize
  Hangman Game("words.txt");

  getLanguage();

  Game.setLanguage(m_languageId);

  Game.play();

  return 0;
}

void getLanguage() {
  cout << "Enter your desired language / Изберете предпочитан език" << endl;
  cout << "1 - English; 2 - Български" << endl;
  cout << "1 / 2 : ";
  cin >> m_languageId;
}
