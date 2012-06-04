#ifndef OPTION_H
#define OPTION_H

#include <QString>

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
            _typeDiv = ENTIER;
            //connecter les slots pour le faire apparaître à l'écran
        }

        void changeTypeDiv(QString s) {
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

        /*Exécuté au chargement de l'application
         *Charge le log précédent
         */
        Option& getInstance(){
            if(_option==0){
                _option = new Option();
                //try fopen(log.txt)
                //if fail : créer fichier puis attribuer valeurs de base
            }
            return *_option;
        }


        /*Recoit signal pour switcher une option
         */
        void changeOption(QString option){

        }

        void saveOptions(){
        //à la fermeture du programme, sauver les options courantes dans le fichier log
        }

        void libereInstance() {
            if (_option==0){
                delete _option;
            }
        }

    };
}

#endif // OPTION_H
