#ifndef HANGMAN_HANGMAN_HPP

#define HANGMAN_HANGMAN_HPP

// #include <iostream>
// #include <string>
#include <vector>

class Hangman {
  public:
    Hangman();
    Hangman(std::string t_fileName);
    std::string getPlaceholder();

    bool getIsFinished() const
    {
      return m_isFinished;
    }

    void setLanguage(int t_languageId)
    {
      m_language = t_languageId;
    }

    int getLanguage() const
    {
      return m_language;
    }

    void printWelcome();

    void prinRules() const
    {
      for (const std::string & rule : m_gameRules) {
        std::cout << rule << std::endl;
      }
    }

  private:
    void setIsFinished(bool t_isFinished)
    {
      m_isFinished = t_isFinished;
    }

    void setWelcomeMessage(std::string t_welcomeMessage)
    {
      m_welcomeMessage = t_welcomeMessage;
    }

    void setGameRules(std::vector<std::string> t_gameRules)
    {
      m_gameRules = t_gameRules;
    }

    int m_language { 0 };
    std::string m_placeholder { "" };
    bool m_isFinished { false };
    std::string m_welcomeMessage;
    std::vector<std::string> m_gameRules;
};

#endif // HANGMAN_HANGMAN_HPP
