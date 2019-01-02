#include <iostream>
#include <string>

#include "main.hpp"
#include "game/hangman.hpp"
#include "message/message.hpp"

using namespace std;

int main() {
  Message hello;
  string helloWorld = "Hello World!";
  vector<string> rules = {
    "First rule: This is the most important rule!",
    "Second rule: Follow the path",
    "Third rule: Forget abour rule one and two!",
    "Fourth rule: HAVE FUN!"
  };

  hello.displayMessage(helloWorld);
  hello.displayRules(rules);

  return 0;
}
