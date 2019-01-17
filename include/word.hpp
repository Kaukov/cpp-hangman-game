#ifndef HANGMAN_WORD_HPP

#define HANGMAN_WORD_HPP

class Word {
  public:
    void setWord(std::string t_word);
    void setCorrectGuess(char t_letter);
    bool isCharContained(char t_letter);
    bool isAllowedChar(char t_symbol);
    std::string getFullWord() { return m_currentWord; }
    std::string getPlaceholder() { return m_placeholder; }

  private:
    void setPlaceholder();
    void updatePlaceholder(int t_index, char t_letter);

    std::string                   m_currentWord;
    std::string                   m_placeholder;
};

#endif // HANGMAN_WORD_HPP
