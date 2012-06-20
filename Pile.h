#ifndef PILE_H
#define PILE_H

/*! \file Pile.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-t�te pour d�claration de la classe Pile
  */

#include <QStack>
#include <QDebug>

#include "Expression.h"
#include "Rationnel.h"

/*! \namespace LO21
 *  \brief D�signe les classes d�finies dans le but du projet de LO21 P12
 */
namespace LO21{
    class Gardien;

    /*! \class Pile
     * \brief Classe stockant et manipulant les Expressions pour calcul
     */
    class Pile: public QStack<Expression*>{
        private:
            Pile* _etat; /*! La pile affich�e */
        public:
            /*! \fn Pile()
             * \brief Constructeur par d�faut de la classe Pile
             */
            Pile():_etat(this){}

            /*! \fn void SWAP(int x, int y)
             * \brief Permet d'�changer la place de deux �l�ments dans la pile
             * \param x l'indice du premier �l�ment � �changer
             * \param y l'indice du deuxi�me �l�ment � �changer
             */
            void SWAP(int x, int y);

            /*! \fn void SUM(int n)
             * \brief Calculer la somme des n premiers �l�ments de la pile
             */
            void SUM(int n);

            /*! \fn void MEAN(int n)
             * \brief Calcule la moyenne des n premiers �l�ments de la pile
             */
            void MEAN(int n);

            /*! \fn void CLEAR()
             * \brief Efface toutes les Expressions pr�sentes dans la pile
             */
            void CLEAR();

            /*! \fn void DUP()
             * \brief Duplique l'�l�ment au sommet de la pile
             */
            void DUP();

            /*! \fn void DROP()
             * \brief Ote l'�l�ment au sommet de la pile
             */
            void DROP();

            /*! \fn void sauvegarder()
             * \brief Sauvegarde l'�tat actuel de la pile
             */
            void sauvegarder();

            /*! \fn void charger()
             * \brief Charge un �tat donn� de la pile
             */
            void charger();

            /*! \fn Pile* clone() const
             * \brief Duplique la pile actuellement utilis�e
             * \return Pile* un pointeur vers la pile cr��e par la pile appelante
             */
            Pile* clone() const;

            /*! \fn void afficherPileCourante() const
             * \brief Affiche les �l�ments pr�sents dans la pile
             */
            void afficherPileCourante() const;

            /*! \fn void afficherPileMemoire() const
             * \brief Affiche les �l�ments pr�sents dans la pile �tant sauvegard�e en m�moire
             */
            void afficherPileMemoire() const;

            //DP Memento
            /*! \class Memento
             * \brief Classe permettant de g�rer divers �tats d'un m�me objet
             */
            class Memento{
                private:
                    Pile* _etat; /*! La pile dont on veut garder l'�tat en m�moire */

                public:
                    /*! \fn Memento(const Pile* petat)
                     * \brief Constructeur de la classe Memento
                     * \param petat pointeur vers la pile actuelle � sauver en m�moire
                     */
                    Memento(const Pile* petat):_etat(petat->clone()){}

                    /*! \fn Pile* get_etat() const
                     * \brief Retourne l'�tat sauvegard� de la pile
                     * \return Pile* pointeur vers la pile sauvegard�e
                     */
                    Pile* get_etat() const {return _etat; }
            };

            /*! \fn Memento* sauverDansMemento()
             * \brief Permet de sauver l'�tat de la pile actuelle
             * \return Memento* pile vers la structure permettant de sauvegarder l'�taat
             */
            Memento* sauverDansMemento();

            /*! \fn void restaurerDepuisMemento(const Memento* m)
             * \brief Permet de restaurer la pile � un �tat ant�rieur sauv� dans l'objet Memento
             * \param m pointeur vers l'objet Memento contenant l'�tat � restaurer
             */
            void restaurerDepuisMemento(const Memento* m);

            /*! \fn Pile* get_etat() const
             * \brief Retourne l'�tat actuel de la pile
             * \return Pile* pointeur vers la pile actuelle
             */
            Pile* get_etat()const;
    };
}

#endif // PILE_H
