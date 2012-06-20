#include "LogSystem.h"

using namespace LO21;

void LO21::LogSystem::ecrireConsole(const LogMessage& m){
    qDebug() << m.info();
}

void LO21::LogSystem::ecrireFichier(const LogMessage& m){
    QFile file("/home/florian/Documents/UTC/LO21/Qt/Calculatrice/Calculatrice.log");

    QString old;

    //Lecture
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        throw CalculatriceException("LogSystem",OTHER,"Echec d'ouverture de fichier de log en lecture");

    old=file.readAll();
    file.close();

    //Ecriture
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        throw CalculatriceException("LogSystem",OTHER,"Echec d'ouverture de fichier de log en ecriture");


    qDebug() << "ecriture" << endl;
    QTextStream out(&file);
    out << old << "\n";
    out << m.info();

    file.close();
}

void LO21::LogSystem::ecrireLog(const LogMessage& m){
    LogSystem::ecrireConsole(m);
    LogSystem::ecrireFichier(m);
}
