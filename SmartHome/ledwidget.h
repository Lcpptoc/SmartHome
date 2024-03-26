#ifndef LEDWIDGET_H
#define LEDWIDGET_H

#include <QWidget>

namespace Ui {
class LedWidget;
}

class LedWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LedWidget(QWidget *parent = nullptr);
    ~LedWidget();

signals:
    void led_locl(bool flag,int id);
    void showWidget();

private slots:
    void on_pushButton_return_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::LedWidget *ui;
};

#endif // LEDWIDGET_H
