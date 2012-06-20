#ifndef OPTION_H
#define OPTION_H

#include <QString>
#include <QTextStream>
#include <typeinfo>
#include <QFile>

#include "CalculatriceException.h"
#include "LogSystem.h"
/*Template method : singleton*/

enum TypeDiv {MENU_ENTIER, MENU_REEL, MENU_RATIONNEL};

namespace LO21{
    class Option {
    private:
        TypeDiv _typeDiv;
        bool _complexe;
        bool _degre;
        static Option* _option;

        Option():_complexe(false), _degre(false), _typeDiv(MENU_ENTIER){}

    public:

        /*
         *Exécuté au chargement de l'application
         *Charge le log précédent
         */
        static Option& getInstance();
        static void libereInstance();


        void set_typeDiv(TypeDiv s);
        void set_complexe(bool b){
            _complexe = b;
        }
        void set_degre(bool b){
            _degre= b;
        }

        TypeDiv get_typeDiv() const{ return _typeDiv; }
        bool get_degre() const{ return _degre; }
        bool get_complexe() const{ return _complexe; }


        QString toString() const;


    };
}

#endif // OPTION_H
