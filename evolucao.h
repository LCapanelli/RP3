#ifndef EVOLUCAO_H
#define EVOLUCAO_H
#include "diagnostico.h"
#include "resultesp.h"
#include "QDate"
#include "QString"

class Evolucao
{
public:
    Evolucao();
    Diagnostico g;

private:

QDate dateEvol;
QString obs;


};

#endif // EVOLUCAO_H
