#ifndef HANGMAN_LANGUAGE_HPP

#define HANGMAN_LANGUAGE_HPP

#include <string>
#include <vector>

class Language {
  public:
    Language();
    void setLanguage(int t_languageId);
    void displayRules() const;
    void displayMessage(std::string t_message);

  private:
    int                         m_languageId;
    std::string                 m_welcomeMessage;
    std::vector<std::string>    m_gameRules;
};

#endif // HANGMAN_LANGUAGE_HPP
