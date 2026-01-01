#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H
#include<iostream>
#include <memory>
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
        inline static const std::string DATAREP = "../data";

    private:
        void affmenu();
        std::unique_ptr<strategieEvaluation>  choisireStrategie();
        std::unique_ptr<questionnaire>  questionnaireParDefault();
        std::unique_ptr<questionnaire>  choisirquestionnaire();
        std::vector<std::string> listeQuestionnair();

        affichage ecran;
        std::istream &d_ist;
        std::ostream &d_ost;
};

#endif // GESTIONNAIRE_H
