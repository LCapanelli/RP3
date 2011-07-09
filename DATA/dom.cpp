#include "dom.h"
#include "qdjango/QDjango.h"

Dom::Dom(QObject *parent) :
        QDjangoModel (parent)
{
}

qint32 Dom::idDom()const{
    return m_idDom;
}
void Dom::setIdDom(const qint32 &idDom){
    m_idDom = idDom;
}

QString Dom::nameDom()const{
    return m_nameDom;
}
void Dom::setNameDom(const QString &nameDom){
    m_nameDom = nameDom;
}
