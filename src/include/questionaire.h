#ifndef QUESTIONAIRE_H
#define QUESTIONAIRE_H

#define DEBUTQUESTION '{'
#define FINQUESTION '}'
#define DEBUTTEXT '['
#define FINTEXT ']'
#define QT 'QT' // question texte
#define QN 'QN' // question numérique
#define QC 'QC' // question choix multiple
#define SEPARATEUR ','
#include "question.h"
#include<vector>
#include<memory>
#include<string>
class questionaire
{
    public:
        questionaire();
        virtual ~questionaire();
        std::string titre() const;
        void add(std::unique_ptr<question> question);
        const question getQuestionNumero(int i)const;
        int taille() const;
    private:
        std::string d_titre;
        std::vector<std::unique_ptr<question>> d_questions;
};

#endif // QUESTIONAIRE_H
