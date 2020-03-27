#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Fontanero{
    public: 
        vector<int> minutos_trabajo; 
        int num_trabajos; 

        Fontanero(int num_trabajos){
            this->num_trabajos = num_trabajos; 
        }

        bool compare(int a, int b){
            return a>b?true:false;
        }

        void definir_trabajos(){
            for (int i=0; i<num_trabajos; ++i){
                minutos_trabajo.push_back((rand()%30)+1); 
            }
            sort(minutos_trabajo.begin(), minutos_trabajo.end());
        }
        
        void obtener_satisfaccion(){
            int tiempo_transcurrido = 0; 
            cout<<"Orden de trabajos por (minutos, tiempo transcurrido, satisfaccion): "<<endl;

            for (int i=0; i<minutos_trabajo.size(); ++i){
                tiempo_transcurrido+=minutos_trabajo[i];
                float tiempo_efectivo = (minutos_trabajo[i]*1.0)/tiempo_transcurrido; 
                string satisfaccion; 
                if (tiempo_efectivo <= 0.3){
                    satisfaccion = "Insatisfecho";
                } else if (tiempo_efectivo > 0.3 && tiempo_efectivo <=0.5){
                    satisfaccion = "Medianamente satisfecho";
                } else {
                    satisfaccion = "Satisfecho";
                }

                cout<<"Trabajo ["<<i<<"]: "<<minutos_trabajo[i]<<", "<<tiempo_transcurrido<<", "<<satisfaccion<<endl;
            }
        }
};

int main(){
    Fontanero f(7);
    f.definir_trabajos();
    f.obtener_satisfaccion();

    return 0; 
}