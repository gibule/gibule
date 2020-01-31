#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "gbl_worker.h"
#include <gbl_chat_client.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



    GBL_Chat_Client *client;


private slots:
    void on_pushButton_clicked();
    void ontimer();

private:
    Ui::MainWindow *ui;
    QTimer timer;
};

#endif // MAINWINDOW_H
