#ifndef QUESTIONAIRIEITERATOR_H
#define QUESTIONAIRIEITERATOR_H

#include"question.h"
#include"questionnaire.h"
class questionairIeIterator
{
    public:
        questionairIeIterator(const questionnaire& quest);
        virtual ~questionairIeIterator();
        const question* next();
        bool hasNext();



    protected:

    private:
        int d_current;
        const questionnaire& d_questionnaire;


};

/*questionairIeIterator qit{questionnaire};
while (qit.hasNext())
{
    std::uniq_ptr<question> question = qit.getNext()

}
**/



#endif // QUESTIONAIRIEITERATOR_H
