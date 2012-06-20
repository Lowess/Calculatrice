#include <QString>

#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"
#include "Complexe.h"
#include "Exp.h"

using namespace LO21;

//Réalise l'addition d'un Rationnel avec un Constante (Entier, Reel, Rationnel)
LO21::Constante& LO21::Rationnel::addition(const Constante& nb) const{
    //On essaye le cast en Rationnel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Rationnel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){
                const Complexe* tmp_c = dynamic_cast<const Complexe*>(&nb);
                if(tmp_c == 0){
                    const Exp* tmp_exp = dynamic_cast<const Exp*>(&nb);
                    if(tmp_exp == 0){
                        LogSystem::ecrireLog(LogMessage("Erreur classe rationnel ",ERREUR));
                        throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
                    }
                    else{
                        Constante* res=new Exp(toString());
                        Constante& ref=res->addition(nb);
                        delete res;
                        return(ref);
                    }
                }
                else {
                    Constante& ref = tmp_c->addition(*this);
                    return (ref);
                }
            }
            else{ //Si succÃ¨s on rÃ©alise l'addition Rationnel + Rationnel
                const Entier* p_num=dynamic_cast<const Entier*>(&_n.multiplication(tmp_ra->_d).addition(_d.multiplication(tmp_ra->_n)));
                const Entier* p_den=dynamic_cast<const Entier*>(&_d.multiplication(tmp_ra->_d));

                if(p_num==0 || p_den==0){
                    LogSystem::ecrireLog(LogMessage("Erreur classe rationnel ",ERREUR));
                    throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast<const Entier*>");
                }
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
LO21::Constante& LO21::Rationnel::soustraction(const Constante& nb) const{
    //On essaye le cast en Rationnel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Rationnel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){
                const Complexe* tmp_c = dynamic_cast<const Complexe*>(&nb);
                if(tmp_c == 0){
                    const Exp* tmp_exp = dynamic_cast<const Exp*>(&nb);
                    if(tmp_exp == 0){
                        LogSystem::ecrireLog(LogMessage("Erreur classe rationnel ",ERREUR));
                        throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
                    }
                    else{
                        Constante* res=new Exp(toString());
                        Constante& ref=res->soustraction(nb);
                        delete res;
                        return(ref);
                    }
                }
                else {
                    Constante& ref = tmp_c->soustraction(*this);
                    return (ref);
                }
            }
            else{ //Si succÃ¨s on rÃ©alise la soustraction Rationnel - Rationnel
                const Reel* p_num=dynamic_cast<const Reel *>(&this->_n.multiplication(tmp_ra->_d).soustraction(tmp_ra->_n.multiplication(this->_d)));
                const Reel* p_den=dynamic_cast<const Reel *>(&this->_d.multiplication(tmp_ra->_d));

                if(p_num==0 || p_den==0){
                    LogSystem::ecrireLog(LogMessage("Erreur classe rationnel ",ERREUR));
                    throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast<const Entier*>");
                }
                Rationnel* res= new Rationnel(p_num->toEntier(), p_den->toEntier());
                res->simplifier();
                Constante& ref=*res;
                return (ref);
            }
        }
        else{ //Si succès on réalise la soustraction :Rationnel - Reel
            Constante& ref=tmp_re->soustraction(*this).SIGN(); //Inversion de signe car appel �  Reel - Rationnel
            return (ref);
        }
    }
    else{ //Si succès on réalise la soustraction Rationnel - Entier
        Constante& ref=tmp_en->soustraction(*this).SIGN(); //Inversion de signe car appel �  Entier - Rationnel
        return (ref);
    }
}

//Réalise la multiplication d'un Rationnel avec un Constante (Entier, Reel, Rationnel)
LO21::Constante& LO21::Rationnel::multiplication(const Constante& nb) const{
    //On essaye le cast en Rationnel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Rationnel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){
                const Complexe* tmp_c = dynamic_cast<const Complexe*>(&nb);
                if(tmp_c == 0){
                    const Exp* tmp_exp = dynamic_cast<const Exp*>(&nb);
                    if(tmp_exp == 0){
                        LogSystem::ecrireLog(LogMessage("Erreur classe rationnel ",ERREUR));
                        throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
                    }
                    else{
                        Constante* res=new Exp(toString());
                        Constante& ref=res->multiplication(nb);
                        delete res;
                        return(ref);
                    }
                }
                else {
                    Constante& ref = tmp_c->multiplication(*this);
                    return (ref);
                }
            }
            else{ //Si succÃ¨s on rÃ©alise la multiplication Rationnel * Rationnel
                const Entier* p_num=dynamic_cast<const Entier *>(&this->_n.multiplication(tmp_ra->_n));
                const Entier* p_den=dynamic_cast<const Entier *>(&this->_d.multiplication(tmp_ra->_d));

                if(p_num==0 || p_den==0){
                    LogSystem::ecrireLog(LogMessage("Erreur classe rationnel ",ERREUR));
                    throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast<const Entier*>");
                }

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
LO21::Constante& LO21::Rationnel::division(const Constante& nb) const{
    //On essaye le cast en Rationnel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Rationnel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){
                const Complexe* tmp_c = dynamic_cast<const Complexe*>(&nb);
                if(tmp_c == 0){
                    const Exp* tmp_exp = dynamic_cast<const Exp*>(&nb);
                    if(tmp_exp == 0){
                        LogSystem::ecrireLog(LogMessage("Erreur classe rationnel ",ERREUR));
                        throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
                    }
                    else{
                        Constante* res=new Exp(toString());
                        Constante& ref=res->division(nb);
                        delete res;
                        return(ref);
                    }
                }
                else {
                    Constante& ref = tmp_c->division(*this);
                    return (ref);
                }
            }
            else{ //Si succÃ¨s on rÃ©alise la division Rationnel / Rationnel
                const Rationnel* tmp_ra_inv=dynamic_cast<const Rationnel*>(&tmp_ra->INV());
                const Entier* p_num=dynamic_cast<const Entier *>(&this->_n.multiplication(tmp_ra_inv->_n));
                const Entier* p_den=dynamic_cast<const Entier *>(&this->_d.multiplication(tmp_ra_inv->_d));

                if(p_num==0 || p_den==0){
                    LogSystem::ecrireLog(LogMessage("Erreur classe rationnel ",ERREUR));
                    throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast<const Entier*>");
                }

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

QString LO21::Rationnel::toString() const{
    QString str1,str2;
    str1.setNum(_n.get_x());
    str2.setNum(_d.get_x());
    return QString(str1+"/"+str2);
}

/*
 * MÃ©thodes
 *
*/
void LO21::Rationnel::simplifier(){
    //Simplification par le PGCD
    Entier vpgcd=pgcd(get_n(), get_d());
    const Reel* p_num_div=dynamic_cast<const Reel*>(&get_n().division(vpgcd));
    const Reel* p_den_div=dynamic_cast<const Reel*>(&get_d().division(vpgcd));

    if(p_num_div==0 || p_den_div==0){
        LogSystem::ecrireLog(LogMessage("Erreur classe rationnel ",ERREUR));
        throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast<const Entier*>");
    }

    _n=p_num_div->toEntier();
    _d=p_den_div->toEntier();
}

LO21::Rationnel* LO21::Rationnel::clone() const{ return new Rationnel(*this); }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


LO21::Reel& LO21::Rationnel::toReel() const{
    //Conversion du rationnel en reel 3/2 = 1.5
    double n=(double)_n.get_x();
    double d=(double)_d.get_x();

    Reel* res= new Reel(n / d);
    Reel& ref=*res;
    return (ref);
}



LO21::Entier& LO21::Rationnel::toEntier() const{
    //Conversion du rationnel en entier 3/2 = 1
    Entier* res= new Entier(_n.get_x() / _d.get_x());
    Entier& ref=*res;
    return (ref);
}

LO21::Complexe& LO21::Rationnel::toComplexe() const {
    //Conversion du rationnel en complexe 3/2 = 3/2 + 0i
    const Constante* a = (const Constante*)this;
    const Constante* b = new Rationnel(0);
    Complexe* res = new Complexe(*a,*b);
    Complexe& ref= *res;
    return (ref);
}

/*
 * Fonctions
 *
*/

LO21::Entier LO21::pgcd(const LO21::Entier& a, const LO21::Entier& b){
    Entier x(a.get_x()); // x=a
    Entier y(b.get_x()); // y=b

    if((y.get_x())==0)
        return x;
    else
        return pgcd(y,Entier(x.get_x() % y.get_x()));
}

LO21::Entier LO21::ppcm(const LO21::Entier& a, const LO21::Entier& b){
    Entier x(a.get_x()); // x=a
    Entier y(b.get_x()); // y=b

    if( (y.get_x()==0) || (x.get_x()==0) )
        return 0;
    else // PPCM(x,y)= |x*y| / PGCD(x,y)
        return Entier( (abs(x.get_x())*abs(y.get_x())) / pgcd(x,y).get_x() );
}
