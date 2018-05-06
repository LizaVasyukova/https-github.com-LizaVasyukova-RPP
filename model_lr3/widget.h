#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QAbstractTableModel>
#include <QVariant>
#include <QVector>
#include <QDebug>
using std :: vector;

namespace Ui {
class Widget;
}

struct MyData
{
    QString surname;
    QString phone;
    QString group;
    QString institute;
};

class myTableModel : public QAbstractTableModel
{
    QVector <MyData> vec;


public:
        myTableModel (QVector <MyData> vect)
        {
            vec = vect;
        }
private:
        int rowCount(const QModelIndex &parent) const;
        int columnCount(const QModelIndex &parent) const;
        QVariant data(const QModelIndex &index, int role) const;
        QVariant headerData(int section, Qt::Orientation orientation, int role) const;
};

class Widget : public QWidget
{
    Q_OBJECT

    QVector <MyData> vec;

    void show_table(QVector <MyData> vec);
    void add();
    void del();

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();



private slots:
    void on_upload_clicked(bool checked);

    void on_save_clicked(bool checked);

    void on_delete_2_clicked(bool checked);

    void on_add_clicked(bool checked);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
