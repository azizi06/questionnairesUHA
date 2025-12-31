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
    questionChoixMultiple(const std::string& intitule,const std::vector<std::string>& options,int correct);
    std::vector<std::string> options();
    std::string Intitule() const override;
    bool estBonneReponse(const std::string& reponse) const override;
    std::string getReponseCorrecte() const override;
};

#endif
