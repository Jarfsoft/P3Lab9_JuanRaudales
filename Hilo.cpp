#include <time.h>
#include <iostream>
#include <Windows.h>
#include <process.h>
#include <stdlib.h> 
#include <conio.h>


#ifndef HILO_CPP
#define HILO_CPP

using namespace std;

class Hilo
{
	private:
		bool vive;
		int espera;
		int dinero;
		int vida;
		int vidaMax;
		int nivel;
	public:
		Hilo()
		{
			vive=true;
			espera=10000;
			dinero=0;
			vida=1;
			vidaMax=3;
			nivel=1;
		}
		void setDinero(int v)
		{
			dinero=v;
		}
		void setVida(int v)
		{
			vida=v;
		}
		void setVidaMax(int v)
		{
			vidaMax=v;
		}
		void setNivel(int v)
		{
			nivel=v;
		}
		int *getDinero()
		{
			return &dinero;
		}
		int *getVida()
		{
			return &vida;
		}
		int *getVidaMax()
		{
			return &vidaMax;
		}
		int *getNivel()
		{
			return &nivel;
		}
		bool *getVive()
		{
			return &vive;
		}
		void stop()
		{
			vive=false;
		}
		
		void run()
		{
			_beginthread(&Hilo::runner,0,static_cast<void*>(this));
		}
		static void runner(void* o)
		{
			static_cast<Hilo*>(o)->runnerEstatico();
		}
		void runnerEstatico()
		{
			srand(time(NULL));
			while(vive)
			{
				Sleep(espera);
				int entrar=rand() % 10 + 1;
				if(entrar>0 && entrar<9)
				{
					int puntos=0;
					MessageBox(0,"Nuevo encuentro", "Advertencia",MB_OK);
				
					int opcion=0;
					int oponente= rand() % 3 + 1;
					while(!(opcion>0 && opcion<4))
					{
						cout<<"\n\nVida: "<<vida<<"\tVida Oponente: "<<nivel-puntos<<"\n\nPiedra, papel o tijera:\n\n1.Piedra\n2.Papel\n3.Tijera\n\nSeleccion: ";
						cin>>opcion;
					}
					if(oponente==1)
					{
						if(opcion==1)
						{
							cout<<"\n\nEmpate, repetir.\n\n";
							getch();
							continue;
						}
						if(opcion==2)
						{
							cout<<"\n\nGanaste este encuentro.\n\n";
							puntos++;
							getch();
						}
						if(opcion==3)
						{
							cout<<"\n\nPerdiste este encuentro.\n\n";
							vida--;
							getch();
						}
					}
					if(oponente==2)
					{
						if(opcion==1)
						{
							cout<<"\n\nPerdiste este encuentro.\n\n";
							vida--;
							getch();
						}
						if(opcion==2)
						{
							cout<<"\n\nEmpate, repetir.\n\n";
							getch();
							continue;
						}
						if(opcion==3)
						{
							cout<<"\n\nGanaste este encuentro.\n\n";
							puntos++;
							getch();
						}
					}
					if(oponente==3)
					{
						if(opcion==1)
						{
							cout<<"\n\nGanaste este encuentro.\n\n";
							puntos++;
							getch();
						}
						if(opcion==2)
						{
							cout<<"\n\nPerdiste este encuentro.\n\n";
							vida--;
							getch();
						}
						if(opcion==3)
						{
							cout<<"\n\nEmpate, repetir.\n\n";
							getch();
							continue;
						}
					}
					if(vida==0)
					{
						cout<<"\n\nHas perdido la batalla.\n\n";
						getch();
						vive=false;
					}
					if(puntos<nivel)
						continue;
					else
					{
						MessageBox(0,"Has ganado la batalla", "Aviso",MB_OK);
						nivel++;
						vidaMax++;
						vive=false;
					}
					
					
				}
				
				if(!vive)
				{
					_endthread();
				}
				
			}
			
			
			
				
		}
	
};

#endif
