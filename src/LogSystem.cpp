#include "LogSystem.h"

using namespace LO21;

void LO21::LogSystem::ecrireConsole(const LogMessage& m){
    qDebug() << m.info();
}

void LO21::LogSystem::ecrireFichier(const LogMessage& m){
    QFile file(QDir::currentPath() + "Calculatrice.log");

    //Ecriture
    if (!file.open(QIODevice::Append | QIODevice::Text)){
        throw CalculatriceException("LogSystem",OTHER,"Echec d'ouverture de fichier de log en ecriture");
    }
    QTextStream out(&file);
    out << "\n" << m.info();

    file.close();

}

void LO21::LogSystem::ecrireLog(const LogMessage& m){
    LogSystem::ecrireConsole(m);
    LogSystem::ecrireFichier(m);
}
