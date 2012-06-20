/** \file Pile.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe Pile
  */

#ifndef PILE_H
#define PILE_H

#include <QStack>
#include <QDebug>

#include "Expression.h"
#include "Rationnel.h"

/*! \namespace LO21
 *  \brief Désigne les classes définies dans le but du projet de LO21 P12
 */
namespace LO21{
    class Gardien;
    /*! \class Complexe
     * \brief Classe permettant de gérer les nombres complexes
     */
    class Pile: public QStack<Expression*>{
        private:
            Pile* _etat; /*! */
        public:
            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            Pile():_etat(this){}

            //MÃƒÂ©thodes agissant sur la pile
            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            void SWAP(int x, int y);

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            void SUM(int n);

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            void MEAN(int n);

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            void CLEAR();

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            void DUP();

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            void DROP();

            //MÃ©thodes de sauvegarde et de chargement

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            void sauvegarder();

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            void charger();

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            Pile* clone() const;

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            void afficherPileCourante() const;

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            void afficherPileMemoire() const;

            //DP Memento
            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            class Memento{
                private:
                    Pile* _etat; /*! */

                public:
                    /*! \class Complexe
                     * \brief Classe permettant de gérer les nombres complexes
                     */
                    Memento(const Pile* petat):_etat(petat->clone()){}

                    /*! \class Complexe
                     * \brief Classe permettant de gérer les nombres complexes
                     */
                    Pile* get_etat() const {return _etat; }
            };

            //void mementoSuivant(){}

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            Memento* sauverDansMemento();

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            void restaurerDepuisMemento(const Memento* m);

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            Pile* get_etat()const;
    };
}

#endif // PILE_H
