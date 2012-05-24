#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"

using namespace Calculatrice;

//Implementation des méthodes vituelles pures de la class "Nombre"
void Calculatrice::Reel::SIN(){}
void Calculatrice::Reel::COS(){}
void Calculatrice::Reel::TAN(){}
void Calculatrice::Reel::SINH(){}
void Calculatrice::Reel::COSH(){}
void Calculatrice::Reel::TANH(){}
void Calculatrice::Reel::LN(){}
void Calculatrice::Reel::LOG(){}
void Calculatrice::Reel::INV(){}
void Calculatrice::Reel::SQRT(){}
void Calculatrice::Reel::POW(){}


//Réalise l'addition d'un Reel avec un Nombre (Entier, Reel, Rationnel)
Calculatrice::Nombre& Calculatrice::Reel::addition(const Nombre& nb) const{
    //On essaye le cast en Reel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0) //Si echec erreur
                throw;

            else{ //Si succès on réalise l'addition Reel + Rationnel
                Nombre& ref=toRationnel().addition(*tmp_ra);
                return (ref);
            }
        }
        else{ //Si succès on réalise l'addition Reel + Reel
            Reel* res= new Reel(_x + tmp_re->get_x());
            Nombre& ref=*res;
            return (ref);
        }
    }
    else{ //Si succès on réalise l'addition Reel + Entier
        Nombre& ref=tmp_en->addition(*this);
        return (ref);
    }
}

//Réalise la soustraction d'un Reel avec un Nombre (Entier, Reel, Rationnel)
Calculatrice::Nombre& Calculatrice::Reel::soustraction(const Nombre& nb) const{
    //On essaye le cast en Reel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){ //Si echec erreur
                throw;
            }
            else{ //Si succès on réalise la soustraction Reel + Rationnel
                Nombre& ref=toRationnel().soustraction(*tmp_ra);
                return (ref);
            }
        }
        else{ //Si succès on réalise la soustraction Reel + Reel
            Reel* res= new Reel(_x - tmp_re->get_x());
            Nombre& ref=*res;
            return (ref);
        }
    }
    else{ //Si succès on réalise la soustraction Reel + Entier
        Nombre& ref=tmp_en->soustraction(*this);
        return (ref);
    }
}

//Réalise la multiplication d'un Reel avec un Nombre (Entier, Reel, Rationnel)
Calculatrice::Nombre& Calculatrice::Reel::multiplication(const Nombre& nb) const{
    //On essaye le cast en Reel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0) //Si echec erreur
                throw;

            else{ //Si succès on réalise la multiplication Reel * Rationnel
                Nombre& ref=toRationnel().multiplication(*tmp_ra);
                return (ref);
            }
        }
        else{ //Si succès on réalise la multiplication Reel * Reel
            Reel* res= new Reel(_x * tmp_re->get_x());
            Nombre& ref=*res;
            return (ref);
        }
    }
    else{ //Si succès on réalise la multiplication Reel * Entier
        Nombre& ref=tmp_en->multiplication(*this);
        return (ref);
    }
}

//Réalise la division d'un Reel par un Nombre (Entier, Reel, Rationnel)
Calculatrice::Nombre& Calculatrice::Reel::division(const Nombre& nb) const{
    //On essaye le cast en Reel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){ //Si echec erreur
                throw;
            }
            else{ //Si succès on réalise la division Reel / Rationnel
                Nombre& ref=toRationnel().division(*tmp_ra);
                return (ref);
            }
        }
        else{ //Si succès on réalise la division Reel / Reel
            if(tmp_re->get_x()==0) //Si division par 0 Exception
                throw CalculatriceException(typeid(nb).name(),MATHS,"Division par 0");
            Reel* res=new Reel(this->_x / tmp_re->get_x());
            Nombre& ref=*res;
            return (ref);
        }
    }
    else{ //Si succès on réalise la division Reel / Entier
        Nombre& ref=tmp_en->division(*this);
        return (ref);
    }
}


QString Calculatrice::Reel::toString() const{
    QString str;
    str.setNum(_x);
    return str;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Implementation des méthodes vituelles pures de la class "Expression"
void Calculatrice::Reel::EVAL(){}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Calculatrice::Rationnel Calculatrice::Reel::toRationnel() const{
    //Conversion du réel en rationnel 3.31 = 331/100
    QString str;
    str.setNum(_x); //Création d'un QString depuis le Reel

    QStringList list=str.split("."); //Séparation partie entiere et decimale
    int nbdec=list.value(1).count(); //Compte le nombre de décimale

    return (new Rationnel(_x * pow(10,nbdec) + 1, pow(10,nbdec))); //Construction du Rationnel correspondant au Reel +1 car valeur tronquée
}

