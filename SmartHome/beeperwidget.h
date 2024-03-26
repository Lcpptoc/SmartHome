#ifndef BEEPERWIDGET_H
#define BEEPERWIDGET_H

#include <QWidget>

namespace Ui {
class BeeperWidget;
}

class BeeperWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BeeperWidget(QWidget *parent = nullptr);
    ~BeeperWidget();

signals:
    void sendBeeper(bool flag);

private slots:
    void on_pushButton_on_clicked();

    void on_pushButton_return_clicked();

private:
    Ui::BeeperWidget *ui;
};

#endif // BEEPERWIDGET_H
