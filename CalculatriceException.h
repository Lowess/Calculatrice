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

            /*! \class CalculatriceException
             * \brief Classe gérant l'affichage des erreurs, et la levée d'exceptions
             */
            CalculatriceException(const QString& c, const CalculatriceExceptionType t, const QString& s) throw():_class(c),_type(t),_info(s){}

            /*! \class CalculatriceException
             * \brief Classe gérant l'affichage des erreurs, et la levée d'exceptions
             */
            QString get_info() const throw(){ return _info; }

            /*! \class CalculatriceException
             * \brief Classe gérant l'affichage des erreurs, et la levée d'exceptions
             */
            QString get_class() const throw(){ return _class; }

            /*! \class CalculatriceException
             * \brief Classe gérant l'affichage des erreurs, et la levée d'exceptions
             */
            CalculatriceExceptionType get_type() const throw(){ return _type; }

            /*! \class CalculatriceException
             * \brief Classe gérant l'affichage des erreurs, et la levée d'exceptions
             */
            const char* what() const throw(){
                QString type;
                switch (_type){
                    case MATHS:
                        type="MATHS"; break;
                    default:
                        type="OTHER"; break;
                }

                QString str("Exception emise par la classe: "+_class+" de type "+type+" Information: "+_info);
                return str.toStdString().c_str();
            }

            /*! \class CalculatriceException
             * \brief Classe gérant l'affichage des erreurs, et la levée d'exceptions
             */
            virtual ~CalculatriceException() throw();

        private:

            QString _class; /*!  */
            CalculatriceExceptionType _type; /*! */
            QString _info; /*! */
    };
}
#endif // CALCULATRICEEXCEPTION_H
