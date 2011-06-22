#ifndef EXPLORER_H
#define EXPLORER_H

#include <QWidget>

namespace Ui {
    class Explorer;
}

class Explorer : public QWidget
{
    Q_OBJECT

public:
    explicit Explorer(QWidget *parent = 0);
    ~Explorer();


private:
    Ui::Explorer *ui;

public slots:
        void listUpdate();
};

#endif // EXPLORER_H
