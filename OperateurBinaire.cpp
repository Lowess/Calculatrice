#include "OperateurBinaire.h"
#include "CalculatriceException.h"

Calculatrice::OperateurBinaire::OperateurBinaire(const QString op){
    if (op == "+")
        _operateur = ADD;
    else if (op == "-")
        _operateur = SOU;
    else if (op == "*")
        _operateur = MUL;
    else if (op == "/")
        _operateur = DIV;
    else if (op == "LOG")
        _operateur = LOG;
    else if (op == "PWR")
        _operateur = PWR;
    else
        //lancer erreur
        std::cout << "Operateur binaire non reconnu" << std::endl;
}

QString Calculatrice::OperateurBinaire::toString() const{
    QString s;
    switch(_operateur){
    case ADD: s = "+"; break;
    case SOU: s = "-"; break;
    case MUL: s = "*"; break;
    case DIV: s = "/"; break;
    case LOG: s = "LOG"; break;
    case PWR: s = "PWR"; break;
    default: //lancer erreur
        std::cout << "ERROR" << std::endl; break;
    }
    return s;
}

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
