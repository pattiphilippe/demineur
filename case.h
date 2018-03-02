#ifndef CASE_H
#define CASE_H

/*
    Test git versionning sur pc portable...

    blablabla modifs
*/

/*
10: analyse
40: model et console
50: remise graphique 20 et examen 30
*/

enum CaseState{
    dft,
    marked,
    revealed,
    lol //TODO à retirer
};

class Case{
private:
    int indice;
    int line;
    int column;
    CaseState state;

public:
    Case(line, column);

};

#endif // CASE_H
