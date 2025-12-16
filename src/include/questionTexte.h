#ifndef QUESTIONTEXTE_H
#define QUESTIONTEXTE_H

#include "question.h"
#include <string>

class questionTexte : public question {
private:
    std::string d_reponse;
public:
    questionTexte(const std::string& intitule,const std::string& texte,const std::string& reponse);
    bool estBonneReponse(const std::string& reponse) const override;
    std::string getReponseCorrecte() const override;
};
#endif
