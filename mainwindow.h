#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*! \file mainwindow.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-t�te pour d�claration de la classe mainwindow
  */

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <stdexcept>

#include "Calculatrice.h"
#include "Fabrique.h"
#include "Pile.h"
#include "Option.h"
#include "Expression.h"
#include "LogSystem.h"


namespace Ui {
    /*! \class MainWindow
     * \brief Fen�tre principale pour l'interface de la calculatrice et le lien avec
     * les donn�es
     */
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
            void memorisePileUndo();
            void memorisePileRedo();
            void save();
            void load();
            bool notify ( QObject * receiver, QEvent * e );

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
            void spaceBarPressed();

            //Connexion des boutons opÃ©rateurs classiques + - * /
            void plusPressed();
            void moinsPressed();
            void multiplierPressed();
            void diviserPressed();
            void dollarPressed();

            //Connexion des boutons opÃ©rations spÃ©ciales POW MOD SIGN
            void powPressed();
            void modPressed();
            void signPressed();

            //Connexion des opÃ©rateurs mathÃ©matiques
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

            //Connexion des opÃ©rateurs de pile Swap Sum Mean Clear Drop Dup
            void swapPressed();
            void sumPressed();
            void meanPressed();
            void clearPressed();
            void dropPressed();
            void dupPressed();

            void spinChanged(int i);

            //Connection des actions choix de constante
            void actionEntiersChanged();
            void actionReelsChanged();
            void actionRationnelsChanged();

            //Autoriser les complexes
            void actionComplexesChanged();

            //Connection du mode degrées / radians
            void actionDegrChanged();
            void actionRadianChanged();

            //Connection des boutons dans fichier
            void actionNouveauChanged();
            void actionSave();
            void actionQuitterChanged();

            //Connection des boutons dans fichier
            void actionMasquerOptionsAvancees();
            void actionMasquerTrigo();
            void actionMasquerPile();
            void actionMasquerClavier();

            void actionUndo();
            void actionRedo();

    };
}

#endif // MAINWINDOW_H
