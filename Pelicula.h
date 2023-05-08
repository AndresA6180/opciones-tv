class Pelicula : public Video{
    public:
        //Constructores
        Pelicula() : Video() {;}
        Pelicula(int i,string n,string g,double d,double c) : Video(i,n,g,d,c) {;}
        //Otros Metodos
        void imprimir();
};
//Otros Metodos
void Pelicula :: imprimir(){
    cout << "ID: " << id  << endl;
    cout << "NOMBRE: " << nombre << endl;
    cout << "GENERO: " << genero << endl;
    cout << "DURACION: " << duracion << endl;
    cout << "CALIFICACION: " << calificacion << endl << endl;
}