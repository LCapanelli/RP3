#ifndef DIAGNOSTICO_H
#define DIAGNOSTICO_H
#include "QString"
#include <qdjango/QDjangoModel.h>
#include <QObject>
//#include "ui_mainwindow.h"

class diagnostico : public QDjangoModel{
        Q_OBJECT
        //Q_PROPERTY(QString nomeDiag READ nomeDiag WRITE setNomeDiag)
        //Q_PROPERTY(int numDiag READ numDiag WRITE setNumDiag)

public:

    //QString dominio, classe, nomeDiag, fatRel, caracDefin, definicao;
    //int numDiag, numTax1, numTax2;

private:

private slots:


};

#endif // DIAGNOSTICO_H
