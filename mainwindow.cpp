#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    slotConnection();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Connexion des slots
void MainWindow::slotConnection()
{
    //Connexion des boutons 0 à 9
    connect(ui->btn0, SIGNAL(clicked()), this, SLOT(num0Pressed()));
    connect(ui->btn1, SIGNAL(clicked()), this, SLOT(num1Pressed()));
    connect(ui->btn2, SIGNAL(clicked()), this, SLOT(num2Pressed()));
    connect(ui->btn3, SIGNAL(clicked()), this, SLOT(num3Pressed()));
    connect(ui->btn4, SIGNAL(clicked()), this, SLOT(num4Pressed()));
    connect(ui->btn5, SIGNAL(clicked()), this, SLOT(num5Pressed()));
    connect(ui->btn6, SIGNAL(clicked()), this, SLOT(num6Pressed()));
    connect(ui->btn7, SIGNAL(clicked()), this, SLOT(num7Pressed()));
    connect(ui->btn8, SIGNAL(clicked()), this, SLOT(num8Pressed()));
    connect(ui->btn9, SIGNAL(clicked()), this, SLOT(num9Pressed()));



}

void MainWindow::num0Pressed(){ ui->lineEdit->setText(ui->lineEdit->text()+"0"); }
void MainWindow::num1Pressed(){ ui->lineEdit->setText(ui->lineEdit->text()+"1"); }
void MainWindow::num2Pressed(){ ui->lineEdit->setText(ui->lineEdit->text()+"2"); }
void MainWindow::num3Pressed(){ ui->lineEdit->setText(ui->lineEdit->text()+"3"); }
void MainWindow::num4Pressed(){ ui->lineEdit->setText(ui->lineEdit->text()+"4"); }
void MainWindow::num5Pressed(){ ui->lineEdit->setText(ui->lineEdit->text()+"5"); }
void MainWindow::num6Pressed(){ ui->lineEdit->setText(ui->lineEdit->text()+"6"); }
void MainWindow::num7Pressed(){ ui->lineEdit->setText(ui->lineEdit->text()+"7"); }
void MainWindow::num8Pressed(){ ui->lineEdit->setText(ui->lineEdit->text()+"8"); }
void MainWindow::num9Pressed(){ ui->lineEdit->setText(ui->lineEdit->text()+"9"); }

