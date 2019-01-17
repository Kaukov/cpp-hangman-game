#ifndef HANGMAN_DICTIONARY_HPP

#define HANGMAN_DICTIONARY_HPP

#include <vector>

#include "./word.hpp"

class Dictionary {
  public:
    void initialize(std::string t_fileName);
    std::string pickRandomWord();

  private:
    void fillDictionary();
    std::string wordToLower(std::string word);

    std::string                   m_fileName;
    std::vector<std::string>      m_words;
};

#endif // HANGMAN_DICTIONARY_HPP
