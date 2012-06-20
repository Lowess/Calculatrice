#ifndef CALCULATRICEEXCEPTION_H
#define CALCULATRICEEXCEPTION_H

#include <QString>

#include <stdexcept>

enum CalculatriceExceptionType { MATHS, OTHER, PILE, OPTION };


namespace LO21{
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

            virtual ~CalculatriceException() throw();

        private:
            QString _class;
            CalculatriceExceptionType _type;
            QString _info;
    };
}
#endif // CALCULATRICEEXCEPTION_H
