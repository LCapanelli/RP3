#ifndef ADMISSAO_H
#define ADMISSAO_H
#include <qdjango/QDjangoModel.h>
#include <QObject>

class Admissao : public QDjangoModel{
    Q_OBJECT
    Q_PROPERTY (qint32 idIntake READ idIntake WRITE setIdIntake)
            Q_PROPERTY (qint32 prontFK READ prontFK WRITE setProntFK)
            Q_PROPERTY (QString patNameFK READ patNameFK WRITE setPatNameFK)
            Q_PROPERTY (QString Fis READ Fis WRITE setFis)
            Q_PROPERTY (QString anam READ anam WRITE setAnam)
            Q_PROPERTY (QString prescr READ prescr WRITE setPrescr)
            Q_CLASSINFO("idIntake", "primary_key=true auto_increment=true")

public:
            explicit Admissao(QObject *parent = 0);
        qint32 idIntake() const;
        qint32 prontFK() const;
        QString patNameFK() const;
        QString Fis() const;
        QString anam() const;
        QString prescr() const;

        void setIdIntake(const qint32 & idIntake);
        void setProntFK(const qint32 & prontFK);
        void setPatNameFK(const QString & patNameFK);
        void setFis(const QString & Fis);
        void setAnam(const QString & anam);
        void setPrescr(const QString & prescr);

private:
        qint32 m_idIntake;
        qint32 m_prontFK;
        QString m_patNameFK;
        QString m_Fis;
        QString m_anam;
        QString m_prescr;
};

#endif // ADMISSAO_H
