#ifndef EXPRESSION_H
#define EXPRESSION_H

/*! \file Expression.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tete pour declaration de la classe Expression
  */

#include <QTextStream>

/*! \namespace LO21
 *  \brief Designe les classes definies dans le but du projet de LO21 P12
 */
namespace LO21{

    class Constante;
    class Operateur;

    /*! \class Expression
     * \brief Classe permettant d'encapsuler des Constantes et des Operateurs pour les stocker dans la pile
     */
    class Expression {
        public:
            /*! \class virtual void EVAL()
             * \brief Methode pure permettant d'evaluer un objet Expression
             */
            virtual void EVAL() = 0;

            /*! \class virtual QString toString() const
             * \brief Permet d'afficher sous forme textuelle les objets Expression
             * \return QString contenant le texte definissant l'objet Expression
             */
            virtual QString toString() const =0;

            /*! \fn void afficher() const
             * \brief Affiche l'expression
             */
            void afficher() const{
                QTextStream cout(stdout, QIODevice::WriteOnly);
                cout << this->toString();
            }

            /*! \fn virtual Expression* clone() const
             * \brief Duplique un objet Expression
             * \return Expression* un pointeur qui encapsule le reel objet duplique (Constante ou Operateur)
             */
            virtual Expression* clone() const=0;
    };
}

/*! \fn QTextStream& operator<<(QTextStream& s, const LO21::Expression& n)
 * \brief Classe permettant de gerer les nombres complexes
 * \param s
 * \param n
 * \return QTextStream&
 */
QTextStream& operator<<(QTextStream& s, const LO21::Expression& n);

#endif // EXPRESSION_H
