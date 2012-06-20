/** \file Expression.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe Expression
  */

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <QTextStream>

/*! \namespace LO21
 *  \brief Désigne les classes définies dans le but du projet de LO21 P12
 */
namespace LO21{

    class Constante;
    class Operateur;

    /*! \class Complexe
     * \brief Classe permettant de gérer les nombres complexes
     */
    class Expression {
        private:

        public:
            //MÃ©thodes virtuelles pures
            //virtual Expression& EVAL() =0;

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            virtual void EVAL() = 0;

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            virtual QString toString() const =0;

        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
            void afficher() const{
                QTextStream cout(stdout, QIODevice::WriteOnly);
                cout << this->toString();
            }

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            virtual Expression* clone() const=0;
    };
}

/*! \class Complexe
 * \brief Classe permettant de gérer les nombres complexes
 */
QTextStream& operator<<(QTextStream& s, const LO21::Expression& n);

#endif // EXPRESSION_H
