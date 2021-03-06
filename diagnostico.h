#ifndef DIAGNOSTICO_H
#define DIAGNOSTICO_H
#include <qdjango/QDjangoModel.h>
#include <QObject>

class Diagnostico : public QDjangoModel{
    Q_OBJECT
    Q_PROPERTY (qint32 idDiag READ idDiag WRITE setIdDiag)
            Q_PROPERTY (QString nomeDiag READ nomeDiag WRITE setNomeDiag)
            Q_PROPERTY (QString num01 READ num01 WRITE setNum01)
            Q_PROPERTY (QString num02 READ num02 WRITE setNum02)
            Q_PROPERTY (qint32 idDom READ idDom WRITE setIdDom)
            Q_PROPERTY (QString definicao READ definicao WRITE setDefinicao)
            Q_PROPERTY (QString cDefin READ cDefin WRITE setCDefin)
            Q_PROPERTY (QString fRelac READ fRelac WRITE setFRelac)
            Q_CLASSINFO("idDiag", "primary_key=true auto_increment=true")

public:
            explicit Diagnostico(QObject *parent = 0);
    qint32 idDiag() const;
    QString nomeDiag() const;
    QString num01() const;
    QString num02() const;
    qint32 idDom() const;
    QString definicao() const;
    QString cDefin() const;
    QString fRelac() const;

    void setIdDiag(const qint32 & idDiag);
    void setNomeDiag(const QString & nomeDiag);
    void setNum01(const QString & num01);
    void setNum02(const QString & num02);
    void setIdDom(const int & idDom);
    void setDefinicao(const QString & definicao);
    void setCDefin(const QString & cDefin);
    void setFRelac(const QString & fRelac);

private:
    qint32 m_idDiag;
    QString m_nomeDiag;
    QString m_num01;
    QString m_num02;
    qint32 m_idDom;
    QString m_definicao;
    QString m_cDefin;
    QString m_fRelac;

public slots:
    void updateViewDiag();
    void setExamples();
};

#endif // DIAGNOSTICO_H
