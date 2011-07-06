#ifndef INTERVENCAO_H
#define INTERVENCAO_H
#include <QObject>
#include <qdjango/QDjangoModel.h>

class Intervencao : public QDjangoModel{
    Q_OBJECT
    Q_PROPERTY (qint32 idInter READ idInter WRITE setIdInter)
            Q_PROPERTY (QString idDiagFK READ idDiagFK WRITE setIdDiagFK)
            Q_PROPERTY (qint32 idDiagIFK READ idDiagIFK WRITE setIdDiagIFK)
            Q_PROPERTY (QString interName READ interName WRITE setInterName)
            Q_CLASSINFO("idInter", "primary_key=true auto_increment=true")

public:
            explicit Intervencao(QObject *parent = 0);
    qint32 idInter() const;
    QString idDiagFK() const;
    qint32 idDiagIFK() const;
    QString interName() const;

    void setIdInter(const qint32 & idInter);
    void setIdDiagFK(const QString & idDiagFK);
    void setIdDiagIFK(const qint32 & idDiagIFK);
    void setInterName(const QString & interName);

private:
    qint32 m_idInter;
    QString m_idDiagFK;
    qint32 m_idDiagIFK;
    QString m_interName;

public slots:
    void setExamplesOfInterventions();
};

#endif // INTERVENCAO_H
