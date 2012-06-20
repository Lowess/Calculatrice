#ifndef LOGMESSAGE_H
#define LOGMESSAGE_H

/*! \file Entier.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-t�te pour d�claration de la classe LogMessage
  */

#include <QString>
#include <QDebug>
#include <QDateTime>

/*! \namespace LO21
 *  \brief D�signe les classes d�finies dans le but du projet de LO21 P12
 */
namespace LO21{
    /*! \enum enum_LogMessage
     * \brief D�finit les diff�rents types de messages affichables
     */
    enum enum_LogMessage {INFO, ERREUR, SYSTEME};

    /*! \class LogMessage
     * \brief Classe permettant de g�rer l'affichage de messages informatifs
     */
    class LogMessage{
        private:
            QString _mes; /*! Texte du message � afficher */
            enum_LogMessage _imp; /*! Type du message */

        public:

            /*! \fn LogMessage(const QString& s, enum_LogMessage i)
             * \brief Constructeur de la classe LogMessage
             * \param s la cha�ne de caract�res que le message affichera
             * \param i le type du message
             */
            LogMessage(const QString& s, enum_LogMessage i=INFO):_mes(s),_imp(i){}

            /*! \fn QString info() const
             * \brief Renvoie un message contenant les informations sur le log (date, type, message)
             * \return QString contenant la version textualis�e des informations
             */
            QString info() const;

    };
}


#endif // LOGMESSAGE_H
