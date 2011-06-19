#ifndef PACIENTE_H
#define PACIENTE_H
#include <QString>
#include <QDate>

class Paciente
{
public:
    Paciente();

private:
        QString nomePac, enderecoPac, dataNascPac, RG, sexo, proveniencia, procedencia, estadoCivil, profissao, alergia, crenca, tipoSang, observacoesPac, raca;
        QString telefoneRPac, telefoneCPac, telefoneCellPac;
        int prontuario;
        int idade;

};

#endif // PACIENTE_H
