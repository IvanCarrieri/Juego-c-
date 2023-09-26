#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void cerdito();

void cartel();

void linea();

void linealarga();

void rectangulo(int posx, int posy);

void mostrar_menu_de_opciones(int &op);

void ingresar_nombres(string &jugador1, string &jugador2);

void tirar_dados(int vec[], int cant);

void Quien_empieza_dados(string &jugador1, string &jugador2);

void mostrar_datos_trufas_ambos(string jugador1, int trufastotales1, string jugador2, int trufastotales2);

void mostrar_datos_ronda(string jugador, int cant, int trufas[], int lanzamientos[]);

void desarrollo_con_dos_dados(char &decide, char &barro, char &continuar, int trufas[], int i, int &oinks, int &trufastotales, int &tbarro, int &p, int &pmax, int &b);

void desarrollo_con_tres_dados(char &decide, char &barro, char &continuar, int trufas[], int i, int &oinks, int &trufastotales, int &trufastotalesdelotro, int &p, int &pmax, int &b);

void deciciones(char &decide, char &continuar);

void suma_puntaje_final(int &trufastotales1, int &trufastotales2, string &jugador1, string &jugador2, int lanzamientos1[], int lanzamientos2[], int i, int &oinks1, int &oinks2, string &jugadorganador, int &pvdganador, int &pmax1, int &pmax2);

void estadisticas(string &jugadorganador,int &pdvganador, string &jugadormax, int &pdvmax);

void mostrar_estadistica(string &jugadormax, int &pdvmax);

void mostrar_credito();

void motrarasterisco(int &pdvmaxrrano);


#endif // FUNCIONES_H_INCLUDED
