#include "../include/utiles.h"
#include<iostream>
namespace util {




    std::string make_lower(std::string& str) {
        std::string lows = "";
        for (char& c : str) {
            char lower_char = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
            c = lower_char;  
            lows += lower_char;  
        }
        return lows;  
    }

    std::vector<std::string> trim(std::string& phrase, char sep) {
        std::vector<std::string> resultat;
        if (phrase.empty()) {
            return resultat;
        }
        int debut = 0;
        int fin = 0;
        while (debut < phrase.size()) {
            fin = phrase.find(sep, debut);
            std::string element;
            if (fin == std::string::npos) {
                element = phrase.substr(debut);
            } else {
                element = phrase.substr(debut, fin - debut);
            }
            resultat.push_back(element);
            if (fin == std::string::npos) {
                break;
            }
            debut = fin + 1;
        }
        return resultat;
    }
}
