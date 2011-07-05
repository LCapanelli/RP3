#ifndef DIAGASS_H
#define DIAGASS_H
#include <qdjango/QDjangoModel.h>
#include <QObject>
#include <QDateTime>

class DiagAss : public QDjangoModel{
    Q_OBJECT
            Q_PROPERTY (qint32 idDiagAss READ idDiagAss WRITE setIdDiagAss)
            Q_PROPERTY (QString patientNameIntakeFK READ patientNameIntakeFK WRITE setPatientNameIntakeFK)
            Q_PROPERTY (QDateTime dHour READ dHour WRITE setDhour)
            Q_PROPERTY (QString diagAssNAME READ diagAssNAME WRITE setDiagAssNAME)
            Q_CLASSINFO("idDiagAss", "primary_key=true auto_increment=true")

public:
            explicit DiagAss(QObject *parent = 0);
            qint32 idDiagAss() const;
            QString patientNameIntakeFK() const;
            QDateTime dHour() const;
            QString diagAssNAME() const;

            void setIdDiagAss(const qint32 & idDiagAss);
            void setPatientNameIntakeFK(const QString & patientNameIntakeFK);
            void setDhour(const QDateTime & dHour);
            void setDiagAssNAME(const QString & diagAssNAME);

private:
            qint32 m_idDiagAss;
            QString m_patientNameIntakeFK;
            QDateTime m_dHour;
            QString m_diagAssNAME;
};

#endif // DIAGASS_H
