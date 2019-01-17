#ifndef HANGMAN_DICTIONARY_HPP

#define HANGMAN_DICTIONARY_HPP

#include <vector>

class Dictionary {
  public:
    void initialize(std::string t_fileName);
    std::string getRandomWord() { return m_currentWord; }

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
