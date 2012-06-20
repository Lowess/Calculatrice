#ifndef OPERATEUR_H
#define OPERATEUR_H

/*! \file Operateur.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-t�te pour d�claration de la classe Operateur
  */

#include <stdexcept>
#include <QString>
#include <QStringList>

#include "Expression.h"
#include "Fabrique.h"
#include "Pile.h"
#include "Calculatrice.h"

/*! \namespace LO21
 *  \brief D�signe les classes d�finies dans le but du projet de LO21 P12
 */
namespace LO21{
    /*! \enum enumOperateurs
     * \brief D�finit tous les types d'op�rateurs possibles dans une expression
     */
    enum enumOperateurs {ADD, MUL, SOU, DIV, COS, SIN, TAN, COSH, SINH, TANH, SQR, CUBE, SQRT, INV, SIGN, LN, LOG, POW, FACT, MOD, EVALUATION};

    /*! \class Operateur
     * \brief Classe permettant de g�rer les diff�rents types d'op�rateurs
     */
    class Operateur: public Expression {
        protected:
            enumOperateurs _operateur; /*! Le type de l'op�rateur */

        public:
            /*! \fn QString toString() const
             * \brief Renvoie une forme textuelle de l'op�rateur pour affichage
             * \return QString contenant le texte correspondant � l'op�rateur
             */
            QString toString() const =0;

            /*! \fn QString getOperator() const
             * \brief Retourne le type de l'op�rateur sous une forme textuelle
             * \return QString qui est le texte de l'op�rateur
             */
            QString getOperator() const{ return toString(); }

            /*! \fn void appliqueOperateur()
             * \brief Permet d'appeler la fonction correspondant � un op�rateur
             */
            void appliqueOperateur();

            /*! \fn void EVAL()
             * \brief Evalue un op�rateur
             */
            void EVAL();

            /*! \fn QString& afficher()
             * \brief Sert � l'affichage de l'op�rateur
             * \return QString& une r�f�rence vers le QString contenant l'affichage textuel de l'op�rateur
             */
            QString& afficher();

            /*! \fn Operateur* clone() const
             * \brief Permet de dupliquer un objet Op�rateur
             * \return Operateur* un pointeur vers l'operateur nouvellement cr��
             */
            Operateur* clone() const;
    };
}

#endif // OPERATEUR_H
