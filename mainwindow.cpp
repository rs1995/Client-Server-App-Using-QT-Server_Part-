#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_pushButtonStart_clicked()
{
    serverclass= new WorldServerClass(this);
    bool success = serverclass->listen(QHostAddress::Any,quint16(ui->textEdit->toPlainText().toInt()));

    if(!success)
    {
        addmsg("Server Failed");
    }
    else{
        addmsg("Server Started...");
    }
}

void MainWindow::addmsg(QString msg)
{
    ui->textEdit_2->setText(msg);
}
