#ifndef USUARIO_H
#define USUARIO_H
#include <qdjango/QDjangoModel.h>
#include <QObject>
#include <QDate>

class Usuario : public QDjangoModel{

    Q_OBJECT
    Q_PROPERTY (qint32 idUser READ idUser WRITE setIdUser)
    Q_PROPERTY (QString username READ username WRITE setUsername)
    Q_PROPERTY (QString emailUser READ emailUser WRITE setEmailUser)
    Q_PROPERTY (QString login READ login WRITE setLogin)
    Q_PROPERTY (QString passW READ passW WRITE setPassW)
    Q_PROPERTY (QString streetUser READ streetUser WRITE setStreetUser)
    Q_PROPERTY (QString streetNUser READ streetNUser WRITE setStreetNUser)
    Q_PROPERTY (QString cepUser READ cepUser WRITE setCepUser)
    Q_PROPERTY (QString cityUser READ cityUser WRITE setCityUser)
    Q_PROPERTY (QString ufUser READ ufUser WRITE setUfUser)
    Q_PROPERTY (QString blockUser READ blockUser WRITE setBlockUser)
    Q_PROPERTY (QString countryUser READ countryUser WRITE setCountryUser)
    Q_PROPERTY (int uType READ uType WRITE setUtype)
    Q_PROPERTY (QString telResUser READ telResUser WRITE setTelResUser)
    Q_PROPERTY (QString cellUser READ cellUser WRITE setCellUser)
    Q_PROPERTY (int coren  READ coren WRITE setCoren)
    Q_PROPERTY (QDate dBorn READ dBorn WRITE setDborn)
    Q_CLASSINFO("idUser", "primary_key=true auto_increment=true")

public:
    explicit Usuario(QObject *parent = 0);
    qint32 idUser() const;
    QString username() const;
    QString emailUser() const;
    QString login() const;
    QString passW() const;
    QString streetUser() const;
    QString streetNUser() const;
    QString cepUser() const;
    QString cityUser() const;
    QString ufUser() const;
    QString blockUser() const;
    QString countryUser() const;
    int  uType() const;
    QString telResUser() const;
    QString cellUser() const;
    int coren() const;
    QDate dBorn() const;

    void setIdUser(const qint32 & idUser);
    void setUsername(const QString & username);
    void setEmailUser(const QString & emailUser);
    void setLogin(const QString & login);
    void setPassW(const QString & passW);
    void setStreetUser(const QString & streetUser);
    void setStreetNUser(const QString & streetNUser);
    void setCepUser(const QString & cepUser);
    void setCityUser(const QString & cityUser);
    void setUfUser(const QString & ufUser);
    void setBlockUser(const QString & blockUser);
    void setCountryUser(const QString & countryUser);
    void setUtype(const int & uType);
    void setTelResUser(const QString & telResUser);
    void setCellUser(const QString & cellUser);
    void setCoren(const int & coren);
    void setDborn(const QDate & dBorn);

private:
    qint32 m_idUser;
    QString m_username;
    QString m_emailUser;
    QString m_login;
    QString m_passW;
    QString m_streetUser;
    QString m_streetNUser;
    QString m_cepUser;
    QString m_cityUser;
    QString m_ufUser;
    QString m_blockUser;
    QString m_countryUser;
    int  m_uType;
    QString m_telResUser;
    QString m_cellUser;
    int m_coren;
    QDate m_dBorn;

public slots:
    void setUserExamples();
};

#endif // USUARIO_H
