#ifndef DIALOGREGISTER_H
#define DIALOGREGISTER_H

#include <QDialog>
#include "fsmpKeyboard/keyboard.h"
#include <QTcpSocket>

namespace Ui {
class DialogRegister;
}

class DialogRegister : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRegister(QWidget *parent = nullptr);
    ~DialogRegister();

    bool isUsernameAlreadyExists(const char *newUsername, FILE *file);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_registre_clicked();

private:
    Ui::DialogRegister *ui;

    //键盘
    KeyBoard *keyBoard;

    QTcpSocket *register_Sock;
};

#endif // DIALOGREGISTER_H
