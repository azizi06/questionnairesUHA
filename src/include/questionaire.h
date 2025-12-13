#ifndef QUESTIONAIRE_H
#define QUESTIONAIRE_H

#define DEBUTQUESTION '{'
#define FINQUESTION '}'
#define DEBUTTEXT '['
#define FINTEXT ']'
#define QT 'QT' // question texte
#define QN 'QN' // question numérique
#define QC 'QC' // question choix multiple
#define SEPARATEUR ','

class questionaire
{
    public:
        questionaire();
        virtual ~questionaire();

    protected:

    private:
};

#endif // QUESTIONAIRE_H
