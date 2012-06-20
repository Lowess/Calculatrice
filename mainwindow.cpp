#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace LO21;
using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionDegr->setChecked(true);
    ui->actionEntiers->setChecked(true);

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
    connect(ui->btnSpace, SIGNAL(clicked()), this, SLOT(spaceBarPressed()));

    //Connexion des boutons opÃ©rateurs classiques + - * /
    connect(ui->btnPlus, SIGNAL(clicked()), this, SLOT(plusPressed()));
    connect(ui->btnMoins, SIGNAL(clicked()), this, SLOT(moinsPressed()));
    connect(ui->btnMultiplier, SIGNAL(clicked()), this, SLOT(multiplierPressed()));
    connect(ui->btnDiviser, SIGNAL(clicked()), this, SLOT(diviserPressed()));
    connect(ui->btnDollar, SIGNAL(clicked()), this, SLOT(dollarPressed()));

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

    ////////////
    // MENU
    ////////////

    //Connection des actions choix de constante
    connect(ui->radioButtonEntier, SIGNAL(clicked()), this, SLOT(actionEntiersChanged()));
    connect(ui->radioButtonReel, SIGNAL(clicked()), this, SLOT(actionReelsChanged()));
    connect(ui->radioButtonRationnel, SIGNAL(clicked()), this, SLOT(actionRationnelsChanged()));

    //Autoriser les complexes
    connect(ui->actionComplexes, SIGNAL(changed()), this, SLOT(actionComplexesChanged()));

    //Connection du mode degrées / radians
    connect(ui->actionDegr, SIGNAL(changed()), this, SLOT(actionDegrChanged()));
    connect(ui->actionRadian, SIGNAL(changed()), this, SLOT(actionRadianChanged()));

    //Connection des boutons dans fichier
    connect(ui->actionNouveau, SIGNAL(changed()), this, SLOT(actionNouveauChanged()));
    connect(ui->actionQuitter, SIGNAL(changed()), this, SLOT(actionQuitterChanged()));

    connect(ui->actionUndo, SIGNAL(triggered()), this, SLOT(actionUndo()));
    connect(ui->actionRedo, SIGNAL(triggered()), this, SLOT(actionRedo()));

<<<<<<< HEAD
    //connect(ui->chkDegre, SIGNAL(triggered()), this, SLOT(changeDegre()));
    //connect(ui->chkComplexe, SIGNAL(triggered()), this, SLOT(changeComplexe()));
=======

    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(spinChanged(int)));
>>>>>>> d185c98c462ba10aa067a3689a678560fbeed857

    connect(ui->actionMasquerOptionsAvancees, SIGNAL(triggered()), this, SLOT(actionMasquerOptionsAvancees()));
    connect(ui->actionMasquerPile, SIGNAL(triggered()), this, SLOT(actionMasquerPile()));

    ui->label_lastRes->setVisible(false);
    ui->lineEdit_lastRes->setVisible(false);

    memorisePileUndo();
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
void MainWindow::delPressed(){
    if(ui->lineEdit->text()=="")
        dropPressed();
    else
        ui->lineEdit->setText("");
}
void MainWindow::enterPressed(){
    if(ui->lineEdit->text()=="")
        dupPressed();
    else
        try{
            Fabrique::getInstance().creer(ui->lineEdit->text());
            memorisePileUndo();

            rafraichirPile();
            ui->lastStack->setText(ui->lineEdit->text().simplified());
            ui->lineEdit->clear();
        } catch (exception& e){
           QMessageBox msgBox;
            msgBox.setText(e.what());
            msgBox.exec();
        }
}
void MainWindow::spaceBarPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" "); }

//Connexion des boutons opÃ©rateurs classiques + - * /
void MainWindow::plusPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" + "); }
void MainWindow::moinsPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" - "); }
void MainWindow::multiplierPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" * "); }
void MainWindow::diviserPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" / "); }
void MainWindow::dollarPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+"$"); }

//Connexion des boutons opÃ©rations spÃ©ciales POW MOD SIGN
void MainWindow::powPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" POW "); }
void MainWindow::modPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" MOD "); }
void MainWindow::signPressed(){ ui->lineEdit->setText(ui->lineEdit->text()+" SIGN"); }

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

/*void MainWindow::changeDegre() {
    bool degre = ui->chkDegre->checked();
    Option.getInstance().switchDegre(degre);
}

void MainWindow::changeComplexe() {
    bool complexe = ui->chkComplexe->checked();
    Option.getInstance().switchComplexe(complexe);
}*/

//Connexion des opérateurs de pile Swap Sum Mean Clear Drop Dup
void MainWindow::swapPressed(){
    QString x=ui->lineEditX->text();
    QString y=ui->lineEditY->text();

    if(x.isEmpty()||y.isEmpty()){
        QMessageBox msgBox;
        msgBox.setText("Vous devez saisir deux valeurs dans les zones de texte X, Y");
        msgBox.exec();
    }
    else{
        try{
            memorisePileUndo();
            Calculatrice::getInstance().get_pile()->SWAP(x.toInt()-1,y.toInt()-1);
            memorisePileRedo();

            rafraichirPile();
        } catch (exception& e){
            QMessageBox msgBox;
            msgBox.setText(e.what());
            msgBox.exec();
        }
    }
}
void MainWindow::sumPressed(){
    QString x=ui->lineEditX->text();

    if(x.isEmpty()){
        QMessageBox msgBox;
        msgBox.setText("Vous devez saisir une valeur dans la zone de texte X");
        msgBox.exec();
    }
    else{
        try{
            memorisePileUndo();
            Calculatrice::getInstance().get_pile()->SUM(x.toInt()-1);
            memorisePileRedo();

            rafraichirPile();
        } catch (exception& e){
            QMessageBox msgBox;
            msgBox.setText(e.what());
            msgBox.exec();
        }
    }
}
void MainWindow::meanPressed(){

    QString x=ui->lineEditX->text();
    if(x.isEmpty()){
        QMessageBox msgBox;
        msgBox.setText("Vous devez saisir une valeur dans la zone de texte X");
        msgBox.exec();
    }
    else{
        try{
            memorisePileUndo();
            Calculatrice::getInstance().get_pile()->MEAN(x.toInt()-1);
            memorisePileRedo();

            rafraichirPile();
        } catch (exception& e){
            QMessageBox msgBox;
            msgBox.setText(e.what());
            msgBox.exec();
        }
    }
}
void MainWindow::clearPressed(){
    memorisePileUndo();
    Calculatrice::getInstance().get_pile()->CLEAR();
    memorisePileRedo();

    rafraichirPile();
}
void MainWindow::dropPressed(){
    try {
        memorisePileUndo();
        Calculatrice::getInstance().get_pile()->DROP();
        memorisePileRedo();

        rafraichirPile();
    } catch (exception& e){
        QMessageBox msgBox;
        msgBox.setText(e.what());
        msgBox.exec();
    }
}
void MainWindow::dupPressed(){
    try {
        memorisePileUndo();
        Calculatrice::getInstance().get_pile()->DUP();
        memorisePileRedo();

        rafraichirPile();
    } catch (exception& e){
        QMessageBox msgBox;
        msgBox.setText(e.what());
        msgBox.exec();
    }
}

void MainWindow::spinChanged(int i){
    rafraichirPile();
}

void MainWindow::actionUndo(){
    try{
        Gardien* g=Calculatrice::getInstance().get_gardien();

        Calculatrice::getInstance().get_pile()->restaurerDepuisMemento(g->getMementoUndo());
        Pile* p=Calculatrice::getInstance().get_pile()->get_etat();


        //Remplace la pile par une pile sauvegardée
        Calculatrice::getInstance().set_pile(p);
        qDebug() << "Affichage de la pile mémoire restaurée" << endl;
        p->afficherPileMemoire();

        qDebug() << "Affichage de la pile restaurée" << endl;
        p->afficherPileCourante();


        ui->listStack->clear();

        rafraichirPile();
    }catch (exception& e){ qDebug() << e.what(); }
}

void MainWindow::actionRedo(){
    try{
        Gardien* g=Calculatrice::getInstance().get_gardien();

        Calculatrice::getInstance().get_pile()->restaurerDepuisMemento(g->getMementoRedo());
        Pile* p=Calculatrice::getInstance().get_pile()->get_etat();


        //Remplace la pile par une pile sauvegardée
        Calculatrice::getInstance().set_pile(p);
        qDebug() << "Affichage de la pile restaurée" << endl;
        p->afficherPileMemoire();

        ui->listStack->clear();

        rafraichirPile();
    }catch (exception& e){ qDebug() << e.what(); }
}

void MainWindow::rafraichirPile(){
    ui->listStack->clear();

    //Mise �  jour de l'affichage
    QStack<Expression*>::iterator it;
    Expression* exp=0;
    /*
    for(it=Calculatrice::getInstance().get_pile()->begin(); it!=Calculatrice::getInstance().get_pile()->end(); ++it){ //On parcourt la pile
        exp=*it;
        ui->listStack->addItem(exp->toString());
    }
    */

    int afficheur=ui->spinBox->value();

    //Affiche la pile avec sommet vers le haut
    it=Calculatrice::getInstance().get_pile()->end();
    while ((it != Calculatrice::getInstance().get_pile()->begin()) && afficheur>0) {
        --it;
        afficheur--;
        exp=*it;
        ui->listStack->addItem(exp->toString());
    }
    if(ui->listStack->count()!=0)
        ui->lineEdit_lastRes->setText(ui->listStack->item(0)->text());
    else
        ui->lineEdit_lastRes->setText("");
}

void MainWindow::memorisePileUndo(){
    //Mémorise la pile pour permettre le undo
    Gardien* g=Calculatrice::getInstance().get_gardien();
    //Mémorise la pile courante
    g->ajouterMementoUndo(Calculatrice::getInstance().get_pile()->sauverDansMemento());
    //Calculatrice::getInstance().get_pile()->mementoSuivant();
}

void MainWindow::memorisePileRedo(){
    //Mémorise la pile pour permettre le undo
    Gardien* g=Calculatrice::getInstance().get_gardien();
    //Mémorise la pile courante
    g->ajouterMementoRedo(Calculatrice::getInstance().get_pile()->sauverDansMemento());
    //Calculatrice::getInstance().get_pile()->mementoSuivant();
}

//Connection des actions choix de constante
void MainWindow::actionEntiersChanged(){
    Option::getInstance().set_typeDiv(MENU_ENTIER);
}
void MainWindow::actionReelsChanged(){
    Option::getInstance().set_typeDiv(MENU_REEL);
}
void MainWindow::actionRationnelsChanged(){
    Option::getInstance().set_typeDiv(MENU_RATIONNEL);
}

//Autoriser les complexes
void MainWindow::actionComplexesChanged(){}

//Connection du mode degrées / radians
void MainWindow::actionDegrChanged(){}
void MainWindow::actionRadianChanged(){}

//Connection des boutons dans fichier
void MainWindow::actionNouveauChanged(){}
void MainWindow::actionQuitterChanged(){}

void MainWindow::actionMasquerOptionsAvancees(){
    if(ui->actionMasquerOptionsAvancees->isChecked()){
        ui->tabWidget->setVisible(false);
        ui->line_3->setVisible(false);
    }
    else{
        ui->tabWidget->setVisible(true);
        ui->line_3->setVisible(true);
    }
}
void MainWindow::actionMasquerPile(){
    if(ui->actionMasquerPile->isChecked()){
        ui->lastStack->setVisible(false);

        ui->label_X->setVisible(false);
        ui->label_Y->setVisible(false);

        ui->line->setVisible(false);
        ui->line_4->setVisible(false);
        ui->line_2->setVisible(false);

        ui->lineEditX->setVisible(false);
        ui->lineEditY->setVisible(false);

        ui->listStack->setVisible(false);

        ui->btnSwap->setVisible(false);
        ui->btnSum->setVisible(false);
        ui->btnMean->setVisible(false);
        ui->btnDrop->setVisible(false);
        ui->btnDup->setVisible(false);
        ui->btnClear->setVisible(false);

        ui->line_6->setVisible(false);

        ui->spinBox->setVisible(false);

        ui->label_lastRes->setVisible(true);
        ui->lineEdit_lastRes->setVisible(true);
    }
    else{
        ui->lastStack->setVisible(true);

        ui->label_X->setVisible(true);
        ui->label_Y->setVisible(true);

        ui->line->setVisible(true);
        ui->line_4->setVisible(true);
        ui->line_2->setVisible(true);

        ui->lineEditX->setVisible(true);
        ui->lineEditY->setVisible(true);

        ui->listStack->setVisible(true);

        ui->btnSwap->setVisible(true);
        ui->btnSum->setVisible(true);
        ui->btnMean->setVisible(true);
        ui->btnDrop->setVisible(true);
        ui->btnDup->setVisible(true);
        ui->btnClear->setVisible(true);

        ui->line_6->setVisible(true);

        ui->spinBox->setVisible(true);

        ui->label_lastRes->setVisible(false);
        ui->lineEdit_lastRes->setVisible(false);
    }
    adjustSize();
}
