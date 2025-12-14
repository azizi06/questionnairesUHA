#include "QuestionNumerique.h"
#include <stdexcept>

QuestionNumerique::QuestionNumerique(const std::string& i,
                                     const std::string& t,
                                     int r,
                                     int minV,
                                     int maxV)
    : Question(i, t), reponse(r), minVal(minV), maxVal(maxV) {}

bool QuestionNumerique::estBonneReponse(const std::string& r) const {
    try {
        int val = std::stoi(r);
        return (val == reponse && val >= minVal && val <= maxVal);
    } catch (...) {
        return false;
    }
}

std::string QuestionNumerique::getReponseCorrecte() const {
    return std::to_string(reponse);
}
