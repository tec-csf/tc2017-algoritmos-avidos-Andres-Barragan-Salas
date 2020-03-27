#include<iostream>
using namespace std;

struct elemento{
    float peso; 
    int beneficio; 
};

class Mochila{
    public: 
        int capacidad;
        int num_elementos = 10; 

        Mochila(int capacidad){
            this->capacidad = capacidad; 
        }

        elemento elementos[10];
        int solucion[10];

        void definir_elementos(){
            float peso_beneficio[num_elementos]; 

            for (int i=0; i<num_elementos; ++i){
                elementos[i].peso = (rand()%10)+1;
                elementos[i].beneficio = (rand()%15)+1;
                peso_beneficio[i] = elementos[i].peso/elementos[i].beneficio; 
            }
            
            int min;   
            for (int i = 0; i < num_elementos-1; i++){  
                min = i;  
                for (int j = i+1; j < num_elementos; j++){  
                    if (peso_beneficio[j] < peso_beneficio[min])  
                        min = j;  
                }
        
                elemento temp = elementos[i];
                elementos[i] = elementos[min]; 
                elementos[min] = temp; 

                float temp2 = peso_beneficio[i];
                peso_beneficio[i] = peso_beneficio[min]; 
                peso_beneficio[min] = temp2; 
            }  
        }
        
        void  anadir_elementos(){
            float peso_actual; 
            int i;

            for (i=0; i < num_elementos; ++i){
                solucion[i] = 1; 
            }
            peso_actual = 0.0; 
            i=0;
            while ((peso_actual<capacidad) && (i<num_elementos)){
                if (elementos[i].peso + peso_actual < capacidad){
                    peso_actual+=elementos[i].peso;
                    solucion[i] = 1; 
                } else {
                    solucion[i] = 0;
                }
                ++i;
            }
        }

        void obtener_elementos_en_mochila(){
            cout<<"Elementos por (peso, beneficio): "<<endl; 
            for(int i=0; i<num_elementos; ++i){
                if(solucion[i]==1){
                    cout<<"Elemento ["<<i<<"]: "<<elementos[i].peso<<", "<<elementos[i].beneficio<<endl; 
                }
            }
        }
};

int main(){
    Mochila m(15);
    m.definir_elementos();
    m.anadir_elementos();
    m.obtener_elementos_en_mochila();

    return 0;
}