#include "OperateurUnaire.h"

LO21::OperateurUnaire::OperateurUnaire(const QString op){
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
    else if (op == "!")
        _operateur = FACT;
    else if (op == "LOG")
        _operateur = LOG;
    else if (op == "LN")
        _operateur = LN;
    else if (op == "EVAL")
        _operateur = EVALUATION;

    else //lancer erreur
        throw CalculatriceException(typeid(this).name(), OTHER, "Operateur unaire non reconnu");
}

/*LO21::enumOperateurs LO21::OperateurUnaire::getOperator() const{
    return _operateur;
}*/

QString LO21::OperateurUnaire::toString() const{
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
        case FACT: s = "!"; break;
        case LOG: s = "LOG"; break;
        case LN: s = "LN"; break;
        case EVALUATION: s = "EVAL"; break;

        default: //lancer erreur
            throw CalculatriceException(typeid(this).name(), OTHER, "Erreur affichage opérateur");
            break;
    }
    return s;
}

