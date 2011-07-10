#ifndef EVOLUCAO_H
#define EVOLUCAO_H
#include "diagnostico.h"
#include <QDateTime>
#include <QObject>
#include <qdjango/QDjangoModel.h>

class Evolucao : public QDjangoModel
{
    Q_OBJECT
            Q_PROPERTY (qint32 idEvDiag READ idEvDiag WRITE setIdEvDiag)
            Q_PROPERTY (qint32 idIntake READ idIntake WRITE setIdIntake)
            Q_PROPERTY (QString diagName READ diagName WRITE setDiagName)
            Q_PROPERTY (QString state READ state WRITE setState)
            Q_PROPERTY (QDateTime hourD READ hourD WRITE setHourD)
            Q_CLASSINFO("idEvDiag", "primary_key=true auto_increment=true")


public:
            explicit Evolucao(QObject *parent = 0);
            qint32 idEvDiag() const;
            qint32 idIntake() const;
            QString diagName() const;
            QString state() const;
            QDateTime hourD() const;

            void setIdEvDiag(const qint32 & idEvDiag);
            void setIdIntake(const qint32 & idIntake);
            void setDiagName(const QString & diagName);
            void setState(const QString & state);
            void setHourD(const QDateTime & hourD);

private:
            qint32 m_idEvDiag;
            qint32 m_idIntake;
            QString m_diagName;
            QString m_state;
            QDateTime m_hourD;

};

#endif // EVOLUCAO_H
