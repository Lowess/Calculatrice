#ifndef LOGMESSAGE_H
#define LOGMESSAGE_H

#include <QString>
#include <QDebug>
#include <QDateTime>
namespace LO21{
    enum enum_LogMessage {INFO, ERREUR, SYSTEME};

    class LogMessage{
        private:
            QString _mes;
            enum_LogMessage _imp;
        public:
            LogMessage(const QString& s, enum_LogMessage i=INFO):_mes(s),_imp(i){}
            QString info() const;

    };
}


#endif // LOGMESSAGE_H
