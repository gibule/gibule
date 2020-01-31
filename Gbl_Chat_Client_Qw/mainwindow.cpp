#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDebug>
#include <QColor>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect(&timer,SIGNAL(timeout()),this,SLOT(ontimer()));
    timer.start(1000);


}


MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::on_pushButton_clicked()
{



    QString s;
    s=ui->textEdit_2->toPlainText();
    ui->textEdit->setTextColor(QColor(255,0,0));
    ui->textEdit->append("Me: "+s);
    ui->textEdit_2->clear();
    ui->textEdit_2->setFocus();
    client->sndmsg.push_back(s.toStdString());




}
void MainWindow::ontimer()
{
    ui->textEdit->setTextColor(QColor(0,0,0));

    //ui->textEdit->append(QString::number(client->datalist.size()));

    //qDebug() << "===============";// << client->datalist.size();
    for (int i = 0; i < client->datalist.size(); ++i)
    {
        ui->textEdit->append("Guest: "+client->datalist.at(i));
    }
    client->datalist.clear();

}
