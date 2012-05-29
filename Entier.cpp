#include "Entier.h"
#include "Rationnel.h"
#include "CalculatriceException.h"

using namespace Calculatrice;

//Implementation des méthodes vituelles pures de la class "Nombre"

Nombre& Calculatrice::Entier::SIN() const{}
Nombre& Calculatrice::Entier::COS() const{}
Nombre& Calculatrice::Entier::TAN() const{}
Nombre& Calculatrice::Entier::SINH() const{}
Nombre& Calculatrice::Entier::COSH() const{}
Nombre& Calculatrice::Entier::TANH() const{}
Nombre& Calculatrice::Entier::LN() const{}
Nombre& Calculatrice::Entier::LOG() const{}
//Nombre& Calculatrice::Entier::INV() const{}
Nombre& Calculatrice::Entier::SQRT() const{}
Nombre& Calculatrice::Entier::POW() const{}

//Réalise l'addition d'un Entier avec un Nombre (Entier,Reel,Rationnel)
Calculatrice::Nombre& Calculatrice::Entier::addition(const Nombre& nb) const{
    //On essaye le cast en Entier
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){ //Si echec erreur
                throw;
            }
            else{ //Si succès on réalise l'addition Entier + Rationnel
                Entier num=(this->_x * tmp_ra->get_d().get_x() + tmp_ra->get_n().get_x()); //mise au même dénominateur et addition des numérateurs
                Entier den=tmp_ra->get_d().get_x();

                //Simplification par le PGCD
                Entier vpgcd=pgcd(num,den);
                num._x = num._x / vpgcd._x;
                den._x = den._x / vpgcd._x;
                Rationnel* res=new Rationnel(num, den);
                Nombre& ref=*res;
                return (ref);
            }
        }
        else{ //Si succès on réalise l'addition Entier + Reel
            Reel* res=new Reel(this->_x + tmp_re->get_x());
            Nombre& ref=*res;
            return (ref);
        }
    }
    else{ //Si succès on réalise l'addition Entier + Entier
            Entier* res=new Entier(this->_x + tmp_en->_x);
            Nombre& ref=*res;
            return (ref);
    }
}

//Réalise la soustraction d'un Entier avec un Nombre (Entier,Reel,Rationnel)
Calculatrice::Nombre& Calculatrice::Entier::soustraction(const Nombre& nb) const{
    //On essaye le cast en Entier
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){ //Si echec erreur
                throw;
            }
            else{ //Si succès on réalise la soustraction Entier - Rationnel
                Entier num(this->_x * tmp_ra->get_d().get_x() - tmp_ra->get_n().get_x()); //mise au même dénominateur et soustraction des numérateurs
                Entier den(tmp_ra->get_d().get_x());
                Rationnel* res=new Rationnel(num,den);
                Nombre& ref=*res;
                return (ref);
            }
        }
        else{ //Si succès on réalise la soustraction Entier - Reel
            Reel* res=new Reel(this->_x - tmp_re->get_x());
            Nombre& ref=*res;
            return (ref);
        }
    }
    else{ //Si succès on réalise la soustraction Entier - Entier
        Entier* res=new Entier(this->_x - tmp_en->_x);
        Nombre& ref=*res;
        return (ref);
    }
}

//Réalise la multiplication d'un Entier avec un Nombre (Entier,Reel,Rationnel)
Calculatrice::Nombre& Calculatrice::Entier::multiplication(const Nombre& nb) const{
    //On essaye le cast en Entier
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){ //Si echec erreur
                throw;
            }
            else{ //Si succès on réalise la multiplication Entier * Rationnel
                // x*num/den
                Rationnel* res=new Rationnel( (this->_x  * tmp_ra->get_n().get_x()) , tmp_ra->get_d().get_x());
                Nombre& ref=*res;
                return (ref);
            }
        }
        else{ //Si succès on réalise la multiplication Entier * Reel
            Reel* res=new Reel(this->_x * tmp_re->get_x());
            Nombre& ref=*res;
            return (ref);
        }
    }
    else{ //Si succès on réalise la multiplication Entier * Entier
        Entier* res=new Entier(this->_x * tmp_en->_x);
        Nombre& ref=*res;
        return (ref);
    }
}

//Réalise la division d'un Entier par un Nombre (Entier,Reel,Rationnel)
Calculatrice::Nombre& Calculatrice::Entier::division(const Nombre& nb) const{
    //On essaye le cast en Entier
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){ //Si echec erreur
                throw;
            }
            else{ //Si succès on réalise la division Entier / Rationnel
                if(tmp_ra->get_n().get_x()/tmp_ra->get_d().get_x()==0) //Si division par 0 Exception
                    throw CalculatriceException(typeid(nb).name(),MATHS,"Division par 0");

                Rationnel* res=new Rationnel( (this->_x  * tmp_ra->get_d().get_x()) ,tmp_ra->get_n().get_x());
                Nombre& ref=*res;
                return (ref);

            }
        }
        else{ //Si succès on réalise la division Entier / Reel
            if(tmp_re->get_x()==0) //Si division par 0 Exception
                throw CalculatriceException(typeid(nb).name(),MATHS,"Division par 0");

            Reel* res=new Reel(this->_x / tmp_re->get_x());
            Nombre& ref=*res;
            return (ref);
        }
    }
    else{ //Si succès on réalise la division Entier / Entier
        if(tmp_en->get_x()==0) //Si division par 0 Exception
            throw CalculatriceException(typeid(nb).name(),MATHS,"Division par 0");

        Reel* res=new Reel(this->_x / tmp_en->_x);
        Nombre& ref=*res;
        return (ref);
    }
}

QString Calculatrice::Entier::toString() const{
    QString str;
    str.setNum(_x);
    return str;
}

//Implementation des méthodes vituelles pures de la class "Expression"
void Calculatrice::Entier::EVAL(){}

//Constructeurs

