#ifndef QUESTIONCHOIXMULTIPLE_H
#define QUESTIONCHOIXMULTIPLE_H

#include "question.h"
#include <vector>
#include <string>

class questionChoixMultiple : public question {
private:
    std::vector<std::string> d_options;
    int d_bonneReponse;

public:
    questionChoixMultiple(const std::string& intitule,const std::string& texte,const std::vector<std::string>& options,int correct);

    bool estBonneReponse(const std::string& reponse) const override;
    std::string getReponseCorrecte() const override;
};

#endif
