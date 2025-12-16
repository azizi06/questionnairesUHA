#ifndef QUESTIONAIRIEITERATOR_H
#define QUESTIONAIRIEITERATOR_H

#include"question.h"
class questionairIeIterator
{
    public:
        questionairIeIterator(questionaire );
        virtual ~questionairIeIterator();
        const question& next();



    protected:

    private:
        int d_current;
        const questionaire& d_questionaire;
};

#endif // QUESTIONAIRIEITERATOR_H
