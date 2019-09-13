#include "Hilo.cpp"
#include "Hilo2.cpp"
#include "Hilo3.cpp"


using namespace std;

int main()
{
	Hilo *h1 = new Hilo();
	h1->run();
	bool *vive = h1->getVive();
	int *dinero=h1->getDinero();
	Hilo2 *h2= new Hilo2(dinero,vive);
	h2->run();
	int *vida = h1->getVida();
	int *vidaMax = h1->getVidaMax();
	Hilo3 *h3=new Hilo3(vida,vidaMax,vive);
	h3->run();
	int opcion=0;
	while(opcion!=3)
	{
		if(*h1->getVive()==false)
		{
			return 0;
		}
		cout<<"*************Juego en linea*************\n\n1.Ver datos\n2.Curar vida\n3.Salir\n\nPrecionar para seleccionar...";
		getch();
		cout<<"\n\nSeleccion: ";
		cin>>opcion;
		if(opcion==1)
		{
			cout<<"\n\nDatos:\n\nDinero: "<<*h1->getDinero()<<"\nVida: "<<*h1->getVida()<<"\nVida maxima: "<<*h1->getVidaMax()<<"\nNivel: "<<*h1->getNivel()<<endl;
			getch();
		}
		if(opcion==2)
		{
			if(*h1->getDinero()>=1)
			{
				if(*h1->getVida()<*h1->getVidaMax())
				{
					cout<<"\n\nSe utilizo una unidad de dinero para curar un punto de vida.";
					h1->setDinero(*h1->getDinero()-1);
					h1->setVida(*h1->getVida()+1);
				}
				else
				{
					cout<<"\n\nLa vida esta al maximo.";
				}
				
			}
			else
			{
				cout<<"\n\nNo alcanza el dinero para curar la vida.";
			}
		}
		
		
		cout<<"\n\n";
	}
	
	return 0;
}
