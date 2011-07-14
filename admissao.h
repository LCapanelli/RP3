#ifndef ADMISSAO_H
#define ADMISSAO_H
#include <qdjango/QDjangoModel.h>
#include <QObject>
#include <QDateTime>

class Admissao : public QDjangoModel{
    Q_OBJECT
    Q_PROPERTY (qint32 idIntake READ idIntake WRITE setIdIntake)
            Q_PROPERTY (qint32 prontPK READ prontPK WRITE setProntPK)
            Q_PROPERTY (QString patNameFK READ patNameFK WRITE setPatNameFK)
            Q_PROPERTY (QString Fis READ Fis WRITE setFis)
            Q_PROPERTY (QString anam READ anam WRITE setAnam)
            Q_PROPERTY (bool hasFinished READ hasFinished WRITE setHasFinished)
            Q_PROPERTY (bool hasStarted READ hasStarted WRITE setHasStarted)
            Q_CLASSINFO("idIntake", "primary_key=true auto_increment=true")

public:
            explicit Admissao(QObject *parent = 0);
        qint32 idIntake() const;
        qint32 prontPK() const;
        QString patNameFK() const;
        QString Fis() const;
        QString anam() const;
        bool hasFinished() const;
        bool hasStarted() const;

        void setIdIntake(const qint32 & idIntake);
        void setProntPK(const qint32 & prontPK);
        void setPatNameFK(const QString & patNameFK);
        void setFis(const QString & Fis);
        void setAnam(const QString & anam);
        void setHasFinished(const bool & hasFinished);
        void setHasStarted(const bool & hasStarted);

private:
        qint32 m_idIntake;
        qint32 m_prontPK;
        QString m_patNameFK;
        QString m_Fis;
        QString m_anam;
        bool m_hasFinished;
        bool m_hasStarted;

};

#endif // ADMISSAO_H
