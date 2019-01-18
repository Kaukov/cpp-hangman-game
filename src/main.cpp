#include <iostream>

#include "../include/main.hpp"
#include "../include/hangman.hpp"

using namespace std;

int main() {
  // TODO
  // Handle repeated answers (wrong and right)
  // getLanguage();

  string shortLang = m_languageId == 2 ? "bg" : "en";

  Hangman Game("words_en.txt"); // + shortLang + ".txt");

  Game.setLanguage(1); // Default to English

  Game.play();

  return 0;
}

void getLanguage() {
  cout << "Enter your desired language / Изберете предпочитан език" << endl;
  cout << "1 - English; 2 - Български" << endl;
  cout << "1 / 2 : ";
  cin >> m_languageId;
}
