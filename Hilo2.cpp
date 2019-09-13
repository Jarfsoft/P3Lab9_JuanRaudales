#include <time.h>
#include <iostream>
#include <Windows.h>
#include <process.h>
#include <stdlib.h> 
#include <conio.h>


#ifndef HILO2_CPP
#define HILO2_CPP

using namespace std;

class Hilo2
{
	private:
		bool vive;
		int espera;
		int *dinero;
	public:
		Hilo2(int *din)
		{
			dinero=din;
			vive=true;
			espera=7000;
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
				MessageBox(0,"Gano una unidad", "Aviso",MB_OK);
				*dinero++;
				if(!vive)
				{
					_endthread();
				}
			}
		}
};

#endif
