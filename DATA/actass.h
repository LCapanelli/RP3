#ifndef ACTASS_H
#define ACTASS_H
#include <qdjango/QDjangoModel.h>
#include <QObject>
#include <QDateTime>

class ActAss : public QDjangoModel{
    Q_OBJECT
    Q_PROPERTY (qint32 idAt READ idAt WRITE setIdAt)
            Q_PROPERTY (qint32 idIntakeFK READ idIntakeFK WRITE setIdIntakeFK)
            Q_PROPERTY (QString prescr READ prescr WRITE setPrescr)
            Q_PROPERTY (QString apraz READ apraz WRITE setApraz)
            Q_CLASSINFO("idAt", "primary_key=true auto_increment=true")
public:
            explicit ActAss(QObject *parent = 0);
    qint32 idAt() const;
    qint32 idIntakeFK() const;
    QString prescr() const;
    QString apraz() const;

    void setIdAt(const qint32 & idAt);
    void setIdIntakeFK(const qint32 & idIntakeFK);
    void setPrescr(const QString & prescr);
    void setApraz(const QString & apraz);

private:
    qint32 m_idAt;
    qint32 m_idIntakeFK;
    QString m_prescr;
    QString m_apraz;

public slots:
    void setExamplesOfActivitiesAndApraz();
};

#endif // ACTASS_H
