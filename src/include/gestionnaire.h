#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H
#include<iostream>
#include"../include/affichage.h"
#include"../include/affichageInterface.h"
#include"../include/strategieEvaluation.h"
#include "../include/questionnaire.h"

class gestionnaire
{
    public:
        gestionnaire(std::istream &ist=std::cin,std::ostream &ost=std::cout);
        virtual ~gestionnaire()=default;
        void excuter();

    private:
        std::string entrer();
        void affmenu();
        strategieEvaluation* choisireStrategie();
        questionnaire  questionnaireParDefault();
        affichage ecran;
        std::istream &d_ist;
        std::ostream &d_ost;
};

#endif // GESTIONNAIRE_H
