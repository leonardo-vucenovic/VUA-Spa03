#include"game_of_life.h"
#include<iostream>

bool game_of_life::slucajna_vrijednost(int min,int max)
{
	int n = rand() % (max - min + 1) + min;
	if (n <= 25)
	{
		return true;
	}
	return false;
}
bool game_of_life::celija_zauzeta(int i, int j)
{
	if (this->_generacija[i][j] == true)
	{
		return true;
	}
	return false;
}
int game_of_life::broj_susjeda(int i, int j)
{
	int s = 0;
	for (int a = -1; a < 2; a++)
	{
		for (int b = -1; b < 2; b++)
		{
			int l = ((i + a + STUPACA) % STUPACA);
			int v = ((j + b + REDAKA) % REDAKA);
			if (this->_generacija[l][v] == 1)
			{
				s++;
			}
		}
	}
	return(s - 1);
}

void game_of_life::lv()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (slucajna_vrijednost(1,100))
			{
				this->_generacija[i][j] = 1;
			}
			else
			{
				this->_generacija[i][j] = 0;
			}
		}
	}
}
game_of_life::game_of_life()
{
	lv();
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < STUPACA; i++)
	{
		for (int j = 0; j < REDAKA; j++)
		{
			if (celija_zauzeta(i,j))
			{
				if (broj_susjeda(i,j)==2||broj_susjeda(i,j)==3)
				{
					this->_sljedeca_generacija[i][j] == 1;
				}
				else
				{
					this->_sljedeca_generacija[i][j] == 0;
				}
			}
			else if (celija_zauzeta(i,j)==false)
			{
				if (broj_susjeda(i,j) !=3)
				{
					this->_sljedeca_generacija[i][j] = 0;
				}
				else if (broj_susjeda(i,j)==3)
				{
					this->_sljedeca_generacija[i][j] = 1;
				}
			}
		}
	}
}

void game_of_life::iscrtaj()
{
	sljedeca_generacija();
	for (int i = 0; i < REDAKA; i++)
	{
		cout << endl;
		for (int j = 0; j < STUPACA; j++)
		{
			if (this->_generacija[i][j])
			{
				cout << "*";
			}
			else
			{
				cout << "-";
			}
			this->_generacija[i][j] == this->_sljedeca_generacija[i][j];
		}
	}
}
