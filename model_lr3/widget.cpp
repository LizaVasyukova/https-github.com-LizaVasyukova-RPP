#include "widget.h"
#include "ui_widget.h"
#include <QAbstractTableModel>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QVariant>
#include <QFileDialog>
using std :: iterator;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

int myTableModel::rowCount(const QModelIndex &parent) const
{
    return vec.size();
}

int myTableModel::columnCount(const QModelIndex &parent) const
{
    return 4;
}

QVariant myTableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (index.column() == 0)
        {
            QString answer = vec[index.row()].surname;
            return QVariant(answer);
        }
        if (index.column() == 1)
        {
            QString answer = vec[index.row()].phone;
            return QVariant(answer);
        }
        if (index.column() == 2)
        {
            QString answer = vec[index.row()].group;
            return QVariant(answer);
        }
        if (index.column() == 3)
        {
            QString answer = vec[index.row()].institute;
            return QVariant(answer);
        }
    }
    return QVariant();
}

QVariant myTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();
    if (orientation == Qt::Horizontal)
    {
        switch (section)
        {
        case 0:
            return QVariant(QString::fromUtf8("Фамилия"));
        case 1:
            return QVariant(QString::fromUtf8("Телефон"));
        case 2:
            return QVariant(QString::fromUtf8("Группа"));
        case 3:
            return QVariant(QString::fromUtf8("Институт"));
        default:
            return QVariant();
        }
    }
    return QVariant();
}

void Widget::show_table(QVector <MyData> vec)
{
    myTableModel *myModel = new myTableModel(vec);
    ui->tableView->setModel(myModel);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_upload_clicked(bool checked)
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Загрузить файл"), "",tr("Файлы (*.txt)"));
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly))
         {
             QTextStream fin (&file);
             while (!fin.atEnd())
             {
                 MyData new_el;
                 fin >> new_el.surname >> new_el.phone >> new_el.group >> new_el.institute;
                 vec.push_back(new_el);
             }
         }
         file.close();
         show_table(vec);
}

void Widget::on_save_clicked(bool checked)
{
    QFile file ("C:\\Users\\AcErA\\Desktop\\model_lr3\\result.txt");
    QTextStream fout (&file);
    QVector <MyData> :: iterator it;
    if (file.open(QIODevice::WriteOnly))
    {
        for (it = vec.begin(); it < vec.end(); it++)
        {
            fout << (*it).surname << " " << (*it).phone << " " << (*it).group << " " <<(*it).institute << " ";
        }
    }
    file.close();
}

void Widget::on_delete_2_clicked(bool checked)
{
    if (ui->tableView->currentIndex().row() >= 0)
    {
        vec.removeAt(ui->tableView->currentIndex().row());
    }
    show_table(vec);
}

void Widget::on_add_clicked(bool checked)
{
    MyData new_el;
    new_el.surname = ui->lineEdit->text();
    new_el.phone = ui->lineEdit_2->text();
    new_el.group = ui->lineEdit_3->text();
    new_el.institute = ui->comboBox->currentText();

    vec.push_back(new_el);
    show_table(vec);
}
