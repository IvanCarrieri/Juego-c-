#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <string>
#include <cmath>

using namespace std;

#include "rlutil.h"

void cerdito()
{

    cout << "  ^..^--" << endl;
    cout << " @_      )~"<< endl;
    cout << "   `w  w´"<< endl;
    cout << endl;

}

void cartel()
{
    cout << "GRAN CERDO" << endl;
    cout << endl;
}

void linea()
{
    cout << "------------------------" << endl;
}

void linealarga()
{

    cout << "------------------------------------------------------------" << endl;
}

void rectangulo(int posx, int posy)
{
    rlutil::locate(posx, posy++);
    cout << "+-----------------------+";
    rlutil::locate(posx, posy++);
    cout << "|                       |";
    rlutil::locate(posx, posy++);
    cout << "|                       |";
    rlutil::locate(posx, posy++);
    cout << "|                       |";
    rlutil::locate(posx, posy++);
    cout << "+-----------------------+";

}

void mostrar_menu_de_opciones(int &op)
{
    rlutil::locate(2, 1);
    system("cls");
    rlutil::locate(2, 2);
    cartel();
    rlutil::locate(2, 3);
    cout << "-----------------------";
    rlutil::locate(2, 4);
    cout << "1 - JUGAR";
    rlutil::locate(2, 5);
    cout << "2 - ESTADISTICAS" << endl;
    rlutil::locate(2, 6);
    cout << "3 - CERDITOS (CRÉDITOS)";
    rlutil::locate(2, 7);
    cout << "-----------------------";

    rlutil::locate(2, 8);
    cout << "Opción: ";
    cin >> op;
    cout << endl;

}



void ingresar_nombres(string &jugador1, string &jugador2)
{
    rlutil::locate(2, 2);
    cartel();
    cin.ignore();
    rlutil::locate(2, 4);
    cout << "Ingrese el nombre del jugador 1: ";
    getline(cin, jugador1);
    rlutil::locate(2, 6);
    cout << "Ingrese el nombre del jugador 2: ";
    getline(cin, jugador2);
    cout << endl;
    rlutil::msleep(600);


}


void tirar_dados(int vec[], int cant)
{
    int i;

    for (i=0; i<cant; i++)
    {
        vec[i] = (rand() % 6) + 1;
        switch (vec[i])
        {
        case 1:

            cout << "+-------+" <<endl;
            cout << "|       |" <<endl;
            cout << "|   o   |" <<endl;
            cout << "|       |" <<endl;
            cout << "+-------+" <<endl;

            break;
        case 2:

            cout << "+-------+" <<endl;
            cout << "| o     |" <<endl;
            cout << "|       |" <<endl;
            cout << "|     o |" <<endl;
            cout << "+-------+" <<endl;

            break;
        case 3:

            cout << "+-------+" <<endl;
            cout << "| o     |" <<endl;
            cout << "|   o   |" <<endl;
            cout << "|     o |" <<endl;
            cout << "+-------+" <<endl;

            break;
        case 4:

            cout << "+-------+" <<endl;
            cout << "| o   o |" <<endl;
            cout << "|       |" <<endl;
            cout << "| o   o |" <<endl;
            cout << "+-------+" <<endl;

            break;
        case 5:

            cout << "+-------+" <<endl;
            cout << "| o   o |" <<endl;
            cout << "|   o   |" <<endl;
            cout << "| o   o |" <<endl;
            cout << "+-------+" <<endl;

            break;
        case 6:

            cout << "+-------+" <<endl;
            cout << "| o   o |" <<endl;
            cout << "| o   o |" <<endl;
            cout << "| o   o |" <<endl;
            cout << "+-------+" <<endl;

            break;

        }

        cout << endl;


    }

    cout << endl;

}

void Quien_empieza_dados(string &jugador1, string &jugador2)
{
    int dados1[2], dados2[2], sumadados1, sumadados2;
    string aux;
    srand(time(NULL));
    do
    {

        cout << jugador1 << " Pulse una tecla para lanzar los dados...";
        getch();
        cout << endl;
        cout << endl;
        tirar_dados(dados1, 2);
        rlutil::locate(2, 15);
        system("pause");
        sumadados1 = dados1[0] + dados1[1];
        system("cls");

        cout << jugador2 << " Pulse una tecla para lanzar los dados...";
        getch();
        cout << endl;
        cout << endl;
        tirar_dados(dados2, 2);
        rlutil::locate(2, 15);
        system("pause");
        sumadados2 = dados2[0] + dados2[1];
        system("cls");
    }
    while((dados1[0] == dados2[0] && dados1[1] == dados2[1]) || (dados1[0]==dados2[1] && dados1[1]==dados2[0]));

    if(sumadados1 < sumadados2)
    {
        aux = jugador1;
        jugador1 = jugador2;
        jugador2 = aux;
    }
    else
    {
        if(sumadados1 == sumadados2)
        {
            if((dados1[0]<dados2[0] && dados1[0]<dados2[1]) || (dados1[1]<dados2[0] && dados1[1]<dados2[1]))
            {
                aux = jugador1;
                jugador1 = jugador2;
                jugador2 = aux;
            }
        }
    }

    system("cls");
    rlutil::locate(2, 2);
    cout << "Jugador 1: " << jugador1;
    rlutil::locate(2, 4);
    cout << "Jugador 2: " << jugador2;
    rlutil::locate(2, 6);
    system("pause");

}

void mostrar_datos_trufas_ambos(string jugador1, int trufastotales1, string jugador2, int trufastotales2)
{
    rlutil::locate(2, 1);
    cartel();
    rlutil::locate(2, 2);
    linealarga();
    rlutil::locate(2, 3);
    cout << jugador1 << ": " << trufastotales1 << " trufas acumuladas" << "           " << jugador2 << ": " << trufastotales2 << " trufas acumuladas" << endl;

}

void mostrar_datos_ronda(string jugador, int cant, int trufas[], int lanzamientos[])
{
    rlutil::locate(3, 5);
    cout << "TURNO DE " << jugador << endl;
    rectangulo(2, 7);
    rlutil::locate(3, 8);
    cout << "RONDAS #" << cant;
    rlutil::locate(3, 9);
    cout << "TRUFAS DE LA RONDA: " << trufas[cant];
    rlutil::locate(3, 10);
    cout << "LANZAMIENTOS: " << lanzamientos[cant] << endl;
    lanzamientos[cant]++;
    rlutil::locate(2, 14);
    cout << "LANZAMIENTO #" << lanzamientos[cant] << endl;
    rlutil::locate(2, 16);
    cout <<"Pulse una tecla para tirar los dados" << endl;
    cout << endl;
    getch();
}

void desarrollo_con_dos_dados(char &decide, char &barro, char &continuar, int trufas[], int i, int &oinks, int &trufastotales, int &tbarro, int &p, int &pmax, int &b)
{
    int v[2];
    tirar_dados(v, 2);
    int s;
    b=0;

    if (v[0]!=v[1] && (v[0]!=1) && (v[1]!=1))
    {
        trufas[i] = trufas[i]+v[0]+v[1];
        decide = 't';
        s = v[0]+v[1];
        p = s;
        cout << endl;
        cout << "¡SUMASTE " << s << " TRUFAS! :)" << endl;
        cout << endl;
        s = 0;

    }


    if (v[0]==v[1] && (v[0]!=1) && v[1]!=1)
    {
        trufas[i] = trufas[i]+((v[0]+v[1])*2);
        oinks++;
        decide = 'f';
        continuar = 'S';
        s = ((v[0]+v[1])*2);
        p = s;
        cout << endl;
        cout << "¡SUMASTE " << s << " TRUFAS Y GANASTE 1 OINK :)!" << endl;
        cout << endl;
        s = 0;
        system("pause");

    }


    if (v[0]==1 && v[1]==1)
    {
        trufastotales = 0;
        trufas[i] = 0;
        decide = 'f';
        continuar = 'N';
        barro = 't';
        cout << endl;
        cout << "Perdiste todas las trufas de la ronda, las acumuladas y te caíste al barro, que mala suerte... :(" << endl;
        cout << endl;
        system("pause");
    }



    if ((v[0]!=v[1]) && (v[0]==1 || v[1]==1))
    {

        trufas[i] = 0;
        decide = 'f';
        continuar = 'N';
        cout << endl;
        cout << "Perdiste todas las trufas de la ronda :(" << endl;
        cout << endl;
        cout << endl;
        system("pause");

    }

    if (b==0)
    {
        pmax = p;
        b=1;
    }
    else if(p>pmax);
    {
        pmax=p;

    }


    tbarro += trufas[i];
}

void desarrollo_con_tres_dados(char &decide, char &barro, char &continuar, int trufas[], int i, int &oinks, int &trufastotales, int &trufastotalesdelotro, int &p, int &pmax, int &b)
{
    int v[3];
    tirar_dados(v, 3);
    int s;
    barro='t';
    b=0;

    if ((v[0]!=v[1] && v[0]!=v[2] && v[1]!=v[2]) && (v[0]!=1 && v[1]!=1 && v[2]!=1))
    {
        trufas[i] = trufas[i]+v[0]+v[1]+v[2];
        s = v[0]+v[1]+v[2];
        p = s;
        cout << endl;
        cout << "¡SUMASTE " << s << " TRUFAS! :)" << endl;
        cout << endl;
        s = 0;
        decide = 't';
    }
    if ((v[0]==v[1] || v[0]==v[2] || v[1]==v[2]) && (v[0]!=1 && v[1]!=1 && v[2]!=1))
    {
        decide = 't';
    }
    if ((v[0]==v[1] && v[1]==v[2]) && (v[0]!=1 && v[1]!=1 && v[2]!=1))
    {
        trufas[i] = trufas[i]+((v[0]+v[1]+v[2])*2);
        oinks++;
        decide = 'f';
        continuar = 'S';
        s = ((v[0]+v[1]+v[2])*2);
        p = s;
        cout << endl;
        cout << "¡SUMASTE " << s << " TRUFAS Y GANASTE 1 OINK :)!" << endl;
        s = 0;
        system("pause");

    }
    if ((v[0]!=v[1] && v[0]!=v[2] && v[1]!=v[2]) && (v[0]==1 || v[1]==1 || v[2]==1))
    {
        trufas[i] = 0;
        decide = 'f';
        continuar = 'N';
        cout << endl;
        cout << "Perdiste todas las trufas de la ronda :(" << endl;
        cout << endl;
        cout << endl;
        system("pause");
    }
    if (v[0]==v[1] && (v[0]==1 && v[1]==1 && v[2]!=1))
    {
        trufastotales = 0;
        trufas[i] = 0;
        decide = 'f';
        continuar = 'N';
        cout << endl;
        cout << "Perdiste todas las trufas de la ronda y las acumuladas, que mala suerte... :(" << endl;
        cout << endl;
        system("pause");
    }
    if (v[0]==v[2] && (v[0]==1 && v[2]==1 && v[1]!=1))
    {
        trufastotales = 0;
        trufas[i] = 0;
        decide = 'f';
        continuar = 'N';
        cout << endl;
        cout << "Perdiste todas las trufas de la ronda y las acumuladas, que mala suerte... :(" << endl;
        cout << endl;
        system("pause");
    }
    if (v[2]==v[1] && (v[2]==1 && v[1]==1 && v[0]!=1))
    {
        trufastotales = 0;
        trufas[i] = 0;
        decide = 'f';
        continuar = 'N';
        cout << endl;
        cout << "Perdiste todas las trufas de la ronda y las acumuladas, que mala suerte... :(" << endl;
        cout << endl;
        system("pause");
    }

    if (v[0]==1 && v[1]==1 && v[2]==1)
    {
        trufastotales += trufas[i];
        trufastotalesdelotro = trufastotales;
        trufastotales = 0;
        trufas[i] = 0;
        decide = 'f';
        continuar = 'N';
        cout << endl;
        cout << "Perdiste todas las trufas de la ronda, las acumuladas y se las debes pasar al otro jugador, que mala suerte... :(" << endl;
        cout << endl;
        system("pause");

    }

    if (b==0)
    {
        pmax = p;
        b=1;
    }
    else
    {
        if(p>pmax)
        {
            pmax=p;

        }
    }
}


void deciciones(char &decide, char &continuar)
{
    if (decide=='t')
    {
        cout << "¿Usted desea continuar lanzando?" << endl;
        cout << "digite S para continuar, o N para finalizar" << endl;
        cin >> continuar;
        cout << endl;
        while (continuar!='N' && continuar!='S' && continuar!='n' && continuar!='s')
        {
            cout << "¿Usted desea continuar lanzando?" << endl;
            cout << "digite S para continuar, o N para finalizar" << endl;
            cin >> continuar;
            cout << endl;
        }

    }
}




void suma_puntaje_final(int &trufastotales1, int &trufastotales2, string &jugador1, string &jugador2, int lanzamientos1[], int lanzamientos2[], int i, int &oinks1, int &oinks2, string &jugadorganador, int &pdvganador, int &pmax1, int &pmax2)
{

    int pdvcodicioso1=0, pdvcodicioso2=0, maxlanzamiento1, maxlanzamiento2, pdvtrufastotales1=0, pdvtrufastotales2=0, pdvoinks1, pdvoinks2, pdvjugador1 = 0, pdvjugador2 = 0, pdvmaxrrano1=0, pdvmaxrrano2=0;
    int pdv50trufas1, pdv50trufas2;
    string ok;





    if (trufastotales1>trufastotales2)
    {
        pdvtrufastotales1 = pdvtrufastotales1+5;
    }
    else
    {
        pdvtrufastotales2 = pdvtrufastotales2+5;
    }
    for (int z=0; z<=4; z++)
    {
        if (z==0)
        {
            maxlanzamiento1 = lanzamientos1[i];
        }
        else
        {
            if (lanzamientos1[i]>maxlanzamiento1)
            {
                maxlanzamiento1 = lanzamientos1[i];
            }
        }
    }
    for (int z=0; z<=4; z++)
    {
        if (z==0)
        {
            maxlanzamiento2 = lanzamientos2[i];
        }
        else
        {
            if (lanzamientos1[i]>maxlanzamiento2)
            {
                maxlanzamiento2 = lanzamientos2[i];
            }
        }
    }
    if (maxlanzamiento1>maxlanzamiento2)
    {
        pdvcodicioso1 = pdvcodicioso1+3;
    }
    else
    {
        pdvcodicioso2 = pdvcodicioso2+3;
    }
    pdvoinks1 = oinks1*2;
    pdvoinks2 = oinks2*2;
    pdv50trufas1 = floor(trufastotales1/50);
    pdv50trufas2 = floor(trufastotales2/50);

    if (pmax1>pmax2)
    {
        pdvmaxrrano1=1;
        if (pdvoinks2>pdvoinks1){
            pdvoinks2=pdvoinks2-1;
        }


        pdv50trufas2=pdv50trufas2-1;
        pdvcodicioso2=pdvcodicioso2-1;
        pdvtrufastotales2=pdvtrufastotales2-1;

    }
    else
    {
        pdvmaxrrano2=1;
        pdvoinks1=pdvoinks1-1;
        pdv50trufas1=pdv50trufas1-1;
        pdvcodicioso1=pdvcodicioso1-1;
        pdvtrufastotales1=pdvtrufastotales1-1;

    }

    pdvjugador1 = pdvtrufastotales1+pdvcodicioso1+pdvoinks1+pdv50trufas1+pdvmaxrrano1;
    pdvjugador2 = pdvtrufastotales2+pdvcodicioso2+pdvoinks2+pdv50trufas2+pdvmaxrrano2;
    if (pdvjugador1>pdvjugador2)
    {
        jugadorganador = jugador1;
        pdvganador = pdvjugador1;
    }
    else
    {
        jugadorganador = jugador2;
        pdvganador = pdvjugador2;
    }



    system("cls");
    rlutil::locate(2, 2);
    cout << "GRAN CERDO";
    rlutil::locate(2, 3);
    cout << "------------------------------------------------------------------------------------------";
    rlutil::locate(2, 5);
    cout << "HITO";
    rlutil::locate(30, 5);
    cout << jugador1;
    rlutil::locate(60, 5);
    cout << jugador2;
    rlutil::locate(2, 6);
    cout << "------------------------------------------------------------------------------------------";
    rlutil::locate(2, 7);
    cout << "Mas trufas en total";
    rlutil::locate(30, 7);
    cout << pdvtrufastotales1 << " PDV (" << trufastotales1 << " trufas)";
    rlutil::locate(60, 7);
    cout << pdvtrufastotales2 << " PDV (" << trufastotales2 << " trufas)";
    rlutil::locate(2, 8);
    cout << "Cada 50 trufas";
    rlutil::locate(30, 8);
    cout << pdv50trufas1 << " PDV (" << pdv50trufas1*50 << " trufas)";
    rlutil::locate(60, 8);
    cout << pdv50trufas2 << " PDV (" << pdv50trufas2*50 << " trufas)";
    rlutil::locate(2, 9);
    cout << "Oinks";
    rlutil::locate(30, 9);
    cout << pdvoinks1 << " PDV (" << oinks1 << " Oinks)";
    rlutil::locate(60, 9);
    cout << pdvoinks2 << " PDV (" << oinks2 << " Oinks)";
    rlutil::locate(2, 10);
    cout << "cerdo codicioso";
    rlutil::locate(30, 10);
    cout << pdvcodicioso1 << " PDV (" << maxlanzamiento1 << " lanzamientos)";
    rlutil::locate(60, 10);
    cout << pdvcodicioso2 << " PDV (" << maxlanzamiento2 << " lanzamientos)";
    rlutil::locate(2, 11);
    cout << "Maxrrano";
    rlutil::locate(30, 11);
    cout << pdvmaxrrano1 << " PDV";
    rlutil::locate(60, 11);
    cout << pdvmaxrrano2 << " PDV";

    rlutil::locate(2, 12);
    cout << "------------------------------------------------------------------------------------------";
    rlutil::locate(2, 13);
    cout << "TOTAL";
    rlutil::locate(30, 15);
    cout << pdvjugador1 << " PDV";
    rlutil::locate(60, 15);
    cout << pdvjugador2 << " PDV";
    if (pdvjugador1 != pdvjugador2)
    {
        rlutil::locate(2, 16);
        cout << "GANADOR: " << jugadorganador << " con " << pdvganador << " puntos de victoria." << endl;
    }
    else
    {
        rlutil::locate(2, 16);
        cout << "EMPATE!!" << endl;
    }


    rlutil::locate(2, 18);
    cout << "Ingrese oink para continuar: ";
    cin >> ok;
    rlutil::locate(2, 22);
    cerdito();
    rlutil::msleep(1000);
    while ((ok != "oink") && (ok != "OINK"))
    {
        rlutil::locate(2, 18);
        cout << "Ingrese oink para continuar: ";
        cin >> ok;
        rlutil::locate(2, 22);
        cerdito();
        rlutil::msleep(1500);
    }

}

void estadisticas(string &jugadorganador,int &pdvganador, string &jugadormax, int &pdvmax)
{

    int band = 0;
    if (band == 0)
    {
        jugadormax = jugadorganador;
        pdvmax = pdvganador;
        band = 1;
    }
    else
    {
        if (pdvganador > pdvmax)
        {
            jugadormax = jugadorganador;
            pdvmax = pdvganador;
        }
    }

}
void mostrar_estadistica(string &jugadormax, int &pdvmax)
{

    cartel();
    linea();

    if (pdvmax > 0)
    {

        cout << "El máximo puntaje de puntos de victoria fue obtenido por: " << jugadormax << " con " << pdvmax << " PVD";
        cout << endl;

    }
    else
    {
        cout << "Sin partidas realizadas";
        cout << endl;



    }
    linea();
    cout << endl;
    cerdito();
    cout <<"Toque una tecla para volver al menú";
    getch();
    system("cls");
}
void mostrar_credito()
{
    cartel();
    linea();
    cout << "Iván Carlos Carrieri" << endl;
    cout << "legajo: 25845";
    cout << endl;
    linea();
    cout << endl;
    cerdito();
    cout <<"Toque una tecla para volver al menú";

    getch();
    system("cls");
}

void motrarasterisco(int &pdvmaxrrano)
{

    if (pdvmaxrrano==0)
    {
        cout << "PDV* (";

    }
    else
    {
        cout << "PDV (";
    }
}
