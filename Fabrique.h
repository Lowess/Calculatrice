#ifndef FABRIQUE_H
#define FABRIQUE_H

#include "QString"

#include "Expression.h"
#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"

/**
  * Implementation du DP Singleton
  *
**/
enum enum_Fabrique {ENTIER, REEL, RATIONNEL, COMPLEXE};

namespace Calculatrice{
    class Fabrique{
        private:
            static Fabrique* _f;

            Fabrique(){}
            Fabrique(const Fabrique& f){}
            ~Fabrique(){}
            Fabrique& operator=(const Fabrique& f){}
        public:
            static Fabrique& getInstance();
            static Fabrique& libereInstance();

            Expression* creer(const enum_Fabrique type, const QString& param1="", const QString& param2="") const;
    };
}

#endif // FABRIQUE_H
