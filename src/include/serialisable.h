#ifndef SERIALISABLE_H
#define SERIALISABLE_H
#include"questionnaireSerialisateur.h"

class serialisable
{
    public:
        serialisable();
        virtual ~serialisable();
        virtual void ecrire(questionnaireSerialisateur* qs)=0;
};

#endif // SERIALISABLE_H
