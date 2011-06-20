#ifndef DIAGNOSTICO_H
#define DIAGNOSTICO_H
#include <qdjango/QDjangoModel.h>
#include <QObject>
#include "ui_mainwindow.h"

class Diagnostico : public QDjangoModel {
        Q_OBJECT
        Q_PROPERTY (qint32 idDiag READ idDiag WRITE setIdDiag)
        Q_PROPERTY (QString nomeDiag READ nomeDiag WRITE setNomeDiag)
        Q_PROPERTY (int num01 READ num01 WRITE setNum01)
        Q_PROPERTY (int num02 READ num02 WRITE setNum02)
        Q_PROPERTY (int idDom READ idDom WRITE setIdDom)
        Q_PROPERTY (int idClasse READ idClasse WRITE setIdClasse)
        Q_PROPERTY (QString definicao READ definicao WRITE setDefinicao)
        Q_PROPERTY (QString cDefin READ cDefin WRITE setCDefin)
        Q_PROPERTY (QString fRelac READ fRelac WRITE setFRelac)
        Q_CLASSINFO("idDiag", "primary_key=true auto_increment=true")

public:
        explicit Diagnostico(QObject *parent = 0);
        qint32 idDiag() const;
        QString nomeDiag() const;
        int num01() const;
        int num02() const;
        int idDom() const;
        int idClasse() const;
        QString definicao() const;
        QString cDefin() const;
        QString fRelac() const;

        void setIdDiag(const qint32 & idDiag);
        void setNomeDiag(const QString & nomeDiag);
        void setNum01(const int & num01);
        void setNum02(const int & num02);
        void setIdDom(const int & idDom);
        void setIdClasse(const int & idClasse);
        void setDefinicao(const QString & definicao);
        void setCDefin(const QString & cDefin);
        void setFRelac(const QString & fRelac);

private:
        qint32 m_idDiag;
        QString m_nomeDiag;
        int m_num01;
        int m_num02;
        int m_idDom;
        int m_idClasse;
        QString m_definicao;
        QString m_cDefin;
        QString m_fRelac;
        Ui::Form_Principal_QW ui;

private slots:
        void on_le_FiltroCadDiag_returnPressed();
        void on_pb_SalvarDiag_clicked();
        void updateViewDiag();
};

#endif // DIAGNOSTICO_H
