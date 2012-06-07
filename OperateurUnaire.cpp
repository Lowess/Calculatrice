#include "OperateurUnaire.h"

<<<<<<< HEAD
Calculatrice::OperateurUnaire::OperateurUnaire(const QString op) {
    if(op == "COS")
        _operateur = COS;
    else if(op == "SIN")
        _operateur = SIN;
    else if(op == "TAN")
        _operateur = TAN;
    else if(op == "COSH")
        _operateur = COSH;
    else if(op == "SINH")
        _operateur = SINH;
    else if(op == "TANH")
        _operateur = TANH;
    else if(op == "LN")
        _operateur = LN;
    else if(op == "SQR")
        _operateur = SQR;
    else if(op == "CUBE")
        _operateur = CUBE;
    else if(op == "SQRT")
        _operateur = SQRT;
    else if(op == "INV")
        _operateur = INV;
    else if(op == "SIGN")
        _operateur = SIGN;
    else
        //throw erreur
        std::cout << "Erreur" << std::endl;
}

QString Calculatrice::OperateurUnaire::toString() const {
    QString s;
    switch(_operateur) {
        case COS: s = "COS"; break;
        case SIN: s = "SIN"; break;
        case TAN: s = "TAN"; break;
        case COSH: s = "COSH"; break;
        case SINH: s = "SINH"; break;
        case TANH: s = "TANH"; break;
        case LN: s = "LN"; break;
=======
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


QString& Calculatrice::OperateurUnaire::getOperator() const{}

QString Calculatrice::OperateurUnaire::toString() const{
    QString s;
    switch(_operateur){
        case SIN: s = "SIN"; break;
        case COS: s = "COS"; break;
        case TAN: s = "TAN"; break;
        case SINH: s = "SINH"; break;
        case COSH: s = "COSH"; break;
        case TANH: s = "TANH"; break;
>>>>>>> d50d9c44f71eff56d4eada027bfcd613b1693de1
        case SQR: s = "SQR"; break;
        case CUBE: s = "CUBE"; break;
        case SQRT: s = "SQRT"; break;
        case INV: s = "INV"; break;
        case SIGN: s = "SIGN"; break;
<<<<<<< HEAD
        default: s = "ERROR"; //lancer exception
            break;
    }
    return s;
}

Calculatrice::Expression& Calculatrice::OperateurUnaire::calcul(const Calculatrice::Expression& e) {
    //faire le calcul
    return;
}

bool Calculatrice::OperateurUnaire::isOperateurUnaire() {
    switch(_operateur) {
        case COS: return true;
        case SIN: return true;
        case TAN: return true;
        case COSH: return true;
        case SINH: return true;
        case TANH : return true;
        case LN : return true;
        case SQR: return true;
        case CUBE: return true;
        case SQRT: return true;
        case INV: return true;
        case SIGN: return true;
        default: return false;
    }
=======



        default: //lancer erreur
            throw CalculatriceException(typeid(this).name(), OTHER, "Erreur affichage opérateur");
            break;
    }
    return s;
>>>>>>> d50d9c44f71eff56d4eada027bfcd613b1693de1
}

