#include "Entier.h"
#include "Rationnel.h"
#include "CalculatriceException.h"

using namespace Calculatrice;
//Implementation des méthodes vituelles pures de la class "Nombre"

void Calculatrice::Entier::SIN(){}
void Calculatrice::Entier::COS(){}
void Calculatrice::Entier::TAN(){}
void Calculatrice::Entier::SINH(){}
void Calculatrice::Entier::COSH(){}
void Calculatrice::Entier::TANH(){}
void Calculatrice::Entier::LN(){}
void Calculatrice::Entier::LOG(){}
void Calculatrice::Entier::INV(){}
void Calculatrice::Entier::SQRT(){}
void Calculatrice::Entier::POW(){}

//Réalise l'addition d'un Entier avec un Nombre (Entier,Reel,Rationnel)
Calculatrice::Nombre& Calculatrice::Entier::addition(const Nombre& nb){
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
                float num=(this->_x * tmp_ra->get_d().get_x() + tmp_ra->get_n().get_x()); //mise au même dénominateur et addition des numérateurs
                float den=tmp_ra->get_d().get_x();
                this->_x=(num/den);
                return (*this);
            }
        }
        else{ //Si succès on réalise l'addition Entier + Reel
            this->_x+=tmp_re->get_x();
            return (*this);
        }
    }
    else{ //Si succès on réalise l'addition Entier + Entier
        this->_x+=tmp_en->_x;
        return (*this);
    }
}

//Réalise la soustraction d'un Entier avec un Nombre (Entier,Reel,Rationnel)
Calculatrice::Nombre& Calculatrice::Entier::soustraction(const Nombre& nb){
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
                float num=(this->_x * tmp_ra->get_d().get_x() - tmp_ra->get_n().get_x()); //mise au même dénominateur et soustraction des numérateurs
                float den=tmp_ra->get_d().get_x();
                this->_x=(num/den);
                return (*this);
            }
        }
        else{ //Si succès on réalise la soustraction Entier - Reel
            this->_x-=tmp_re->get_x();
            return (*this);
        }
    }
    else{ //Si succès on réalise la soustraction Entier - Entier
        this->_x-=tmp_en->_x;
        return (*this);
    }
}

//Réalise la multiplication d'un Entier avec un Nombre (Entier,Reel,Rationnel)
Calculatrice::Nombre& Calculatrice::Entier::multiplication(const Nombre& nb){
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
                this->_x=((this->_x  * tmp_ra->get_n().get_x()) / tmp_ra->get_d().get_x()); // x*num/den
                return (*this);
            }
        }
        else{ //Si succès on réalise la multiplication Entier * Reel
            this->_x*=tmp_re->get_x();
            return (*this);
        }
    }
    else{ //Si succès on réalise la multiplication Entier * Entier
        this->_x*=tmp_en->_x;
        return (*this);
    }
}

//Réalise la division d'un Entier par un Nombre (Entier,Reel,Rationnel)
Calculatrice::Nombre& Calculatrice::Entier::division(const Nombre& nb){
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
                this->_x=(this->_x  / (tmp_ra->get_n().get_x() / tmp_ra->get_d().get_x())); // x/(num/den)
                return (*this);
            }
        }
        else{ //Si succès on réalise la division Entier / Reel
            if(tmp_re->get_x()==0) //Si division par 0 Exception
                throw CalculatriceException(typeid(nb).name(),MATHS,"Division par 0");
            this->_x/=tmp_re->get_x();
            return (*this);
        }
    }
    else{ //Si succès on réalise la division Entier / Entier
        if(tmp_en->get_x()==0) //Si division par 0 Exception
            throw CalculatriceException(typeid(nb).name(),MATHS,"Division par 0");
        this->_x/=tmp_en->_x;
        return (*this);
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

