#include "Constante.h"

#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"

void LO21::Constante::EVAL(){}

//Implementation issu de la classe Constante
LO21::Constante& LO21::Constante::SIGN() const{
    //On essaye le cast en Entier
    const Entier* tmp_en=dynamic_cast<const Entier*>(&*this);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&*this);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&*this);
            if(tmp_ra==0){ //Si echec on essaye en Complexe
                const Complexe* tmp_comp=dynamic_cast<const Complexe*>(&*this);
                if(tmp_comp==0){ //Si echec erreur
                    LogSystem::ecrireLog(LogMessage("Erreur classe constante ",ERREUR));
                    throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
                }
                else{
                    Nombre& sig_a=dynamic_cast<Nombre&>(tmp_comp->get_a()->SIGN());
                    Nombre& sig_b=dynamic_cast<Nombre&>(tmp_comp->get_b()->SIGN());
                    Complexe* res=new Complexe(sig_a,sig_b);
                    Constante& ref=*res;
                    return (ref);
                }
            }
            else{ //Si succès on realise SIGN Rationnel
                const Entier* inv=dynamic_cast<const Entier*>(&tmp_ra->get_n().SIGN());
                Rationnel* res=new Rationnel(inv->get_x(),tmp_ra->get_d());
                Constante& ref=*res;
                return (ref);
            }
        }
        else{ //Si succès on realise SIGN Reel
            Reel* res=new Reel(-tmp_re->get_x());
            Constante& ref=*res;
            return (ref);
        }
    }
    else{ //Si succès on realise SIGN Entier
        Entier* res=new Entier(-tmp_en->get_x());
        Constante& ref=*res;
        return (ref);
    }
}

LO21::Constante& LO21::Constante::SQR() const {
    return (*this).multiplication(*this);
}

LO21::Constante& LO21::Constante::CUBE() const {
    return (*this).multiplication(SQR());
}
