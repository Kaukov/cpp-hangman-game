#ifndef HANGMAN_HANGMAN_HPP

#define HANGMAN_HANGMAN_HPP

#include <vector>

class Hangman {
  public:
    Hangman();
    Hangman(std::string t_fileName);
    void printWelcome() const;
    void printRules() const;
    void setAllowedAttempts(int t_allowedAttempts);
    void setLanguage(int t_languageId);
    void run();
    int getAllowedAttempts() const;
    int getAttempts() const;
    int getLanguage() const;
    bool getIsFinished() const;
    std::string getPlaceholder();

  private:
    void setIsFinished(bool t_isFinished);
    void setWelcomeMessage(std::string t_welcomeMessage);
    void setGameRules(std::vector<std::string> t_gameRules);
    void fillWords();
    void initialize();
    void setPlaceholder();
    void printGameScreen();
    void playGame();
    void clearScreen();
    void correctGuess(char t_letter);
    void failAttempt();
    bool isAllowedChar(char t_symbol);
    bool isCharContained(char t_letter);
    std::string wordToLower(std::string t_word);
    std::string getRandomWord() const;

    int                         m_languageId        { 0 };
    int                         m_attempts          { 0 };
    int                         m_allowedAttempts   { 7 };
    bool                        m_isFinished        { false };
    std::string                 m_currentWord       { "" };
    std::string                 m_placeholder       { "" };
    std::string                 m_fileName          { "" };
    char                        m_userInput;
    std::string                 m_welcomeMessage;
    std::vector<std::string>    m_gameRules;
    std::vector<std::string>    m_words;
};

#endif // HANGMAN_HANGMAN_HPP
