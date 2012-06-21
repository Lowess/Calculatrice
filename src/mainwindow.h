/** \file mainwindow.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe mainwindow
  */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

/*! \namespace Ui
 *  \brief Désigne les classes définies dans le but du projet de LO21 P12, concernant l'affichage de la calculatrice
 */

namespace Ui {
class MainWindow;
}

/*! \class MainWindow
 * \brief Classe construisant l'interface de la calculatrice et gérant les actions effectuées par l'utilisateur
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
    public:
        /*! \fn explicit MainWindow(QWidget *parent)
         * \brief Constructeur de la classe MainWindow
         * \param parent le pointeur vers le widget parent du MainWindow
         */
        explicit MainWindow(QWidget *parent = 0);

        /*! \fn ~MainWindow()
         * \brief Destructeur de la classe MainWindow
         */
        ~MainWindow();
    
    private:
        Ui::MainWindow *ui; /*! L'instance de MainWindow actuellement utilisée par l'application */

        /*! \fn slotConnection()
         * \brief Gère toutes les connections entre les objets de l'interface et les actions associés
         * aux évènements déclenchés
         */
        void slotConnection();

        /*! \fn rafraichirPile()
         * \brief Rafraîchit l'affichage de la pile pour y modifier les valeurs selon la pile stockée en mémoire
         */
        void rafraichirPile();

        /*! \fn memorisePileUndo()
         * \brief Sauve l'état de la pile actuelle affichée avant qu'elle soit actualisée
         * afin de pouvoir annuler une action
         */
        void memorisePileUndo();

        /*! \fn memorisePileRedo()
         * \brief Sauve l'état de la pile actuelle affichée par la calculatrice dans le cas où
         * l'utilisateur veut réeffectuer une action annulée
         */
        void memorisePileRedo();

        /*! \fn void save()
         * \brief Permet de sauvegarder l'état de la calculatrice actuelle afin de l'utiliser ultérieurement
         */
        void save();

        /*! \fn void load()
         * \brief Permet de charger l'état d'une calculatrice précédente
         */
        void load();

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

        //Connexion des boutons opÃƒÂ©rateurs classiques + - * /
        void plusPressed();
        void moinsPressed();
        void multiplierPressed();
        void diviserPressed();
        void dollarPressed();

        //Connexion des boutons opÃƒÂ©rations spÃƒÂ©ciales POW MOD SIGN
        void powPressed();
        void modPressed();
        void signPressed();

        //Connexion des opÃƒÂ©rateurs mathÃƒÂ©matiques
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

        //Connexion des opÃƒÂ©rateurs de pile Swap Sum Mean Clear Drop Dup
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

        //Connection du mode degrÃ©es / radians
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

#endif // MAINWINDOW_H
