#include "OperateurBinaire.h"
#include "CalculatriceException.h"

using namespace Calculatrice;

Calculatrice::OperateurBinaire::OperateurBinaire(const QString& op){
    if (op == "+")
        _operateur = ADD;
    else if (op == "-")
        _operateur = SOU;
    else if (op == "*")
        _operateur = MUL;
    else if (op == "/")
        _operateur = DIV;
    else //lancer erreur
        throw CalculatriceException(typeid(this).name(), OTHER, "Operateur binaire non reconnu");
}

QString Calculatrice::OperateurBinaire::toString() const{
    QString s;
    switch(_operateur){
        case ADD: s = "+"; break;
        case SOU: s = "-"; break;
        case MUL: s = "*"; break;
        case DIV: s = "/"; break;
        default: //lancer erreur
            throw CalculatriceException(typeid(this).name(), OTHER, "Erreur affichage opérateur");
            break;
    }
    return s;
}

Calculatrice::enumOperateurs Calculatrice::OperateurBinaire::getOperator() const{
    return _operateur;
}

/*
Expression& Calculatrice::OperateurBinaire::eval(const Expression& e1, const Expression& e2) {

}
*/
