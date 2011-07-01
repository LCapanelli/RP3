#ifndef INTERVENCAO_H
#define INTERVENCAO_H
#include <QObject>
#include <qdjango/QDjangoModel.h>

class Intervencao : public QDjangoModel{
    Q_OBJECT
    Q_PROPERTY (qint32 idInter READ idInter WRITE setIdInter)
            Q_PROPERTY (qint32 idDiagFK READ idDiagFK WRITE setIdDiagFK)
            Q_PROPERTY (QString interName READ interName WRITE setInterName)
            Q_CLASSINFO("idInter", "primary_key=true auto_increment=true")

public:
            explicit Intervencao(QObject *parent = 0);
    qint32 idInter() const;
    qint32 idDiagFK() const;
    QString interName() const;

    void setIdInter(const qint32 & idInter);
    void setIdDiagFK(const qint32 & idDiagFK);
    void setInterName(const QString & interName);

private:
    qint32 m_idInter;
    qint32 m_idDiagFK;
    QString m_interName;
};

#endif // INTERVENCAO_H
