#include <QString>

#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"

using namespace Calculatrice;

//Réalise l'addition d'un Rationnel avec un Constante (Entier, Reel, Rationnel)
Calculatrice::Constante& Calculatrice::Rationnel::addition(const Constante& nb) const{
    //On essaye le cast en Rationnel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Rationnel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){ //Si echec erreur
                throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
            }
            else{ //Si succès on réalise l'addition Rationnel + Rationnel
                const Entier* p_num=dynamic_cast<const Entier*>(&_n.multiplication(tmp_ra->_d).addition(_d.multiplication(tmp_ra->_n)));
                const Entier* p_den=dynamic_cast<const Entier*>(&_d.multiplication(tmp_ra->_d));

                if(p_num==0 || p_den==0)
                    throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast<const Entier*>");

                Rationnel* res= new Rationnel(*p_num, *p_den);
                res->simplifier();
                Constante& ref=*res;
                return (ref);
            }
        }
        else{ //Si succès on réalise l'addition Rationnel + Reel
            Constante& ref=tmp_re->addition(*this);
            return (ref);
        }
    }
    else{ //Si succès on réalise l'addition Rationnel + Entier
        Constante& ref=tmp_en->addition(*this);
        return (ref);
    }
}

//Réalise la soustraction d'un Rationnel avec un Constante (Entier, Reel, Rationnel)
Calculatrice::Constante& Calculatrice::Rationnel::soustraction(const Constante& nb) const{
    //On essaye le cast en Rationnel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Rationnel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){ //Si echec erreur
                throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
            }
            else{ //Si succès on réalise la soustraction Rationnel - Rationnel
                const Reel* p_num=dynamic_cast<const Reel *>(&this->_n.multiplication(tmp_ra->_d).soustraction(tmp_ra->_n.multiplication(this->_d)));
                const Reel* p_den=dynamic_cast<const Reel *>(&this->_d.multiplication(tmp_ra->_d));

                if(p_num==0 || p_den==0)
                    throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast<const Entier*>");

                Rationnel* res= new Rationnel(p_num->toEntier(), p_den->toEntier());
                res->simplifier();
                Constante& ref=*res;
                return (ref);
            }
        }
        else{ //Si succès on réalise la soustraction :Rationnel - Reel
            Constante& ref=tmp_re->soustraction(*this).SIGN(); //Inversion de signe car appel à Reel - Rationnel
            return (ref);
        }
    }
    else{ //Si succès on réalise la soustraction Rationnel - Entier
        Constante& ref=tmp_en->soustraction(*this).SIGN(); //Inversion de signe car appel à Entier - Rationnel
        return (ref);
    }
}

//Réalise la multiplication d'un Rationnel avec un Constante (Entier, Reel, Rationnel)
Calculatrice::Constante& Calculatrice::Rationnel::multiplication(const Constante& nb) const{
    //On essaye le cast en Rationnel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Rationnel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){ //Si echec erreur
                throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
            }
            else{ //Si succès on réalise la multiplication Rationnel * Rationnel
                const Entier* p_num=dynamic_cast<const Entier *>(&this->_n.multiplication(tmp_ra->_n));
                const Entier* p_den=dynamic_cast<const Entier *>(&this->_d.multiplication(tmp_ra->_d));

                if(p_num==0 || p_den==0)
                    throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast<const Entier*>");

                Rationnel* res= new Rationnel(*p_num, *p_den);
                res->simplifier();
                Constante& ref=*res;
                return (ref);
            }
        }
        else{ //Si succès on réalise la multiplication Rationnel * Reel
            Constante& ref=tmp_re->multiplication(*this);
            return (ref);
        }
    }
    else{ //Si succès on réalise la multiplication Rationnel * Entier
        Constante& ref=tmp_en->multiplication(*this);
        return (ref);
    }
}

//Réalise la division d'un Rationnel par un Constante (Entier, Reel, Rationnel)
Calculatrice::Constante& Calculatrice::Rationnel::division(const Constante& nb) const{
    //On essaye le cast en Rationnel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Rationnel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){ //Si echec erreur
                throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
            }
            else{ //Si succès on réalise la division Rationnel / Rationnel
                const Rationnel* tmp_ra_inv=dynamic_cast<const Rationnel*>(&tmp_ra->INV());
                const Entier* p_num=dynamic_cast<const Entier *>(&this->_n.multiplication(tmp_ra_inv->_n));
                const Entier* p_den=dynamic_cast<const Entier *>(&this->_d.multiplication(tmp_ra_inv->_d));

                if(p_num==0 || p_den==0)
                    throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast<const Entier*>");

                Rationnel* res= new Rationnel(*p_num, *p_den);
                res->simplifier();
                Constante& ref=*res;
                return (ref);
            }
        }
        else{ //Si succès on réalise la division Rationnel / Reel
            Constante& pt=tmp_re->division(*this);
            Nombre* pt2=dynamic_cast<Nombre *>(&pt);
            Constante& ref=pt2->INV();
            return (ref);
        }
    }
    else{ //Si succès on réalise la division Rationnel / Entier
        Constante& pt=tmp_en->division(*this);
        Nombre* pt2=dynamic_cast<Nombre *>(&pt);
        Constante& ref=pt2->INV();
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


//Constructeurs
/*
//Recopie et operator=
Calculatrice::Rationnel::Rationnel(const Entier& e){

}

Calculatrice::Rationnel& Calculatrice::Rationnel::operator=(const Entier& e){

    return *this;
}
*/

/*
 * Méthodes
 *
*/
void Calculatrice::Rationnel::simplifier(){
    //Simplification par le PGCD
    Entier vpgcd=pgcd(get_n(), get_d());
    const Reel* p_num_div=dynamic_cast<const Reel*>(&get_n().division(vpgcd));
    const Reel* p_den_div=dynamic_cast<const Reel*>(&get_d().division(vpgcd));

    if(p_num_div==0 || p_den_div==0)
        throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast<const Entier*>");

    _n=p_num_div->toEntier();
    _d=p_den_div->toEntier();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Calculatrice::Reel& Calculatrice::Rationnel::toReel() const{
    //Conversion du rationnel en reel 3/2 = 1.5
    double n=(double)_n.get_x();
    double d=(double)_d.get_x();

    Reel* res= new Reel(n / d);
    Reel& ref=*res;
    return (ref);
}



Calculatrice::Entier& Calculatrice::Rationnel::toEntier() const{
    //Conversion du rationnel en entier 3/2 = 1
    Entier* res= new Entier(_n.get_x() / _d.get_x());
    Entier& ref=*res;
    return (ref);
}

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
