#ifndef HANGMAN_HANGMAN_HPP

#define HANGMAN_HANGMAN_HPP

#include <vector>
#include "./localize.hpp"

class Hangman {
  public:
    Hangman();
    Hangman(std::string t_fileName);
    void setAllowedAttempts(int t_allowedAttempts);
    void setLanguage(int t_languageId);
    void run();
    int getAllowedAttempts() const;
    int getAttempts() const;
    bool getIsFinished() const;
    std::string getPlaceholder();
    Localize getLocale();

  private:
    void setIsFinished(bool t_isFinished);
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

    int                         m_attempts          { 0 };
    int                         m_allowedAttempts   { 7 };
    bool                        m_isFinished        { false };
    std::string                 m_currentWord       { "" };
    std::string                 m_placeholder       { "" };
    std::string                 m_fileName          { "" };
    char                        m_userInput;
    std::vector<std::string>    m_words;
    Localize                    m_Locale;
};

#endif // HANGMAN_HANGMAN_HPP
