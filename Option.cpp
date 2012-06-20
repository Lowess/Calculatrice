#include "Option.h"

using namespace std;
using namespace LO21;

LO21::Option* LO21::Option::_option=0;

LO21::Option& LO21::Option::getInstance(){
    if(_option==0){
        _option = new Option();
        //try fopen(log.txt)
        //if fail : cr√©er fichier puis attribuer valeurs de base
    }
    return *_option;
}

void LO21::Option::libereInstance() {
    if (_option==0){
        delete _option;
    }
}

void LO21::Option::set_typeDiv(TypeDiv option){
    QTextStream cout(stdout, QIODevice::WriteOnly);

    cout << endl << "Changement du mode de constante en" << option << endl;

    switch(option){
        case MENU_ENTIER: _typeDiv = MENU_ENTIER; break;
        case MENU_REEL: _typeDiv = MENU_REEL; break;
        case MENU_RATIONNEL: _typeDiv = MENU_RATIONNEL; break;
        default: _typeDiv = MENU_ENTIER; break;

    }
}

void LO21::Option::saveOptions(){
//√  la fermeture du programme, sauver les options courantes dans le fichier log
}
