#ifndef FANWIDGET_H
#define FANWIDGET_H

#include <QWidget>

namespace Ui {
class FanWidget;
}

class FanWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FanWidget(QWidget *parent = nullptr);
    ~FanWidget();

signals:
    void fan_ctrl(bool flag);
private slots:
    void on_pushButton_return_clicked();

    void on_pushButton_on_clicked();

private:
    Ui::FanWidget *ui;
};

#endif // FANWIDGET_H
