#include "widget.h"
#include "ui_widget.h"
#include <QTableWidget>
#include <QFile>
#include <QTextStream>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->resize(450, 300);
    QStringList headers;
    headers << "ID" << "ФИО" << "Зарплата" << "Отдел";
    tableWidget->setHorizontalHeaderLabels(headers);
    tableWidget->resize(450,300);

     QFile file("C:\\Users\\AcErA\\Desktop\\table_lr2\\database.txt");

     if (file.open(QIODevice::ReadOnly))
     {
         QTextStream fin (&file);
         QChar s;
         fin >> s;
         int end = QString(s).toInt();
         tableWidget->setRowCount(end);
         int row = 0;
        fin >> s;
        fin >> s;
        fin >> s;
         int counter = 0;
         QString word = "";

         while (row < end)
         {
             while (counter < 4)
             {
                  if (s == '\x0')
                  {
                      QTableWidgetItem *newItem1 = new QTableWidgetItem();
                      newItem1->setText(word);
                      tableWidget->setItem(row, counter, newItem1);
                      break;
                  }
                    if ((QString(s) == ',')||(QString(s) == '\r'))
                    {
                        if (QString(s) == '\r')
                        {
                            fin >> s;
                        }
                         QTableWidgetItem *newItem1 = new QTableWidgetItem();
                         newItem1->setText(word);
                         tableWidget->setItem(row, counter, newItem1);
                         word = "";
                         counter++;
                         fin>>s;
                         continue;
                    }
                    if (QString(s) == '"')
                    {
                        fin >> s;
                        if (QString(s) == '"')
                        {
                            word.push_back(QString(s));
                        }
                        else
                        {
                            if (QString(s) == '\r')
                            {
                                fin >> s;
                                if (QString (s) == '\n')
                                {
                                    QTableWidgetItem *newItem1 = new QTableWidgetItem();
                                    newItem1->setText("ПЕРЕНОС СТРОКИ");
                                    tableWidget->setItem(row, counter, newItem1);
                                    fin >> s;
                                    fin >> s;
                                    fin >> s;
                                    counter++;
                                    continue;
                                }
                            }
                            while (QString(s)!='"')
                            {
                                word.push_back(QString(s));
                                fin >> s;
                            }
                           fin >> s;
                           if (QString(s) == '"')
                           {
                               word.push_back(QString(s));
                               fin >> s;
                           }
                        }
                    }
                    if ((QString(s) != ',')&&(QString(s) != '"'))
                    {
                        word.push_back(QString(s));
                        fin >> s;
                    }
                }
                counter = 0;
                row ++;
             }
         file.close();
     }
}

Widget::~Widget()
{
    delete ui;
}
