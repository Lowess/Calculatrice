#ifndef OPTION_H
#define OPTION_H

#include <QString>
#include <QTextStream>
#include <typeinfo>

#include "CalculatriceException.h"

/*Template method : singleton*/

enum TypeDiv {MENU_ENTIER, MENU_REEL, MENU_RATIONNEL};

namespace Calculatrice{
    class Option {
    private:
        TypeDiv _typeDiv;
        bool _complexe, _degre;
        static Option* _option;

        Option(){
            _complexe = false;
            _degre = false;
            _typeDiv = MENU_ENTIER;
            //connecter les slots pour le faire apparaître à l'écran
        }

        void switchDegre(){
            _degre = !_degre;
        }

        void switchComplexe(){
            _complexe = !_complexe;
        }

    public:

        /*
         *Exécuté au chargement de l'application
         *Charge le log précédent
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
