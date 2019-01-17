#ifndef HANGMAN_LOCALIZE_HPP

#define HANGMAN_LOCALIZE_HPP

#include "./language.hpp"

class Localize {
  public:
    Localize();
    void setLanguage(int t_languageId);
    Language getLanguage();

  private:
    Language m_Language;
};

#endif // HANGMAN_LOCALIZE_HPP
