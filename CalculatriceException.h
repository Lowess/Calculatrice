#ifndef CALCULATRICEEXCEPTION_H
#define CALCULATRICEEXCEPTION_H

/*! \file CalculatriceException.h
 * \author Florian Dambrine, Olivia Reaney
 * \brief Fichier d'en-tête pour déclaration de la classe CalculatriceException
 */

#include <QString>
#include <stdexcept>

/*! \namespace LO21
 *  \brief Désigne les classes définies dans le but du projet de LO21 P12
 */
namespace LO21{

    /*! \enum CalculatriceExceptionType
     * Définit les différents types d'erreur rencontrés lors du fonctionnement de la calculatrice
     */
    enum CalculatriceExceptionType { MATHS, OTHER, PILE, OPTION };

    /*! \class CalculatriceException
     * \brief Classe gérant l'affichage des erreurs, et la levée d'exceptions
     */
    class CalculatriceException : public std::exception{
        public:

            /*! \fn CalculatriceException(const QString& c, const CalculatriceExceptionType t, const QString& s) throw()
             * \brief Construit une exception, en définissant la classe qui l'a appelé, le type et l'explication de l'erreur
             * \param c représente le nom de la classe ayant levé l'exception
             * \param t représente le type de l'erreur levée, grâce à l'enum défini précédemment
             * \param s représente le texte d'explication de l'erreur
             */
            CalculatriceException(const QString& c, const CalculatriceExceptionType t, const QString& s) throw():_class(c),_type(t),_info(s){}

            /*! \fn QString get_info() const throw()
             * \brief Récupère l'information concernant l'exception
             * \return QString qui renvoie le texte décrivant l'exception
             */
            QString get_info() const throw(){ return _info; }

            /*! \fn QString get_class() const throw()
             * \brief Récupère le nom de la classe ayant levé l'exception
             * \return QString qui renvoie le nom de la classe
             */
            QString get_class() const throw(){ return _class; }

            /*! \fn CalculatriceExceptionType get_type() const throw()
             * \brief Récupère le type de l'exception
             * \return CalculatriceExceptionType définissant le type de l'exception
             */
            CalculatriceExceptionType get_type() const throw(){ return _type; }

            /*! \fn const char* what() const throw()
             * \brief Permet l'affichage de l'erreur
             * \return const char* (comme méthode virtuelle pure de la bibliothèque)
             * construit à partir des informations de la classe Calculatrice Exception
             */
            const char* what() const throw(){
                QString type;
                switch (_type){
                    case MATHS:
                        type="maths"; break;
                    case PILE:
                        type="pile"; break;
                    case OPTION:
                        type="option"; break;
                    default:
                        type="autre"; break;
                }

                QString str("Oups... Une exception de type "+ type +" a ete captee:\n\n");
                str += "Message d'information:\n\n"+_info;
                str.toUtf8();
                return str.toStdString().c_str();
            }

            /*! \fn virtual ~CalculatriceException() throw()
             * \brief Destructeur de la classe CalculatriceException
             */
            virtual ~CalculatriceException() throw();

        private:

            QString _class; /*! Attribut contenant le nom de la classe ayant levé l'exception */
            CalculatriceExceptionType _type; /*! Attribut contenant le type de l'exception levée */
            QString _info; /*! Attribut contenant la description de l'exception */
    };
}
#endif // CALCULATRICEEXCEPTION_H
