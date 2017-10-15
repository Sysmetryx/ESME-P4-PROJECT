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
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <string.h>

using namespace std;


void menu();

class Token
{
	private :
		char type; //Correspond au type de jeton ( 'x', 'o') ' ')*
		friend class P4;
		friend class P4Boost;
	public :
		Token();
		void setType(char tpe);
		char* getType();
};

class Grid
{
	private :
		vector<Token *> grille; //Gère tous les emplacments de l'aire de jeu, et évite de passer par un tableau dynamique Besoin d'un accesseur pour le passer en private
		int colonnes; //définit le nombre de colonnes, par défaut 7 Besoin d'un accesseur pour le passer en private
		int lignes; //définit le nombre de lignes, par défaut 6 Besoin d'un accesseur pour le passer en private
		friend class P4;
		friend class P4Boost;

	public :
		Grid();
		bool gIsFull(); //Vérifie si l'aire de jeu est pleine
		void setCol(int COL);
		void setLin(int LIN);
		void resize();
		int getElem(int COL);
};

class Player
{
	protected :
	friend class P4;
	friend class P4Boost;
	public :
        Player();
        virtual char choseCOLL() = 0;
};

class PlayerHuman : public Player
{
	protected :
	string playerName;
	friend class P4;
	friend class P4Boost;
	public :
	    PlayerHuman();
		void setName(string name);
		string getName();
		char choseCOLL();
		void testINPUT(string input);
};
class P4
{
	private :

	public :
		P4();
		void display(Grid *aire_de_jeu);//Permet de rafraichir l'affichage
		void play(PlayerHuman p, Grid *aire_de_jeu, Token * tkn, int  *COL);
		bool victoireVerticale(int elem, Grid aire_de_jeu);
		int HorizontaleD(int elem, Grid aire_de_jeu);
		int HorizontaleG(int elem, Grid aire_de_jeu);
		int DiagMD(int elem, Grid aire_de_jeu);
		int DiagDG(int elem, Grid aire_de_jeu);
		int DiagMG(int elem, Grid aire_de_jeu);
		int DiagDD(int elem, Grid aire_de_jeu);

};

class P4Boost : public P4
{
	private :
	public :
	P4Boost();
    void save(Grid * aire_de_jeu);


};

class WIN
{
private:
	bool isWon = false;
	string pWinner = "Personne";
public:
	void setAll(bool tpe, string spe);
	bool getisWon();
	string getpWinner();
};





