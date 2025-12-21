#include "../include/questionnaire.h"

questionnaire::questionnaire():d_titre{},d_questions{}
{}

std::string questionnaire::titre() const{
    return d_titre;
}

void questionnaire::setTitre(const std::string& titre){
    d_titre = titre;
}

void questionnaire::add(std::unique_ptr<question> question){
    d_questions.push_back(std::move(question));
}

const question* questionnaire::getQuestionNumero(int i)const{
    return d_questions[i].get();
}

int questionnaire::taille() const{
    return d_questions.size();
}
