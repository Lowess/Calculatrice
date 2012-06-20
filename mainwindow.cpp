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
    ui->btnDollar->setEnabled(false);

    //Connection du mode degrées / radians
    connect(ui->actionDegr, SIGNAL(changed()), this, SLOT(actionDegrChanged()));
    connect(ui->actionRadian, SIGNAL(changed()), this, SLOT(actionRadianChanged()));
    ui->actionRadian->setChecked(true);

    //Connection des boutons dans fichier
    connect(ui->actionNouveau, SIGNAL(triggered()), this, SLOT(actionNouveauChanged()));
    connect(ui->actionSauvegarder, SIGNAL(triggered()), this, SLOT(actionSave()));
    connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(actionQuitterChanged()));

    connect(ui->actionUndo, SIGNAL(triggered()), this, SLOT(actionUndo()));
    connect(ui->actionRedo, SIGNAL(triggered()), this, SLOT(actionRedo()));

    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(spinChanged(int)));

    connect(ui->actionMasquerOptionsAvancees, SIGNAL(triggered()), this, SLOT(actionMasquerOptionsAvancees()));
    connect(ui->actionMasquerTrigo, SIGNAL(triggered()), this, SLOT(actionMasquerTrigo()));
    connect(ui->actionMasquerPile, SIGNAL(triggered()), this, SLOT(actionMasquerPile()));
    connect(ui->actionMasquerClavier, SIGNAL(triggered()), this, SLOT(actionMasquerClavier()));

    ui->label_lastRes->setVisible(false);
    ui->lineEdit_lastRes->setVisible(false);

    memorisePileUndo();

    try{
        load();
    } catch (exception& e){
        QMessageBox msgBox;
        msgBox.setText(e.what());
        msgBox.exec();
    }
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
            LogSystem::ecrireLog(LogMessage("Erreur impossible d'effectuer l'opération demandée classe mainWindow ",ERREUR));
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
        LogSystem::ecrireLog(LogMessage("Erreur de saisie classe mainWindow ",ERREUR));
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
            LogSystem::ecrireLog(LogMessage("Erreur impossible d'effectuer l'opération demandée classe mainWindow ",ERREUR));
            QMessageBox msgBox;
            msgBox.setText(e.what());
            msgBox.exec();
        }
    }


}
void MainWindow::sumPressed(){
    QString x=ui->lineEditX->text();

    if(x.isEmpty()){
        LogSystem::ecrireLog(LogMessage("Erreur de saisie classe mainWindow ",ERREUR));
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
            LogSystem::ecrireLog(LogMessage("Erreur impossible d'effectuer l'opération demandée classe mainWindow ",ERREUR));
            QMessageBox msgBox;
            msgBox.setText(e.what());
            msgBox.exec();
        }
    }


}
void MainWindow::meanPressed(){

    QString x=ui->lineEditX->text();
    if(x.isEmpty()){
        LogSystem::ecrireLog(LogMessage("Erreur de saisie classe mainWindow ",ERREUR));
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
            LogSystem::ecrireLog(LogMessage("Erreur impossible d'effectuer l'opération demandée classe mainWindow ",ERREUR));
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
        LogSystem::ecrireLog(LogMessage("Erreur impossible d'effectuer l'opération demandée classe mainWindow ",ERREUR));
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
        LogSystem::ecrireLog(LogMessage("Erreur impossible d'effectuer l'opération demandée classe mainWindow ",ERREUR));
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
    }catch (exception& e){
        LogSystem::ecrireLog(LogMessage("Erreur impossible d'effectuer l'opération demandée classe mainWindow ",ERREUR));
    }


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
    }catch (exception& e){
        LogSystem::ecrireLog(LogMessage("Erreur impossible d'effectuer l'opération demandée classe mainWindow ",ERREUR));
    }


}

void MainWindow::rafraichirPile(){
    ui->listStack->clear();

    /*
    for(it=Calculatrice::getInstance().get_pile()->begin(); it!=Calculatrice::getInstance().get_pile()->end(); ++it){ //On parcourt la pile
        exp=*it;
        ui->listStack->addItem(exp->toString());
    }
    */

    int afficheur=ui->spinBox->value();

    QStack<Expression*>::iterator it;
    Expression* exp=0;
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
void MainWindow::actionComplexesChanged(){
    if(ui->actionComplexes->isChecked()) {
        Option::getInstance().set_complexe(true);
        ui->btnDollar->setEnabled(true);
    }
    else {
        Option::getInstance().set_complexe(false);
        ui->btnDollar->setEnabled(false);
    }
}

//Connection du mode degrées / radians
void MainWindow::actionDegrChanged(){

    if(ui->actionDegr->isChecked()){
        Option::getInstance().set_degre(true);
        if(ui->actionRadian->isChecked()){
           ui->actionRadian->setChecked(false);
        }
    }
}
void MainWindow::actionRadianChanged(){
    if(ui->actionRadian->isChecked()){
        Option::getInstance().set_degre(false);
        if(ui->actionRadian->isChecked()){
           ui->actionDegr->setChecked(false);
        }
    }
}

//Connection des boutons dans fichier
void MainWindow::actionNouveauChanged(){
    qDebug() << "New" << endl;

    ui->radioButtonEntier->setChecked(true);
    actionEntiersChanged();
    ui->lineEdit_lastRes->setText("");
    ui->lastStack->setText("");

    ui->actionComplexes->setChecked(false);
    actionComplexesChanged();

    ui->actionMasquerOptionsAvancees->setChecked(false);
    actionMasquerOptionsAvancees();
    ui->actionMasquerTrigo->setChecked(false);
    actionMasquerTrigo();
    ui->actionMasquerPile->setChecked(false);
    actionMasquerPile();
    ui->actionMasquerClavier->setChecked(false);
    actionMasquerClavier();

    ui->actionDegr->setChecked(false);
    actionDegrChanged();

    Calculatrice::getInstance().get_pile()->CLEAR();

    rafraichirPile();


}
void MainWindow::actionQuitterChanged(){
    save();
    close();
}

void MainWindow::actionMasquerOptionsAvancees(){
    if(ui->actionMasquerOptionsAvancees->isChecked()){
        ui->labelAvance->setVisible(false);
        ui->btnMod->setVisible(false);
        ui->btnLn->setVisible(false);
        ui->btnLog->setVisible(false);
        ui->btnFactorielle->setVisible(false);
        ui->btnInv->setVisible(false);
        ui->btnSign->setVisible(false);
        ui->btnPow->setVisible(false);
        ui->line_3->setVisible(false);
    }
    else{
        ui->labelAvance->setVisible(true);
        ui->btnMod->setVisible(true);
        ui->btnLn->setVisible(true);
        ui->btnLog->setVisible(true);
        ui->btnFactorielle->setVisible(true);
        ui->btnInv->setVisible(true);
        ui->btnSign->setVisible(true);
        ui->btnPow->setVisible(true);
        ui->line_3->setVisible(true);
    }
    adjustSize();
}

void MainWindow::actionMasquerTrigo(){
    if(ui->actionMasquerTrigo->isChecked()){
        ui->labelTrigo->setVisible(false);
        ui->btnSin->setVisible(false);
        ui->btnCos->setVisible(false);
        ui->btnTan->setVisible(false);
        ui->btnSinh->setVisible(false);
        ui->btnCosh->setVisible(false);
        ui->btnTanh->setVisible(false);
        ui->line_7->setVisible(false);
    }
    else{
        ui->labelTrigo->setVisible(true);
        ui->btnSin->setVisible(true);
        ui->btnCos->setVisible(true);
        ui->btnTan->setVisible(true);
        ui->btnSinh->setVisible(true);
        ui->btnCosh->setVisible(true);
        ui->btnTanh->setVisible(true);
        ui->line_7->setVisible(true);
    }
    adjustSize();
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

void MainWindow::actionMasquerClavier(){
    if(ui->actionMasquerClavier->isChecked()){
        ui->btn0->setVisible(false);
        ui->btn1->setVisible(false);
        ui->btn2->setVisible(false);
        ui->btn3->setVisible(false);
        ui->btn4->setVisible(false);
        ui->btn5->setVisible(false);
        ui->btn6->setVisible(false);
        ui->btn7->setVisible(false);
        ui->btn8->setVisible(false);
        ui->btn9->setVisible(false);

        ui->btnPlus->setVisible(false);
        ui->btnMoins->setVisible(false);
        ui->btnMultiplier->setVisible(false);
        ui->btnDiviser->setVisible(false);
        ui->btnEval->setVisible(false);
        ui->btnDollar->setVisible(false);
        ui->btnSpace->setVisible(false);
        ui->btnSqr->setVisible(false);
        ui->btnCube->setVisible(false);
        ui->btnSqrt->setVisible(false);

        ui->line_5->setVisible(false);
    }
    else{
        ui->btn0->setVisible(true);
        ui->btn1->setVisible(true);
        ui->btn2->setVisible(true);
        ui->btn3->setVisible(true);
        ui->btn4->setVisible(true);
        ui->btn5->setVisible(true);
        ui->btn6->setVisible(true);
        ui->btn7->setVisible(true);
        ui->btn8->setVisible(true);
        ui->btn9->setVisible(true);

        ui->btnPlus->setVisible(true);
        ui->btnMoins->setVisible(true);
        ui->btnMultiplier->setVisible(true);
        ui->btnDiviser->setVisible(true);
        ui->btnEval->setVisible(true);
        ui->btnDollar->setVisible(true);
        ui->btnSpace->setVisible(true);
        ui->btnSqr->setVisible(true);
        ui->btnCube->setVisible(true);
        ui->btnSqrt->setVisible(true);

        ui->line_5->setVisible(true);
    }
    adjustSize();
}

void MainWindow::save(){
    //QFile file("/home/florian/Documents/UTC/LO21/Qt/Calculatrice/Options.save");
    QFile file(QDir::currentPath() + "Option.save");


    //Ecriture
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        throw CalculatriceException("LogSystem",OTHER,"Echec d'ouverture de fichier de log en ecriture");


    QDataStream out(&file);
    //Enregistre les options
    out << Option::getInstance().get_degre();
    out << Option::getInstance().get_complexe();
    out << Option::getInstance().get_typeDiv();

    //Affichage
    out << ui->actionMasquerOptionsAvancees->isChecked();
    out << ui->actionMasquerTrigo->isChecked();
    out << ui->actionMasquerPile->isChecked();
    out << ui->actionMasquerClavier->isChecked();

    QStack<Expression*>::iterator it;
    Expression* exp=0;

    //Recopie la pile
    it=Calculatrice::getInstance().get_pile()->begin();
    for(it=Calculatrice::getInstance().get_pile()->begin(); it!=Calculatrice::getInstance().get_pile()->end(); ++it){ //On parcourt la pile
        exp=*it;
        out << exp->toString();
        qDebug() << exp->toString();
    }

    file.close();
    LogSystem::ecrireLog(LogMessage("Sauvegarde de contexte effectuée classe mainWindow ",INFO));

}


void MainWindow::load(){
    //QFile file("/home/florian/Documents/UTC/LO21/Qt/Calculatrice/Options.save");
    QFile file(QDir::currentPath() + "Option.save");
    //Lecture
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        throw CalculatriceException("LogSystem",OTHER,"Echec d'ouverture de fichier de save en lecture");


    QDataStream in(&file);
    //Enregistre les options
    bool deg,comp,avance,trigo,pile,clav;
    int type;

    in >> deg;
    in >> comp;
    in >> type;
    in >> avance;
    in >> trigo;
    in >> pile;
    in >> clav;

    if(deg){
        ui->actionDegr->setChecked(true);
        actionDegrChanged();
    }
    if(comp){
        ui->actionComplexes->setChecked(true);
        actionComplexesChanged();
    }
    switch(type){
        case 1:{
            actionReelsChanged();
            ui->radioButtonReel->setChecked(true);
            break;
        }
        case 2:{
            actionRationnelsChanged();
            ui->radioButtonRationnel->setChecked(true);
            break;
        }
        default: break;
    }
    //Affichage
    if(avance){
        ui->actionMasquerOptionsAvancees->setChecked(true);
        actionMasquerOptionsAvancees();
    }
    if(trigo){
        ui->actionMasquerTrigo->setChecked(true);
        actionMasquerTrigo();
    }
    if(pile){
        ui->actionMasquerPile->setChecked(true);
        actionMasquerPile();
    }
    if(clav){
        ui->actionMasquerClavier->setChecked(true);
        actionMasquerClavier();
    }

    //On ré-insert les éléments sauvegardés dans la pile
    QString buf;
    while(!in.atEnd()){
        in >> buf;
        Fabrique::getInstance().creer(buf);
    }
    file.close();

    rafraichirPile();

    LogSystem::ecrireLog(LogMessage("Restauration de contexte effectuée classe mainWindow ",INFO));
}

void MainWindow::actionSave(){
    save();
}
