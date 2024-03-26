#ifndef VIBRATORWIDGET_H
#define VIBRATORWIDGET_H

#include <QWidget>

namespace Ui {
class VibratorWidget;
}

class VibratorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit VibratorWidget(QWidget *parent = nullptr);
    ~VibratorWidget();

signals:
    void vibrator_ctrl(bool flag);
private slots:
    void on_pushButton_return_clicked();

    void on_pushButton_on_clicked();

private:
    Ui::VibratorWidget *ui;
};

#endif // VIBRATORWIDGET_H
