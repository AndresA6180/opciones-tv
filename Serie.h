class Serie{
    private:
        int numSerie;
        string titulo;
        int numEpisodios;
        Episodio episodios[50];
    public:
        //Constructores
        Serie() {numSerie = 0; titulo = ""; numEpisodios = 0;}
        Serie(int ns, string t) {numSerie = ns; titulo = t; numEpisodios = 0;}
        //Getters
        int getNumSerie() {return numSerie;}
        string getTitulo() {return titulo;}
        int getNumEpisodios() {return numEpisodios;}
        //Setters
        void setNumSerie(int ns) {numSerie = ns;}
        void setTitulo(string t) {titulo = t;}
        //Otros Metodos
        void agregarEpisodio(Episodio);
        double calculaCalificacion();
        void imprimirSerie();
        void imprimirEpisodios();
};
//Otros Metodos
void Serie :: agregarEpisodio(Episodio e){
    episodios[numEpisodios] = e;
    numEpisodios++;
}
double Serie :: calculaCalificacion(){
    double total = 0;
    int cont = 0;
    for(int i = 0; i < numEpisodios; i++){
        total += episodios[i].getCalificacion();
        cont++;
    }
    if(cont == 0){
        return 0;
    } else {
        return total/cont;
    }
}
void Serie :: imprimirSerie() {
    cout << "NUMERO DE SERIE: " << numSerie << endl;
    cout << "TITULO: " << titulo << endl << endl;
}
void Serie :: imprimirEpisodios(){
    for(int i = 0; i < numEpisodios; i++){
        episodios[i].imprimir();
    }
}