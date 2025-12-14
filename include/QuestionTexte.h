#ifndef QUESTIONTEXTE_H
#define QUESTIONTEXTE_H

#include "Question.h"
#include <string>

class QuestionTexte : public Question {
private:
    std::string reponse;

public:
    QuestionTexte(const std::string& intitule,
                  const std::string& texte,
                  const std::string& reponse);

    bool estBonneReponse(const std::string& r) const override;
    std::string getReponseCorrecte() const override;
};

#endif
