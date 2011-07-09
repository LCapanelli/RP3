#ifndef PACIENTE_H
#define PACIENTE_H
#include <QDate>
#include <qdjango/QDjangoModel.h>
#include <QObject>

class Paciente : public QDjangoModel{
    Q_OBJECT
    Q_PROPERTY (qint32 pront READ pront WRITE setPront)
            Q_PROPERTY (QString nameP READ nameP WRITE setNameP)
            Q_PROPERTY (QString jobP READ jobP WRITE setJobP)
            Q_PROPERTY (QString proced READ proced WRITE setProced)
            Q_PROPERTY (QString rg READ rg WRITE setRg)
            Q_PROPERTY (QString proven READ proven WRITE setProven)
            Q_PROPERTY (int sex READ sex WRITE setSex)
            Q_PROPERTY (int blood READ blood WRITE setBlood)
            Q_PROPERTY (QDate dBornP READ dBornP WRITE setDbornP)
            Q_PROPERTY (QString ethn READ ethn WRITE setEthn)
            Q_PROPERTY (QString relig READ relig WRITE setRelig)
            Q_PROPERTY (int civilS READ civilS WRITE setCivilS)
            Q_PROPERTY (QString mailP READ mailP WRITE setMailP)
            Q_PROPERTY (QString telR READ telR WRITE setTelR)
            Q_PROPERTY (QString telC READ telC WRITE setTelC)
            Q_PROPERTY (QString cellP READ cellP WRITE setCellP)
            Q_PROPERTY (QString alerg READ alerg WRITE setAlerg)
            Q_PROPERTY (QString obsP READ obsP WRITE setObsP)
            Q_CLASSINFO("pront", "primary_key=true auto_increment=true")

public:
            explicit Paciente(QObject *parent = 0);
            qint32 pront() const;
            QString nameP() const;
            QString jobP() const;
            QString proced() const;
            QString rg() const;
            QString proven() const;
            int sex() const;
            int blood() const;
            QDate dBornP() const;
            QString ethn() const;
            QString relig() const;
            int civilS() const;
            QString mailP() const;
            QString telR() const;
            QString telC() const;
            QString cellP() const;
            QString alerg() const;
            QString obsP() const;

            void setPront(const qint32 & pront);
            void setNameP(const QString & nameP);
            void setJobP(const QString & jobP);
            void setProced(const QString & proced);
            void setRg(const QString & rg);
            void setProven(const QString & proven);
            void setSex(const int & sex);
            void setBlood(const int & blood);
            void setDbornP(const QDate & dBornP);
            void setEthn(const QString & ethn);
            void setRelig(const QString & relig);
            void setCivilS(const int & civilS);
            void setMailP(const QString & mailP);
            void setTelR(const QString & telR);
            void setTelC(const QString & telC);
            void setCellP(const QString & cellP);
            void setAlerg(const QString & alerg);
            void setObsP(const QString & obsP);


private:
            qint32 m_pront;
            QString m_nameP;
            QString m_jobP;
            QString m_proced;
            QString m_rg;
            QString m_proven;
            int m_sex;
            int m_blood;
            QDate m_dBornP;
            QString m_ethn;
            QString m_relig;
            int m_civilS;
            QString m_mailP;
            QString m_telR;
            QString m_telC;
            QString m_cellP;
            QString m_alerg;
            QString m_obsP;

        public slots:
            void setPatExamples();
};

#endif // PACIENTE_H
