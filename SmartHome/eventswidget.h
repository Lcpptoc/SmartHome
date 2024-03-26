#ifndef EVENTSWIDGET_H
#define EVENTSWIDGET_H

#include <QWidget>

namespace Ui {
class EventsWidget;
}

class EventsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EventsWidget(QWidget *parent = nullptr);
    ~EventsWidget();

private slots:
    void peopleData(bool detected);

    void on_pushButton_return_clicked();

private:
    Ui::EventsWidget *ui;
};

#endif // EVENTSWIDGET_H
