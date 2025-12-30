#ifndef QUESTIONNAIREITERATOR_H
#define QUESTIONNAIREITERATOR_H

#include"question.h"
#include"questionnaire.h"
class questionnaireIterator
{
    public:
        questionnaireIterator(const questionnaire& quest);
        virtual ~questionnaireIterator();
        const question* next();
        bool hasNext();
    private:
        int d_current;
        const questionnaire& d_questionnaire;


};

/*questionnaireIterator qit{questionnaire};
while (qit.hasNext())
{
    const question* = qit.getNext()
}
**/



#endif 
