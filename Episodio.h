class Episodio : public Video{
    private:
        string nombreSerie;
        string numEpisodio;
        string temporada;
    public:
        //Constructores
        Episodio() : Video() {nombreSerie = temporada = "";}
        Episodio(int i,string n,string g,double d,double c,string ns,string ne,string t) : Video(i,n,g,d,c) {nombreSerie = ns; numEpisodio = ne; temporada = t;}
        //Getters
        string getNombreSerie() {return nombreSerie;}
        string getNumEpisodio() {return numEpisodio;}
        string getTemporada() {return temporada;}
        //Setters
        void setNombreSerie(string ns) {nombreSerie = ns;}
        void setNumEpisodio(string ne) {numEpisodio = ne;}
        void setTemporada(string t) {temporada = t;}
        //Otros Metodos
        void imprimir();
};
void Episodio :: imprimir(){
    cout << "NOMBRE SERIE: " << nombreSerie << endl;
    cout << "NOMBRE EPISODIO: " << nombre << endl;
    cout << "NUMERO EPISODIO: " << numEpisodio << endl;
    cout << "TEMPORADA: " << temporada << endl;
    cout << "ID: " << id  << endl;
    cout << "DURACION: " << duracion << endl;
    cout << "GENERO: " << genero << endl;
    cout << "CALIFICACION: " << calificacion << endl << endl;
}