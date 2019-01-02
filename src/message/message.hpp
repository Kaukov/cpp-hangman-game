#ifndef _Message_

#define _Message_

#include <iostream>
#include <string>
#include <vector>

class Message {
  private:
    int language;

  public:
    Message();
    Message(int language);
    void displayMessage(std::string message);
    void displayRules(std::vector<std::string> rules);
};

#endif // _Message_
