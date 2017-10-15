/*
_____________________________________________________________________________________________________________________________________
|																																	|
|													Puissance 4 C++ Groupe 1  INFO3													|
|																																	|
|															Herbin Armelle															|
|															Laporte Nathan															|
|															Lefaure Antoine 														|
|															Loussaut Morgan															|
|																																	|
|																																	|
|																												ESME-Sudria 2017	|
|				 																								Ver 2.1A			|
-------------------------------------------------------------------------------------------------------------------------------------
*/

#include "p4.hpp"


P4::P4()
{
}
P4Boost::P4Boost()
{
}
Token::Token()
{
}
Grid::Grid()
{
}
Player::Player()
{
}
PlayerHuman::PlayerHuman()
{
}


void Token::setType(char tpe)
{
	this->type = tpe;
}

char* Token::getType()
{
	return &(this->type);
}

void Grid::setCol(int COL)
{
	colonnes = COL;
}

void Grid::setLin(int LIN)
{
	lignes = LIN;
}

void Grid::resize()
{
	for(int i = 0; i < lignes * colonnes; i++)
	{
		grille.push_back (nullptr);
	}
}

bool Grid::gIsFull()
{
	int tmp = 0;
	for(int i = 0; i < grille.size(); i++)
	{
		if(!grille[i])
		{
			tmp++;
		}
	}
	if(tmp == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Grid::getElem(int COL)
{
    int colTemp = 0;
    	for (int i = lignes; i > 0 ; i--)
    	{
        	colTemp = (colonnes * i) - (colonnes - COL );
        	if (grille[colTemp] == nullptr)
        	{
            	break;
        	}

    	}
    	return colTemp;
}

void P4::display(Grid *aire_de_jeu)
{
	system("cls");
    for (int i = 1; i <= aire_de_jeu->lignes * aire_de_jeu->colonnes; ++i)
    {
        char *type = aire_de_jeu->grille[i - 1]->getType();
        if (type != nullptr)
        {
            cout << " " << *type << " ";
        }
        else
        {
            cout << " . ";
        }
        if (i % aire_de_jeu->colonnes == 0)
        {
            cout << endl;
        }
    }
	for(int k = 0; k < 3 * aire_de_jeu->colonnes; k++)
	{
		cout << "-";
	}
	cout << endl;
	for(int l = 0; l < aire_de_jeu->colonnes; l++)
	{
		cout << l << ": ";
	}
	cout << endl;
}

void P4::play(PlayerHuman p, Grid *aire_de_jeu, Token * tkn, int * COL)
{
	*COL = aire_de_jeu->getElem(*COL);
	if(aire_de_jeu->grille[*COL] == nullptr)
	{
        aire_de_jeu->grille[*COL] = tkn;
	}
	else
	{
		cout << "colonne pleine" << endl;
	}
	display(aire_de_jeu);

}

bool P4::victoireVerticale(int elem, Grid aire_de_jeu)
{
	int count = 1;
	for(elem; 0 <= elem < aire_de_jeu.grille.size();	elem += aire_de_jeu.colonnes )
	{
		if(elem + aire_de_jeu.colonnes >= aire_de_jeu.grille.size())
		{
			return false;
		}
		else
		{
			if(aire_de_jeu.grille[elem] == aire_de_jeu.grille[elem + aire_de_jeu.colonnes])
			{
				count++;
				if(count == 4)
				{
					return true;
				}
			}
			else
			{
				return false;
			}
		}
	}
	return false;
}

 int P4::HorizontaleD(int elem, Grid aire_de_jeu)
 {
 	int count = 0;
 	for(elem; 0 <= elem < aire_de_jeu.grille.size(); elem++)
 	{
 		if((elem)%aire_de_jeu.colonnes == aire_de_jeu.colonnes - 1 )
 		{
 			return count;
 		}
 		else
 		{
 			if(aire_de_jeu.grille[elem] == aire_de_jeu.grille[elem + 1])
			{
				count++;
				cout << count << endl;
			}
			else
			{
				return count;
			}

 		}

 	}
 	return count;
 }

 int P4::HorizontaleG(int elem, Grid aire_de_jeu)
 {
    int count = 0;
 	for(elem; 0 <= elem < aire_de_jeu.grille.size(); elem--)
 	{
 		if((elem) % aire_de_jeu.colonnes == 0)
 		{
 			return count;
 		}
 		else
 		{
 			if(aire_de_jeu.grille[elem] == aire_de_jeu.grille[elem - 1])
			{
				count++;
			}
			else
			{
				return count;
			}
 		}
 	}
 	return count;
 }

 int P4::DiagMD(int elem, Grid aire_de_jeu)
 {
 	int count = 0;
 	for(elem; 0 <= elem < aire_de_jeu.grille.size(); elem = elem - aire_de_jeu.colonnes + 1)
 	{
 		if(elem % aire_de_jeu.colonnes == aire_de_jeu.colonnes -1 || (elem - aire_de_jeu.colonnes + 1) <= 0)
 		{
 			return count;
 		}
 		else
 		{
 			if(aire_de_jeu.grille[elem] == aire_de_jeu.grille[elem - aire_de_jeu.colonnes + 1])
 			{
 				count ++;
 			}
 			else
 			{
 				return count;
 			}
 		}
 	}
 	return count;
 }

int P4::DiagDG(int elem, Grid aire_de_jeu)
{
	int count = 0;
 	for(elem; 0 <= elem < aire_de_jeu.grille.size(); elem = elem + aire_de_jeu.colonnes - 1)
 	{
 		if(elem % aire_de_jeu.colonnes == 0 || (elem + aire_de_jeu.colonnes -1) > aire_de_jeu.grille.size())
 		{
 			return count;
 		}
 		else
 		{
 			if(aire_de_jeu.grille[elem] == aire_de_jeu.grille[elem + aire_de_jeu.colonnes - 1])
 			{
 				count ++;
 			}
 			else
 			{
 				return count;
 			}
 		}
 	}
 	return count;
}

int P4::DiagMG(int elem, Grid aire_de_jeu)
{
	int count = 0;
	for(elem; 0 <= elem < aire_de_jeu.grille.size(); elem = elem - aire_de_jeu.colonnes - 1 )
	{
		if(elem % aire_de_jeu.colonnes == 0 || (elem - aire_de_jeu.colonnes - 1) < 0)
 		{
 			return count;
 		}
 		else
 		{
 			if(aire_de_jeu.grille[elem] == aire_de_jeu.grille[elem - aire_de_jeu.colonnes - 1])
 			{
 				count ++;
 			}
 			else
 			{
 				return count;
 			}
 		}
	}
	return 0;
}

int P4::DiagDD(int elem, Grid aire_de_jeu)
{
	int count = 0;
	for(elem; 0 <= elem < aire_de_jeu.grille.size(); elem = elem + aire_de_jeu.colonnes + 1 )
	{
		if(elem % aire_de_jeu.colonnes == aire_de_jeu.colonnes - 1 || (elem + aire_de_jeu.colonnes + 1) >= aire_de_jeu.grille.size())
 		{
 			return count;
 		}
 		else
 		{
 			if(aire_de_jeu.grille[elem] == aire_de_jeu.grille[elem + aire_de_jeu.colonnes + 1])
 			{
 				count ++;
 			}
 			else
 			{
 				return count;
 			}
 		}
	}
	return 0;
}

void PlayerHuman::setName(string name)
{
    playerName= name;
}

char PlayerHuman::choseCOLL()
{
	char colPlay;
	cout << "entrez une colonne a jouer pour : " << playerName << endl;
	cin >> colPlay;
	return colPlay;
}

void P4Boost::save(Grid * aire_de_jeu)
{
	string fileNameOut = "save.txt";
	cout << "Veuillez entrer un nom de fichier pour la sauvegarde (exemple save.txt )" << endl;
	cin >> fileNameOut;
    ofstream monFlux(fileNameOut);
    if(monFlux)
    {
    	monFlux << aire_de_jeu->colonnes;
    	monFlux << " ";
    	monFlux << aire_de_jeu->lignes;
    	monFlux << " ";
    	for(int i = 0; i < aire_de_jeu->grille.size(); i += aire_de_jeu->colonnes)
    	{
    		for(int j = aire_de_jeu->colonnes; j > 0; j--)
    		{
    			int temp = aire_de_jeu->grille.size() - (i + j);
    			if(aire_de_jeu->grille[temp])
    			{
    				monFlux << aire_de_jeu->grille[temp]->type;
    			}
    			else
    			{
    				monFlux << " ";
    			}
    		}
    	}

    }
    monFlux.close();
}

void WIN::setAll(bool btpe, string stpe)
{
	isWon = btpe;
	pWinner = stpe;
}

string WIN::getpWinner()
{
	return pWinner;
}

bool WIN::getisWon()
{
	return isWon;
}

string PlayerHuman::getName()
{
	return playerName;
}



