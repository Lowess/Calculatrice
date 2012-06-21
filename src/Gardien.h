#ifndef GARDIEN_H
#define GARDIEN_H

/*! \file Gardien.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tete pour declaration de la classe Gardien
  */

#include <QString>
#include <QStack>
#include "Pile.h"

/*! \namespace LO21
 *  \brief Designe les classes definies dans le but du projet de LO21 P12
 */
using namespace LO21;

namespace LO21{
    //class Pile;
    //class Pile::Memento;

    /*! \class Gardien
     * \brief Classe qui s'occupe de gerer les operations d'undo redo grace
     * a l'implementation d'un design pattern Memento
     */
    class Gardien{
        private:
            static Gardien* _gard; /*! L'instance du gardien */
            int _index; /*! Index permettant de situer la pile actuellement affichee dans la pile des etats des piles */
            QStack<Pile::Memento*> _liste; /*! Pile contenant les differents etats de la pile utilisee par la calculatrice */

            /*! \fn Gardien()
             * \brief Constructeur de la classe Gardien
             */
            Gardien():_index(0){}

            /*! \fn Gardien(const Gardien&)
             * \brief Constructeur par recopie de la classe Gardien
             * \param g Une instance de la classe gardien
             */
            Gardien(const Gardien& g){}

            /*! \fn ~Gardien()
             * \brief Destructeur de la classe Gardien
             */
            ~Gardien(){}

        public:
            /*! \fn static Gardien* getInstance()
             * \brief Recupere l'instance de l'objet Gardien, et s'il n'en existe pas, en cree une
             * \return Gardien* un pointeur vers l'objet Gardien surveillant l'etat de la calculatrice
             */
            static Gardien* getInstance();

            /*! \fn static void libereInstance()
             * \brief Demande la destruction de l'instance de la classe Gardien
             */
            static void libereInstance();

            /*! \fn void ajouterMementoUndo(Pile::Memento* pMemento)
             * \brief Constructeur de la classe Memento
             * \param petat pointeur vers la pile actuelle a sauver en memoire
             */
            void ajouterMementoUndo(Pile::Memento* pMemento);

            /*! \fn void ajouterMementoRedo(Pile::Memento* pMemento)
             * \brief Constructeur de la classe Memento
             * \param petat pointeur vers la pile actuelle a sauver en memoire
             */
            void ajouterMementoRedo(Pile::Memento* pMemento);

            /*! \fn Pile::Memento* getMementoUndo()
             * \brief Constructeur de la classe Memento
             * \param petat pointeur vers la pile actuelle a sauver en memoire
             */
            Pile::Memento* getMementoUndo();

            /*! \fn Pile::Memento* getMementoRedo()
             * \brief Constructeur de la classe Memento
             * \param petat pointeur vers la pile actuelle a sauver en memoire
             */
            Pile::Memento* getMementoRedo();

            /*! \fn Memento(const Pile* petat)
             * \brief Constructeur de la classe Memento
             * \param petat pointeur vers la pile actuelle a sauver en memoire
             */
            void afficher();

            /*! \fn void set_index(int i)
             * \brief Permet de modifier l'attribut index du Gardien
             * \param i l'indice de la pile actuellement utilisee
             */
            void set_index(int i){ _index=i; }
    };
}

#endif // GARDIEN_H
