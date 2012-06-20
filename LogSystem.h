#ifndef LOGSYSTEM_H
#define LOGSYSTEM_H

#include <QFile>
#include "CalculatriceException.h"
#include "LogMessage.h"

namespace LO21{
    /*! \class Complexe
     * \brief Classe permettant de gérer les nombres complexes
     */
    class LogSystem{
        public:
        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        static void ecrireConsole(const LogMessage& m);

        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        static void ecrireFichier(const LogMessage& m);

        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        static void ecrireLog(const LogMessage& m);

    };
}
#endif // LOGSYSTEM_H
