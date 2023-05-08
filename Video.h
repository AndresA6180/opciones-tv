class Video{
    protected:
        int id;
        string nombre;
        string genero;
        double duracion;
        double calificacion;
    public:
        //Constructores
        Video() {id = duracion = calificacion = 0; nombre = genero = "";}
        Video(int,string,string,double,double);
        //Getters
        int getId() {return id;}
        string getNombre() {return nombre;}
        string getGenero() {return genero;}
        double getDuracion() {return duracion;}
        double getCalificacion() {return calificacion;}
        //Setters
        void setId(int i) {id = i;}
        void setNombre(string n) {nombre = n;}
        void setGenero(string g) {genero = g;}
        void setDuracion(double d) {duracion = d;}
        void setCalificacion(double c) {calificacion = c;}
        //Otros Metodos
        virtual void imprimir() = 0; //Este metodo hace a la clase abstracta por lo que no se pueden instanciar obejetos.

};
//Constructores
Video :: Video(int i,string n,string g,double d,double c){
    id = i;
    nombre = n;
    duracion = d;
    genero = g;
    calificacion = c;
}