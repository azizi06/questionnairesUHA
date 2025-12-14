#include "QuestionChoixMultiple.h"
#include <stdexcept>

QuestionChoixMultiple::QuestionChoixMultiple(const std::string& i,
                                             const std::string& t,
                                             const std::vector<std::string>& opts,
                                             int correct)
    : Question(i, t), options(opts), bonneReponse(correct) {}

bool QuestionChoixMultiple::estBonneReponse(const std::string& r) const {
    try {
        int val = std::stoi(r);
        return val == bonneReponse;
    } catch (...) {
        return false;
    }
}

std::string QuestionChoixMultiple::getReponseCorrecte() const {
    return std::to_string(bonneReponse);
}
