#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDebug>
#include <QColor>
#include <gbl_chat_client.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}


MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    GBL_Chat_Client c;

    QString s;
    s=ui->textEdit_2->toPlainText();
    ui->textEdit->setTextColor(QColor(255,0,0));
    ui->textEdit->append("Me: "+s);
    ui->textEdit_2->clear();
    ui->textEdit_2->setFocus();
    c.sndmsg.push_back(s.toStdString());




}
