#ifndef DOM_H
#define DOM_H
#include <qdjango/QDjangoModel.h>
#include <QObject>

class Dom : public QDjangoModel{
    Q_OBJECT
    Q_PROPERTY (qint32 idDom READ idDom WRITE setIdDom)
            Q_PROPERTY (QString nameDom READ nameDom WRITE setNameDom)
            Q_CLASSINFO("idDom", "primary_key=true auto_increment=true")
public:

    explicit Dom(QObject *parent = 0);
    qint32 idDom() const;
    QString nameDom() const;

    void setIdDom(const qint32 & idDom);
    void setNameDom(const QString & nameDom);

private:
    qint32 m_idDom;
    QString m_nameDom;

};

#endif // DOM_H
