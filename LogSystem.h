#ifndef LOGSYSTEM_H
#define LOGSYSTEM_H

#include <QFile>
#include <QDir>
#include "CalculatriceException.h"
#include "LogMessage.h"

namespace LO21{
    class LogSystem{
        public:
        static void ecrireConsole(const LogMessage& m);
        static void ecrireFichier(const LogMessage& m);
        static void ecrireLog(const LogMessage& m);

    };
}
#endif // LOGSYSTEM_H
