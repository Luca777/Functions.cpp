#include <ctime>
#include <iostream>
#include <cstdlib>

using namespace std;

//Funzioni base
		void scambia(int &a, int &b);
		void scambia(float &a, float &b);
		void inserisciNumerosita(int &n);

//Gestione random
		bool random_inizializzato = false;
		int random_min = 0; int random_max = 100;
		int randomNM(int n, int m);
		float randomNM_float(int n, int m);
		int random0N(int n);
		float random0N_float(int n);
		void setRandomMin(int min);
		void setRandomMax(int max);
		void inserisciValoriRandom(int &min, int &max);

//Gestione vettore
		int dim_max = 1000;

		void setDimensioneMax(int x);
		void riempiVettore(int v[], int n);
		void riempiVettore(float v[], int n);
		void riempiVettoreRandom(int v[], int n);
		void riempiVettoreRandom(float v[], int n);
		bool aggiungiElemento(int v[], int &n, int x);
		bool aggiungiElemento(float v[], int &n, float x);
		bool rimuoviElemento(int v[], int &n, int x);
		bool rimuoviElemento(float v[], int &n, float x);

//Stampa elementi del vettore
		void stampaVettore(int v[], int n);
		void stampaVettore(float v[], int n);

//Algoritmi array
		void ordinamentoIngenuo(int v[], int n, bool inverso = false);
		void ordinamentoIngenuo(float v[], int n, bool inverso = false);	
		void bubbleSort(int v[], int n, bool inverso = false);
		void bubbleSort(float v[], int n, bool inverso = false);

//Funzioni su array
		float media(int v[], int n);
		float media(float v[], int n);
		int sommaVettore(int v[], int n);
		float sommaVettore(float v[], int n);
		void inverti(int v[], int n);
		void inverti(float v[], int n);
		bool ricercaBinaria(int v[], int n, int x);
		bool ricercaBinaria(float v[], int n, float x);
		int presente(int v[], int n, int x);
		int presente(float v[], int n, float x);
		int minore(int v[], int n);
		float minore(float v[], int n);
		int maggiore(int v[], int n);
		float maggiore(float v[], int n);
		int posizioneMinore(int v[], int n);
		int posizioneMinore(float v[], int n);
		int posizioneMaggiore(int v[], int n);
		int posizioneMaggiore(float v[], int n);


//Funzioni base
	void scambia(int &a, int &b)
	{
		int c = a;
		a = b;
		b = c;
	}

	void scambia(float &a, float &b)
	{
		float d = a;
		a = b;
		b = d;
	}
	
	void inserisciNumerosita(int &n)
	{
		do
		{
			cout << "Inserisci numerosita: " << endl;
			cin >> n;	
		} while (n <= 0);
	}

//Gestione random
	int randomNM(int n, int m)
	{
		int valoreRandom = rand() % (m - n + 1) + n;
		return valoreRandom;
	}

	float randomNM_float(int n, int m)
	{
		float valoreRandom = (rand() % (m*100 - n*100 + 1) + n*100) / 100.0;
		return valoreRandom;
	}

	int random0N(int n)
	{
		int valoreRandom = rand() % (n + 1);
		return valoreRandom;
	}

	float random0N_float(int n)
	{
		float valoreRandom = rand() % (n*100 + 1) / 100.0;
		return valoreRandom;
	}

	void setRandomMin(int min)
	{
		random_min = min;
	}

	void setRandomMax(int max)
	{
		random_max = max;
	}

	void inserisciValoriRandom(int &random_min, int &random_max)
	{
		cout << "Inserisci il valore minimo del random: " << endl;
		cin >> random_min;	
		cout << "Inserisci il valore massimo del random: " << endl;
		cin >> random_max;	
	}

//Gestione vettore
	void setDimensioneMax(int x)
	{
		dim_max = x;
	}

	void riempiVettore(int v[], int n)
	{
		cout << "Inserisci valori del vettore:" << endl;
		for (int i=0; i<n; i++){
			cout << "\tElemento " << i+1 << ": ";
			cin >> v[i];
		}
		cout << endl;
	}

	void riempiVettore(float v[], int n)
	{
		cout << "Inserisci valori del vettore:" << endl;
		for (int i=0; i<n; i++){
			cout << "\tElemento " << i+1 << ": ";
			cin >> v[i];
		}
		cout << endl;
	}

	void riempiVettoreRandom(int v[], int n)
	{
		for (int i=0; i<n; i++)
			v[i] = randomNM(random_min, random_max);
	}

	void riempiVettoreRandom(float v[], int n)
	{
		for (int i=0; i<n; i++)
			v[i] = randomNM_float(random_min, random_max);
	}

	bool aggiungiElemento(int v[], int x, int &n)
	{
		if (n != dim_max)
		{
			v[n] = x;
			n ++;
			return true;
		}
		return false;
	}

	bool aggiungiElemento(float v[], float x, int &n)
	{
		if (n != dim_max)
		{
			v[n] = x;
			n ++;
			return true;
		}
		return false;
	}

	bool rimuoviElemento(int v[], int x, int &n)
	{
		if (presente(v,n,x) != -1)
		{
			int pos = presente(v,n,x);
			for (int i = pos; i < n-1; i++)
				v[i] = v[i+1];
			n--;
			return true;
		}
		return false;
	}

	bool rimuoviElemento(float v[], float x, int &n)
	{
		if (presente(v,n,x) != -1)
		{
			int pos = presente(v,n,x);
			for (int i = pos; i < n-1; i++)
				v[i] = v[i+1];
			n--;
			return true;
		}
		return false;
	}

//Stampa elementi del vettore
	void stampaVettore(int v[], int n)
	{
		cout << "Stampa vettore di interi:" << endl;
		for (int i=0; i<n; i++)
			cout << "\tElemento " << i+1 << ": " << v[i] << endl;
		cout << endl;
	}

	void stampaVettore(float v[], int n)
	{
		cout << "Stampa vettore di float:" << endl;
		for (int i=0; i<n; i++)
			cout << "\tElemento " << i+1 << ": " << v[i] << endl;
		cout << endl;
	}

//Algoritmi array
	void ordinamentoIngenuo(int v[], bool inverso, int n)
	{
		for (int i=0; i<n-1; i++)
			for (int j=i+1; j<n; j++)
				if (v[i] > v[j] && !inverso)
					scambia(v[i], v[j]);		
				else if (v[i] < v[j] && inverso)
					scambia(v[i], v[j]);
				
	}

	void ordinamentoIngenuo(float v[], bool inverso, int n)
	{
		for (int i=0; i<n-1; i++)
			for (int j=i+1; j<n; j++)
				if (v[i] > v[j] && !inverso)
					scambia(v[i], v[j]);
				else if (v[i] < v[j] && inverso)
					scambia(v[i], v[j]);
	}

	void bubbleSort(int v[], bool inverso, int n)
	{
		bool ordinato = true;
		while (n > 1 && ordinato)
		{
			ordinato = false;

			for (int i = 0; i < n-1; i++)
				if (v[i] > v[i+1] && !inverso)
				{
					scambia(v[i], v[i+1]);
					ordinato = true;
				} 
				else if (v[i] < v[i+1] && inverso)
				{
					scambia(v[i], v[i+1]);
					ordinato = true;
				}
			n--;
		}
	}

	void bubbleSort(float v[], bool inverso, int n)
	{
		bool ordinato = true;
		while (n > 1 && ordinato)
		{
			ordinato = false;

			for (int i = 0; i < n-1; i++)
				if (v[i] > v[i+1] && !inverso)
				{
					scambia(v[i], v[i+1]);
					ordinato = true;
				} 
				else if (v[i] < v[i+1] && inverso)
				{
					scambia(v[i], v[i+1]);
					ordinato = true;
				}
			n--;
		}
	}

//Funzioni su array
	float media(int v[], int n)
	{
		return sommaVettore(v,n)/float(n);
	}

	float media(float v[], int n)
	{
		return sommaVettore(v,n)/float(n);
	}

	int sommaVettore(int v[], int n)
	{
		int somma = 0;
		for (int i = 0; i < n; i++)
			somma += v[i];
		return somma;
	}

	float sommaVettore(float v[], int n)
	{
		float somma = 0;
		for (int i = 0; i < n; i++)
			somma += v[i];
		return somma;
	}

	void inverti(int v[], int n)
	{
		for (int i = 0; i < n/2; i++)
			scambia(v[i],v[n-1-i]);
	}

	void inverti(float v[], int n)
	{
		for (int i = 0; i < n/2; i++)
			scambia(v[i],v[n-1-i]);
	}

	bool ricercaBinaria(int v[], int n, int x)
	{
		int inizio = 0, fine = n-1, meta;
		while (inizio <= fine)
		{
			meta = (inizio + fine) / 2;
			
			if (v[medio] == x)
				return true;
				
			if (v[medio] > x)
				fine = meta - 1;
			else
				inizio = meta + 1;
		}
		
		return false;
	}

	bool ricercaBinaria(float v[], int n, float x)
	{
		int inizio = 0, fine = n-1, meta;
		while (inizio <= fine)
		{
			medio = (inizio + fine) / 2;
			
			if (v[meta] == x)
				return true;
				
			if (v[meta] > x)
				fine = meta - 1;
			else
				inizio = meta + 1;
		}
		
		return false;
	}

	int presente(int v[], int x, int n)
	{
		for (int i=0; i<n; i++)
			if (v[i] == x)
				return i;
		return -1;
	}

	int presente(float v[], float x, int n)
	{
		for (int i=0; i<n; i++)
			if (v[i] == x)
				return i;
		return -1;
	}

	int minore(int v[], int n)
	{
		int min = v[0];
		for (int i = 1; i < n; i++)
			if (min > v[i])
				min = v[i];
		return min;	
	}

	float minore(float v[], int n)
	{
		float min = v[0];
		for (int i = 1; i < n; i++)
			if (min > v[i])
				min = v[i];
		return min;	
	}

	int maggiore(int v[], int n)
	{
		int max = v[0];
		for (int i = 1; i < n; i++)
			if (max < v[i])
				max = v[i];
		return max;
	}

	float maggiore(float v[], int n)
	{
		float max = v[0];
		for (int i = 1; i < n; i++)
			if (max < v[i])
				max = v[i];
		return max;
	}

	int posizioneMinore(int v[], int n)
	{
		int min = v[0]; int p = 0;
		for (int i = 1; i < n; i++)
			if (min > v[i])
			{
				min = v[i];
				p = i;
			}
		return p;	
	}

	int posizioneMinore(float v[], int n)
	{
		float min = v[0]; int p = 0;
		for (int i = 1; i < n; i++)
			if (min > v[i])
			{
				min = v[i];
				p = i;
			}
		return p;	
	}

	int posizioneMaggiore(int v[], int n)
	{
		int max = v[0]; int p = 0;
		for (int i = 1; i < n; i++)
			if (max < v[i])
			{
				max = v[i];
				p = i;
			}
		return p;	
	}

	int posizioneMaggiore(float v[], int n)
	{
		float max = v[0]; int p = 0;
		for (int i = 1; i < n; i++)
			if (max < v[i])
			{
				max = v[i];
				p = i;
			}
		return p;	
	}
