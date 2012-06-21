#ifndef PILE_H
#define PILE_H

/*! \file Pile.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tete pour declaration de la classe Pile
  */

#include <QStack>
#include <QDebug>

#include "Expression.h"
#include "Rationnel.h"

/*! \namespace LO21
 *  \brief Designe les classes definies dans le but du projet de LO21 P12
 */
namespace LO21{
    class Gardien;

    /*! \class Pile
     * \brief Classe stockant et manipulant les Expressions pour calcul
     */
    class Pile: public QStack<Expression*>{
        private:
            Pile* _etat; /*! La pile affichee */
        public:
            /*! \fn Pile()
             * \brief Constructeur par defaut de la classe Pile
             */
            Pile():_etat(this){}

            /*! \fn void SWAP(int x, int y)
             * \brief Permet d'echanger la place de deux elements dans la pile
             * \param x l'indice du premier element a echanger
             * \param y l'indice du deuxieme element a echanger
             */
            void SWAP(int x, int y);

            /*! \fn void SUM(int n)
             * \brief Calculer la somme des n premiers elements de la pile
             */
            void SUM(int n);

            /*! \fn void MEAN(int n)
             * \brief Calcule la moyenne des n premiers elements de la pile
             */
            void MEAN(int n);

            /*! \fn void CLEAR()
             * \brief Efface toutes les Expressions presentes dans la pile
             */
            void CLEAR();

            /*! \fn void DUP()
             * \brief Duplique l'element au sommet de la pile
             */
            void DUP();

            /*! \fn void DROP()
             * \brief Ote l'element au sommet de la pile
             */
            void DROP();

            /*! \fn void sauvegarder()
             * \brief Sauvegarde l'etat actuel de la pile
             */
            void sauvegarder();

            /*! \fn void charger()
             * \brief Charge un etat donne de la pile
             */
            void charger();

            /*! \fn Pile* clone() const
             * \brief Duplique la pile actuellement utilisee
             * \return Pile* un pointeur vers la pile creee par la pile appelante
             */
            Pile* clone() const;

            /*! \fn void afficherPileCourante() const
             * \brief Affiche les elements presents dans la pile
             */
            void afficherPileCourante() const;

            /*! \fn void afficherPileMemoire() const
             * \brief Affiche les elements presents dans la pile etant sauvegardee en memoire
             */
            void afficherPileMemoire() const;

            //DP Memento
            /*! \class Memento
             * \brief Classe permettant de gerer divers etats d'un meme objet
             */
            class Memento{
                private:
                    Pile* _etat; /*! La pile dont on veut garder l'etat en memoire */

                public:
                    /*! \fn Memento(const Pile* petat)
                     * \brief Constructeur de la classe Memento
                     * \param petat pointeur vers la pile actuelle a sauver en memoire
                     */
                    Memento(const Pile* petat):_etat(petat->clone()){}

                    /*! \fn Pile* get_etat() const
                     * \brief Retourne l'etat sauvegarde de la pile
                     * \return Pile* pointeur vers la pile sauvegardee
                     */
                    Pile* get_etat() const {return _etat; }
            };

            /*! \fn Memento* sauverDansMemento()
             * \brief Permet de sauver l'etat de la pile actuelle
             * \return Memento* pile vers la structure permettant de sauvegarder l'etaat
             */
            Memento* sauverDansMemento();

            /*! \fn void restaurerDepuisMemento(const Memento* m)
             * \brief Permet de restaurer la pile a un etat anterieur sauve dans l'objet Memento
             * \param m pointeur vers l'objet Memento contenant l'etat a restaurer
             */
            void restaurerDepuisMemento(const Memento* m);

            /*! \fn Pile* get_etat() const
             * \brief Retourne l'etat actuel de la pile
             * \return Pile* pointeur vers la pile actuelle
             */
            Pile* get_etat()const;
    };
}

#endif // PILE_H
