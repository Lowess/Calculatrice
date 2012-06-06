#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Fabrique.h"
#include "Pile.h"

#include "Expression.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();
    
    private:
        Ui::MainWindow *ui;
        void slotConnection();
        void rafraichirPile();
    private slots:
        //Connexion des boutons 0-9
        void num0Pressed();
        void num1Pressed();
        void num2Pressed();
        void num3Pressed();
        void num4Pressed();
        void num5Pressed();
        void num6Pressed();
        void num7Pressed();
        void num8Pressed();
        void num9Pressed();

        //Connexion des boutons DEL & ENTER
        void delPressed();
        void enterPressed();

        //Connexion des boutons opérateurs classiques + - * /
        void plusPressed();
        void moinsPressed();
        void multiplierPressed();
        void diviserPressed();

        //Connexion des boutons opérations spéciales POW MOD SIGN
        void powPressed();
        void modPressed();
        void signPressed();

        //Connexion des opérateurs mathématiques
        //Sin Cos Tan
        void sinPressed();
        void cosPressed();
        void tanPressed();
        //Sinh Cosh Tanh
        void sinhPressed();
        void coshPressed();
        void tanhPressed();
        //Ln Log
        void lnPressed();
        void logPressed();
        //Inv Factorielle(!) Eval
        void invPressed();
        void factoriellePressed();
        void evalPressed();
        //Sqrt Sqr Cube
        void sqrtPressed();
        void sqrPressed();
        void cubePressed();

        //Connexion des opérateurs de pile Swap Sum Mean Clear Drop Dup
        void swapPressed();
        void sumPressed();
        void meanPressed();
        void clearPressed();
        void dropPressed();
        void dupPressed();
};

#endif // MAINWINDOW_H
