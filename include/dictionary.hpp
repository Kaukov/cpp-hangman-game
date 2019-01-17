#ifndef HANGMAN_DICTIONARY_HPP

#define HANGMAN_DICTIONARY_HPP

class Dictionary {
  public:
    Dictionary();
    void setFileName(std::string t_fileName);
    void fillCorrectGuess(char t_letter);
    bool isAllowedChar(char t_symbol);
    bool isCharContained(char m_userInput);
    bool isWordComplete() { return m_placeholder == m_currentWord; }
    std::string getRandomWord();
    std::string getPlaceholder() { return m_placeholder; }

  private:
    void fillWords();
    void setPlaceholder();
    std::string wordToLower(std::string t_word);

    std::string                 m_fileName;
    std::string                 m_placeholder;
    std::string                 m_currentWord;
    std::vector<std::string>    m_words;
};

#endif // HANGMAN_DICTIONARY_HPP
