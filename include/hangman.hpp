#ifndef HANGMAN_HANGMAN_HPP

#define HANGMAN_HANGMAN_HPP

#include "./localize.hpp"
#include "./dictionary.hpp"
#include "./word.hpp"

class Hangman {
  public:
    Hangman(std::string t_fileName);
    void play();
    void setAllowedAttempts(int t_allowedAttempts) { m_allowedAttempts = t_allowedAttempts; }
    void setLanguage(int t_languageId);
    int getAllowedAttempts() const { return m_allowedAttempts; }
    int getAttempts() const { return m_attempts; }
    bool getIsFinished() const { return m_isFinished; }
    bool getIsWon() const { return m_isWon; }
    Localize& getLocale() { return m_Locale; }
    Dictionary& getDictionary() { return m_Dictionary; }
    Word& getWord() { return m_Word; }

  private:
    void setIsFinished(bool t_isFinished) { m_isFinished = t_isFinished; }
    void setIsWon(bool t_isWon) { m_isWon = t_isWon; }
    void printGameScreen();
    void clearScreen();
    void correctGuess(char t_letter);
    void failAttempt();
    void printEndGame();

    int                         m_attempts          { 0 };
    int                         m_allowedAttempts   { 7 };
    bool                        m_isFinished        { false };
    bool                        m_isWon             { false };
    std::string                 m_fileName          { "" };
    char                        m_userInput;
    Localize                    m_Locale;
    Dictionary                  m_Dictionary;
    Word                        m_Word;
};

#endif // HANGMAN_HANGMAN_HPP
