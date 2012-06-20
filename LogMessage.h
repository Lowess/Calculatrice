#ifndef LOGMESSAGE_H
#define LOGMESSAGE_H

#include <QString>
#include <QDebug>
#include <QDateTime>

namespace LO21{
    /*! \class Complexe
     * \brief Classe permettant de gérer les nombres complexes
     */
    enum enum_LogMessage {INFO, ERREUR, SYSTEME};

    /*! \class Complexe
     * \brief Classe permettant de gérer les nombres complexes
     */
    class LogMessage{
        private:
            QString _mes; /*! */
            enum_LogMessage _imp; /*! */
        public:
            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            LogMessage(const QString& s, enum_LogMessage i=INFO):_mes(s),_imp(i){}

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            QString info() const;

    };
}


#endif // LOGMESSAGE_H
