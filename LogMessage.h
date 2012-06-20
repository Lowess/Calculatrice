#ifndef LOGMESSAGE_H
#define LOGMESSAGE_H

/*! \file Entier.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe LogMessage
  */

#include <QString>
#include <QDebug>
#include <QDateTime>

/*! \namespace LO21
 *  \brief Désigne les classes définies dans le but du projet de LO21 P12
 */
namespace LO21{
    /*! \enum enum_LogMessage
     * \brief Définit les différents types de messages affichables
     */
    enum enum_LogMessage {INFO, ERREUR, SYSTEME};

    /*! \class LogMessage
     * \brief Classe permettant de gérer l'affichage de messages informatifs
     */
    class LogMessage{
        private:
            QString _mes; /*! Texte du message à afficher */
            enum_LogMessage _imp; /*! Type du message */

        public:

            /*! \fn LogMessage(const QString& s, enum_LogMessage i)
             * \brief Constructeur de la classe LogMessage
             * \param s la chaîne de caractères que le message affichera
             * \param i le type du message
             */
            LogMessage(const QString& s, enum_LogMessage i=INFO):_mes(s),_imp(i){}

            /*! \fn QString info() const
             * \brief Renvoie un message contenant les informations sur le log (date, type, message)
             * \return QString contenant la version textualisée des informations
             */
            QString info() const;

    };
}


#endif // LOGMESSAGE_H
