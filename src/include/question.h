#ifndef QUESTION_H
#define QUESTION_H

#include <string>

class question {
private:
    std::string d_intitule;


public:
    question(const std::string& intitule);
    virtual ~question() = default;
    std::string Intitule() const;
    virtual bool estBonneReponse(const std::string& reponse) const =0;
    virtual std::string getReponseCorrecte() const =0;
};

#endif

