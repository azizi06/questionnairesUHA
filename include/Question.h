#ifndef QUESTION_H
#define QUESTION_H

#include <string>

class Question {
protected:
    std::string intitule;
    std::string texte;

public:
    Question(const std::string& intitule, const std::string& texte);
    virtual ~Question() = default;

    std::string getIntitule() const;
    std::string getTexte() const;


    virtual bool estBonneReponse(const std::string& reponse) const = 0;
    virtual std::string getReponseCorrecte() const = 0;
};

#endif
