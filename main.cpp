#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

//Declarando nuestros Arrays, y una estructura de variables a utilizar
string nombre[25], nacionalidad[25], destino[25];
int numeroDePasaporte[25], edad[25];
struct extras{
    int op, numPas, contPas=0, lugaresDisp, contrasenia, numAsiento=1;
};
struct extras datosExt;
//Función para ingresar los datos a nuestros Arrays de manera de Notación de punteros
void ingresarDatos(){
	ofstream archivoClientesSalida("clientes.txt", ios::app);
	if(!archivoClientesSalida){
		cerr<<"No se pudo abrir el archivo"<<endl;
		exit(EXIT_FAILURE);
	}
    datosExt.lugaresDisp=51-datosExt.numAsiento;
    cout<<"Por cada persona se ocupa 2 lugares, debido al distanciamiento!!!"<<endl;
    cout<<"Lugares disponibles: "<<datosExt.lugaresDisp<<endl;
    cout<<"Ingrese el numero de personas que viajaran: ";
    cin>>datosExt.numPas;
    //archivoClientesSalida<<"\n"<<setw(25)<<"Nombre del pasajero"<<setw(25)<<"Numero de pasaporte"<<setw(20)<<"Nacionalidad"<<setw(15)<<"Edad"<<setw(20)<<"No. de Asiento"<<endl;
    system("CLS");
    //Condición para evaluar si existen lugares disponibles para el numero de personas que viajaran
    if(datosExt.numPas<datosExt.lugaresDisp){
        //Ciclo para ingresar los datos de las personas
        for(int i=0; i<datosExt.numPas;i++){
            datosExt.contPas+=1;
            cout<<"Ingrese el nombre del pasajero No."<<i+1<<": ";
            cin>>*(nombre + i);
            cout<<"Ingrese su numero de pasaporte: ";
            cin>>*(numeroDePasaporte + i);
            cout<<"Ingrese su Nacionalidad: ";
            cin>>*(nacionalidad + i);
            cout<<"Ingrese su Destino: ";
            cin>>*(destino + i);
            cout<<"Ingrese edad: ";
            cin>>*(edad + i);
            cout<<"Su numero de asiento es: "<<datosExt.numAsiento<<"\n\n";
            //La siguiente linea de codigo sirve para ingresar la informaicón a nuestro archivo
            archivoClientesSalida<<setw(25)<<*(nombre + i)<<setw(25)<<*(numeroDePasaporte + i)<<setw(20)<<*(nacionalidad + i)<<setw(20)<<*(destino + i)<<setw(15)<<*(edad + i)<<setw(20)<<datosExt.numAsiento<<endl;
            datosExt.numAsiento+=2;
        }//Fin de ingresar datos
    }else{
        //Condicion si aun existe lugares vacíos
        cout<<"Lugares agotados!!!\n\n";
    }
    system("PAUSE");
}

//Función para mostrar datos del archivo en pantalla
void mostrarDatosDelArchivo(string nombreMostrar, int numeroDePasaporteMostrar, string nacionalidadMostrar, string destinoMostrar, int edadMostrar, int numAsientoMostrar){
    //Leer el archivo .txt
    ifstream archivoClientesEntrada("clientes.txt", ios::in);
    if(!archivoClientesEntrada){
        cerr<<"No se pudo abrir el archivo"<<endl;
        exit(EXIT_FAILURE);
    }
    //Imprimir datos en pantalla
    cout<<"\n"<<setw(25)<<"Nombre del pasajero"<<setw(25)<<"Numero de pasaporte"<<setw(20)<<"Nacionalidad"<<setw(20)<<"Destino"<<setw(15)<<"Edad"<<setw(20)<<"No. de Asiento"<<endl;
    for(int i=0; i<datosExt.contPas; i++){
        archivoClientesEntrada>>nombreMostrar>>numeroDePasaporteMostrar>>nacionalidadMostrar>>destinoMostrar>>edadMostrar>>numAsientoMostrar;
        cout<<setw(25)<<nombreMostrar<<setw(25)<<numeroDePasaporteMostrar<<setw(20)<<nacionalidadMostrar<<setw(20)<<destinoMostrar<<setw(15)<<edadMostrar<<setw(20)<<numAsientoMostrar<<endl;
    }
    cout<<"\n\n";
}

//Menú Principal
int main(){
    do{
        system("CLS");
        cout<<"\t**Bienvenido a Express Airlines**\n\n"<<endl;
        cout<<"1. Ingreso de pasajeros"<<endl;
        cout<<"2. Solicitar informacion"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<"Ingrese la opcion que desea realizar: ";
        cin>>datosExt.op;
        system("CLS");
        switch(datosExt.op){
            case 1:
                ingresarDatos();
                break;
            case 2:
                int numeroDePasaporteMostrar, edadMostrar, numAsientoMostrar;
                string nombreMostrar, nacionalidadMostrar, destinoMostrar;
                cout<<"Ingrese la constrasenia de 'Administrador': ";
                cin>>datosExt.contrasenia;
                //Seguridad para mostrar datos del archivo .txt (NO CUALQUIER PERSONA LO PUEDE VISUALIZAR)
                if(datosExt.contrasenia==2021){
                    mostrarDatosDelArchivo(nombreMostrar, numeroDePasaporteMostrar, nacionalidadMostrar, destinoMostrar, edadMostrar, numAsientoMostrar);
                }else{
                    cout<<"Contraseña Incorrecta!!!\n\n";
                }
                //FIN SEGURIDAD
                system("PAUSE");
                break;
        }

    }while(datosExt.op!=3);
    cout<<"\n\n\t**-GRACIAS POR UTILIZAR NUESTRO PROGRAMA EXPRESS AIRLINES 21-**\n\n";

	return (0);
}

