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
Calculatrice::Nombre& Calculatrice::Rationnel::addition(const Nombre& nb){
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
                if(this->_d.get_x() != tmp_ra->_d.get_x()){//Si dénominateurs différents: a/b + c/d = (ad+bc)/(bd)
                    this->_n=( (this->_n.get_x() * tmp_ra->_d.get_x()) + (tmp_ra->_n.get_x() * this->_d.get_x()) );
                    this->_d * tmp_ra->_d;
                }
                else //Dénominateurs identiques
                    this->_n + tmp_ra->_n;

                //Simplification par le PGCD
                Entier vpgcd=pgcd(this->_n,this->_d);
                this->_n / vpgcd;
                this->_d / vpgcd;

                return (*this);
            }
        }
        else{ //Si succès on réalise l'addition Rationnel + Reel
            return (*this+tmp_re->toRationnel());
        }
    }
    else{ //Si succès on réalise l'addition Rationnel + Entier
        Rationnel tmp(tmp_en->get_x());
        return (*this+tmp);
    }
}

//Réalise la soustraction d'un Rationnel avec un Nombre (Entier, Reel, Rationnel)
Calculatrice::Nombre& Calculatrice::Rationnel::soustraction(const Nombre& nb){
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
                if(this->_d.get_x() != tmp_ra->_d.get_x()){//Si dénominateurs différents: a/b - c/d = (ad-bc)/(bd)
                    this->_n=( (this->_n.get_x() * tmp_ra->_d.get_x()) - (tmp_ra->_n.get_x() * this->_d.get_x()) );
                    this->_d * tmp_ra->_d;
                }
                else //Dénominateurs identiques
                    this->_n - tmp_ra->_n;

                //Simplification par le PGCD
                Entier vpgcd=pgcd(this->_n,this->_d);
                this->_n / vpgcd;
                this->_d / vpgcd;

                return (*this);
            }
        }
        else{ //Si succès on réalise la soustraction Rationnel - Reel
            return (*this-tmp_re->toRationnel());
        }
    }
    else{ //Si succès on réalise la soustraction Rationnel - Entier
        Rationnel tmp(tmp_en->get_x());
        return (*this-tmp);
    }
}

//Réalise la multiplication d'un Rationnel avec un Nombre (Entier, Reel, Rationnel)
Calculatrice::Nombre& Calculatrice::Rationnel::multiplication(const Nombre& nb){
    //On essaye le cast en Rationnel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Rationnel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){ //Si echec erreur
                throw;
            }
            else{ //Si succès on réalise la multiplication Rationnel * Rationnel //a/b * c/d = (a*c)/(b*d))
                this->_n * tmp_ra->_n;
                this->_d * tmp_ra->_d;

                //Simplification par le PGCD
                Entier vpgcd=pgcd(this->_n,this->_d);
                this->_n / vpgcd;
                this->_d / vpgcd;

                return (*this);
            }
        }
        else{ //Si succès on réalise la multiplication Rationnel * Reel
            return (*this*tmp_re->toRationnel());
        }
    }
    else{ //Si succès on réalise la multiplication Rationnel * Entier
        Rationnel tmp(tmp_en->get_x());
        return (*this*tmp);
    }
}

//Réalise la division d'un Rationnel par un Nombre (Entier, Reel, Rationnel)
Calculatrice::Nombre& Calculatrice::Rationnel::division(const Nombre& nb){
    //On essaye le cast en Rationnel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Rationnel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){ //Si echec erreur
                throw;
            }
            else{ //Si succès on réalise la division Rationnel / Rationnel: a/b / c/d <=> a/b * d/c
                this->_n * tmp_ra->_d;
                this->_d * tmp_ra->_n;

                //Simplification par le PGCD
                Entier vpgcd=pgcd(this->_n,this->_d);
                this->_n / vpgcd;
                this->_d / vpgcd;

                return (*this);
            }
        }
        else{ //Si succès on réalise la division Rationnel / Reel
            return (*this/tmp_re->toRationnel());
        }
    }
    else{ //Si succès on réalise la multiplication Rationnel / Entier
        Rationnel tmp(tmp_en->get_x());
        return (*this/tmp);
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
