#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
#include <QString>
#include <QDebug>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
//    ui->label_2->text()=client->logresult;
//    ui->label->text()=client->regresult;
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QString usrlog,pwdlog,logmsg;

    usrlog=ui->lineEdit->text();
    pwdlog=ui->lineEdit_2->text();
    logmsg=usrlog+"$"+pwdlog;
    client->sndlog.push_back(logmsg.toStdString());

    accept();
}

void Dialog::on_pushButton_2_clicked()
{
    QString usrreg,pwdreg,regmsg;

    usrreg=ui->lineEdit_3->text();
    pwdreg=ui->lineEdit_4->text();
    regmsg=usrreg+"$"+pwdreg;
    client->sndreg.push_back(regmsg.toStdString());



}
