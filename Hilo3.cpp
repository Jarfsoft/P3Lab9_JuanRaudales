#include <time.h>
#include <iostream>
#include <Windows.h>
#include <process.h>
#include <stdlib.h> 
#include <conio.h>


#ifndef HILO3_CPP
#define HILO3_CPP

using namespace std;

class Hilo3
{
	private:
		bool vive;
		int espera;
		int *vida;
		int *vidaMax;
		bool *viveOtro;
	public:
		Hilo3(int *vid, int *viMa, bool *viOt)
		{
			vida=vid;
			vidaMax=viMa;
			viveOtro=viOt;
			vive=true;
			espera=6000;
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
			while(vive)
			{
				Sleep(espera);
				if(*vida<*vidaMax && !*viveOtro)
				{
					MessageBox(0,"Gano un punto de vida", "Aviso",MB_OK);
					*vida++;
				
				}
				if(!vive)
				{
					_endthread();
				}
			}
		}
};

#endif
