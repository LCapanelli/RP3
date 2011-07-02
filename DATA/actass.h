#ifndef ACTASS_H
#define ACTASS_H
#include <qdjango/QDjangoModel.h>
#include <QObject>
#include <QDateTime>

class ActAss : public QDjangoModel{
    Q_OBJECT
    Q_PROPERTY (qint32 idAt READ idAt WRITE setIdAt)
            Q_PROPERTY (qint32 idIntakeFK READ idIntakeFK WRITE setIdIntakeFK)
            Q_PROPERTY (QString intervNameFK READ intervNameFK WRITE setIntervNameFK)
            Q_PROPERTY (QString atList READ atList WRITE setAtList)
            Q_PROPERTY (QString apraz READ apraz WRITE setApraz)
            Q_CLASSINFO("idAt", "primary_key=true auto_increment=true")
public:
            explicit ActAss(QObject *parent = 0);
    qint32 idAt() const;
    qint32 idIntakeFK() const;
    QString intervNameFK() const;
    QString atList() const;
    QString apraz() const;

    void setIdAt(const qint32 & idAt);
    void setIdIntakeFK(const qint32 & idIntakeFK);
    void setIntervNameFK(const QString & intervNameFK);
    void setAtList(const QString & atList);
    void setApraz(const QString & apraz);

private:
    qint32 m_idAt;
    qint32 m_idIntakeFK;
    QString m_intervNameFK;
    QString m_atList;
    QString m_apraz;
};

#endif // ACTASS_H
