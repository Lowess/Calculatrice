/** \file Option.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-t�te pour d�claration de la classe Option
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
 *  \brief D�signe les classes d�finies dans le but du projet de LO21 P12
 */
namespace LO21{
/*! \class Complexe
 * \brief Classe permettant de g�rer les nombres complexes
 */
    class Option {
    private:
        TypeDiv _typeDiv; /*! */
        bool _complexe, _degre; /*! */
        static Option* _option; /*! */

        /*! \class Complexe
         * \brief Classe permettant de g�rer les nombres complexes
         */
        Option(){
            _complexe = false;
            _degre = false;
            _typeDiv = MENU_ENTIER;
            //connecter les slots pour le faire appara�tre � l'�cran
        }

        /*! \class Complexe
         * \brief Classe permettant de g�rer les nombres complexes
         */
        void switchDegre(bool d){
            _degre = d;
        }

        /*! \class Complexe
         * \brief Classe permettant de g�rer les nombres complexes
         */
        void switchComplexe(bool c){
            _complexe = c;
        }

    public:

        /*! \class Complexe
         * \brief Classe permettant de g�rer les nombres complexes
         */
        static Option& getInstance();

        /*! \class Complexe
         * \brief Classe permettant de g�rer les nombres complexes
         */
        static void libereInstance();

        /*! \class Complexe
         * \brief Classe permettant de g�rer les nombres complexes
         */
        void set_typeDiv(TypeDiv s);

        /*! \class Complexe
         * \brief Classe permettant de g�rer les nombres complexes
         */
        TypeDiv get_typeDiv() const{ return _typeDiv; }

        /*! \class Complexe
         * \brief Classe permettant de g�rer les nombres complexes
         */
        void saveOptions();

        /*! \class Complexe
         * \brief Classe permettant de g�rer les nombres complexes
         */
        QString toString() const;

    };
}

#endif // OPTION_H
