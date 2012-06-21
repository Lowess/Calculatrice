#ifndef CALCULATRICEEXCEPTION_H
#define CALCULATRICEEXCEPTION_H

/*! \file CalculatriceException.h
 * \author Florian Dambrine, Olivia Reaney
 * \brief Fichier d'en-tete pour declaration de la classe CalculatriceException
 */

#include <QString>
#include <stdexcept>

/*! \namespace LO21
 *  \brief Designe les classes definies dans le but du projet de LO21 P12
 */
namespace LO21{

    /*! \enum CalculatriceExceptionType
     * Definit les differents types d'erreur rencontres lors du fonctionnement de la calculatrice
     */
    enum CalculatriceExceptionType { MATHS, OTHER, PILE, OPTION };

    /*! \class CalculatriceException
     * \brief Classe gerant l'affichage des erreurs, et la levee d'exceptions
     */
    class CalculatriceException : public std::exception{
        public:

            /*! \fn CalculatriceException(const QString& c, const CalculatriceExceptionType t, const QString& s) throw()
             * \brief Construit une exception, en definissant la classe qui l'a appele, le type et l'explication de l'erreur
             * \param c represente le nom de la classe ayant leve l'exception
             * \param t represente le type de l'erreur levee, grace a l'enum defini precedemment
             * \param s represente le texte d'explication de l'erreur
             */
            CalculatriceException(const QString& c, const CalculatriceExceptionType t, const QString& s) throw():_class(c),_type(t),_info(s){}

            /*! \fn QString get_info() const throw()
             * \brief Recupere l'information concernant l'exception
             * \return QString qui renvoie le texte decrivant l'exception
             */
            QString get_info() const throw(){ return _info; }

            /*! \fn QString get_class() const throw()
             * \brief Recupere le nom de la classe ayant leve l'exception
             * \return QString qui renvoie le nom de la classe
             */
            QString get_class() const throw(){ return _class; }

            /*! \fn CalculatriceExceptionType get_type() const throw()
             * \brief Recupere le type de l'exception
             * \return CalculatriceExceptionType definissant le type de l'exception
             */
            CalculatriceExceptionType get_type() const throw(){ return _type; }

            /*! \fn const char* what() const throw()
             * \brief Permet l'affichage de l'erreur
             * \return const char* (comme methode virtuelle pure de la bibliotheque)
             * construit a partir des informations de la classe Calculatrice Exception
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

            QString _class; /*! Attribut contenant le nom de la classe ayant leve l'exception */
            CalculatriceExceptionType _type; /*! Attribut contenant le type de l'exception levee */
            QString _info; /*! Attribut contenant la description de l'exception */
    };
}
#endif // CALCULATRICEEXCEPTION_H
