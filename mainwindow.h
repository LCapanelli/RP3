#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ui_PrincipalForm.h"
#include "ui_001_LogIn.h"
#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    //Ui::MainWindow *ui;
    Ui::Form_Principal_QW *ui;
};

#endif // MAINWINDOW_H
