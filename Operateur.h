#ifndef OPERATEUR_H
#define OPERATEUR_H

/*! \file Operateur.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe Operateur
  */

#include <stdexcept>
#include <QString>
#include <QStringList>

#include "Expression.h"
#include "Fabrique.h"
#include "Pile.h"
#include "Calculatrice.h"

/*! \namespace LO21
 *  \brief Désigne les classes définies dans le but du projet de LO21 P12
 */
namespace LO21{
    /*! \enum enumOperateurs
     * \brief Définit tous les types d'opérateurs possibles dans une expression
     */
    enum enumOperateurs {ADD, MUL, SOU, DIV, COS, SIN, TAN, COSH, SINH, TANH, SQR, CUBE, SQRT, INV, SIGN, LN, LOG, POW, FACT, MOD, EVALUATION};

    /*! \class Operateur
     * \brief Classe permettant de gérer les différents types d'opérateurs
     */
    class Operateur: public Expression {
        protected:
            enumOperateurs _operateur; /*! Le type de l'opérateur */

        public:
            /*! \fn QString toString() const
             * \brief Renvoie une forme textuelle de l'opérateur pour affichage
             * \return QString contenant le texte correspondant à l'opérateur
             */
            QString toString() const =0;

            /*! \fn QString getOperator() const
             * \brief Retourne le type de l'opérateur sous une forme textuelle
             * \return QString qui est le texte de l'opérateur
             */
            QString getOperator() const{ return toString(); }

            /*! \fn void appliqueOperateur()
             * \brief Permet d'appeler la fonction correspondant à un opérateur
             */
            void appliqueOperateur();

            /*! \fn void EVAL()
             * \brief Evalue un opérateur
             */
            void EVAL();

            /*! \fn QString& afficher()
             * \brief Sert à l'affichage de l'opérateur
             * \return QString& une référence vers le QString contenant l'affichage textuel de l'opérateur
             */
            QString& afficher();

            /*! \fn Operateur* clone() const
             * \brief Permet de dupliquer un objet Opérateur
             * \return Operateur* un pointeur vers l'operateur nouvellement créé
             */
            Operateur* clone() const;
    };
}

#endif // OPERATEUR_H
