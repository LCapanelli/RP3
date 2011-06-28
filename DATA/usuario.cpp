#include "usuario.h"
#include <QString>
#include "qdjango/QDjango.h"
#include "qdjango/QDjangoQuerySet.h"

/**
Esta classe serve para criação dos usuários do sistema
e verificação de LogIn
  **/

Usuario::Usuario(QObject *parent):
        QDjangoModel(parent)
{
}

qint32 Usuario::idUser() const{
    return m_idUser;
}
void Usuario::setIdUser(const qint32 &idUser){
    m_idUser = idUser;
}

QString Usuario::username() const{
    return m_username;
}
void Usuario::setUsername(const QString &username){
    m_username = username;
}

QString Usuario::emailUser() const{
    return m_emailUser;
}
void Usuario::setEmailUser(const QString &emailUser){
    m_emailUser = emailUser;
}

QString Usuario::login() const{
    return m_login;
}
void Usuario::setLogin(const QString &login){
    m_login = login;
}

QString Usuario::passW() const{
    return m_passW;
}
void Usuario::setPassW(const QString &passW){
    m_passW = passW;
}

QString Usuario::streetUser() const{
    return m_streetUser;
}
void Usuario::setStreetUser(const QString &streetUser){
    m_streetUser = streetUser;
}

QString Usuario::streetNUser() const{
    return m_streetNUser;
}
void Usuario::setStreetNUser(const QString &streetNUser){
    m_streetNUser = streetNUser;
}

QString Usuario::cepUser() const{
    return m_cepUser;
}
void Usuario::setCepUser(const QString &cepUser){
    m_cepUser = cepUser;
}

QString Usuario::cityUser() const{
    return m_cityUser;
}
void Usuario::setCityUser(const QString &cityUser){
    m_cityUser = cityUser;
}

QString Usuario::ufUser() const{
    return m_ufUser;
}
void Usuario::setUfUser(const QString &ufUser){
    m_ufUser = ufUser;
}

QString Usuario::blockUser() const{
    return m_blockUser;
}
void Usuario::setBlockUser(const QString &blockUser){
    m_blockUser = blockUser;
}

QString Usuario::countryUser() const{
    return m_countryUser;
}
void Usuario::setCountryUser(const QString &countryUser){
    m_countryUser = countryUser;
}

int Usuario::uType() const{
    return m_uType;
}
void Usuario::setUtype(const int &uType){
    m_uType = uType;
}

QString Usuario::telResUser() const{
    return m_telResUser;
}
void Usuario::setTelResUser(const QString &telResUser){
    m_telResUser = telResUser;
}

QString Usuario::cellUser() const{
    return m_cellUser;
}
void Usuario::setCellUser(const QString &cellUser){
    m_cellUser = cellUser;
}

int Usuario::coren() const{
    return m_coren;
}
void Usuario::setCoren(const int &coren){
    m_coren = coren;
}

QDate Usuario::dBorn() const{
    return m_dBorn;
}
void Usuario::setDborn(const QDate &dBorn){
    m_dBorn = dBorn;
}
void Usuario::setUserExamples(){
    Usuario *u = new Usuario();
    u->setIdUser(1);
    u->setUsername("admin");
    u->setEmailUser("admin@adm.com");
    u->setLogin("admin");
    u->setPassW("admin");
    u->setStreetUser("Foo Street");
    u->setStreetNUser("555");
    u->setCepUser("55055");
    u->setCityUser("Townsville");
    u->setBlockUser("Foo square");
    u->setUfUser("OO");
    u->setCountryUser("QtLand");
    u->setUtype(1);
    u->setTelResUser("55979797");
    u->setCellUser("557878787");
    u->setCoren(837847384);
    QDate data = QDate::currentDate();
    u->setDborn(data);
    u->save();
}
