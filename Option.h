/** \file Option.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe Option
  */

#ifndef OPTION_H
#define OPTION_H

#include <QString>
#include <QTextStream>
#include <typeinfo>

#include "CalculatriceException.h"

/*Template method : singleton*/

enum TypeDiv {MENU_ENTIER, MENU_REEL, MENU_RATIONNEL};

/*! \namespace LO21
 *  \brief Désigne les classes définies dans le but du projet de LO21 P12
 */
namespace LO21{
/*! \class Complexe
 * \brief Classe permettant de gérer les nombres complexes
 */
    class Option {
    private:
        TypeDiv _typeDiv; /*! */
        bool _complexe, _degre; /*! */
        static Option* _option; /*! */

        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        Option(){
            _complexe = false;
            _degre = false;
            _typeDiv = MENU_ENTIER;
            //connecter les slots pour le faire apparaître à l'écran
        }

        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        void switchDegre(bool d){
            _degre = d;
        }

        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        void switchComplexe(bool c){
            _complexe = c;
        }

    public:

        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        static Option& getInstance();

        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        static void libereInstance();

        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        void set_typeDiv(TypeDiv s);

        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        TypeDiv get_typeDiv() const{ return _typeDiv; }

        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        void saveOptions();

        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        QString toString() const;

    };
}

#endif // OPTION_H
