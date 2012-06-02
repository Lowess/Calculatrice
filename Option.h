#ifndef OPTION_H
#define OPTION_H

/*Template method : singleton*/

enum TypeDiv {ENTIER,REEL,RATIONNEL};

namespace Calculatrice{
    class Option {
    private:
        TypeDiv _typeDiv;
        bool _complexe, _degre;
        static Option* _option;

        Option(){
            _complexe = false;
            _degre = false;
        }

        void changeTypeDiv(string s) {
            switch(s) {
                case 'entier':
                        _typeDiv = ENTIER;
                        break;
                case 'reel':
                        _typeDiv = REEL;
                        break;
                case 'rationnel':
                        _typeDiv = RATIONNEL;
                        break;
                default:
                        _typeDiv = ENTIER;
                        break;
            }
        }

        void switchDegre(){
            _degre = !_degre;
        }

        void switchComplexe(){
            _complexe = !_complexe;
        }

    public:

        /*ExÃ©cutÃ© dÃ¨s le chargement de l'application
         *Charge le log prÃ©cÃ©dent
         */
        Option& getInstance(){
            if(_option==0){
                _option = new Option();
                //Quand fait, load le log
            }
            return _option;
        }

        /*ReÃ§oit signal pour switcher une option
         */

        void changeOption(QString option){

        }


    };
}

#endif // OPTION_H
