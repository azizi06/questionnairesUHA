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
}
