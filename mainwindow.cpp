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
    //Connexion des boutons 0 Ã  9
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

    //Connexion des boutons DEL & ENTER
    connect(ui->btnDel, SIGNAL(clicked()), this, SLOT(delPressed()));
    connect(ui->btnEnter, SIGNAL(clicked()), this, SLOT(enterPressed()));

    //Connexion des boutons opÃ©rateurs classiques + - * /
    connect(ui->btnPlus, SIGNAL(clicked()), this, SLOT(plusPressed()));
    connect(ui->btnMoins, SIGNAL(clicked()), this, SLOT(moinsPressed()));
    connect(ui->btnMultiplier, SIGNAL(clicked()), this, SLOT(multiplierPressed()));
    connect(ui->btnDiviser, SIGNAL(clicked()), this, SLOT(diviserPressed()));

    //Connexion des boutons opÃ©rations spÃ©ciales POW MOD SIGN
    connect(ui->btnPow, SIGNAL(clicked()), this, SLOT(powPressed()));
    connect(ui->btnMod, SIGNAL(clicked()), this, SLOT(modPressed()));
    connect(ui->btnSign, SIGNAL(clicked()), this, SLOT(signPressed()));

    //Connexion des opÃ©rateurs mathÃ©matiques
    //Sin Cos Tan
    connect(ui->btnSin, SIGNAL(clicked()), this, SLOT(sinPressed()));
    connect(ui->btnCos, SIGNAL(clicked()), this, SLOT(cosPressed()));
    connect(ui->btnTan, SIGNAL(clicked()), this, SLOT(tanPressed()));
    //Sinh Cosh Tanh
    connect(ui->btnSinh, SIGNAL(clicked()), this, SLOT(sinhPressed()));
    connect(ui->btnCosh, SIGNAL(clicked()), this, SLOT(coshPressed()));
    connect(ui->btnTanh, SIGNAL(clicked()), this, SLOT(tanhPressed()));
    //Ln Log
    connect(ui->btnLn, SIGNAL(clicked()), this, SLOT(lnPressed()));
    connect(ui->btnLog, SIGNAL(clicked()), this, SLOT(logPressed()));
    //Inv Factorielle(!) Eval
    connect(ui->btnInv, SIGNAL(clicked()), this, SLOT(invPressed()));
    connect(ui->btnFactorielle, SIGNAL(clicked()), this, SLOT(factoriellePressed()));
    connect(ui->btnEval, SIGNAL(clicked()), this, SLOT(evalPressed()));
    //Sqrt Sqr Cube
    connect(ui->btnSqrt, SIGNAL(clicked()), this, SLOT(sqrtPressed()));
    connect(ui->btnSqr, SIGNAL(clicked()), this, SLOT(sqrPressed()));
    connect(ui->btnCube, SIGNAL(clicked()), this, SLOT(cubePressed()));

    //Connexion des opÃ©rateurs de pile Swap Sum Mean Clear Drop Dup
    connect(ui->btnSwap, SIGNAL(clicked()), this, SLOT(swapPressed()));
    connect(ui->btnSum, SIGNAL(clicked()), this, SLOT(sumPressed()));
    connect(ui->btnMean, SIGNAL(clicked()), this, SLOT(meanPressed()));
    connect(ui->btnClear, SIGNAL(clicked()), this, SLOT(clearPressed()));
    connect(ui->btnDrop, SIGNAL(clicked()), this, SLOT(dropPressed()));
    connect(ui->btnDup, SIGNAL(clicked()), this, SLOT(dupPressed()));
}

//Connexion des boutons 0-9
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

//Connexion des boutons DEL & ENTER
void MainWindow::delPressed(){ ui->lineEdit->setText(""); }
void MainWindow::enterPressed(){}

//Connexion des boutons opÃ©rateurs classiques + - * /
void MainWindow::plusPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" + "); }
void MainWindow::moinsPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" - "); }
void MainWindow::multiplierPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" * "); }
void MainWindow::diviserPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" / "); }

//Connexion des boutons opÃ©rations spÃ©ciales POW MOD SIGN
void MainWindow::powPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" POW "); }
void MainWindow::modPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" MOD "); }
void MainWindow::signPressed(){ ui->lineEdit->setText("SIGN "+ui->lineEdit->text()); }

//Connexion des opÃ©rateurs mathÃ©matiques
//Sin Cos Tan
void MainWindow::sinPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" SIN "); }
void MainWindow::cosPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" COS "); }
void MainWindow::tanPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" TAN "); }
//Sinh Cosh Tanh
void MainWindow::sinhPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" SINH "); }
void MainWindow::coshPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" COSH "); }
void MainWindow::tanhPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" TANH "); }
//Ln Log
void MainWindow::lnPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" LN "); }
void MainWindow::logPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" LOG "); }
//Inv Factorielle(!) Eval
void MainWindow::invPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" INV "); }
void MainWindow::factoriellePressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" ! "); }
void MainWindow::evalPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" EVAL "); }
//Sqrt Sqr Cube
void MainWindow::sqrtPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" SQRT "); }
void MainWindow::sqrPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" SQR "); }
void MainWindow::cubePressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" CUBE "); }

//Connexion des opÃ©rateurs de pile Swap Sum Mean Clear Drop Dup
void MainWindow::swapPressed(){}
void MainWindow::sumPressed(){}
void MainWindow::meanPressed(){}
void MainWindow::clearPressed(){}
void MainWindow::dropPressed(){}
void MainWindow::dupPressed(){}
