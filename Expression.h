#ifndef EXPRESSION_H
#define EXPRESSION_H

/*! \file Expression.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe Expression
  */

#include <QTextStream>

/*! \namespace LO21
 *  \brief Désigne les classes définies dans le but du projet de LO21 P12
 */
namespace LO21{

    class Constante;
    class Operateur;

    /*! \class Expression
     * \brief Classe permettant d'encapsuler des Constantes et des Opérateurs pour les stocker dans la pile
     */
    class Expression {
        public:
            /*! \class virtual void EVAL()
             * \brief Méthode pure permettant d'évaluer un objet Expression
             */
            virtual void EVAL() = 0;

            /*! \class virtual QString toString() const
             * \brief Permet d'afficher sous forme textuelle les objets Expression
             * \return QString contenant le texte définissant l'objet Expression
             */
            virtual QString toString() const =0;

            /*! \fn void afficher() const
             * \brief Affiche l'expression (pour debug)
             */
            /*void afficher() const{
                QTextStream cout(stdout, QIODevice::WriteOnly);
                cout << this->toString();
            }*/

            /*! \fn virtual Expression* clone() const
             * \brief Duplique un objet Expression
             * \return Expression* un pointeur qui encapsule le réel objet dupliqué (Constante ou Opérateur)
             */
            virtual Expression* clone() const=0;
    };
}

/*! \fn QTextStream& operator<<(QTextStream& s, const LO21::Expression& n)
 * \brief Classe permettant de gérer les nombres complexes
 * \param s
 * \param n
 * \return QTextStream&
 */
QTextStream& operator<<(QTextStream& s, const LO21::Expression& n);

#endif // EXPRESSION_H
