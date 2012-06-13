#include "Gardien.h"

using namespace std;
using namespace LO21;

LO21::Gardien* LO21::Gardien::_gard=0;

//Méthodes publiques
LO21::Gardien* LO21::Gardien::getInstance(){
    if(_gard==0){
        _gard=new Gardien();
    }
    return _gard;
}

void LO21::Gardien::libereInstance(){
    if(_gard!=0){
        delete _gard;
    }
    _gard=0;
}

