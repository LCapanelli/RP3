#ifndef DIAGASS_H
#define DIAGASS_H
#include <qdjango/QDjangoModel.h>
#include <QObject>
#include <QDateTime>

class DiagAss : public QDjangoModel{
    Q_OBJECT
            Q_PROPERTY (qint32 idDiagAss READ idDiagAss WRITE setIdDiagAss)
            Q_PROPERTY (QString idIntakeFK READ idIntakeFK WRITE setIdIntakeFK)
            Q_PROPERTY (QDateTime dHour READ dHour WRITE setDhour)
            Q_PROPERTY (QString diagAssNAME READ diagAssNAME WRITE setDiagAssNAME)
            Q_CLASSINFO("idDiagAss", "primary_key=true auto_increment=true")

public:
            explicit DiagAss(QObject *parent = 0);
            qint32 idDiagAss() const;
            QString idIntakeFK() const;
            QDateTime dHour() const;
            QString diagAssNAME() const;

            void setIdDiagAss(const qint32 & idDiagAss);
            void setIdIntakeFK(const QString & idIntakeFK);
            void setDhour(const QDateTime & dHour);
            void setDiagAssNAME(const QString & diagAssNAME);

private:
            qint32 m_idDiagAss;
            QString m_idIntakeFK;
            QDateTime m_dHour;
            QString m_diagAssNAME;
};

#endif // DIAGASS_H
