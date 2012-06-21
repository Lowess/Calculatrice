#ifndef GARDIEN_H
#define GARDIEN_H

/*! \file Gardien.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe Gardien
  */

#include <QString>
#include <QStack>
#include "Pile.h"

/*! \namespace LO21
 *  \brief Désigne les classes définies dans le but du projet de LO21 P12
 */
using namespace LO21;

namespace LO21{
    //class Pile;
    //class Pile::Memento;

    /*! \class Gardien
     * \brief Classe qui s'occupe de gérer les opérations d'undo redo grâce
     * à l'implémentation d'un design pattern Memento
     */
    class Gardien{
        private:
            static Gardien* _gard; /*! L'instance du gardien */
            int _index; /*! Index permettant de situer la pile actuellement affichée dans la pile des états des piles */
            QStack<Pile::Memento*> _liste; /*! Pile contenant les différents états de la pile utilisée par la calculatrice */

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
             * \brief Récupère l'instance de l'objet Gardien, et s'il n'en existe pas, en créé une
             * \return Gardien* un pointeur vers l'objet Gardien surveillant l'état de la calculatrice
             */
            static Gardien* getInstance();

            /*! \fn static void libereInstance()
             * \brief Demande la destruction de l'instance de la classe Gardien
             */
            static void libereInstance();

            /*! \fn void ajouterMementoUndo(Pile::Memento* pMemento)
             * \brief Constructeur de la classe Memento
             * \param petat pointeur vers la pile actuelle à sauver en mémoire
             */
            void ajouterMementoUndo(Pile::Memento* pMemento);

            /*! \fn void ajouterMementoRedo(Pile::Memento* pMemento)
             * \brief Constructeur de la classe Memento
             * \param petat pointeur vers la pile actuelle à sauver en mémoire
             */
            void ajouterMementoRedo(Pile::Memento* pMemento);

            /*! \fn Pile::Memento* getMementoUndo()
             * \brief Constructeur de la classe Memento
             * \param petat pointeur vers la pile actuelle à sauver en mémoire
             */
            Pile::Memento* getMementoUndo();

            /*! \fn Pile::Memento* getMementoRedo()
             * \brief Constructeur de la classe Memento
             * \param petat pointeur vers la pile actuelle à sauver en mémoire
             */
            Pile::Memento* getMementoRedo();

            /*! \fn Memento(const Pile* petat)
             * \brief Constructeur de la classe Memento
             * \param petat pointeur vers la pile actuelle à sauver en mémoire
             */
            void afficher();

            /*! \fn void set_index(int i)
             * \brief Permet de modifier l'attribut index du Gardien
             * \param i l'indice de la pile actuellement utilisée
             */
            void set_index(int i){ _index=i; }
    };
}

#endif // GARDIEN_H
