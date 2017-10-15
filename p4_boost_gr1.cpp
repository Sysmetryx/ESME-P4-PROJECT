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

#include "p4.cpp"

int main()
{
string tmp1;
	int tmp = 0;
	int COL = 0;
	char input;
	WIN testWin;
	P4Boost JEUX;
	Grid AIRE;
	PlayerHuman player1;
	Token tokenp1;
	tokenp1.setType('x');
	PlayerHuman player2;
	Token tokenp2;
	tokenp2.setType('o');
	int comm = 0;
	cout << "Bienvenue dans le jeu puissance 4" << endl;
	cout << "Selectionnez une option : " << endl;
	cout << "1: Commencer une nouvelle partie." << endl << "2: Quitter." <<endl;
	cin >> comm;
	switch(comm)
	{
		case 1:
		cout << "Entrez un nom pour le 1er joueur :" << endl;
		cin >> tmp1;
		player1.setName(tmp1);
		cout << "Entrez un nom pour le 2eme joueur :" << endl;
		cin >> tmp1;
		player2.setName(tmp1);
		cout << "Entrez un nombre de colonnes :" << endl;
		cin >> tmp;
		AIRE.setCol(tmp);
		cout << "Entrez un nombre de lignes :" << endl;
		cin >> tmp;
		AIRE.setLin(tmp);
		AIRE.resize();
		JEUX.display(&AIRE);
		while(true)
		{
			input = player1.choseCOLL();
			if(input == 'S' || input == 's')
			{
				JEUX.save(&AIRE);
			}
			else
			{
				COL = (int)input - '0';
			}
			JEUX.play(player1, &AIRE, &tokenp1, &COL);
			if(JEUX.victoireVerticale(COL, AIRE) || (JEUX.HorizontaleD(COL, AIRE) + JEUX.HorizontaleG(COL, AIRE) == 3) || (JEUX.DiagMD(COL, AIRE) + JEUX.DiagDG(COL, AIRE)) == 3 || (JEUX.DiagMG(COL, AIRE) + JEUX.DiagDD(COL, AIRE)) == 3)
			{
				testWin.setAll(true, player1.getName());
				break;
			}
			else if(AIRE.gIsFull())
			{
				break;
			}
			input = player2.choseCOLL();
			if(input == 'S' || input == 's')
			{
				JEUX.save(&AIRE);
			}
			else
			{
				COL = (int)input - '0';
			}
			JEUX.play(player2, &AIRE, &tokenp2, &COL);
			if(JEUX.victoireVerticale(COL, AIRE) || (JEUX.HorizontaleD(COL, AIRE) + JEUX.HorizontaleG(COL, AIRE) == 3) || (JEUX.DiagMD(COL, AIRE) + JEUX.DiagDG(COL, AIRE)) == 3 || (JEUX.DiagMG(COL, AIRE) + JEUX.DiagDD(COL, AIRE)) == 3)
			{
				testWin.setAll(true, player2.getName());
				break;
			}
			else if(AIRE.gIsFull())
			{
				break;
			}
		}
		if(testWin.getisWon())
		{
			cout <<"partie terminee, " <<  testWin.getpWinner() << " a gagne ! " << endl;
		}
		else
		{
			cout <<"match nul !! : " << testWin.getpWinner() << " n a gagne !" << endl;
		}

        break;
		case 2:
			cout << "Merci, au revoir";
			break;
		default :
			return 0;
	}
    return 0;
}
