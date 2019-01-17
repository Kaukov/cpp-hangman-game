#ifndef HANGMAN_DICTIONARY_HPP

#define HANGMAN_DICTIONARY_HPP

#include <vector>

class Dictionary {
  public:
    Dictionary();
    void initialize(std::string t_fileName);
    void setCorrectGuess(char t_letter);
    bool isAllowedChar(char t_symbol);
    bool isCharContained(char t_letter);
    std::string getCurrentWord() { return m_currentWord; }
    std::string getPlaceholder() { return m_placeholder; }

  private:
    void fillDictionary();
    void setPlaceholder();
    void pickRandomWord();
    std::string wordToLower(std::string word);

    std::string                   m_fileName;
    std::string                   m_placeholder;
    std::string                   m_currentWord;
    std::vector<std::string>      m_words;
};

#endif // HANGMAN_DICTIONARY_HPP
