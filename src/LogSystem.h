#ifndef LOGSYSTEM_H
#define LOGSYSTEM_H

/*! \file Entier.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tete pour declaration de la classe LogSystem
  */

#include <QFile>
#include <QDir>
#include "CalculatriceException.h"
#include "LogMessage.h"

/*! \namespace LO21
 *  \brief Designe les classes definies dans le but du projet de LO21 P12
 */
namespace LO21{
    /*! \class LogSystem
     * \brief Classe permettant de gerer les nombres complexes
     */
    class LogSystem{
        public:
        /*! \fn static void ecrireConsole(const LogMessage& m)
         * \brief Ecrire le message sur la console
         * \param m le message a afficher
         */
        static void ecrireConsole(const LogMessage& m);

        /*! \fn static void ecrireFichier(const LogMessage& m)
         * \brief Ecrire le message dans un fichier
         * \param m le message a afficher
         */
        static void ecrireFichier(const LogMessage& m);

        /*! \fn static void ecrireLog(const LogMessage& m)
         * \brief Permet l'appel aux deux fonctions pour ecrire dans un fichier et sur la console
         * \param m le message a afficher
         */
        static void ecrireLog(const LogMessage& m);

    };
}
#endif // LOGSYSTEM_H
