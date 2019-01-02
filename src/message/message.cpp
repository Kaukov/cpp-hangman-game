#include <iostream>
#include <string>
#include <vector>

#include "message.hpp"

using namespace std;

Message::Message() {
  language = 0;
}

Message::Message(int language) {
  language = language;
}

void Message::displayMessage(string message) {
  cout << message << endl;
}

void Message::displayRules(vector<string> rules) {
  for (const string & rule : rules) {
    displayMessage(rule);
  }
}
