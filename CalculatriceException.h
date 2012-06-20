#ifndef CALCULATRICEEXCEPTION_H
#define CALCULATRICEEXCEPTION_H

/*! \file CalculatriceException.h
 * \author Florian Dambrine, Olivia Reaney
 * \brief Fichier d'en-t�te pour d�claration de la classe CalculatriceException
 */

#include <QString>
#include <stdexcept>

/*! \namespace LO21
 *  \brief D�signe les classes d�finies dans le but du projet de LO21 P12
 */
namespace LO21{

    /*! \enum CalculatriceExceptionType
     * D�finit les diff�rents types d'erreur rencontr�s lors du fonctionnement de la calculatrice
     */
    enum CalculatriceExceptionType { MATHS, OTHER, PILE, OPTION };

    /*! \class CalculatriceException
     * \brief Classe g�rant l'affichage des erreurs, et la lev�e d'exceptions
     */
    class CalculatriceException : public std::exception{
        public:

            /*! \fn CalculatriceException(const QString& c, const CalculatriceExceptionType t, const QString& s) throw()
             * \brief Construit une exception, en d�finissant la classe qui l'a appel�, le type et l'explication de l'erreur
             * \param c repr�sente le nom de la classe ayant lev� l'exception
             * \param t repr�sente le type de l'erreur lev�e, gr�ce � l'enum d�fini pr�c�demment
             * \param s repr�sente le texte d'explication de l'erreur
             */
            CalculatriceException(const QString& c, const CalculatriceExceptionType t, const QString& s) throw():_class(c),_type(t),_info(s){}

            /*! \fn QString get_info() const throw()
             * \brief R�cup�re l'information concernant l'exception
             * \return QString qui renvoie le texte d�crivant l'exception
             */
            QString get_info() const throw(){ return _info; }

            /*! \fn QString get_class() const throw()
             * \brief R�cup�re le nom de la classe ayant lev� l'exception
             * \return QString qui renvoie le nom de la classe
             */
            QString get_class() const throw(){ return _class; }

            /*! \fn CalculatriceExceptionType get_type() const throw()
             * \brief R�cup�re le type de l'exception
             * \return CalculatriceExceptionType d�finissant le type de l'exception
             */
            CalculatriceExceptionType get_type() const throw(){ return _type; }

            /*! \fn const char* what() const throw()
             * \brief Permet l'affichage de l'erreur
             * \return const char* (comme m�thode virtuelle pure de la biblioth�que)
             * construit � partir des informations de la classe Calculatrice Exception
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

            QString _class; /*! Attribut contenant le nom de la classe ayant lev� l'exception */
            CalculatriceExceptionType _type; /*! Attribut contenant le type de l'exception lev�e */
            QString _info; /*! Attribut contenant la description de l'exception */
    };
}
#endif // CALCULATRICEEXCEPTION_H
