// main.cpp: Okupació
//Entrada: Numero de jugadors, fitxer amb dades del tauler i tirades
//Sortida: Tauler de joc en cada iteracio i resultat de la partida al final

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

const int MAX_FC = 25; // Numero màxim de files i columnes.
const int MAX_JUGADORS = 10; //Numero màxim de jugadors
const int AMPLADA = 13; //Amplada per defecte al escriure els llistats


struct Player {
	char nom;
	int caselles, arrabassades, senseTirar;
	bool estaJugant;
};

typedef Player vectorJugadors[MAX_JUGADORS];
typedef char matriuTauler[MAX_FC + 3][MAX_FC + 3];

void demanarJugadors(int & numeroJugadors) {
	//Pre: variable buida numeroJugadors
	//Post: numeroJugadors amb la entrada del usuari
	cout << "ENTRA NOMBRE DE JUGADORS(2..10) :" << endl;
	cin >> numeroJugadors;
	bool jugCorrectes = numeroJugadors >= 2 && numeroJugadors <= 10;
	while (!jugCorrectes) {
		cout << "ENTRA NOMBRE DE JUGADORS(2..10) :" << endl;
		cin >> numeroJugadors;
		jugCorrectes = numeroJugadors >= 2 && numeroJugadors <= 10;
	}
}

void demanarFitxer(ifstream & dadesTauler) {
	//Pre: variable de fitxer
	//Post: fitxer obert, o surt del programa si no es pot obrir
	cout << "NOM DEL FITXER DEL TAULER:" << endl;
	string nomFitxer;
	cin >> nomFitxer;
	dadesTauler.open(nomFitxer.c_str());
	if (!dadesTauler.is_open()) {
		cout << "NO ES POT OBRIR EL FITXER" << endl;
		exit(1);
	}

}

void ordenarJugadors(vectorJugadors jugadors, int numeroJugadors, char parametre) {
	//Pre: vector de jugadors, numero de jugadors i parametre
	//Post: Ordena per nom si parametre es A i sino per ordre de classificacio
	Player k;
	if (parametre == 'A') {
		for (int i = 0; i < numeroJugadors; i++) {
			for (int j = (numeroJugadors - 1); j > i; j--) {
				if (jugadors[j].nom < jugadors[j - 1].nom) {
					k = jugadors[j];
					jugadors[j] = jugadors[j - 1];
					jugadors[j - 1] = k;
				}
			}
		}
	}
	else {
		for (int i = 0; i < numeroJugadors; i++) {
			for (int j = (numeroJugadors - 1); j > i; j--) {
				if (jugadors[j].caselles > jugadors[j - 1].caselles) {
					k = jugadors[j];
					jugadors[j] = jugadors[j - 1];
					jugadors[j - 1] = k;
				}
				else if (jugadors[j].caselles == jugadors[j - 1].caselles) {
					if (jugadors[j].arrabassades > jugadors[j - 1].arrabassades) {
						k = jugadors[j];
						jugadors[j] = jugadors[j - 1];
						jugadors[j - 1] = k;
					}
					else if (jugadors[j].arrabassades == jugadors[j - 1].arrabassades) {
						if (jugadors[j].senseTirar > jugadors[j - 1].senseTirar) {
							k = jugadors[j];
							jugadors[j] = jugadors[j - 1];
							jugadors[j - 1] = k;
						}
					}
				}
			}
		}
	}

}

void inicialitzarTauler(matriuTauler tauler, int files, int columnes) {
	//Pre: Tauler, files i columnes que ha de tenir (mes petites que 28)
	//Post: Tauler inicialitzat, amb els murs exteriors i els noms de files i columnes
	tauler[0][0] = ' ';
	tauler[1][0] = ' ';
	tauler[0][1] = ' ';
	tauler[files - 1][0] = ' ';
	tauler[0][columnes - 1] = ' ';
	tauler[1][1] = '#';
	tauler[1][columnes - 1] = '#';
	tauler[files - 1][1] = '#';
	tauler[files - 1][columnes - 1] = '#';
	for (int i = 2;i < files - 1;i++) {
		tauler[i][0] = ('a') + (i - 2);
		tauler[i][1] = '#';
		tauler[i][columnes - 1] = '#';
	}
	for (int i = 2;i < columnes - 1;i++) {
		tauler[0][i] = ('a') + (i - 2);
		tauler[1][i] = '#';
		tauler[files - 1][i] = '#';
	}
}

void ferTauler(ifstream & dadesTauler, matriuTauler tauler, int files, int columnes) {
	//Pre: fitxer amb les dades del tauler, la matriu del tauler, les files i les columnes (mes petites que 28)
	//Post: Tauler inicialitzat amb tots els murs i caselles.
	inicialitzarTauler(tauler, files, columnes);
	int moviment, posicio = 2, recorregut = 0, filaActual = 2;
	dadesTauler >> moviment;
	bool esMur = false;
	while (!dadesTauler.eof()) {
		while (recorregut != moviment) {
			if (posicio == (columnes - 1)) {
				posicio = 2;
				filaActual++;
			}
			if (!esMur) {
				tauler[filaActual][posicio] = ' ';
			}
			else tauler[filaActual][posicio] = '#';
			posicio++;
			recorregut++;
		}
		recorregut = 0;
		dadesTauler >> moviment;
		esMur = !esMur;
	}
}

void mostrarTauler(matriuTauler tauler, int files, int columnes) {
	//Pre: Tauler, files i columnes que ha de tenir (mes petites que 28)
	//Post: Tauler escrit per pantalla
	for (int i = 0;i < files;i++) {
		for (int j = 0;j < columnes;j++) {
			cout << tauler[i][j];
		}
		cout << endl;
	}
}



void inicialitzarSenseTirar(vectorJugadors jugadors, int numeroJugadors) {
	//Pre: vector amb els jugadors, numero de jugadors (<10) i el torn (<numeroJugadors)
	//Post: jugadors amb els torns sense tirar inicialitzats
	jugadors[0].senseTirar = 0;
	for (int i = 1; i < numeroJugadors;i++) {
		jugadors[i].senseTirar = (numeroJugadors - i);
	}
}

void inicialitzarJugadors(vectorJugadors jugadors, int numeroJugadors) {
	//Pre: vector jugadors i numero de jugadors (<10)
	//Post: llista de jugadors inicialitzada
	for (int i = 0; i < numeroJugadors; i++) {
		jugadors[i].nom = 'A' + i;
		jugadors[i].caselles = 0;
		jugadors[i].arrabassades = 0;
		jugadors[i].estaJugant = true;
		inicialitzarSenseTirar(jugadors, numeroJugadors);
	}
}

void correccioSenseTirar(vectorJugadors jugadors, int numeroJugadors, int torn) {
	//Pre: -
	//Post: corregeix les vegades sense tirar de cada jugador
	for (int i = 0; i < numeroJugadors; i++) {
		jugadors[i].senseTirar++;
	}
	jugadors[torn].senseTirar = 0;
}

void mostrarLlistat(vectorJugadors jugadors, int numeroJugadors, int torn) {
	//Pre: vector amb els jugadors, numero de jugadors (<10) i el torn (<numeroJugadors)
	//Post: es mostra els jugadors per pantalla ordenats per classificacio
	ordenarJugadors(jugadors, numeroJugadors, 'B');
	cout << setw(AMPLADA) << right << "JUGADOR" << setw(AMPLADA) << right << "CASELLES" << setw(AMPLADA) << right << "ARRABASSADES" << setw(AMPLADA) << right << "SENSE TIRAR" << endl;
	for (int i = 0; i<numeroJugadors;i++) {
		if (jugadors[i].estaJugant) {
			cout << setw(AMPLADA) << right << jugadors[i].nom << setw(AMPLADA) << right << jugadors[i].caselles << setw(AMPLADA) << right << jugadors[i].arrabassades << setw(AMPLADA) << right << jugadors[i].senseTirar << endl;
		}
	}
	ordenarJugadors(jugadors, numeroJugadors, 'A');
}

int contarCasellesBuides(matriuTauler tauler, int files, int columnes) {
	//Pre: tauler, files i columnes (les dos <28)
	//Post: nombre de caselles buides
	int nombreCaselles = 0;
	for (int i = 2; i < (files - 1); i++) {
		for (int j = 2; j < (columnes - 1); j++) {
			if (tauler[i][j] == ' ') nombreCaselles++;
		}
	}
	return nombreCaselles;
}

int contarCasellesOcupades(vectorJugadors jugadors, int numeroJugadors) {
	//Pre: tauler, files i columnes (les dos <28)
	//Post: Nombre caselles ocupades
	int nombreCaselles = 0;
	for (int i = 0; i < numeroJugadors; i++) {
		nombreCaselles += jugadors[i].caselles;
	}
	return nombreCaselles;
}

bool esBona(char tirada[2], matriuTauler tauler, int pFila, int pColumna, int files, int columnes) {
	// Pre: taula amb la tirada, matriu del tauler, posicio en la fila (<files), posicio columnes (<columnes), files i columnes (<28)
	// Post: Si la tirada es valida o no
	bool a;
	if (tauler[pFila][pColumna] != ' ') a = false;
	else a = ((pFila>=2 && pFila <=files-1)||(pColumna>=2 && pColumna<=columnes-1));
	if (tirada[0] == '0' && tirada[1] == '0') a = true;
	return a;
}

void demanarTirada(matriuTauler tauler, vectorJugadors jugadors, char tirada[2], int & pFila, int & pColumna, int files, int columnes, int torn) {
	//Pre: files<29 i columnes<29 i tirada de tamany 2
	//Post: Demana tirada i guarda la informacio a tirada, pFila i pColumna
	bool tiradaBona = false;
	cout << endl << "JUGADOR " << jugadors[torn].nom << endl;
	cin >> tirada[0] >> tirada[1];
	pFila = int(tirada[0] - 'a') + 2;
	pColumna = int(tirada[1] - 'a') + 2;
	tiradaBona = esBona(tirada, tauler, pFila, pColumna, files, columnes);
	while (!tiradaBona) {
		cout << "JUGADOR " << jugadors[torn].nom << endl;
		cin >> tirada[0] >> tirada[1];
		pFila = int(tirada[0] - 'a') + 2;
		pColumna = int(tirada[1] - 'a') + 2;
		tiradaBona = esBona(tirada, tauler, pFila, pColumna, files, columnes);
	}
}

bool quedaUn(vectorJugadors jugadors, int numeroJugadors) {
	//pre: numeroJugadors<=10
	//Post: retorna true si nomes queda un jugador i false si en queden més.
	int jugant = 0;
	for (int i = 0; i < numeroJugadors;i++) {
		if (jugadors[i].estaJugant) jugant++;
	}
	return (jugant == 1);
}

void arrabasar(matriuTauler tauler, vectorJugadors jugadors, int fila, int columna, int torn) {
	//Pre: files i columnes mes petites que 28 i torn mes petit que 10, en la posicio ha de estar ocupada
	//post: el jugador que esta jugant ocupa la posicio i se li resta al que hi havia
	char ocupa;
	ocupa = tauler[fila][columna];
	tauler[fila][columna] = jugadors[torn].nom;
	jugadors[ocupa - 'A'].caselles--;
	jugadors[torn].caselles++;
	jugadors[torn].arrabassades++;
}

void colocarATauler(matriuTauler tauler, vectorJugadors jugadors, int fila, int columna, int torn) {
	//Pre: files i columnes mes petites que 28 i torn mes petit que 10, en la posicio  no pot estar ocupada
	//post: el jugador que esta jugant ocupa la posicio
	tauler[fila][columna] = jugadors[torn].nom;
	jugadors[torn].caselles++;
}

int contarAdjacents(matriuTauler tauler, int pFila, int pColumna) {
	//Pre: pFila i pColumna <28 les 2
	//Post: numero de adjacents que no son mur en la posicio
	bool adj_adalt = tauler[pFila - 1][pColumna] != '#';
	bool adj_avall = tauler[pFila + 1][pColumna] != '#';
	bool adj_dreta = tauler[pFila][pColumna + 1] != '#';
	bool adj_esquerra = tauler[pFila][pColumna - 1] != '#';
	return (adj_adalt + adj_avall + adj_dreta + adj_esquerra);

}

void adjacentsTipus1(matriuTauler tauler, vectorJugadors jugadors, int pFila, int pColumna, int torn) {
	//Pre:  pFila i pColumna <28 les 2 i la posicio te que tenir nomes una casella adjacent
	//Post: Aplica les normes de les adjacents en el cas de tenir una adjacent
	if (tauler[pFila][pColumna] != '#') {
		if (tauler[pFila][pColumna] != ' ' && tauler[pFila][pColumna] != jugadors[torn].nom) arrabasar(tauler, jugadors, pFila, pColumna, torn);
		else if (tauler[pFila][pColumna] != jugadors[torn].nom) colocarATauler(tauler, jugadors, pFila, pColumna, torn);
	}

}

void adjacentsTipus2(matriuTauler tauler, vectorJugadors jugadors, int pFila, int pColumna, int filaTir, int columnaTir, int torn) {
	//Pre: filaTir, columnaTir, pFila i pColumna <28 les 4, torn menor que 10 , i la posicio te que tenir nomes dues caselles adjacents
	//Post:  Aplica les normes de les adjacents en el cas de tenir dues adjacents
	if (tauler[pFila][pColumna] != '#') {
		if (tauler[pFila + 1][pColumna] == jugadors[torn].nom && pFila + 1 != filaTir) {
			if (tauler[pFila][pColumna] != ' ' && tauler[pFila][pColumna] != jugadors[torn].nom) arrabasar(tauler, jugadors, pFila, pColumna, torn);
			else if (tauler[pFila][pColumna] != jugadors[torn].nom) colocarATauler(tauler, jugadors, pFila, pColumna, torn);
		}
		else if (tauler[pFila - 1][pColumna] == jugadors[torn].nom && pFila - 1 != filaTir) {
			if (tauler[pFila][pColumna] != ' ' && tauler[pFila][pColumna] != jugadors[torn].nom) arrabasar(tauler, jugadors, pFila, pColumna, torn);
			else if (tauler[pFila][pColumna] != jugadors[torn].nom) colocarATauler(tauler, jugadors, pFila, pColumna, torn);
		}
		else if (tauler[pFila][pColumna + 1] == jugadors[torn].nom && pColumna + 1 != columnaTir) {
			if (tauler[pFila][pColumna] != ' ' && tauler[pFila][pColumna] != jugadors[torn].nom) arrabasar(tauler, jugadors, pFila, pColumna, torn);
			else if (tauler[pFila][pColumna] != jugadors[torn].nom) colocarATauler(tauler, jugadors, pFila, pColumna, torn);
		}
		else if (tauler[pFila][pColumna - 1] == jugadors[torn].nom && pColumna - 1 != columnaTir) {
			if (tauler[pFila][pColumna] != ' ' && tauler[pFila][pColumna] != jugadors[torn].nom) arrabasar(tauler, jugadors, pFila, pColumna, torn);
			else if (tauler[pFila][pColumna] != jugadors[torn].nom) colocarATauler(tauler, jugadors, pFila, pColumna, torn);
		}
	}
}

void adjacentsTipus3(matriuTauler tauler, vectorJugadors jugadors, int pFila, int pColumna, int torn) {
	//Pre:  pFila i pColumna <28 les 2 i la posicio ha de tenir tres casella adjacent
	//Post: Aplica les normes de les adjacents en el cas de tenir tres caselles adjacents
	if (tauler[pFila][pColumna] != '#') {
		bool adj_adalt = tauler[pFila - 1][pColumna] == jugadors[torn].nom;
		bool adj_avall = tauler[pFila + 1][pColumna] == jugadors[torn].nom;
		bool adj_dreta = tauler[pFila][pColumna + 1] == jugadors[torn].nom;
		bool adj_esquerra = tauler[pFila][pColumna - 1] == jugadors[torn].nom;
		int quantitat_iguals = (adj_adalt + adj_avall + adj_dreta + adj_esquerra);
		if (quantitat_iguals == 3) {
			if (tauler[pFila][pColumna] != ' ' && tauler[pFila][pColumna] != jugadors[torn].nom) arrabasar(tauler, jugadors, pFila, pColumna, torn);
			else colocarATauler(tauler, jugadors, pFila, pColumna, torn);
		}
		else if (quantitat_iguals == 2) {
			if (tauler[pFila][pColumna] == ' ') colocarATauler(tauler, jugadors, pFila, pColumna, torn);
		}
	}
}

void adjacentsTipus4(matriuTauler tauler, vectorJugadors jugadors, int pFila, int pColumna, int torn) {
	//Pre:  pFila i pColumna <28 les 2 i la posicio ha de tenir 4 casella adjacents
	//Post: Aplica les normes de les adjacents en el cas de tenir 4 caselles adjacents
	if (tauler[pFila][pColumna] != '#') {
		bool adj_adalt = tauler[pFila - 1][pColumna] == jugadors[torn].nom;
		bool adj_avall = tauler[pFila + 1][pColumna] == jugadors[torn].nom;
		bool adj_dreta = tauler[pFila][pColumna + 1] == jugadors[torn].nom;
		bool adj_esquerra = tauler[pFila][pColumna - 1] == jugadors[torn].nom;
		int quantitat_iguals = (adj_adalt + adj_avall + adj_dreta + adj_esquerra);
		if (quantitat_iguals == 4) {
			if (tauler[pFila][pColumna] != ' ' && tauler[pFila][pColumna] != jugadors[torn].nom) arrabasar(tauler, jugadors, pFila, pColumna, torn);
			else if(tauler[pFila][pColumna] != jugadors[torn].nom) colocarATauler(tauler, jugadors, pFila, pColumna, torn);
		}
		else if (quantitat_iguals == 3) {
			if (tauler[pFila][pColumna] == ' ') colocarATauler(tauler, jugadors, pFila, pColumna, torn);
			else if (!adj_adalt && tauler[pFila - 1][pColumna] != tauler[pFila][pColumna] && tauler[pFila][pColumna] != jugadors[torn].nom) arrabasar(tauler, jugadors, pFila, pColumna, torn);
			else if (!adj_avall && tauler[pFila + 1][pColumna] != tauler[pFila][pColumna] && tauler[pFila][pColumna] != jugadors[torn].nom) arrabasar(tauler, jugadors, pFila, pColumna, torn);
			else if (!adj_dreta && tauler[pFila][pColumna + 1] != tauler[pFila][pColumna] && tauler[pFila][pColumna] != jugadors[torn].nom) arrabasar(tauler, jugadors, pFila, pColumna, torn);
			else if (!adj_esquerra && tauler[pFila][pColumna - 1] != tauler[pFila][pColumna] && tauler[pFila][pColumna] != jugadors[torn].nom) arrabasar(tauler, jugadors, pFila, pColumna, torn);
		}
	}
}

void aplicarNormesAdjacents(matriuTauler tauler, vectorJugadors jugadors, int pFila, int pColumna, int torn) {
	//Pre: -
	//Post: Normes adjacents aplicades
	if (contarAdjacents(tauler, pFila, pColumna + 1) == 1) adjacentsTipus1(tauler, jugadors, pFila, pColumna + 1, torn);
	else if (contarAdjacents(tauler, pFila, pColumna + 1) == 2) adjacentsTipus2(tauler, jugadors, pFila, pColumna + 1, pFila, pColumna, torn);
	else if (contarAdjacents(tauler, pFila, pColumna + 1) == 3) adjacentsTipus3(tauler, jugadors, pFila, pColumna + 1, torn);
	else if (contarAdjacents(tauler, pFila, pColumna + 1) == 4) adjacentsTipus4(tauler, jugadors, pFila, pColumna + 1, torn);

	if (contarAdjacents(tauler, pFila, pColumna - 1) == 1) adjacentsTipus1(tauler, jugadors, pFila, pColumna - 1, torn);
	else if (contarAdjacents(tauler, pFila, pColumna - 1) == 2) adjacentsTipus2(tauler, jugadors, pFila, pColumna - 1, pFila, pColumna, torn);
	else if (contarAdjacents(tauler, pFila, pColumna - 1) == 3) adjacentsTipus3(tauler, jugadors, pFila, pColumna - 1, torn);
	else if (contarAdjacents(tauler, pFila, pColumna - 1) == 4) adjacentsTipus4(tauler, jugadors, pFila, pColumna - 1, torn);

	if (contarAdjacents(tauler, pFila + 1, pColumna) == 1)	adjacentsTipus1(tauler, jugadors, pFila + 1, pColumna, torn);
	else if (contarAdjacents(tauler, pFila + 1, pColumna) == 2) adjacentsTipus2(tauler, jugadors, pFila + 1, pColumna, pFila, pColumna, torn);
	else if (contarAdjacents(tauler, pFila + 1, pColumna) == 3) adjacentsTipus3(tauler, jugadors, pFila + 1, pColumna, torn);
	else if (contarAdjacents(tauler, pFila + 1, pColumna) == 4) adjacentsTipus4(tauler, jugadors, pFila + 1, pColumna, torn);

	if (contarAdjacents(tauler, pFila - 1, pColumna) == 1) adjacentsTipus1(tauler, jugadors, pFila - 1, pColumna, torn);
	else if (contarAdjacents(tauler, pFila - 1, pColumna) == 2) adjacentsTipus2(tauler, jugadors, pFila - 1, pColumna, pFila, pColumna, torn);
	else if (contarAdjacents(tauler, pFila - 1, pColumna) == 3) adjacentsTipus3(tauler, jugadors, pFila - 1, pColumna, torn);
	else if (contarAdjacents(tauler, pFila - 1, pColumna) == 4) adjacentsTipus4(tauler, jugadors, pFila - 1, pColumna, torn);
}

void aplicarRendicio(matriuTauler tauler, vectorJugadors jugadors, int torn, int files, int columnes, int numeroJugadors) {
	//Pre: Jugadors[torn] sha rendit
	//Post: s'aplica la rendicio, es mostra el tauler i el llsitat.
	jugadors[torn].estaJugant = false;
	for (int i = 2; i < files - 1; i++) {
		for (int j = 2; j < columnes - 1; j++) {
			if (tauler[i][j] == jugadors[torn].nom) tauler[i][j] = ' ';
		}
	}
	jugadors[torn].caselles = 0;
	cout << endl;
	mostrarTauler(tauler, files, columnes);
	cout << endl;
	mostrarLlistat(jugadors, numeroJugadors, torn);
}

void controlFiles(matriuTauler tauler, int files, int columnes, bool & filaControlada, char & controlador, char&controlat) {
	//Pre: -
	//Post: Es mira si un jugador ha controlat alguna fila
	int controlats = 0, k = 2, totals = 0;
	while (k != files && !filaControlada) {
		for (int j = 2; j < columnes - 1; j++) {
			if (tauler[k][j] != '#' && tauler[k][j + 1] != '#') {
				if (tauler[k][j] == tauler[k][j + 1]) {
					controlador = tauler[k][j];
					controlats++;
				}
				else controlats = 0;
				totals++;
			}
		}

		k++;
		filaControlada = controlats == totals;
	}
	controlat = ((k - 3) + 'a');
}

void controlColumnes(matriuTauler tauler, int files, int columnes, bool & columnaControlada, char & controlador, char&controlat) {
	//Pre: -
	//Post: Es mira si un jugador ha controlat alguna columna
	int controlats = 0, k = 2, totals = 0;
	while (k != columnes && !columnaControlada) {
		for (int j = 2; j < columnes; j++) {
			if (tauler[j][k] != '#' && tauler[j - 1][k] != '#') {
				if (tauler[j][k] == tauler[j - 1][k]) {
					controlador = tauler[j][k];
					controlats++;
				}
				else controlats = 0;
				totals++;
			}
		}

		k++;
		columnaControlada = (controlats == totals);
	}
	controlat = ((k - 3) + 'a');
}

void tramitarFinalPartida(matriuTauler tauler, vectorJugadors jugadors, int files, int columnes, int numeroJugadors, bool senseJugadors) {
	//Pre: partida acabada
	//Post: Mostra el guanyador i si hi ha algu que controli una fila o columna
	int winner = 0;
	if (senseJugadors) {
		while (!jugadors[winner].estaJugant) {
			winner++;
		}
		cout << "GUANYADOR: JUGADOR " << jugadors[winner].nom << endl;
	}
	else {
		ordenarJugadors(jugadors, numeroJugadors, 'B');
		cout << "GUANYADOR: JUGADOR " << jugadors[0].nom << endl;
	}

	bool filaControlada = false, columnaControlada = false;
	char controlador, controlat;
	controlFiles(tauler, files, columnes, filaControlada, controlador, controlat);
	if (!filaControlada) controlColumnes(tauler, files, columnes, columnaControlada, controlador, controlat);

	if (filaControlada && controlador != ' ') {
		cout << "EL JUGADOR " << controlador << " CONTROLA LA FILA " << controlat << endl;
	}
	else if (columnaControlada && controlador != ' ') {
		cout << "EL JUGADOR " << controlador << " CONTROLA LA COLUMNA " << controlat << endl;
	}
	else cout << "CAP JUGADOR CONTROLA CAP FILA NI COLUMNA" << endl;
}

int main()
{
	cout << "BENVINGUTS A OKUPACIO !" << endl;
	int numeroJugadors;
	demanarJugadors(numeroJugadors);
	ifstream dadesTauler;
	demanarFitxer(dadesTauler);
	matriuTauler tauler;
	int files;
	int columnes;
	dadesTauler >> files;
	dadesTauler >> columnes;
	files += 3;
	columnes += 3;
	ferTauler(dadesTauler, tauler, files, columnes);
	cout << endl;
	mostrarTauler(tauler, files, columnes);
	vectorJugadors jugadors; //Amb el tauler creat, procedim a generar la taula de jugadors i a inicialitzarla
	inicialitzarJugadors(jugadors, numeroJugadors);
	bool finalTauler = false, senseJugadors = false;
	char tirada[2];
	int torn = 0, pFila, pColumna, nombreCasellesOcupades;
	int nombreCaselles = contarCasellesBuides(tauler, files, columnes);
	while (!finalTauler && !senseJugadors) {
		if (torn == numeroJugadors) torn = 0;
		if (jugadors[torn].estaJugant) {
			demanarTirada(tauler, jugadors, tirada, pFila, pColumna, files, columnes, torn);
			if (tirada[0] == '0' && tirada[1] == '0') aplicarRendicio(tauler, jugadors, torn, files, columnes, numeroJugadors);
			if (jugadors[torn].estaJugant) {
				tauler[pFila][pColumna] = jugadors[torn].nom;
				jugadors[torn].caselles++;
				aplicarNormesAdjacents(tauler, jugadors, pFila, pColumna, torn);
				cout << endl;
				mostrarTauler(tauler, files, columnes);
				cout << endl;
				mostrarLlistat(jugadors, numeroJugadors, torn);
			}
		}
		torn++;
		correccioSenseTirar(jugadors, numeroJugadors, torn);
		senseJugadors = quedaUn(jugadors, numeroJugadors); //Comprovació Jugadors Jugant
		nombreCasellesOcupades = contarCasellesOcupades(jugadors, numeroJugadors); // comprovació caselles buides
		finalTauler = (nombreCaselles == nombreCasellesOcupades);
	}
	cout << endl << "GAME OVER" << endl << endl;
	tramitarFinalPartida(tauler, jugadors, files, columnes, numeroJugadors, senseJugadors);
	system("pause");
	return 0;
}
