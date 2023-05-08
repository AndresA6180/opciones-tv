#include <iostream>
#include <fstream>
#include <typeinfo>
using namespace std;
#include "Video.h"
#include "Pelicula.h"
#include "Episodio.h"
#include "Serie.h"
//Declaramos las variables
Video* arrVideos[50];
int numVideos = 0;
Serie arrSeries[20];
int numSeries = 0;
int opcion = 0;
//Desarrollamos los encabezados funciones
void cargarDatos();
void mostrarPeliculas();
void mostrarSeries();
void mostrarVideosCalificacion();
void mostrarVideosGenero();
void mostrarEpisodiosSerie();
void mostrarPeliculasCalificacion();
//Desarrollo del programa principal
int main(){
    do{
        cout << "1) Cargar archivos de datos" << endl;
        cout << "2) Mostrar todas las peliculas" << endl;
        cout << "3) Mostrar lista de series" << endl;
        cout << "4) Mostrar videos con cierta calificacion" << endl;
        cout << "5) Mostrar videos con cierto genero" << endl;
        cout << "6) Mostrar episodios de una serie" << endl;
        cout << "7) Mostrar peliculas con cierta calificacion" << endl;
        cout << "8) Salir" << endl;
        cin >> opcion;
        cout << endl;

        switch(opcion){
            case 1:{
                cargarDatos();
                break;
            }
            case 2: {
                mostrarPeliculas();
                break;
            }
            case 3:{
                mostrarSeries();
                break;
            }
            case 4:{
                mostrarVideosCalificacion();
                break;
            }
            case 5:{
                mostrarVideosGenero();
                break;
            }
            case 6:{
                mostrarEpisodiosSerie();
                break;
            }
            case 7:{
                mostrarPeliculasCalificacion();
                break;
            }
        }
    } while (opcion != 8);
    return 0;
}
//Desarrollo de funciones
//Cargar datos de los archivos de texto
void cargarDatos(){
    ifstream archivoSeries;
    ifstream archivoVideos;
    archivoSeries.open("datosSeries.txt");
    archivoVideos.open("datosVideos.txt");
    int tempId;
    string tempNomSerie;
    while(!archivoSeries.eof()){
        archivoSeries >> tempId >> tempNomSerie;
        arrSeries[numSeries].setNumSerie(tempId);
        arrSeries[numSeries].setTitulo(tempNomSerie);
        numSeries++;
    }
    string tipo;
    string tempNomEpisodio;
    string tempGen;
    double tempDur;
    double tempCal;
    string numEp;
    string numTemp;
    while(!archivoVideos.eof()){
        archivoVideos >> tipo; 
        if(tipo == "p"){
            archivoVideos >> tempId >> tempNomEpisodio >> tempGen >> tempDur >> tempCal; 
            arrVideos[numVideos] = new Pelicula(tempId,tempNomEpisodio,tempGen,tempDur,tempCal);
            numVideos++;
        } else if(tipo == "e"){
            archivoVideos >> tempId >> tempNomEpisodio >> tempGen >> tempDur >> tempCal >> tempNomSerie >> numEp >> numTemp;
            arrVideos[numVideos] = new Episodio(tempId,tempNomEpisodio,tempGen,tempDur,tempCal,tempNomSerie,numEp,numTemp);
            Episodio tempEp(tempId,tempNomEpisodio,tempGen,tempDur,tempCal,tempNomSerie,numEp,numTemp);
            for(int i = 0; i < numSeries; i++){
                if(arrSeries[i].getTitulo() == tempNomSerie){
                    arrSeries[i].agregarEpisodio(tempEp);
                }
            }
            numVideos++;
        }
    }
}
//Imprimir todas las peliculas
void mostrarPeliculas(){
    cout << "PELICULAS" << endl << endl;
    for(int i = 0; i < numVideos; i++){
        if(typeid(*arrVideos[i]) == typeid(Pelicula)){
            arrVideos[i]->imprimir();
        }
    }
}
//Imprimir todas las series
void mostrarSeries(){
    cout << "SERIES" << endl << endl;
    for(int i = 0; i < numSeries; i++){
        arrSeries[i].imprimirSerie();
    }
}
//Imprimir todos los videos con cierta calificacion
void mostrarVideosCalificacion(){
    double tempCal;
    cout << "Introduzca la calificacion deseada: ";
    cin >> tempCal;
    for(int i = 0; i < numVideos; i++){
        if(arrVideos[i]->getCalificacion() == tempCal){
            arrVideos[i]->imprimir();
        }
    }
}
//Imprimir todos los videos con cierto genero
void mostrarVideosGenero(){
    string tempGen;
    cout << "Introduzca el genero deseado: ";
    cin >> tempGen;
    for(int i = 0; i < numVideos; i++){
        if(arrVideos[i]->getGenero() == tempGen){
            arrVideos[i]->imprimir();
        }
    }
}
//Imprimir todos los episodios de una serie
void mostrarEpisodiosSerie(){
    string tempSerie;
    cout << "Introduzca la serie deseada: ";
    cin >> tempSerie;
    for(int i = 0; i < numSeries; i++){
        if(arrSeries[i].getTitulo() == tempSerie){
            arrSeries[i].imprimirEpisodios();
        }
    }
}
//Mostrar todas las peliculas con cierta calificacion
void mostrarPeliculasCalificacion(){
    double tempCalP;
    cout << "Introduzca la calificacion deseada: ";
    cin >> tempCalP;
    for(int i = 0; i < numVideos; i++){
        if(typeid(*arrVideos[i]) == typeid(Pelicula)){
            if(arrVideos[i]->getCalificacion() == tempCalP){
                arrVideos[i]->imprimir();
            }
        }
    }
}