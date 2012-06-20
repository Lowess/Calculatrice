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
    class Option {
    private:
        TypeDiv _typeDiv;
        bool _complexe, _degre;
        static Option* _option;

        Option(){
            _complexe = false;
            _degre = false;
            _typeDiv = MENU_ENTIER;
            //connecter les slots pour le faire appara�tre � l'�cran
        }

        void switchDegre(bool d){
            _degre = d;
        }

        void switchComplexe(bool c){
            _complexe = c;
        }

    public:

        /*
         *Ex�cut� au chargement de l'application
         *Charge le log pr�c�dent
         */
        static Option& getInstance();
        static void libereInstance();

        void set_typeDiv(TypeDiv s);

        TypeDiv get_typeDiv() const{ return _typeDiv; }

        void saveOptions();

        QString toString() const;


    };
}

#endif // OPTION_H
