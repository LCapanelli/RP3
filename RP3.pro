#-------------------------------------------------
#
# Project created by QtCreator 2011-05-06T01:50:20
#
#-------------------------------------------------

QT       += core gui \
            sql

TARGET = RP3
TEMPLATE = app

LIBS += -lqdjango

SOURCES += main.cpp \
    DATA/admissao.cpp \
    DATA/diagnostico.cpp \
    DATA/evolucao.cpp \
    DATA/histenf.cpp \
    DATA/internacao.cpp \
    DATA/intervencao.cpp \
    DATA/paciente.cpp \
    DATA/resultesp.cpp \
    DATA/usuario.cpp \
    DATA/datamodel.cpp \
    mainwindow.cpp \
    GUI/reports.cpp

HEADERS  += \
    diagnostico.h \
    evolucao.h \
    histenf.h \
    intervencao.h \
    paciente.h \
    resultesp.h \
    usuario.h \
    internacao.h \
    admissao.h \
    DATA/datamodel.h \
    mainwindow.h \
    GUI/reports.h

FORMS    += \
    GUI/PrincipalForm.ui \
    GUI/001_LogIn.ui \
    #mainwindow.ui \
    GUI/reports.ui

#DBUSER sae sae0192

OTHER_FILES += \
