#include "LogMessage.h"

using namespace LO21;
using namespace std;

QString LO21::LogMessage::info() const{
    QString res(QDateTime::currentDateTime().toString() + " - ");
    switch(_imp){
        case INFO:{
            res+="INFORM";break;
        }
        case ERREUR:{
            res+="ERREUR";break;
        }
        case SYSTEME:{
            res+="SYSTEM";break;
        }
        default: break;
    }
    res+=" - ";
    res+=_mes;
    return res;
}
