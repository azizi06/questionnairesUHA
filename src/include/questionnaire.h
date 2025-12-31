#ifndef QUESTIONNAIRE_H
#define QUESTIONNAIRE_H

#define DEBUTQUESTION '{'
#define FINQUESTION '}'
#define DEBUTTEXT '['
#define FINTEXT ']'
#define QT 1 // question texte
#define QN 2 // question numérique
#define QC 3 // question choix multiple
#define SEPARATEUR ','

#include "question.h"
#include<vector>
#include<memory>
#include<string>
class questionnaire
{
    public:
        questionnaire();
        std::string titre() const;
        void setTitre(const std::string& titre);
        void add(std::unique_ptr<question> question);
        const question* getQuestionNumero(int i) const;
        int taille() const;
    private:
        std::string d_titre;
        std::vector<std::unique_ptr<question>> d_questions;
};

#endif
