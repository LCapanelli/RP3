#ifndef DIAGASS_H
#define DIAGASS_H
#include <qdjango/QDjangoModel.h>
#include <QObject>
#include <QDateTime>

class DiagAss : public QDjangoModel{
    Q_OBJECT
            Q_PROPERTY (qint32 idDiagAss READ idDiagAss WRITE setIdDiagAss)
            Q_PROPERTY (qint32 idIntakeFK READ idIntakeFK WRITE setIdIntakeFK)
            Q_PROPERTY (QDateTime dHour READ dHour WRITE setDhour)
            Q_CLASSINFO("idDiagAss", "primary_key=true auto_increment=true")

public:
            explicit DiagAss(QObject *parent = 0);
            qint32 idDiagAss() const;
            qint32 idIntakeFK() const;
            QDateTime dHour() const;

            void setIdDiagAss(const qint32 & idDiagAss);
            void setIdIntakeFK(const qint32 & idIntakeFK);
            void setDhour(const QDateTime & dHour);

private:
            qint32 m_idDiagAss;
            qint32 m_idIntakeFK;
            QDateTime m_dHour;
};

#endif // DIAGASS_H
