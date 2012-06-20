/** \file Gardien.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-t�te pour d�claration de la classe Gardien
  */

#ifndef GARDIEN_H
#define GARDIEN_H

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

    /*! \class Complexe
     * \brief Classe permettant de g�rer les nombres complexes
     */
    class Gardien{
        private:
            static Gardien* _gard; /*! */
            int _index; /*! */
            QStack<Pile::Memento*> _liste; /*! */

            /*! \class Complexe
             * \brief Classe permettant de g�rer les nombres complexes
             */
            Gardien():_index(0){}

            /*! \class Complexe
             * \brief Classe permettant de g�rer les nombres complexes
             */
            Gardien(const Gardien&){}

            /*! \class Complexe
             * \brief Classe permettant de g�rer les nombres complexes
             */
            ~Gardien(){}

        public:
            /*! \class Complexe
             * \brief Classe permettant de g�rer les nombres complexes
             */
            static Gardien* getInstance();

            /*! \class Complexe
             * \brief Classe permettant de g�rer les nombres complexes
             */
            static void libereInstance();

            /*! \class Complexe
             * \brief Classe permettant de g�rer les nombres complexes
             */
            void ajouterMementoUndo(Pile::Memento* pMemento);

            /*! \class Complexe
             * \brief Classe permettant de g�rer les nombres complexes
             */
            void ajouterMementoRedo(Pile::Memento* pMemento);

            /*! \class Complexe
             * \brief Classe permettant de g�rer les nombres complexes
             */
            Pile::Memento* getMementoUndo();

            /*! \class Complexe
             * \brief Classe permettant de g�rer les nombres complexes
             */
            Pile::Memento* getMementoRedo();

            /*! \class Complexe
             * \brief Classe permettant de g�rer les nombres complexes
             */
            void afficher();

            /*! \class Complexe
             * \brief Classe permettant de g�rer les nombres complexes
             */
            void set_index(int i){ _index=i; }
    };
}

#endif // GARDIEN_H
