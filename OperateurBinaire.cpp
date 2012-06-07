#include "OperateurBinaire.h"
#include "CalculatriceException.h"

<<<<<<< HEAD
Calculatrice::OperateurBinaire::OperateurBinaire(const QString op){
=======
using namespace Calculatrice;

Calculatrice::OperateurBinaire::OperateurBinaire(const QString& op){
>>>>>>> d50d9c44f71eff56d4eada027bfcd613b1693de1
    if (op == "+")
        _operateur = ADD;
    else if (op == "-")
        _operateur = SOU;
    else if (op == "*")
        _operateur = MUL;
    else if (op == "/")
        _operateur = DIV;
<<<<<<< HEAD
    else if (op == "LOG")
        _operateur = LOG;
    else if (op == "PWR")
        _operateur = PWR;
    else
        //lancer erreur
        std::cout << "Operateur binaire non reconnu" << std::endl;
=======
    else //lancer erreur
        throw CalculatriceException(typeid(this).name(), OTHER, "Operateur binaire non reconnu");
>>>>>>> d50d9c44f71eff56d4eada027bfcd613b1693de1
}

QString Calculatrice::OperateurBinaire::toString() const{
    QString s;
    switch(_operateur){
<<<<<<< HEAD
    case ADD: s = "+"; break;
    case SOU: s = "-"; break;
    case MUL: s = "*"; break;
    case DIV: s = "/"; break;
    case LOG: s = "LOG"; break;
    case PWR: s = "PWR"; break;
    default: //lancer erreur
        std::cout << "ERROR" << std::endl; break;
=======
        case ADD: s = "+"; break;
        case SOU: s = "-"; break;
        case MUL: s = "*"; break;
        case DIV: s = "/"; break;
        default: //lancer erreur
            throw CalculatriceException(typeid(this).name(), OTHER, "Erreur affichage opérateur");
            break;
>>>>>>> d50d9c44f71eff56d4eada027bfcd613b1693de1
    }
    return s;
}

<<<<<<< HEAD
Calculatrice::Expression& Calculatrice::OperateurBinaire::calcul(const Calculatrice::Expression& e1, const Calculatrice::Expression& e2) {
    //faire du calcul =D
    return;
}

bool Calculatrice::OperateurBinaire::isOperateurBinaire() {
    switch(_operateur) {
        case ADD: return true;
        case SOU: return true;
        case MUL: return true;
        case DIV: return true;
        case LOG: return true;
        case PWR: return true;
        default: return false;
    }
}
=======
QString& Calculatrice::OperateurBinaire::getOperator() const{}

/*
Expression& Calculatrice::OperateurBinaire::eval(const Expression& e1, const Expression& e2) {

}
*/
>>>>>>> d50d9c44f71eff56d4eada027bfcd613b1693de1
