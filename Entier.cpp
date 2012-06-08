#include "Entier.h"
#include "Rationnel.h"
#include "CalculatriceException.h"

using namespace Calculatrice;

//Réalise l'addition d'un Entier avec un Constante (Entier,Reel,Rationnel)
Calculatrice::Constante& Calculatrice::Entier::addition(const Constante& nb) const{
    //On essaie le cast en Entier
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaie en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaie en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){ //Si echec on essaie en Complexe
                const Complexe* tmp_c = dynamic_cast<const Complexe*>(&nb);
                if(tmp_c == 0)
                    throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
                else {
                    Constante* res = tmp_c->addition(*this);
                    Constante& ref = *res;
                    return (ref);
                }
            }
            else{ //Si succÃ¨s on rÃ©alise l'addition Entier + Rationnel
                Entier num=(this->_x * tmp_ra->get_d().get_x() + tmp_ra->get_n().get_x()); //mise au mÃªme dÃ©nominateur et addition des numÃ©rateurs
                Entier den=tmp_ra->get_d().get_x();
                Rationnel* res=new Rationnel(num, den);
                res->simplifier();
                Constante& ref=*res;
                return (ref);
            }
        }
        else{ //Si succÃ¨s on rÃ©alise l'addition Entier + Reel
            Reel* res=new Reel(this->_x + tmp_re->get_x());
            Constante& ref=*res;
            return (ref);
        }
    }
    else{ //Si succÃ¨s on rÃ©alise l'addition Entier + Entier
            Entier* res=new Entier(this->_x + tmp_en->_x);
            Constante& ref=*res;
            return (ref);
    }
}

//Réalise la soustraction d'un Entier avec un Constante (Entier,Reel,Rationnel)
Calculatrice::Constante& Calculatrice::Entier::soustraction(const Constante& nb) const{
    //On essaye le cast en Entier
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){ //Si echec on essaie en Complexe
                const Complexe* tmp_c = dynamic_cast<const Complexe*>(&nb);
                if(tmp_c == 0) //Si echec on throw une exception
                    throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
                else {
                    Constante* res = tmp_c->soustraction(*this);
                    Constante& ref = *res;
                    return (ref);
                }
            }
            else{ //Si succÃ¨s on rÃ©alise la soustraction Entier - Rationnel
                Entier num(this->_x * tmp_ra->get_d().get_x() - tmp_ra->get_n().get_x()); //mise au mÃªme dÃ©nominateur et soustraction des numÃ©rateurs
                Entier den(tmp_ra->get_d().get_x());

                Rationnel* res= new Rationnel(num.toEntier(), den.toEntier());
                res->simplifier();
                Constante& ref=*res;
                return (ref);
            }
        }
        else{ //Si succÃ¨s on rÃ©alise la soustraction Entier - Reel
            Reel* res=new Reel(this->_x - tmp_re->get_x());
            Constante& ref=*res;
            return (ref);
        }
    }
    else{ //Si succÃ¨s on rÃ©alise la soustraction Entier - Entier
        Entier* res=new Entier(this->_x - tmp_en->_x);
        Constante& ref=*res;
        return (ref);
    }
}

//Réalise la multiplication d'un Entier avec un Constante (Entier,Reel,Rationnel)
Calculatrice::Constante& Calculatrice::Entier::multiplication(const Constante& nb) const{
    //On essaye le cast en Entier
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){ //Si echec on essaie en Complexe
                const Complexe* tmp_c = dynamic_cast<const Complexe*>(&nb);
                if(tmp_c == 0)
                    throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
                else {
                    Constante* res = tmp_c->multiplication(*this);
                    Constante& ref = *res;
                    return (ref);
                }
            }
            else{ //Si succÃ¨s on rÃ©alise la multiplication Entier * Rationnel
                // x*num/den
                Rationnel* res=new Rationnel( (this->_x  * tmp_ra->get_n().get_x()) , tmp_ra->get_d().get_x());
                Constante& ref=*res;
                return (ref);
            }
        }
        else{ //Si succÃ¨s on rÃ©alise la multiplication Entier * Reel
            Reel* res=new Reel(this->_x * tmp_re->get_x());
            Constante& ref=*res;
            return (ref);
        }
    }
    else{ //Si succÃ¨s on rÃ©alise la multiplication Entier * Entier
        Entier* res=new Entier(this->_x * tmp_en->_x);
        Constante& ref=*res;
        return (ref);
    }
}

//Réalise la division d'un Entier par un Constante (Entier,Reel,Rationnel)
Calculatrice::Constante& Calculatrice::Entier::division(const Constante& nb) const{
    //On essaye le cast en Entier
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){ //Si echec on essaie en Complexe
                const Complexe* tmp_c = dynamic_cast<const Complexe*>(&nb);
                if(tmp_c == 0)
                    throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
                else {
                    Constante* res = tmp_c->division(*this);
                    Constante& ref = *res;
                    return (ref);
                }
            }
            else{ //Si succÃ¨s on rÃ©alise la division Entier / Rationnel
                if(tmp_ra->get_n().get_x()/tmp_ra->get_d().get_x()==0) //Si division par 0 Exception
                    throw CalculatriceException(typeid(nb).name(),MATHS,"Division par 0");

                Entier num=Entier(this->_x  * tmp_ra->get_d().get_x());
                Entier den=Entier(tmp_ra->get_n().get_x());

                Rationnel* res= new Rationnel(num.toEntier(), den.toEntier());
                res->simplifier();
                Constante& ref=*res;
                return (ref);
            }
        }
        else{ //Si succÃ¨s on rÃ©alise la division Entier / Reel
            if(tmp_re->get_x()==0) //Si division par 0 Exception
                throw CalculatriceException(typeid(nb).name(),MATHS,"Division par 0");

            Constante& ref=division(tmp_re->toRationnel()); // 3 / 2.5 <=> 3 / 5/2
            return (ref);
        }
    }
    else{ //Si succÃ¨s on rÃ©alise la division Entier / Entier
        if(tmp_en->get_x()==0) //Si division par 0 Exception
            throw CalculatriceException(typeid(nb).name(),MATHS,"Division par 0");

        Reel* res=new Reel(this->_x / tmp_en->_x);
        Constante& ref=*res;
        return (ref);
    }
}

QString Calculatrice::Entier::toString() const{
    QString str;
    str.setNum(_x);
    return str;
}

//Constructeurs


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Calculatrice::Rationnel& Calculatrice::Entier::toRationnel() const{
    //Conversion de l'entier en rationnel 3 = 3/1
    Rationnel* res= new Rationnel(_x,1);
    Rationnel& ref=*res;
    return (ref);
}


Calculatrice::Reel& Calculatrice::Entier::toReel() const{
    //Conversion d'un entier en reel 3.0 = 3
    Reel* res= new Reel(_x);
    Reel& ref=*res;
    return (ref);
}

Calculatrice::Complexe& Calculatrice::Entier::toComplexe() const{
    //Conversion d'un entier en complexe 3 = 3 + 0i
    const Constante* a = (const Constante*)this;
    const Constante& b = new Entier(0);
    Complexe* res = new Complexe(*a,b);
    Complexe& ref = *res;
    return (ref);
}
