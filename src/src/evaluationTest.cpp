#include "evaluationTest.h"


evaluationTest::evaluationTest()
    : nombreQuestions(0), indiceCourant(0)
{
}

/*
 Initialisation :
 on démarre à la première question
*/
void evaluationTest::init(int nQuestions) {
    nombreQuestions = nQuestions;
    indiceCourant = 0;
}

/*
 Il reste des questions tant que
 on n'a pas tout parcouru
*/
bool evaluationTest::aDesQuestions() const {
    return indiceCourant < nombreQuestions;
}

/*
 Retourne l'indice de la question suivante
 (dans l'ordre)
*/
int evaluationTest::questionSuivante() {
    return indiceCourant++;
}

/*
 La stratégie test ne fait rien
 après une réponse
*/
void evaluationTest::soumettreReponse(int, bool) {
    // rien à faire
}


bool evaluationTest::peutAfficherCorrection(int) const {
    return false;
}
