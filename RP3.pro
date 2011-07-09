#-------------------------------------------------
#
# Project created by QtCreator 2011-05-06T01:50:20
#
#-------------------------------------------------

QT       += core gui sql

TARGET = RP3
TEMPLATE = app

LIBS += -lqdjango

SOURCES += main.cpp \
    DATA/admissao.cpp \
    DATA/diagnostico.cpp \
    DATA/evolucao.cpp \
    DATA/intervencao.cpp \
    DATA/paciente.cpp \
    DATA/usuario.cpp \
    DATA/datamodel.cpp \
    mainwindow.cpp \
    GUI/reports.cpp \
    GUI/intake.cpp \
    GUI/discharged.cpp \
    GUI/maintenance.cpp \
    GUI/patient.cpp \
    GUI/escorting.cpp \
    GUI/explorer.cpp \
    DATA/model_diagnostable.cpp \
    DATA/diagass.cpp \
    DATA/actass.cpp \
    DATA/dom.cpp

HEADERS  += \
    diagnostico.h \
    evolucao.h \
    intervencao.h \
    paciente.h \
    usuario.h \
    admissao.h \
    DATA/datamodel.h \
    mainwindow.h \
    GUI/reports.h \
    GUI/intake.h \
    GUI/discharged.h \
    GUI/maintenance.h \
    GUI/patient.h \
    GUI/escorting.h \
    GUI/explorer.h \
    DATA/diagnostableview.h \
    DATA/model_diagnostable.h \
    DATA/diagass.h \
    DATA/actass.h \
    DATA/dom.h

FORMS    += \
    GUI/PrincipalForm.ui \
    GUI/001_LogIn.ui \
    GUI/reports.ui \
    GUI/intake.ui \
    GUI/discharged.ui \
    GUI/maintenance.ui \
    GUI/patient.ui \
    GUI/escorting.ui \
    GUI/explorer.ui

#DBUSER sae sae0192

OTHER_FILES += \

RESOURCES +=
