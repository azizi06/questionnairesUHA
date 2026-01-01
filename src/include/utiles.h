#ifndef UTILES_H
#define UTILES_H


#include <string>
#include <algorithm>
#include <cctype>
#include <vector>



namespace util {



    std::string make_lower(std::string& str);
    std::vector<std::string> trim(std::string& phrase, char sep);

}


#endif // UTILES_H
