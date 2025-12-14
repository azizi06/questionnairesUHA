#ifndef QUESTIONCHOIXMULTIPLE_H
#define QUESTIONCHOIXMULTIPLE_H

#include "Question.h"
#include <vector>
#include <string>

class QuestionChoixMultiple : public Question {
private:
    std::vector<std::string> options;
    int bonneReponse;

public:
    QuestionChoixMultiple(const std::string& intitule,
                          const std::string& texte,
                          const std::vector<std::string>& opts,
                          int correct);

    bool estBonneReponse(const std::string& r) const override;
    std::string getReponseCorrecte() const override;
};

#endif
