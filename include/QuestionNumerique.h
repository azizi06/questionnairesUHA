#ifndef QUESTIONNUMERIQUE_H
#define QUESTIONNUMERIQUE_H

#include "Question.h"
#include <string>

class QuestionNumerique : public Question {
private:
    int reponse;
    int minVal;
    int maxVal;

public:
    QuestionNumerique(const std::string& intitule,
                      const std::string& texte,
                      int reponse,
                      int minVal,
                      int maxVal);

    bool estBonneReponse(const std::string& r) const override;
    std::string getReponseCorrecte() const override;
};

#endif
