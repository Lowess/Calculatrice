#ifndef OPERATEUR_H
#define OPERATEUR_H

/*! \file Operateur.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tete pour declaration de la classe Operateur
  */

#include <stdexcept>
#include <QString>
#include <QStringList>

#include "Expression.h"
#include "Fabrique.h"
#include "Pile.h"
#include "Calculatrice.h"

/*! \namespace LO21
 *  \brief Designe les classes definies dans le but du projet de LO21 P12
 */
namespace LO21{
    /*! \enum enumOperateurs
     * \brief Definit tous les types d'operateurs possibles dans une expression
     */
    enum enumOperateurs {ADD, MUL, SOU, DIV, COS, SIN, TAN, COSH, SINH, TANH, SQR, CUBE, SQRT, INV, SIGN, LN, LOG, POW, FACT, MOD, EVALUATION};

    /*! \class Operateur
     * \brief Classe permettant de gerer les differents types d'operateurs
     */
    class Operateur: public Expression {
        protected:
            enumOperateurs _operateur; /*! Le type de l'operateur */

        public:
            /*! \fn QString toString() const
             * \brief Renvoie une forme textuelle de l'operateur pour affichage
             * \return QString contenant le texte correspondant a l'operateur
             */
            QString toString() const =0;

            /*! \fn QString getOperator() const
             * \brief Retourne le type de l'operateur sous une forme textuelle
             * \return QString qui est le texte de l'operateur
             */
            QString getOperator() const{ return toString(); }

            /*! \fn void appliqueOperateur()
             * \brief Permet d'appeler la fonction correspondant a un operateur
             */
            void appliqueOperateur();

            /*! \fn void EVAL()
             * \brief Evalue un operateur
             */
            void EVAL();

            /*! \fn QString& afficher()
             * \brief Sert a l'affichage de l'operateur
             * \return QString& une reference vers le QString contenant l'affichage textuel de l'operateur
             */
            QString& afficher();

            /*! \fn Operateur* clone() const
             * \brief Permet de dupliquer un objet Operateur
             * \return Operateur* un pointeur vers l'operateur nouvellement cree
             */
            Operateur* clone() const;
    };
}

#endif // OPERATEUR_H
