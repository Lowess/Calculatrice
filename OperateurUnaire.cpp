#include "OperateurUnaire.h"

Calculatrice::OperateurUnaire::OperateurUnaire(const QString op){
    if (op == "SIN")
        _operateur = SIN;
    else if (op == "COS")
        _operateur = COS;
    else if (op == "TAN")
        _operateur = TAN;
    else if (op == "SINH")
        _operateur = SINH;
    else if (op == "COSH")
        _operateur = COSH;
    else if (op == "TANH")
        _operateur = TANH;
    else if (op == "SQR")
        _operateur = SQR;
    else if (op == "CUBE")
        _operateur = CUBE;
    else if (op == "SQRT")
        _operateur = SQRT;
    else if (op == "INV")
        _operateur = INV;
    else if (op == "SIGN")
        _operateur = SIGN;
    else //lancer erreur
        throw CalculatriceException(typeid(this).name(), OTHER, "Operateur binaire non reconnu");
}


Calculatrice::enumOperateurs Calculatrice::OperateurUnaire::getOperator() const{
    return _operateur;
}

QString Calculatrice::OperateurUnaire::toString() const{
    QString s;
    switch(_operateur){
        case SIN: s = "SIN"; break;
        case COS: s = "COS"; break;
        case TAN: s = "TAN"; break;
        case SINH: s = "SINH"; break;
        case COSH: s = "COSH"; break;
        case TANH: s = "TANH"; break;
        case SQR: s = "SQR"; break;
        case CUBE: s = "CUBE"; break;
        case SQRT: s = "SQRT"; break;
        case INV: s = "INV"; break;
        case SIGN: s = "SIGN"; break;
        default: //lancer erreur
            throw CalculatriceException(typeid(this).name(), OTHER, "Erreur affichage opérateur");
            break;
    }
    return s;
}

