#include "../include/questionnaire.h"

questionnaire::questionnaire():d_titre{},d_questions{}
{}

std::string titre() const{
    return d_titre;
}

void setTitre(const std::string& titre){
    d_titre = titre;
}

void add(std::unique_ptr<question> question){
    d_questions(std::move(question));
}

const question* getQuestionNumero(int i)const{
    return d_qestions[i].get();
}

int taille() const{
    return d_questions.size();
}
