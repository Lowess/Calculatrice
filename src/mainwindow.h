/** \file mainwindow.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-t�te pour d�claration de la classe mainwindow
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
 *  \brief D�signe les classes d�finies dans le but du projet de LO21 P12, concernant l'affichage de la calculatrice
 */

namespace Ui {
class MainWindow;
}

/*! \class MainWindow
 * \brief Classe construisant l'interface de la calculatrice et g�rant les actions effectu�es par l'utilisateur
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
        Ui::MainWindow *ui; /*! L'instance de MainWindow actuellement utilis�e par l'application */

        /*! \fn slotConnection()
         * \brief G�re toutes les connections entre les objets de l'interface et les actions associ�s
         * aux �v�nements d�clench�s
         */
        void slotConnection();

        /*! \fn rafraichirPile()
         * \brief Rafra�chit l'affichage de la pile pour y modifier les valeurs selon la pile stock�e en m�moire
         */
        void rafraichirPile();

        /*! \fn memorisePileUndo()
         * \brief Sauve l'�tat de la pile actuelle affich�e avant qu'elle soit actualis�e
         * afin de pouvoir annuler une action
         */
        void memorisePileUndo();

        /*! \fn memorisePileRedo()
         * \brief Sauve l'�tat de la pile actuelle affich�e par la calculatrice dans le cas o�
         * l'utilisateur veut r�effectuer une action annul�e
         */
        void memorisePileRedo();

        /*! \fn void save()
         * \brief Permet de sauvegarder l'�tat de la calculatrice actuelle afin de l'utiliser ult�rieurement
         */
        void save();

        /*! \fn void load()
         * \brief Permet de charger l'�tat d'une calculatrice pr�c�dente
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

#endif // MAINWINDOW_H
