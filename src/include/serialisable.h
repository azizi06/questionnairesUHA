#ifndef SERIALISABLE_H
#define SERIALISABLE_H
#include"questionaireSerialisateur.h"

class serialisable
{
    public:
        serialisable();
        virtual ~serialisable(questionaireSerialisateur* qs);
        virtual void ecrire()=0;
}

#endif // SERIALISABLE_H
