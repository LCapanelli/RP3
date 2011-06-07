#-------------------------------------------------
#
# Project created by QtCreator 2011-05-06T01:50:20
#
#-------------------------------------------------

QT       += core gui

TARGET = RP3
TEMPLATE = app


SOURCES += main.cpp \
    DATA/admissao.cpp \
    DATA/classed.cpp \
    DATA/classeinterv.cpp \
    DATA/diagnostico.cpp \
    DATA/dominiod.cpp \
    DATA/dominiointerv.cpp \
    DATA/evolucao.cpp \
    DATA/histenf.cpp \
    DATA/internacao.cpp \
    DATA/intervencao.cpp \
    DATA/paciente.cpp \
    DATA/resultesp.cpp \
    DATA/usuario.cpp

HEADERS  += \
    classed.h \
    classeinterv.h \
    diagnostico.h \
    dominiod.h \
    dominiointerv.h \
    evolucao.h \
    histenf.h \
    intervencao.h \
    paciente.h \
    resultesp.h \
    usuario.h \
    internacao.h \
    admissao.h

FORMS    += \
    GUI/PrincipalForm.ui \
    GUI/001_LogIn.ui
