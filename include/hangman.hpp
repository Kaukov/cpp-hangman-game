#ifndef HANGMAN_HANGMAN_HPP

#define HANGMAN_HANGMAN_HPP

#include <vector>

class Hangman {
  public:
    Hangman();
    Hangman(std::string t_fileName);
    void printWelcome() const;
    void prinRules() const;
    void setAllowedAttempts(int t_allowedAttempts);
    void setLanguage(int t_languageId);
    int getAllowedAttempts() const;
    int getAttempts() const;
    int getLanguage() const;
    bool getIsFinished() const;
    std::string getPlaceholder();

  private:
    void setIsFinished(bool t_isFinished);
    void setWelcomeMessage(std::string t_welcomeMessage);
    void setGameRules(std::vector<std::string> t_gameRules);
    void getRandomWord() const;

    int                         m_languageId        { 0 };
    int                         m_attempts          { 0 };
    int                         m_allowedAttempts   { 7 };
    bool                        m_isFinished        { false };
    std::string                 m_currentWord       { "" };
    std::string                 m_placeholder       { "" };
    std::string                 m_fileName          { "" };
    std::string                 m_welcomeMessage;
    std::vector<std::string>    m_gameRules;
    // std::vector<std::string>    m_words;
};

#endif // HANGMAN_HANGMAN_HPP
