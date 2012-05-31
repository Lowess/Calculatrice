#ifndef FABRIQUE_H
#define FABRIQUE_H

#include "QString"
/**
  * Implementation du DP Singleton
  *
**/
namespace Calculatrice{
    class Fabrique{
        private:
            static Fabrique* _f;

            Fabrique(){}
            Fabrique(const Fabrique& f){}
            ~Fabrique(){}
            Fabrique& operator=(const Fabrique& f){}
        public:
            static Fabrique& getInstance(){
                if(_f==0){
                    _f=new Fabrique();
                }
                else
                    return *_f;
            }
            static Fabrique& libereInstance(){
                if(_f!=0){
                    delete _f;
                }
                _f=0;
            }

            void creer(QString obj);
    };
}

#endif // FABRIQUE_H
