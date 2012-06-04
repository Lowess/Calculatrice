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
    else
        //lancer erreur
        cout << "Operateur binaire non reconnu" << endl;
}

QString& Calculatrice::OperateurBinaire::toString() const{
    QString s;
    switch(_operateur){
    case ADD: s = "+"; break;
    case SOU: s = "-"; break;
    case MUL: s = "*"; break;
    case DIV: s = "/"; break;
    default: //lancer erreur
        cout << "ERROR" << endl; break;
    }
    return s;
}

Expression& Calculatrice::OperateurBinaire::EVAL(const Expression& e1, const Expression& e2) {

}
