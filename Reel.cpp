#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"

using namespace Calculatrice;

//RÃ©alise l'addition d'un Reel avec un Nombre (Entier, Reel, Rationnel)
Calculatrice::Nombre& Calculatrice::Reel::addition(const Nombre& nb) const{
    //On essaye le cast en Reel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0) //Si echec erreur
                throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");

            else{ //Si succÃ¨s on rÃ©alise l'addition Reel + Rationnel
                Nombre& ref=toRationnel().addition(*tmp_ra);
                return (ref);
            }
        }
        else{ //Si succÃ¨s on rÃ©alise l'addition Reel + Reel
            Reel* res= new Reel(_x + tmp_re->get_x());
            Nombre& ref=*res;
            return (ref);
        }
    }
    else{ //Si succÃ¨s on rÃ©alise l'addition Reel + Entier
        Nombre& ref=tmp_en->addition(*this);
        return (ref);
    }
}

//RÃ©alise la soustraction d'un Reel avec un Nombre (Entier, Reel, Rationnel)
Calculatrice::Nombre& Calculatrice::Reel::soustraction(const Nombre& nb) const{
    //On essaye le cast en Reel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){ //Si echec erreur
                throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
            }
            else{ //Si succÃ¨s on rÃ©alise la soustraction Reel - Rationnel
                Nombre& ref=toRationnel().soustraction(*tmp_ra);
                return (ref);
            }
        }
        else{ //Si succÃ¨s on rÃ©alise la soustraction Reel - Reel
            Reel* res= new Reel(_x - tmp_re->get_x());
            Nombre& ref=*res;
            return (ref);
        }
    }
    else{ //Si succÃ¨s on rÃ©alise la soustraction Reel - Entier
        Nombre& ref=tmp_en->soustraction(*this).SIGN(); //Inversion de signe car appel Ã  Entier - Reel
        return (ref);
    }
}

//RÃ©alise la multiplication d'un Reel avec un Nombre (Entier, Reel, Rationnel)
Calculatrice::Nombre& Calculatrice::Reel::multiplication(const Nombre& nb) const{
    //On essaye le cast en Reel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0) //Si echec erreur
                throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");

            else{ //Si succÃ¨s on rÃ©alise la multiplication Reel * Rationnel
                Reel res(_x * tmp_ra->get_n().get_x());
                Nombre& ref=res.toRationnel();
                return (ref);
            }
        }
        else{ //Si succÃ¨s on rÃ©alise la multiplication Reel * Reel
            Reel* res= new Reel(_x * tmp_re->get_x());
            Nombre& ref=*res;
            return (ref);
        }
    }
    else{ //Si succÃ¨s on rÃ©alise la multiplication Reel * Entier
        Nombre& ref=tmp_en->multiplication(*this);
        return (ref);
    }
}

//RÃ©alise la division d'un Reel par un Nombre (Entier, Reel, Rationnel)
Calculatrice::Nombre& Calculatrice::Reel::division(const Nombre& nb) const{
    //On essaye le cast en Reel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){ //Si echec erreur
                throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
            }
            else{ //Si succÃ¨s on rÃ©alise la division Reel / Rationnel
                Nombre& ref=toRationnel().division(*tmp_ra);
                return (ref);
            }
        }
        else{ //Si succÃ¨s on rÃ©alise la division Reel / Reel
            if(tmp_re->get_x()==0) //Si division par 0 Exception
                throw CalculatriceException(typeid(nb).name(),MATHS,"Division par 0");
            Reel* res=new Reel(this->_x / tmp_re->get_x());
            Nombre& ref=*res;
            return (ref);
        }
    }
    else{ //Si succÃ¨s on rÃ©alise la division Reel / Entier
        Nombre& ref=tmp_en->division(*this).INV();
        return (ref);
    }
}


QString Calculatrice::Reel::toString() const{
    QString str;
    str.setNum(_x);
    return str;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Implementation des mÃ©thodes vituelles pures de la class "Expression"
void Calculatrice::Reel::EVAL(){}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Calculatrice::Rationnel& Calculatrice::Reel::toRationnel() const{
    //Conversion du rÃ©el en rationnel 3.31 = 331/100
    QString str;
    str.setNum(_x); //CrÃ©ation d'un QString depuis le Reel

    QStringList list=str.split("."); //SÃ©paration partie entiere et decimale
    int nbdec=list.value(1).count(); //Compte le nombre de dÃ©cimale

    Rationnel* res= new Rationnel(_x * pow(10,nbdec), pow(10,nbdec));
    res->simplifier();
    Rationnel& ref=*res;
    return (ref); //Construction du Rationnel correspondant au Reel +1 car valeur tronquÃ©e
}



Calculatrice::Entier& Calculatrice::Reel::toEntier() const{
    //Conversion du rÃ©el en entier 3.0 = 3
    Entier* res= new Entier(_x);
    Entier& ref=*res;
    return (ref);
}
