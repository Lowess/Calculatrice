#ifndef CALCULATRICEEXCEPTION_H
#define CALCULATRICEEXCEPTION_H

#include <QString>

#include <stdexcept>

enum CalculatriceExceptionType { MATHS, OTHER, PILE };


namespace Calculatrice{
    class CalculatriceException : public std::exception{
        public:
            CalculatriceException(const QString& c, const CalculatriceExceptionType t, const QString& s) throw():_class(c),_type(t),_info(s){}

            QString get_info() const throw(){ return _info; }
            QString get_class() const throw(){ return _class; }
            CalculatriceExceptionType get_type() const throw(){ return _type; }

            const char* what() const throw(){
                QString type;
                switch (_type){
                    case MATHS:
                        type="MATHS"; break;
                    default:
                        type="OTHER";
                }

                QString str("Exception emise par la classe: "+_class+" de type "+type+" Information: "+_info);
                return str.toStdString().c_str();
            }

            virtual ~CalculatriceException() throw();

        private:
            QString _class;
            CalculatriceExceptionType _type;
            QString _info;
    };
}
#endif // CALCULATRICEEXCEPTION_H
