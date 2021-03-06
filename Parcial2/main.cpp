#include <iostream>
#include "canion.h"
#include "bala.h"

using namespace std;

int main()
{
    Canion COfensivo(800,100,0,0.05);
    Canion CDefensivo(800,20,800,0.025);
    Bala bala;
    int Voo,opcion=-1;
    while(opcion != 0){
        cout << "-----------------------------------------------------BIENVENIDO------------------------------------------------------" << endl;
        cout << "1. Generar disparos (al menos tres) ofensivos que comprometan la integridad del";
        cout << " canion defensivo." << endl;
        cout << "2. Generar disparos (al menos tres) defensivos que comprometan la integridad del";
        cout << " canion ofensivo." << endl;
        cout << "3. Dado un disparo ofensivo, generar (al menos tres) disparos defensivos que impida";
        cout <<" que el canion defensivo sea destruido sin importar si el canion ofensivo pueda ser destruido."<<endl;
        cout << "4. Dado un disparo ofensivo, generar (al menos tres) disparo defensivos que impidan";
        cout << " que los caniones defensivo y ofensivo puedan ser destruidos." <<endl;
        cout << "5. Dado un disparo ofensivo efectivo y un disparo defensivo que comprometa la";
        cout << "efectividad del ataque ofensivo, generar (al menos tres) disparos que neutralicen el ataque defensivo";
        cout << "y permitan que el ataque ofensivo sea efectivo." << endl;
        cout << "0.Para salir." << endl;
        cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Ingrese una opcion: " << endl;
        cin >> opcion;
        switch (opcion) {
        case 0:break;
        case 1:{
            cout << "Ingrese la velocidad inicial desde la cual quiere probar: " << endl;
            cin >> Voo;
            bala.DisparoOfensivo(COfensivo, CDefensivo, Voo);
        }break;
        case 2:{
            cout << "Ingrese la velocidad inicial desde la cual quiere probar: " << endl;
            cin >> Voo;
            bala.DisparoDefensivo(COfensivo, CDefensivo, Voo);
        }break;
        case 3:{
            int an,vo;
            cout << "Ingrese la velocidad inicial desde la cual quiere probar: " << endl;
            cin >> Voo;
            cout<< "Ingrese angulo con el cual se ejecuto el disparo ofensivo: "<< endl;
            cin >> an;
            cout << "Ingrese la velocidad inicial con la cual se ejecuto el disparo ofensivo:" << endl;
            cin >> vo;
            bala.DisparoDefensivo2(COfensivo,CDefensivo,Voo,an,vo);
        }break;
        case 4:{
            int an,vo;
            cout << "Ingrese la velocidad inicial desde la cual quiere probar: " << endl;
            cin >> Voo;
            cout<< "Ingrese angulo con el cual se ejecuto el disparo ofensivo: "<< endl;
            cin >> an;
            cout << "Ingrese la velocidad inicial con la cual se ejecuto el disparo ofensivo:" << endl;
            cin >> vo;
            bala.DisparoDefensivo3(COfensivo,CDefensivo,Voo,an,vo);
        }break;
        case 5:{
            int ango,vo,angd,vd;
            cout << "Ingrese la velocidad inicial desde la cual quiere probar: " << endl;
            cin >> Voo;
            cout<< "Ingrese angulo con el cual se ejecuto el disparo ofensivo: "<< endl;
            cin >> ango;
            cout << "Ingrese la velocidad inicial con la cual se ejecuto el disparo ofensivo:" << endl;
            cin >> vo;
            cout<< "Ingrese angulo con el cual se ejecuto el disparo ofensivo: "<< endl;
            cin >> angd;
            cout << "Ingrese la velocidad inicial con la cual se ejecuto el disparo ofensivo:" << endl;
            cin >> vd;
            bala.DisparoOfensivo1(COfensivo,CDefensivo,Voo,ango,vo,angd,vd);
        }break;
        }
     }
    return 0;
}
