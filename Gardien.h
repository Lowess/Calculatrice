#ifndef GARDIEN_H
#define GARDIEN_H

/*! \file Gardien.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-t�te pour d�claration de la classe Gardien
  */

#include <QString>
#include <QStack>
#include "Pile.h"

/*! \namespace LO21
 *  \brief D�signe les classes d�finies dans le but du projet de LO21 P12
 */
using namespace LO21;

namespace LO21{
    //class Pile;
    //class Pile::Memento;

    /*! \class Gardien
     * \brief Classe qui s'occupe de g�rer les op�rations d'undo redo gr�ce
     * � l'impl�mentation d'un design pattern Memento
     */
    class Gardien{
        private:
            static Gardien* _gard; /*! L'instance du gardien */
            int _index; /*! Index permettant de situer la pile actuellement affich�e dans la pile des �tats des piles */
            QStack<Pile::Memento*> _liste; /*! Pile contenant les diff�rents �tats de la pile utilis�e par la calculatrice */

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
             * \brief R�cup�re l'instance de l'objet Gardien, et s'il n'en existe pas, en cr�� une
             * \return Gardien* un pointeur vers l'objet Gardien surveillant l'�tat de la calculatrice
             */
            static Gardien* getInstance();

            /*! \fn static void libereInstance()
             * \brief Demande la destruction de l'instance de la classe Gardien
             */
            static void libereInstance();

            /*! \fn void ajouterMementoUndo(Pile::Memento* pMemento)
             * \brief Constructeur de la classe Memento
             * \param petat pointeur vers la pile actuelle � sauver en m�moire
             */
            void ajouterMementoUndo(Pile::Memento* pMemento);

            /*! \fn void ajouterMementoRedo(Pile::Memento* pMemento)
             * \brief Constructeur de la classe Memento
             * \param petat pointeur vers la pile actuelle � sauver en m�moire
             */
            void ajouterMementoRedo(Pile::Memento* pMemento);

            /*! \fn Pile::Memento* getMementoUndo()
             * \brief Constructeur de la classe Memento
             * \param petat pointeur vers la pile actuelle � sauver en m�moire
             */
            Pile::Memento* getMementoUndo();

            /*! \fn Pile::Memento* getMementoRedo()
             * \brief Constructeur de la classe Memento
             * \param petat pointeur vers la pile actuelle � sauver en m�moire
             */
            Pile::Memento* getMementoRedo();

            /*! \fn Memento(const Pile* petat)
             * \brief Constructeur de la classe Memento
             * \param petat pointeur vers la pile actuelle � sauver en m�moire
             */
            void afficher();

            /*! \fn void set_index(int i)
             * \brief Permet de modifier l'attribut index du Gardien
             * \param i l'indice de la pile actuellement utilis�e
             */
            void set_index(int i){ _index=i; }
    };
}

#endif // GARDIEN_H
