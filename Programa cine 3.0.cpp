#include<iostream>
#include<cstdlib>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<fstream>
#include<cstring>
#include<vector>
#include<sstream>
#include<conio.h>
#include<time.h> 
#include <stdio.h>

using namespace std;


struct Peliculas{
	char Codigo[5];
	char Nombre[40];
	char Duracion[40];
	char Director[40];
	char Genero[40]; 
	char Censura[40]; 
	char Sinopsis[1000];
};

struct Turnos{
	char CodigoPelicula[5];
	char HoraInicio[10];
	char HoraFin[10];
	char Sala[10];
	int asientos;
	int asientosComprados;
	bool Status;
};

struct Bouchers{
	int CodigoBoucher;
	char NombreUsuario[40];
	char NombrePelicula[40];
	char HoraInicial[10];	
	char HoraFinal[10];
	char CodigoSala[10];
	char TipoCompra[7]; 
	float Gasto;
	string fecha;
};

vector<Peliculas> p;
vector<Turnos> t;
vector<Bouchers> b;


void menuPrincipal();
void menuAdministrador();
void menuUsuario();
void mostrarCartelera();
void ventaEntradas();
void listaCompradores();
void mostrarCarteleraUsuario();
void datosPelicula();
void CompraEntradas();

void leeTurnos();
void leePeliculas();
void guardarBouchers();
int consistencia();
void limpiarPantalla();
void terminarAccion();

int valor;
bool validador;

int main(){
	leePeliculas();
	leeTurnos();
	menuPrincipal();
	guardarBouchers();
	
	return 0;
}

void menuPrincipal(){
	do{
		system ("cls");
		cout << "\n\t\tElija una opcion:\n";
		cout << "\n\t\t1 :: Entrar como administrador\n";
		cout << "\t\t2 :: Entrar como Usuario\n";
		cout << "\t\t3 :: Salir del programa\n";
		cout << "\n\n\t\tElija una opcion: ";
		valor = consistencia();
		switch (valor){
			case 1:
				menuAdministrador();
				break;
			case 2:
				menuUsuario();
				break;
			case 3:
				validador = false;
				break;
			default:
				cout <<"\n\t\tERROR #404 Opcion invalida\n";
				Sleep(1000); 
		} 
	}while (validador);
}

void menuAdministrador(){
	do{
		system ("cls");
		cout << "\n\t\tElija una opcion:\n";
		cout << "\n\t\t1 :: Mostrar la cartelera\n";
		cout << "\t\t2 :: Venta de entradas\n";
		cout << "\t\t3 :: Mostrar lista de compradores\n";
		cout << "\t\t4 :: Ir al menu principal\n";
		cout << "\n\n\t\tElija una opcion: ";
		valor = consistencia();
		switch (valor){
			case 1:
				mostrarCarteleraUsuario();
				break;
			case 2:
				ventaEntradas();
				break;
			case 3:
				listaCompradores();
				break;
			case 4:
				menuPrincipal();
				break;
			default:
				cout <<"\n\t\tERROR #404 Opcion invalida\n";
				Sleep(1000);
				break; 
		}
	}while(validador);		
}

void menuUsuario(){
	limpiarPantalla();
		do{
		system ("cls");
		cout << "\n\t\tElija una opcion:\n";
		cout << "\n\t\t1 :: Mostrar la cartelera\n";
		cout << "\t\t2 :: Datos de las peliculas\n";
		cout << "\t\t3 :: Compra de entradas\n";
		cout << "\t\t4 :: Ir al menu principal\n";
		cout << "\n\n\t\tElija una opcion: ";
		valor = consistencia();
		switch (valor){
			case 1:
				mostrarCartelera();
				break;
			case 2:
				datosPelicula();
				break;
			case 3:
				CompraEntradas();
				break;
			case 4:
				menuPrincipal();
				break;	
			default:
				cout <<"\n\t\tERROR #404 Opcion invalida\n";
				Sleep(1000);
				break; 
		}
	}while(validador);
}

void mostrarCartelera(){
	limpiarPantalla();
	cout<<"\n\n";
	for (int i=0; i< 5; i++){
		cout <<"\t" << p[i].Nombre <<": ";
		for(int j=0;j<25;j++){ 
			if(p[i].Codigo[0] == t[j].CodigoPelicula[0]){
				cout << "[" << t[i].HoraInicio << "] ";
			}	
		}
		cout << "\n";		
	}
	terminarAccion();
	menuAdministrador();
}

void ventaEntradas(){
	limpiarPantalla();
	time_t rawtime; 
  	struct tm * timeinfo;
  	char buffer [80];
  	time (&rawtime);
  	timeinfo = localtime (&rawtime);
  	strftime (buffer,80,"%c",timeinfo);
  	string lfecha=buffer;
	int i=0,valor1;
	char aux[40],aux1[40];
	do{
		limpiarPantalla();
		cout << "\n\tIngrese el nombre del cliente: ";
		cin.getline(aux,40);
		cout << "\n";
		b.push_back(Bouchers());
		strcpy(b[i].NombreUsuario,aux);
		for (int j=0; j< 5; j++){
			cout <<j+1<<"::"<< p[j].Nombre<<" ";
		}
		cout << "\n\n\tElejir la funcion: ";
		do{
			valor = consistencia();
			cout<<"\n\t";
			switch(valor){
				case 1:
					cout << p[0].Nombre <<"\n";
					strcpy(b[i].NombrePelicula,p[0].Nombre);
					validador = true;
					break;
				case 2:
					cout << p[1].Nombre <<"\n";
					strcpy(b[i].NombrePelicula,p[1].Nombre);
					validador = true;
					break;
				case 3:
					cout << p[2].Nombre <<"\n";
					strcpy(b[i].NombrePelicula,p[2].Nombre);
					validador = true;
					break;
				case 4:
					cout << p[3].Nombre <<"\n";
					strcpy(b[i].NombrePelicula,p[3].Nombre);			
					validador = true;
					break;
				case 5:
					cout << p[4].Nombre <<"\n";
					strcpy(b[i].NombrePelicula,p[4].Nombre);			
					validador = true;
					break;
				default:
					cout << "\n\tERROR #404 Opcion invalida.";
					validador = false;
					break;
			}
		}while(validador == false);
		itoa(valor,aux1,10);
		cout<<"\n\t¿Que turno desea?:";
		int k=1;
		for(int j=0;j<25;j++){ 
			if( aux1[0] == t[j].CodigoPelicula[0]){
				cout <<k<<"."<<t[j].HoraInicio << " ";
				k++;
			}
		}
		valor1 = consistencia();
		cout<<"\n";
		switch (valor1){
			case 1:
				cout<<"\tTurno 1 elegido\n";
				break;
			case 2:
				cout<<"\tTurno 2 elegido\n";
				break;
			case 3:
				cout<<"\tTurno 3 elegido\n";
				break;
			case 4:
				cout<<"\tTurno 4 elegido\n";
				break;
			case 5:
				cout<<"\tTurno 5 elegido\n";
				break;
			default:
				cout <<"\tERROR #404 Opcion invalida.\n";
				break;
		}
		k=0;
		for(int j=0;j<25;j++){ 
			if(aux1[0] == t[j].CodigoPelicula[0]){
				if( k+1 == valor1){
				strcpy(b[i].HoraInicial,t[j].HoraInicio);
				strcpy(b[i].HoraFinal,t[j].HoraFin);
				strcpy(b[i].CodigoSala,t[j].Sala);
				}
			k++;
			}
		}
		cout<<"\n\tCantidad de entradas: ";
		valor = consistencia();
		b[i].Gasto = valor*12;
		b[i].fecha=lfecha;
		strcpy(b[i].TipoCompra,"Caja");
		i++;
		cout << "\n\t¿Desea hacer otra compra? 1::SI 0::NO ";
		valor = consistencia();
		if (valor == 0){
			validador = false;
		}
	}while(validador);
	menuAdministrador();
}

void CompraEntradas(){
	limpiarPantalla();
	time_t rawtime; 
  	struct tm * timeinfo;
  	char buffer [80];
  	time (&rawtime);
  	timeinfo = localtime (&rawtime);
  	strftime (buffer,80,"%c",timeinfo);
  	string lfecha=buffer;
	int i=0,valor1;
	char aux[40],aux1[40];
	do{
		limpiarPantalla();
		cout << "\n\tIngrese el nombre del cliente: ";
		cin.getline(aux,40);
		cout << "\n";
		b.push_back(Bouchers());
		strcpy(b[i].NombreUsuario,aux);
		for (int j=0; j< 5; j++){
			cout <<j+1<<"::"<< p[j].Nombre<<" ";
		}
		cout << "\n\n\tElejir la funcion: ";
		do{
			valor = consistencia();
			cout<<"\n\t";
			switch(valor){
				case 1:
					cout << p[0].Nombre <<"\n";
					strcpy(b[i].NombrePelicula,p[0].Nombre);
					validador = true;
					break;
				case 2:
					cout << p[1].Nombre <<"\n";
					strcpy(b[i].NombrePelicula,p[1].Nombre);
					validador = true;
					break;
				case 3:
					cout << p[2].Nombre <<"\n";
					strcpy(b[i].NombrePelicula,p[2].Nombre);
					validador = true;
					break;
				case 4:
					cout << p[3].Nombre <<"\n";
					strcpy(b[i].NombrePelicula,p[3].Nombre);			
					validador = true;
					break;
				case 5:
					cout << p[4].Nombre <<"\n";
					strcpy(b[i].NombrePelicula,p[4].Nombre);			
					validador = true;
					break;
				default:
					cout << "\n\tERROR #404 Opcion invalida.";
					validador = false;
					break;
			}
		}while(validador == false);
		itoa(valor,aux1,10);
		cout<<"\n\t¿Que turno desea?:";
		int k=1;
		for(int j=0;j<25;j++){ 
			if( aux1[0] == t[j].CodigoPelicula[0]){
				cout <<k<<"."<<t[j].HoraInicio << " ";
				k++;
			}
		}
		valor1 = consistencia();
		cout<<"\n";
		switch (valor1){
			case 1:
				cout<<"\tTurno 1 elegido\n";
				break;
			case 2:
				cout<<"\tTurno 2 elegido\n";
				break;
			case 3:
				cout<<"\tTurno 3 elegido\n";
				break;
			case 4:
				cout<<"\tTurno 4 elegido\n";
				break;
			case 5:
				cout<<"\tTurno 5 elegido\n";
				break;
			default:
				cout <<"\tERROR #404 Opcion invalida.\n";
				break;
		}
		k=0;
		for(int j=0;j<25;j++){ 
			if(aux1[0] == t[j].CodigoPelicula[0]){
				if( k+1 == valor1){
				strcpy(b[i].HoraInicial,t[j].HoraInicio);
				strcpy(b[i].HoraFinal,t[j].HoraFin);
				strcpy(b[i].CodigoSala,t[j].Sala);
				}
			k++;
			}
		}
		cout<<"\n\tCantidad de entradas: ";
		valor = consistencia();
		b[i].Gasto = valor*12;
		b[i].fecha=lfecha;
		strcpy(b[i].TipoCompra,"Online");
		i++;
		cout << "\n\t¿Desea hacer otra compra? 1::SI 0::NO ";
		valor = consistencia();
		if (valor == 0){
			validador = false;
		}
	}while(validador);
	menuUsuario();
}

void mostrarCarteleraUsuario(){
	limpiarPantalla();
	cout<<"\n\n";
	for (int i=0; i< 5; i++){
		cout <<"\t" << p[i].Nombre <<": ";
		for(int j=0;j<25;j++){ 
			if(p[i].Codigo[0] == t[j].CodigoPelicula[0]){
				cout << "[" << t[i].HoraInicio << "] ";
			}	
		}
		cout << "\n";		
	}
	terminarAccion();
	menuUsuario();
}

void listaCompradores(){
	limpiarPantalla();
	cout<<"Compradores"<<endl;
	cout<<"Nombre\tPelicula\tSala\tHora\tImporte\tFecha\tTipo"<<endl;
	for(int i=0;i<b.size();i++){
		cout<<b[i].NombreUsuario<<"\t"<<b[i].NombrePelicula <<"\t"<<b[i].CodigoSala<<"\t"<<b[i].HoraInicial<<"\t"<<b[i].Gasto<<"\t"<<b[i].fecha<<"\t"<<b[i].TipoCompra<<endl;
	}
	terminarAccion();
}

void guardarBouchers(){
	ofstream salida("bouchers.txt",ios::app);
	for(int i=0;i<b.size();i++){
		salida<<b[i].NombreUsuario<<","<<b[i].NombrePelicula <<","<<b[i].CodigoSala<<","<<b[i].HoraInicial<<","<<b[i].Gasto<<","<<b[i].fecha<<","<<b[i].TipoCompra<<endl;
	}	
	salida.close();
}

void datosPelicula(){
	limpiarPantalla();
	for(int i=0;i<p.size()-1;i++){
		cout<<"Pelicula "<<i+1<<":\n";
		cout<<"Nombre:   "<<p[i].Nombre<<"\n";
		cout<<"Duracion: "<<p[i].Duracion<<"\n";
		cout<<"Director: "<<p[i].Director<<"\n";
		cout<<"Genero:   "<<p[i].Genero<<"\n";
		cout<<"Censura:  "<<p[i].Censura<<"\n";
		cout<<"Sinopsis: "<<p[i].Sinopsis<<"\n\n";
	}
	terminarAccion();
}

void leeTurnos(){
	int j=0;
	ifstream archivo("turnos.csv");	
	while(archivo){
		char lCodigoPelicula[5];
		char lHoraInicio[10];
		char lHoraFin[10];
		char lSala[10];
		
		t.push_back(Turnos());
		archivo.getline(lCodigoPelicula,5,';');
		archivo.getline(lHoraInicio,10,';');
		archivo.getline(lHoraFin,10,';');
		archivo.getline(lSala,10,'\n');
	
		strcpy(t[j].CodigoPelicula, lCodigoPelicula);
		strcpy(t[j].HoraInicio, lHoraInicio);
		strcpy(t[j].HoraFin, lHoraFin);
		strcpy(t[j].Sala, lSala);
		
		j++;
	}
}

void leePeliculas(){
	int i=0;
	ifstream archivo("peliculas.csv");	

	while(archivo){
		char lCodigo[5];
		char lNombre[40];
		char lDuracion[40];
		char lDirector[40];
		char lGenero[40];
		char lCensura[40];
		char lSinopsis[1000];
		
		p.push_back(Peliculas());
		archivo.getline(lCodigo,5,';');
		archivo.getline(lNombre,40,';');
		archivo.getline(lDuracion,40,';');
		archivo.getline(lDirector,40,';');
		archivo.getline(lGenero,40,';');
		archivo.getline(lCensura,40,';');
		archivo.getline(lSinopsis,1000,'\n');
	
		strcpy(p[i].Codigo, lCodigo);
		strcpy(p[i].Nombre, lNombre);
		strcpy(p[i].Duracion, lDuracion);
		strcpy(p[i].Director, lDirector);
		strcpy(p[i].Genero, lGenero);
		strcpy(p[i].Censura, lCensura);
		strcpy(p[i].Sinopsis, lSinopsis);

		i++;
	}
}

int consistencia(){
	string opcion;
	int longitud,numero;
	bool validador = true;
	getline (cin,opcion);
	longitud = opcion.size();
	if(longitud==0){
		validador = false;	
	}
	else{
		for(int i=0;i<longitud;i++){
			if(!isdigit(opcion[i])){ 
				validador = false;
			}				
		}		
	}
	if(validador){
		numero = atoi(opcion.c_str());
	}
	else{
		numero = -1;
	}
	return numero;
}

void limpiarPantalla(){
	system("CLS");
}

void terminarAccion(){
	char tecla;
	cout<<endl<<"\n\tPresione para salir";
	tecla=getch();
}
