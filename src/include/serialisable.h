#ifndef SERIALISABLE_H
#define SERIALISABLE_H
#include"questionnaireSerialisateur.h"

class serialisable
{
    public:
        serialisable();
        virtual ~serialisable(questionnaireSerialisateur* qs);
        virtual void ecrire()=0;
}

#endif // SERIALISABLE_H
