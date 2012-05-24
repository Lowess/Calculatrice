#include <QString>

#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"

using namespace Calculatrice;

//Implementation des méthodes vituelles pures de la class "Nombre"

void Calculatrice::Rationnel::SIN(){}
void Calculatrice::Rationnel::COS(){}
void Calculatrice::Rationnel::TAN(){}
void Calculatrice::Rationnel::SINH(){}
void Calculatrice::Rationnel::COSH(){}
void Calculatrice::Rationnel::TANH(){}
void Calculatrice::Rationnel::LN(){}
void Calculatrice::Rationnel::LOG(){}
void Calculatrice::Rationnel::INV(){}
void Calculatrice::Rationnel::SQRT(){}
void Calculatrice::Rationnel::POW(){}

//Réalise l'addition d'un Rationnel avec un Nombre (Entier, Reel, Rationnel)
Calculatrice::Nombre& Calculatrice::Rationnel::addition(const Nombre& nb) const{
    //On essaye le cast en Rationnel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Rationnel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){ //Si echec erreur
                throw;
            }
            else{ //Si succès on réalise l'addition Rationnel + Rationnel
                const Entier* p_num=dynamic_cast<const Entier*>(&_n.multiplication(tmp_ra->_d).addition(_d.multiplication(tmp_ra->_n)));
                const Entier* p_den=dynamic_cast<const Entier*>(&_d.multiplication(tmp_ra->_d));

                if(p_num==0 || p_den==0)
                    throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast<const Entier*>");

                //Simplification par le PGCD
                Entier vpgcd=pgcd(*p_num,*p_den);
                Rationnel* res= new Rationnel(p_num->division(vpgcd), p_den->division(vpgcd));
                Nombre& ref=*res;
                return (ref);
            }
        }
        else{ //Si succès on réalise l'addition Rationnel + Reel
            Nombre& ref=tmp_re->addition(*this);
            return (ref);
        }
    }
    else{ //Si succès on réalise l'addition Rationnel + Entier
        Nombre& ref=tmp_en->addition(*this);
        return (ref);
    }
}

//Réalise la soustraction d'un Rationnel avec un Nombre (Entier, Reel, Rationnel)
Calculatrice::Nombre& Calculatrice::Rationnel::soustraction(const Nombre& nb) const{
    //On essaye le cast en Rationnel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Rationnel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){ //Si echec erreur
                throw;
            }
            else{ //Si succès on réalise la soustraction Rationnel - Rationnel
                Entier num( (this->_n.get_x() * tmp_ra->_d.get_x()) - (tmp_ra->_n.get_x() * this->_d.get_x()) );
                Entier den(this->_d * tmp_ra->_d);

                //Simplification par le PGCD
                Entier vpgcd=pgcd(num,den);
                Rationnel* res= new Rationnel(num / vpgcd, den / vpgcd);
                Nombre& ref=*res;
                return (ref);
            }
        }
        else{ //Si succès on réalise la soustraction Rationnel - Reel
            Nombre& ref=tmp_re->soustraction(*this);
            return (ref);
        }
    }
    else{ //Si succès on réalise la soustraction Rationnel - Entier
        Nombre& ref=tmp_en->soustraction(*this);
        return (ref);
    }
}

//Réalise la multiplication d'un Rationnel avec un Nombre (Entier, Reel, Rationnel)
Calculatrice::Nombre& Calculatrice::Rationnel::multiplication(const Nombre& nb) const{
    //On essaye le cast en Rationnel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Rationnel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){ //Si echec erreur
                throw;
            }
            else{ //Si succès on réalise la multiplication Rationnel * Rationnel
                Entier num(this->_n * tmp_ra->_n);
                Entier den(this->_d * tmp_ra->_d);

                //Simplification par le PGCD
                Entier vpgcd=pgcd(num,den);
                Rationnel* res= new Rationnel(num / vpgcd, den / vpgcd);
                Nombre& ref=*res;
                return (ref);
            }
        }
        else{ //Si succès on réalise la multiplication Rationnel * Reel
            Nombre& ref=tmp_re->multiplication(*this);
            return (ref);
        }
    }
    else{ //Si succès on réalise la multiplication Rationnel * Entier
        Nombre& ref=tmp_en->multiplication(*this);
        return (ref);
    }
}

//Réalise la division d'un Rationnel par un Nombre (Entier, Reel, Rationnel)
Calculatrice::Nombre& Calculatrice::Rationnel::division(const Nombre& nb) const{
    //On essaye le cast en Rationnel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Rationnel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){ //Si echec erreur
                throw;
            }
            else{ //Si succès on réalise la division Rationnel / Rationnel
                Rationnel* res=new Rationnel(*this * nb.INV());

                //Simplification par le PGCD
                Entier vpgcd=pgcd(num,den);
                res->_n / vpgcd;
                res->_d / vpgcd;
                Nombre& ref=*res;
                return (ref);
            }
        }
        else{ //Si succès on réalise la division Rationnel / Reel
            Nombre& ref=tmp_re->division(*this);
            return (ref);
        }
    }
    else{ //Si succès on réalise la division Rationnel / Entier
        Nombre& ref=tmp_en->division(*this);
        return (ref);
    }
}

QString Calculatrice::Rationnel::toString() const{
    QString str1,str2;
    str1.setNum(_n.get_x());
    str2.setNum(_d.get_x());
    return QString(str1+"/"+str2);
}

//Implementation des méthodes vituelles pures de la class "Expression"
void Calculatrice::Rationnel::EVAL(){}

/*
 * Fonctions
 *
*/

Calculatrice::Entier Calculatrice::pgcd(const Calculatrice::Entier& a, const Calculatrice::Entier& b){
    Entier x(a.get_x()); // x=a
    Entier y(b.get_x()); // y=b

    if((y.get_x())==0)
        return x;
    else
        return pgcd(y,Entier(x.get_x() % y.get_x()));
}

Calculatrice::Entier Calculatrice::ppcm(const Calculatrice::Entier& a, const Calculatrice::Entier& b){
    Entier x(a.get_x()); // x=a
    Entier y(b.get_x()); // y=b

    if( (y.get_x()==0) || (x.get_x()==0) )
        return 0;
    else // PPCM(x,y)= |x*y| / PGCD(x,y)
        return Entier( (abs(x.get_x())*abs(y.get_x())) / pgcd(x,y).get_x() );
}
