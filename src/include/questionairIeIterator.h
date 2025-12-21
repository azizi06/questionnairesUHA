#ifndef QUESTIONAIRIEITERATOR_H
#define QUESTIONAIRIEITERATOR_H

#include"question.h"
#include"questionaire.h"
class questionairIeIterator
{
    public:
        questionairIeIterator(const questionaire& quest);
        virtual ~questionairIeIterator();
        const question* next();
        bool hasNext();



    protected:

    private:
        int d_current;
        const questionaire& d_questionaire;


};

/*questionairIeIterator qit{questionaire};
while (qit.hasNext())
{
    std::uniq_ptr<question> question = qit.getNext()

}
**/



#endif // QUESTIONAIRIEITERATOR_H
