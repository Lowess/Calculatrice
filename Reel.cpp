#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"

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
Calculatrice::Nombre& Calculatrice::Reel::addition(const Nombre& nb){
    //On essaye le cast en Reel
    const Reel* tmp_en=dynamic_cast<const Reel*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){ //Si echec erreur
                throw;
            }
            else{ //Si succès on réalise l'addition Reel + Rationnel
                float num=(this->_x * tmp_ra->get_d().get_x() + tmp_ra->get_n().get_x()); //mise au même dénominateur et addition des numérateurs
                float den=tmp_ra->get_d().get_x();
                this->_x=(num/den);
                return (*this);
            }
        }
        else{ //Si succès on réalise l'addition Reel + Reel
            this->_x+=tmp_re->get_x();
            return (*this);
        }
    }
    else{ //Si succès on réalise l'addition Reel + Entier
        this->_x+=tmp_en->_x;
        return (*this);
    }
}

//Réalise la soustraction d'un Reel avec un Nombre (Entier, Reel, Rationnel)
Calculatrice::Nombre& Calculatrice::Reel::soustraction(const Nombre& nb){
    //On essaye le cast en Reel
    const Reel* tmp_en=dynamic_cast<const Reel*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){ //Si echec erreur
                throw;
            }
            else{ //Si succès on réalise la soustraction Reel - Rationnel
                float num=(this->_x * tmp_ra->get_d().get_x() - tmp_ra->get_n().get_x()); //mise au même dénominateur et soustraction des numérateurs
                float den=tmp_ra->get_d().get_x();
                this->_x=(num/den);
                return (*this);
            }
        }
        else{ //Si succès on réalise la soustraction Reel - Reel
            this->_x-=tmp_re->get_x();
            return (*this);
        }
    }
    else{ //Si succès on réalise la soustraction Reel - Entier
        this->_x-=tmp_en->_x;
        return (*this);
    }
}

//Réalise la multiplication d'un Reel avec un Nombre (Entier, Reel, Rationnel)
Calculatrice::Nombre& Calculatrice::Reel::multiplication(const Nombre& nb){
    //On essaye le cast en Reel
    const Reel* tmp_en=dynamic_cast<const Reel*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){ //Si echec erreur
                throw;
            }
            else{ //Si succès on réalise la multiplication Reel * Rationnel
                this->_x=((this->_x  * tmp_ra->get_n().get_x()) / tmp_ra->get_d().get_x()); // x*num/den
                return (*this);
            }
        }
        else{ //Si succès on réalise la multiplication Reel * Reel
            this->_x*=tmp_re->get_x();
            return (*this);
        }
    }
    else{ //Si succès on réalise la multiplication Reel * Entier
        this->_x*=tmp_en->_x;
        return (*this);
    }
}

//Réalise la division d'un Reel par un Nombre (Entier, Reel, Rationnel)
Calculatrice::Nombre& Calculatrice::Reel::division(const Nombre& nb){
    //On essaye le cast en Reel
    const Reel* tmp_en=dynamic_cast<const Reel*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){ //Si echec erreur
                throw;
            }
            else{ //Si succès on réalise la division Reel / Rationnel
                if(tmp_ra->get_n().get_x()/tmp_ra->get_d().get_x()==0) //Si division par 0 Exception
                    throw CalculatriceException(typeid(nb).name(),MATHS,"Division par 0");
                this->_x=(this->_x  / (tmp_ra->get_n().get_x() / tmp_ra->get_d().get_x())); // x/(num/den)
                return (*this);
            }
        }
        else{ //Si succès on réalise la division Reel / Reel
            if(tmp_re->get_x()==0) //Si division par 0 Exception
                throw CalculatriceException(typeid(nb).name(),MATHS,"Division par 0");
            this->_x/=tmp_re->get_x();
            return (*this);
        }
    }
    else{ //Si succès on réalise la division Reel / Entier
        if(tmp_en->get_x()==0) //Si division par 0 Exception
            throw CalculatriceException(typeid(nb).name(),MATHS,"Division par 0");
        this->_x/=tmp_en->_x;
        return (*this);
    }
}


QString Calculatrice::Reel::toString() const{
    QString str;
    str.setNum(_x);
    return str;
}

//Implementation des méthodes vituelles pures de la class "Expression"
void Calculatrice::Reel::EVAL(){}
