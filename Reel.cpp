#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"

using namespace Calculatrice;

//Réalise l'addition d'un Reel avec un Constante (Entier, Reel, Rationnel)
Calculatrice::Constante& Calculatrice::Reel::addition(const Constante& nb) const{
    //On essaye le cast en Reel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0) //Si echec erreur
                throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");

            else{ //Si succès on réalise l'addition Reel + Rationnel
                Constante& ref=toRationnel().addition(*tmp_ra);
                return (ref);
            }
        }
        else{ //Si succès on réalise l'addition Reel + Reel
            Reel* res= new Reel(_x + tmp_re->get_x());
            Constante& ref=*res;
            return (ref);
        }
    }
    else{ //Si succès on réalise l'addition Reel + Entier
        Constante& ref=tmp_en->addition(*this);
        return (ref);
    }
}

//Réalise la soustraction d'un Reel avec un Constante (Entier, Reel, Rationnel)
Calculatrice::Constante& Calculatrice::Reel::soustraction(const Constante& nb) const{
    //On essaye le cast en Reel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){ //Si echec erreur
                throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
            }
            else{ //Si succès on réalise la soustraction Reel - Rationnel
                Constante& ref=toRationnel().soustraction(*tmp_ra);
                return (ref);
            }
        }
        else{ //Si succès on réalise la soustraction Reel - Reel
            Reel* res= new Reel(_x - tmp_re->get_x());
            Constante& ref=*res;
            return (ref);
        }
    }
    else{ //Si succès on réalise la soustraction Reel - Entier
        Constante& ref=tmp_en->soustraction(*this).SIGN(); //Inversion de signe car appel à Entier - Reel
        return (ref);
    }
}

//Réalise la multiplication d'un Reel avec un Constante (Entier, Reel, Rationnel)
Calculatrice::Constante& Calculatrice::Reel::multiplication(const Constante& nb) const{
    //On essaye le cast en Reel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0) //Si echec erreur
                throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");

            else{ //Si succès on réalise la multiplication Reel * Rationnel
                Reel res(_x * tmp_ra->get_n().get_x());
                Constante& ref=res.toRationnel();
                return (ref);
            }
        }
        else{ //Si succès on réalise la multiplication Reel * Reel
            Reel* res= new Reel(_x * tmp_re->get_x());
            Constante& ref=*res;
            return (ref);
        }
    }
    else{ //Si succès on réalise la multiplication Reel * Entier
        Constante& ref=tmp_en->multiplication(*this);
        return (ref);
    }
}

//Réalise la division d'un Reel par un Constante (Entier, Reel, Rationnel)
Calculatrice::Constante& Calculatrice::Reel::division(const Constante& nb) const{
    //On essaye le cast en Reel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){ //Si echec erreur
                throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
            }
            else{ //Si succès on réalise la division Reel / Rationnel
                Constante& ref=toRationnel().division(*tmp_ra);
                return (ref);
            }
        }
        else{ //Si succès on réalise la division Reel / Reel
            if(tmp_re->get_x()==0) //Si division par 0 Exception
                throw CalculatriceException(typeid(nb).name(),MATHS,"Division par 0");
            Reel* res=new Reel(this->_x / tmp_re->get_x());
            Constante& ref=*res;
            return (ref);
        }
    }
    else{ //Si succès on réalise la division Reel / Entier
        Constante& pt=tmp_en->division(*this);
        Nombre* pt2=dynamic_cast<Nombre *>(&pt);
        Constante& ref=pt2->INV();
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


Calculatrice::Rationnel& Calculatrice::Reel::toRationnel() const{
    //Conversion du réel en rationnel 3.31 = 331/100
    QString str;
    str.setNum(_x); //Création d'un QString depuis le Reel

    QStringList list=str.split("."); //Séparation partie entiere et decimale
    int nbdec=list.value(1).count(); //Compte le Constante de décimale

    Rationnel* res= new Rationnel(_x * pow(10,nbdec), pow(10,nbdec));
    res->simplifier();
    Rationnel& ref=*res;
    return (ref); //Construction du Rationnel correspondant au Reel +1 car valeur tronquée
}



Calculatrice::Entier& Calculatrice::Reel::toEntier() const{
    //Conversion du réel en entier 3.0 = 3
    Entier* res= new Entier(_x);
    Entier& ref=*res;
    return (ref);
}
