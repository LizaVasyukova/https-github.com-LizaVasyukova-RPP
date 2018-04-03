#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTableWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
QTableWidget *tableWidget = new QTableWidget(1, 4, this);

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
