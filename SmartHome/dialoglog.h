#ifndef DIALOGLOG_H
#define DIALOGLOG_H

#include <QDialog>
#include "dialogregister.h"
#include <QTcpSocket>

namespace Ui {
class DialogLog;
}

class DialogLog : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLog(QWidget *parent = nullptr);
    ~DialogLog();

signals:
    void showWidget();

private slots:
    void on_pushButton_log_clicked();

    void on_pushButton_register_clicked();

    void on_pushButton_clicked();

private:
    Ui::DialogLog *ui;

    DialogRegister *diaRegister;

    //键盘
    KeyBoard *m_keyBoard;

    QTcpSocket *log_Sock;

};

#endif // DIALOGLOG_H
