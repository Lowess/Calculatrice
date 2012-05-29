#include "Nombre.h"

#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"



QTextStream& operator<<(QTextStream& s, const Calculatrice::Nombre& n){
    n.afficher();
    return s;
}

Calculatrice::Nombre& Calculatrice::Nombre::SIGN() const{
    //On essaye le cast en Entier
    const Entier* tmp_en=dynamic_cast<const Entier*>(&*this);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&*this);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&*this);
            if(tmp_ra==0){ //Si echec erreur
                throw;
            }
            else{ //Si succès on réalise SIGN Rationnel
                const Entier* inv=dynamic_cast<const Entier*>(&tmp_ra->get_n().SIGN());
                Rationnel* res=new Rationnel(inv->get_x(),tmp_ra->get_d());
                Nombre& ref=*res;
                return (ref);
            }
        }
        else{ //Si succès on réalise SIGN Reel
            Reel* res=new Reel(-tmp_re->get_x());
            Nombre& ref=*res;
            return (ref);
        }
    }
    else{ //Si succès on réalise SIGN Entier
        Entier* res=new Entier(-tmp_en->get_x());
        Nombre& ref=*res;
        return (ref);
    }
}


Calculatrice::Nombre& Calculatrice::Nombre::INV() const{
    //On essaye le cast en Entier
    const Entier* tmp_en=dynamic_cast<const Entier*>(&*this);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&*this);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&*this);
            if(tmp_ra==0){ //Si echec erreur
                throw;
            }
            else{ //Si succès on réalise INV Rationnel
                Rationnel* res=new Rationnel(tmp_ra->get_d(),tmp_ra->get_n());
                Nombre& ref=*res;
                return (ref);
            }
        }
        else{ //Si succès on réalise INV Reel
            Reel* res=new Reel(1/tmp_re->get_x());
            Nombre& ref=*res;
            return (ref);
        }
    }
    else{ //Si succès on réalise SIGN Entier
        Reel* res=new Reel(1/tmp_en->get_x());
        Nombre& ref=*res;
        return (ref);
    }
}
