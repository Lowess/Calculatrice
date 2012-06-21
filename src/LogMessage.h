#ifndef LOGMESSAGE_H
#define LOGMESSAGE_H

/*! \file Entier.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tete pour declaration de la classe LogMessage
  */

#include <QString>
#include <QDebug>
#include <QDateTime>

/*! \namespace LO21
 *  \brief Designe les classes definies dans le but du projet de LO21 P12
 */
namespace LO21{
    /*! \enum enum_LogMessage
     * \brief Definit les differents types de messages affichables
     */
    enum enum_LogMessage {INFO, ERREUR, SYSTEME};

    /*! \class LogMessage
     * \brief Classe permettant de gerer l'affichage de messages informatifs
     */
    class LogMessage{
        private:
            QString _mes; /*! Texte du message a afficher */
            enum_LogMessage _imp; /*! Type du message */

        public:

            /*! \fn LogMessage(const QString& s, enum_LogMessage i)
             * \brief Constructeur de la classe LogMessage
             * \param s la chaine de caracteres que le message affichera
             * \param i le type du message
             */
            LogMessage(const QString& s, enum_LogMessage i=INFO):_mes(s),_imp(i){}

            /*! \fn QString info() const
             * \brief Renvoie un message contenant les informations sur le log (date, type, message)
             * \return QString contenant la version textualisee des informations
             */
            QString info() const;

    };
}


#endif // LOGMESSAGE_H
