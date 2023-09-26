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
#include "funciones.h"

int main()
{

    int x, i, trufastotales1 = 0, trufastotales2 = 0, op, oinks1 = 0, oinks2 = 0, pdvganador, pdvmax = 0, tbarro1 = 0, tbarro2 = 0, p1, p2, pmax1, pmax2, b;
    char continuar, decide = 'f', barro = 'f';
    string jugador1, jugador2, jugadorganador, jugadormax;
    int lanzamientos1[5] = {0, 0, 0, 0, 0};
    int lanzamientos2[5] = {0, 0, 0, 0, 0};
    int trufas1[5] = {0, 0, 0, 0, 0};
    int trufas2[5] = {0, 0, 0, 0, 0};

    system("Color ed");

    setlocale(LC_CTYPE, "Spanish");

    system( "Title JUEGO: GRAN CERDO" );

    mostrar_menu_de_opciones(op);


    while (op != 0)
    {

        switch (op)
        {

        case 1:


            rlutil::locate(2, 10);
            cout << "¡A JUGAR!" << endl;
            rlutil::locate(2, 12);
            cerdito();
            rlutil::locate(2, 17);
            system("pause");
            system("cls");
            ingresar_nombres(jugador1, jugador2);
            system("cls");
            Quien_empieza_dados(jugador1, jugador2);
            system("cls");
            for(i=0; i<4; i++)
            {
                for(x=1; x<=2; x++)
                {
                    do
                    {

                        if(x==1)
                        {
                            system("cls");
                            mostrar_datos_trufas_ambos(jugador1, trufastotales1, jugador2, trufastotales2);
                            mostrar_datos_ronda(jugador1, i, trufas1, lanzamientos1);

                            if ((tbarro1 > 50 && tbarro2 > 50) || barro == 't')
                            {
                                desarrollo_con_tres_dados(decide, barro, continuar, trufas1, i, oinks1, trufastotales1, trufastotales2, p1, pmax1, b);
                            }
                            else
                            {
                                desarrollo_con_dos_dados(decide, barro, continuar, trufas1, i, oinks1, trufastotales1, tbarro1, p1, pmax1, b);
                            }

                            deciciones(decide, continuar);
                        }

                        else
                        {
                            system("cls");
                            mostrar_datos_trufas_ambos(jugador1, trufastotales1, jugador2, trufastotales2);
                            mostrar_datos_ronda(jugador2, i, trufas2, lanzamientos2);

                            if ((tbarro1 > 50 && tbarro2 > 50) || barro == 't')
                            {

                                desarrollo_con_tres_dados(decide, barro, continuar, trufas2, i, oinks2, trufastotales2, trufastotales1, p2, pmax2, b);
                            }
                            else
                            {
                                desarrollo_con_dos_dados(decide, barro, continuar, trufas2, i, oinks2, trufastotales2, tbarro2, p2, pmax2, b);
                            }

                            deciciones(decide, continuar);

                        }

                    }
                    while(continuar == 'S'||continuar == 's');

                    if (x==1)
                    {
                        trufastotales1 = trufastotales1+trufas1[i];
                        b=0;
                    }
                    else
                    {
                        trufastotales2 = trufastotales2+trufas2[i];
                        b=0;
                    }

                }
            }
            suma_puntaje_final(trufastotales1, trufastotales2, jugador1, jugador2, lanzamientos1, lanzamientos2, i, oinks1, oinks2, jugadorganador, pdvganador, pmax1, pmax2);

            estadisticas(jugadorganador, pdvganador, jugadormax, pdvmax);
            decide = 'f';
            barro = 'f';
            for (i=0;i<5;i++){
                lanzamientos1[i]=0;
            }
            for (i=0;i<5;i++){
                lanzamientos2[i]=0;
            }
            for (i=0;i<5;i++){
                trufas1[i]=0;
            }
            for (i=0;i<5;i++){
                trufas2[i]=0;
            }
            trufastotales1 = 0;
            trufastotales2 = 0;
            oinks1 = 0;
            oinks2 = 0;
            tbarro1 = 0;
            tbarro2 = 0;

            break;
        case 2:
            system("cls");
            mostrar_estadistica(jugadormax, pdvmax);



            break;

        case 3:
            system("cls");
            mostrar_credito();



            break;
        }


        mostrar_menu_de_opciones(op);
    }

    return 0;
}

