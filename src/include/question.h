#ifndef QUESTION_H
<<<<<<< HEAD
#define ifndef QUESTION_H

class question{


};
#endif // QUESTION_H

=======
#define QUESTION_H

#include <string>

class question {
private:
    std::string d_intitule;
    std::string d_texte;

public:
    question(const std::string& intitule, const std::string& texte);
    virtual ~question() = default;
    std::string Intitule() const;
    std::string Texte() const;
    virtual bool estBonneReponse(const std::string& reponse) const =0;
    virtual std::string getReponseCorrecte() const =0;
};

#endif
>>>>>>> feature/classes-questions
