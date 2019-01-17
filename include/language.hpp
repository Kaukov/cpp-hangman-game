#ifndef HANGMAN_LANGUAGE_HPP

#define HANGMAN_LANGUAGE_HPP

#include <string>
#include <vector>

class Language {
  public:
    Language();
    void displayMessage(std::string t_message) { std::cout << t_message << std::endl; }
    void displayWelcomeMessage() { displayMessage(m_welcomeMessage); }
    void displayRules();

  protected:
    std::string                 m_welcomeMessage;
    std::vector<std::string>    m_gameRules;
    std::string                 m_yourWordMessage;
    std::string                 m_remainingAttemptsMessage;
    std::string                 m_enterGuessMessage;
    std::string                 m_pressEnterMessage;
};

#endif // HANGMAN_LANGUAGE_HPP
