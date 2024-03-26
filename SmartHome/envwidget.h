#ifndef ENVWIDGET_H
#define ENVWIDGET_H

#include <QWidget>

namespace Ui {
class Envwidget;
}

class Envwidget : public QWidget
{
    Q_OBJECT

public:
    explicit Envwidget(QWidget *parent = nullptr);
    ~Envwidget();

private slots:
    void on_pushButton_clicked();
    void showTemHumData(double tem, double hum);
    void showLightData(double light);

private:
    Ui::Envwidget *ui;
};

#endif // ENVWIDGET_H
