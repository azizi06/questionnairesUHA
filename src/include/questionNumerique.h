#ifndef QUESTIONNUMERIQUE_H
#define QUESTIONNUMERIQUE_H

#include "question.h"
#include <string>

class questionNumerique : public question {
private:
    int d_reponse;
    int d_valeurMin;
    int d_valeurMax;

public:
    questionNumerique(const std::string& intitule,int reponse,int valeurMin,int valeurMax);
    bool estBonneReponse(const std::string& reponse) const override;
    std::string getReponseCorrecte() const override;
};

#endif
