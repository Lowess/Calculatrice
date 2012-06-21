#ifndef PILE_H
#define PILE_H

/*! \file Pile.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe Pile
  */

#include <QStack>
#include <QDebug>

#include "Expression.h"
#include "Rationnel.h"

/*! \namespace LO21
 *  \brief Désigne les classes définies dans le but du projet de LO21 P12
 */
namespace LO21{
    class Gardien;

    /*! \class Pile
     * \brief Classe stockant et manipulant les Expressions pour calcul
     */
    class Pile: public QStack<Expression*>{
        private:
            Pile* _etat; /*! La pile affichée */
        public:
            /*! \fn Pile()
             * \brief Constructeur par défaut de la classe Pile
             */
            Pile():_etat(this){}

            /*! \fn void SWAP(int x, int y)
             * \brief Permet d'échanger la place de deux éléments dans la pile
             * \param x l'indice du premier élément à échanger
             * \param y l'indice du deuxième élément à échanger
             */
            void SWAP(int x, int y);

            /*! \fn void SUM(int n)
             * \brief Calculer la somme des n premiers éléments de la pile
             */
            void SUM(int n);

            /*! \fn void MEAN(int n)
             * \brief Calcule la moyenne des n premiers éléments de la pile
             */
            void MEAN(int n);

            /*! \fn void CLEAR()
             * \brief Efface toutes les Expressions présentes dans la pile
             */
            void CLEAR();

            /*! \fn void DUP()
             * \brief Duplique l'élément au sommet de la pile
             */
            void DUP();

            /*! \fn void DROP()
             * \brief Ote l'élément au sommet de la pile
             */
            void DROP();

            /*! \fn void sauvegarder()
             * \brief Sauvegarde l'état actuel de la pile
             */
            void sauvegarder();

            /*! \fn void charger()
             * \brief Charge un état donné de la pile
             */
            void charger();

            /*! \fn Pile* clone() const
             * \brief Duplique la pile actuellement utilisée
             * \return Pile* un pointeur vers la pile créée par la pile appelante
             */
            Pile* clone() const;

            /*! \fn void afficherPileCourante() const
             * \brief Affiche les éléments présents dans la pile
             */
            void afficherPileCourante() const;

            /*! \fn void afficherPileMemoire() const
             * \brief Affiche les éléments présents dans la pile étant sauvegardée en mémoire
             */
            void afficherPileMemoire() const;

            //DP Memento
            /*! \class Memento
             * \brief Classe permettant de gérer divers états d'un même objet
             */
            class Memento{
                private:
                    Pile* _etat; /*! La pile dont on veut garder l'état en mémoire */

                public:
                    /*! \fn Memento(const Pile* petat)
                     * \brief Constructeur de la classe Memento
                     * \param petat pointeur vers la pile actuelle à sauver en mémoire
                     */
                    Memento(const Pile* petat):_etat(petat->clone()){}

                    /*! \fn Pile* get_etat() const
                     * \brief Retourne l'état sauvegardé de la pile
                     * \return Pile* pointeur vers la pile sauvegardée
                     */
                    Pile* get_etat() const {return _etat; }
            };

            /*! \fn Memento* sauverDansMemento()
             * \brief Permet de sauver l'état de la pile actuelle
             * \return Memento* pile vers la structure permettant de sauvegarder l'étaat
             */
            Memento* sauverDansMemento();

            /*! \fn void restaurerDepuisMemento(const Memento* m)
             * \brief Permet de restaurer la pile à un état antérieur sauvé dans l'objet Memento
             * \param m pointeur vers l'objet Memento contenant l'état à restaurer
             */
            void restaurerDepuisMemento(const Memento* m);

            /*! \fn Pile* get_etat() const
             * \brief Retourne l'état actuel de la pile
             * \return Pile* pointeur vers la pile actuelle
             */
            Pile* get_etat()const;
    };
}

#endif // PILE_H
