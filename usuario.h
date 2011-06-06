#ifndef USUARIO_H
#define USUARIO_H
#include <QString>
#include <QDate>

class Usuario{


public:
    Usuario();

private:
    QString nomeUser, emailUser, login, senha, enderecoUser, ;
    int tipoUser;
    QString telefoneResUser, telefoneComUser, telefoneCellUser;
    int coren;
    QDate dataNascUser;
};

#endif // USUARIO_H
