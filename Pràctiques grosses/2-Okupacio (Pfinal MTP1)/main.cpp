#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int MIDA_MAXIMA=25+4;  //Mida màxima del tauler + marges
const int AMPLADA=13;        //Amplada estàndar per les separacions
const int JUGADORS_MAX=10+1; //Número màxim de jugadors
const int PRECISIO=3;        //Precissió dels números reals

struct Jugador{
    int caselles, arrabassades, sense_tirar, suma_caselles;
    double mitjana;
    char lletra;
    bool actiu;
};

struct Tauler{
    int files, columnes, numjugadors, torns_totals;
    char mapa[MIDA_MAXIMA][MIDA_MAXIMA];
};

typedef Jugador VectorJugador[JUGADORS_MAX];

void Inicialitzar_Tupla(VectorJugador Jugadors, Tauler &tauler1){
    //Pre: --
    //Post: Inicialitza el vector de jugadors
    for(int i=0;i<=tauler1.numjugadors;i++){
        Jugadors[i].sense_tirar=tauler1.numjugadors-i;
        Jugadors[i].caselles=0;
        Jugadors[i].arrabassades=0;
        Jugadors[i].suma_caselles=0;
        Jugadors[i].mitjana=0;
        Jugadors[i].lletra=i+'A'-1;
        Jugadors[i].actiu=true;
    }
    tauler1.torns_totals=1;
}

void Netejar_mapa(Tauler &tauler1){
    //Pre: --
    //Post: Neteja les caselles del mapa
    for(int i=0;i<MIDA_MAXIMA;i++){
        for(int j=0;j<MIDA_MAXIMA;j++){
            tauler1.mapa[j][i]=' ';
        }
    }
}

void Fer_Contorn(Tauler &tauler1){
    //Pre: --
    //Post: Fa el contorn del mapa al tauler
    char lletra='a', lletra2='a';
    for(int i=2;i<tauler1.files+2;i++){
        tauler1.mapa[0][i]=lletra;
        lletra++;
    }
    for(int i=2;i<tauler1.columnes+2;i++){
        tauler1.mapa[i][0]=lletra2;
        lletra2++;
    }
    for(int i=1;i<tauler1.columnes+3;i++){
        tauler1.mapa[i][1]='#';
        tauler1.mapa[i][tauler1.files+2]='#';
    }
    for(int i=1;i<tauler1.files+3;i++){
        tauler1.mapa[1][i]='#';
        tauler1.mapa[tauler1.columnes+2][i]='#';
    }
}

void Posar_Murs(fstream &fitxer, Tauler &tauler1){
    //Pre: --
    //Post: Llegeix el fitxer i posa els murs al lloc corresponent del mapa
    int temp, columnactual=2, filactual=2;
    bool esmur=false;
    while(!fitxer.eof()){
        fitxer>>temp;
            for(int i=0;i<temp;i++){
                if(esmur)tauler1.mapa[columnactual][filactual]='#';
                if(columnactual-1==tauler1.columnes){
                    filactual++;
                    columnactual=2;
                }
                else columnactual++;
            }
        esmur=!esmur;
    }
}

void Dibuixar_tauler(Tauler tauler1){
    //Pre: --
    //Post: Dibuixa en pantalla la taula de caracters
    cout<<endl;
    for(int i=0;i<tauler1.files+3;i++){
        for(int j=0;j<tauler1.columnes+4;j++){
            cout<<tauler1.mapa[j][i];
        }
        cout<<endl;
    }
    cout<<endl;
}

int Jugadors_Actius(VectorJugador Jugadors, Tauler tauler1){
    //Pre: --
    //Post: Retorna el numero de jugadors actius
    int actius=0;
    for(int i=1;i<=tauler1.numjugadors;i++){
        if(Jugadors[i].actiu)actius++;
    }
    return actius;
}

bool EsPle(Tauler tauler1){
    //Pre: --
    //Post: Un boleà que es verdader si tot el tauler de joc és ple
    bool trobat=false;
    int i=2,j;
    while(i<tauler1.columnes+2 and !trobat){
        j=2;
        while(j<tauler1.files+2 and !trobat){
            if(tauler1.mapa[i][j]==' ')trobat=true;
            j++;
        }
        i++;
    }
    return !trobat;
}

int Buscar_Proper_Torn(int torn, VectorJugador Jugadors, Tauler &tauler1){
    //Pre: torn>0 torn<=tauler1.numjugadors
    //Post: Retorna el torn del proper jugador o -1 si només en queda un
    int Proper_Jugador=-1;
    bool trobat=false;
    if(Jugadors_Actius(Jugadors,tauler1)>1){
        while(!trobat){
            if(torn+1<=tauler1.numjugadors){
                torn++;
                if(Jugadors[torn].actiu){
                    trobat=true;
                    Proper_Jugador=torn;
                }
            }
            else{
                tauler1.torns_totals++;
                torn=0;
            }
        }
    }
    return Proper_Jugador;
}

void Calcular_Mitjanes(VectorJugador Jugadors, Tauler tauler1){
    //Pre: tauler1.torns_totals>0
    //Post: Calcula la mitjana de caselles de cada jugador
    for(int i=1;i<=tauler1.numjugadors;i++)
        Jugadors[i].mitjana=Jugadors[i].suma_caselles/tauler1.torns_totals;
}

void Actualitzar_Jugadors(int torn, VectorJugador Jugadors, Tauler tauler1){
    //Pre: torn>0 torn<=tauler1.numjugadors
    //Post: Actualitza les dades dels jugadors (torns sense tirar, mitjanes)
    for(int i=1;i<=tauler1.numjugadors;i++){
        Jugadors[i].sense_tirar++;
    }
    Jugadors[torn].sense_tirar=0;
    Jugadors[torn].suma_caselles+=Jugadors[torn].caselles;
    Jugadors[torn].mitjana=float(Jugadors[torn].suma_caselles)/tauler1.torns_totals;
}

void Esborrar_Exercit(char exercit, Tauler &tauler1){
    //Pre: La lletra majúscula del jugador del que s'ha de borrar l'exèrcit
    //Post: Esborra els exercits de l'equip entrat del mapa
    for(int i=2;i<tauler1.columnes+2;i++){
        for(int j=2;j<tauler1.files+2;j++){
            if(tauler1.mapa[i][j]==exercit)tauler1.mapa[i][j]=' ';
        }
    }
}

void Intercanviar(Jugador &a, Jugador &b){
    //Pre: a=A i b=B
    //Post: a=B i b=A
    Jugador aux=a;
    a=b;
    b=aux;
}

bool Esmenor_igual(int j, int mode, VectorJugador temp){
    //Pre: 0<=mode<=7 i 0<j<tauler1.numjugadors
    //Post: Retorna si el jugador és menor o si és igual que l'anterior en funció del mode
    bool menor=false;
    if(mode==0)menor=temp[j].caselles>temp[j-1].caselles;
    else if(mode==1)menor=temp[j].arrabassades>temp[j-1].arrabassades;
    else if(mode==2)menor=temp[j].mitjana>temp[j-1].mitjana;
    else if(mode==3)menor=temp[j].sense_tirar>temp[j-1].sense_tirar;
    else if(mode==4)menor=temp[j].caselles==temp[j-1].caselles;
    else if(mode==5)menor=temp[j].arrabassades==temp[j-1].arrabassades;
    else if(mode==6)menor=temp[j].mitjana==temp[j-1].mitjana;
    return menor;
}

void Ordenar_Ranking(VectorJugador Jugadors, VectorJugador temp, Tauler tauler1){
    //Pre: --
    //Post: Ordena el vector de jugadors
    for(int i=0;i<=tauler1.numjugadors+1;i++)
        temp[i]=Jugadors[i];
    for(int i=1;i<tauler1.numjugadors;i++){
        for(int j=tauler1.numjugadors;j>i;j--){
            int k=0;
            bool fet=false;
            while(k<4 and !fet){
                if(Esmenor_igual(j,k,temp)){
                    Intercanviar(temp[j],temp[j-1]);
                    fet=true;
                }
                else if(!Esmenor_igual(j,k+4,temp))
                    fet=true;
                k++;
            }
        }
    }
}

void Escriure_Ranking(VectorJugador Jugadors, Tauler tauler1){
    //Pre: --
    //Post: Escriu en pantalla el ranking dels jugadors
    VectorJugador temp;
    string dades[]={"JUGADOR","CASELLES","ARRABASSADES","OCUP.MITJA","SENSE TIRAR"};
    Ordenar_Ranking(Jugadors,temp,tauler1);
    Jugadors[0]=temp[1];
    cout.setf(ios::fixed);
    cout.precision(PRECISIO);
    for(int i=0;i<5;i++){
        cout<<right<<setw(AMPLADA)<<dades[i];
    }
    cout<<endl;
    for(int i=1;i<=tauler1.numjugadors;i++){
        if(temp[i].actiu){
            cout<<right<<setw(AMPLADA)<<temp[i].lletra;
            cout<<right<<setw(AMPLADA)<<temp[i].caselles;
            cout<<right<<setw(AMPLADA)<<temp[i].arrabassades;
            cout<<right<<setw(AMPLADA)<<temp[i].mitjana;
            cout<<right<<setw(AMPLADA)<<temp[i].sense_tirar<<endl;
        }
    }
    cout<<endl;
}

void Pos_Orientacio(int fila, int columna, int &fila_transf, int &col_transf, int orientacio){
    //Pre: 0<=orientacio<=3
    //Post: Dona la posició de la casella que es troba en la orientació entrada respecte al punt original
    fila_transf=fila;
    col_transf=columna;
    if(orientacio==0)fila_transf--;
    if(orientacio==1)col_transf--;
    if(orientacio==2)fila_transf++;
    if(orientacio==3)col_transf++;
}

void Buscar_Adjacents(int fila, int columna, int &caselles_adj, int adj_orientacio[], Tauler tauler1){
    //Pre: 1<fila<tauler1.files+2 i 1<columna<tauler1.columnes+2
    //Post: Calcula el numero adjacent de caselles de la posicio entrada i el vector amb les orientacions d'aquestes
    int pos=0;
    for(int i=0;i<5;i++)
        adj_orientacio[i]=-1;
    if(tauler1.mapa[columna][fila-1]!='#'){
        adj_orientacio[pos]=0;
        pos++;
    }
    if(tauler1.mapa[columna-1][fila]!='#'){
        adj_orientacio[pos]=1;
        pos++;
    }
    if(tauler1.mapa[columna][fila+1]!='#'){
        adj_orientacio[pos]=2;
        pos++;
    }
    if(tauler1.mapa[columna+1][fila]!='#'){
        adj_orientacio[pos]=3;
        pos++;
    }
    for(int i=0;i<=3;i++)
        if(adj_orientacio[i]!=-1)caselles_adj++;
}

void Arrabassar(int fila, int col, Jugador Jug[], int torn, Tauler &tauler1){
    //Pre: 0<torn<=tauler1.numjugadors, 1<fila<tauler1.files+2 i 1<columna<tauler1.columnes+2
    //Post: Comprova si la casella pertany a un altre exèrcit i l'arrabassa si no és de ningú
    if(tauler1.mapa[col][fila]==' '){
        tauler1.mapa[col][fila]=Jug[torn].lletra;
        Jug[torn].caselles++;
    }
    else if(tauler1.mapa[col][fila]!=Jug[torn].lletra and tauler1.mapa[col][fila]!=' '){
        Jug[tauler1.mapa[col][fila]-'A'+1].caselles--;
        Jug[torn].arrabassades++;
        tauler1.mapa[col][fila]=Jug[torn].lletra;
        Jug[torn].caselles++;
    }
}

void Tractar_Adjacents(int fila, int columna, VectorJugador Jug, int torn, Tauler &tauler1){
    //Pre: 0<torn<=tauler1.numjugadors, 1<fila<tauler1.files+2 i 1<columna<tauler1.columnes+2
    //Post: Agafa les caselles adjacents seguint les regles del joc
    int adj_prim=0,adj_sec,f_sec,c_sec,c_ter,f_ter,temp=0,temp2=0;
    int adj_prim_orientacio[5],adj_sec_orientacio[5];
    char lletres[6],lletra1;
    Buscar_Adjacents(fila,columna,adj_prim,adj_prim_orientacio,tauler1);
    for(int i=0;i<adj_prim;i++){
        adj_sec=0; temp=0;
        Pos_Orientacio(fila,columna,f_sec,c_sec,adj_prim_orientacio[i]);
        Buscar_Adjacents(f_sec,c_sec,adj_sec,adj_sec_orientacio,tauler1);
        switch(adj_sec){
        case 1:
            Arrabassar(f_sec,c_sec,Jug,torn,tauler1);
            break;
        case 2:
            Pos_Orientacio(f_sec,c_sec,f_ter,c_ter,adj_sec_orientacio[0]);
            lletra1=tauler1.mapa[c_ter][f_ter];
            Pos_Orientacio(f_sec,c_sec,f_ter,c_ter,adj_sec_orientacio[1]);
            if(lletra1==tauler1.mapa[c_ter][f_ter] and lletra1==Jug[torn].lletra)
                Arrabassar(f_sec,c_sec,Jug,torn,tauler1);
            break;
        case 3:
            for(int j=0;j<adj_sec;j++){
                Pos_Orientacio(f_sec,c_sec,f_ter,c_ter,adj_sec_orientacio[j]);
                lletres[j]=tauler1.mapa[c_ter][f_ter];
                if(lletres[j]==Jug[torn].lletra)temp++;
                }
            if(lletres[0]==lletres[1] and lletres[1]==lletres[2])
                Arrabassar(f_sec,c_sec,Jug,torn,tauler1);
            else if(temp==2 and tauler1.mapa[c_sec][f_sec]==' ')
                    Arrabassar(f_sec,c_sec,Jug,torn,tauler1);
            break;
        case 4:
            for(int j=0;j<adj_sec;j++){
                Pos_Orientacio(f_sec,c_sec,f_ter,c_ter,adj_sec_orientacio[j]);
                lletres[j]=tauler1.mapa[c_ter][f_ter];
                if(Jug[torn].lletra==lletres[j])temp++;
                else temp2=j;
            }
            if(temp==4)
                Arrabassar(f_sec,c_sec,Jug,torn,tauler1);
            if(temp==3){
                if(tauler1.mapa[c_sec][f_sec]==' ')
                    Arrabassar(f_sec,c_sec,Jug,torn,tauler1);
                else if(lletres[temp2]!=tauler1.mapa[c_sec][f_sec])
                    Arrabassar(f_sec,c_sec,Jug,torn,tauler1);
            }
            break;
        }
    }
}

bool Entrada_Correcta(int fila, int columna, Tauler tauler1){
    //Pre: 1<fila<tauler1.files+2 i 1<columna<tauler1.columnes+2
    //Post: Retorna cert si l'entrada és correcte
    bool escorrecte=false;
    int fila_mod=fila-'a'+2, columna_mod=columna-'a'+2;
    if(fila>='a' and fila-'a'+1<=tauler1.files)
        if(columna>='a' and columna-'a'+1<=tauler1.columnes)
            if(tauler1.mapa[columna_mod][fila_mod]==' ')
                escorrecte=true;
    if(fila=='0' and columna=='0')
        escorrecte=true;
   return escorrecte;
}

void Processar_Fila_Columna(int limit, int i, char &lletra, bool &possible, Tauler tau){
    //Pre: i>0
    //Post: Comprova si una fila/columna pertany a un jugador
    bool lletraset=false;
    int j=2;
    possible=true;
    while(j<limit and possible){
         if(tau.mapa[j][i]==' ')
            possible=false;
         else if(!lletraset){
            if(tau.mapa[j][i]!=' ' and tau.mapa[j][i]!='#'){
                lletra=tau.mapa[j][i];
                lletraset=true;
            }
        }
        else if(tau.mapa[j][i]!='#' and tau.mapa[j][i]!=lletra)
            possible=false;
        j++;
    }
}

void Escriure_Control(Tauler tau){
    //Pre: --
    //Post: Mostra per pantalla si algun jugador controla una fila i una columna i quines són
    bool trobat=false,possible=false,lletraset;
    char lletra='*',C_files[JUGADORS_MAX];
    int i=2,j;
    for(int k=0;k<JUGADORS_MAX;k++)
        C_files[k]='*';
    while(i<tau.files+2){
        lletraset=false;
        possible=true;
        j=2;
        while(j<tau.columnes+2 and possible){
            if(tau.mapa[j][i]==' ')
                possible=false;
            else if(!lletraset){
                if(tau.mapa[j][i]!=' ' and tau.mapa[j][i]!='#'){
                    lletra=tau.mapa[j][i];
                    lletraset=true;
                }
            }
            else if(tau.mapa[j][i]!='#' and tau.mapa[j][i]!=lletra)
                possible=false;
            j++;
        }
        if(possible)
            if(C_files[lletra-'A']=='*')
                C_files[lletra-'A']=i-2+'a';
        i++;
    }
    i=2;
    while(i<tau.columnes+2 and !trobat){
        Processar_Fila_Columna(tau.files+2,i,lletra,possible,tau);
        lletraset=false;
        possible=true;
        j=2;
        while(j<tau.files+2 and possible){
            if(tau.mapa[i][j]==' ')
                possible=false;
            else if(!lletraset){
                if(tau.mapa[i][j]!=' ' and tau.mapa[i][j]!='#'){
                    lletra=tau.mapa[i][j];
                    lletraset=true;
                }
            }
            else if(tau.mapa[i][j]!='#' and tau.mapa[i][j]!=lletra)
                possible=false;
            j++;
        }
        if(possible and C_files[lletra-'A']!='*')trobat=true;
        i++;
    }
    if(trobat)cout<<"EL JUGADOR "<<lletra<<" CONTROLA LA FILA "<<C_files[lletra-'A']<<" I LA COLUMNA "<<char(i+'a'-3)<<endl;
    else cout<<"CAP JUGADOR CONTROLA UNA FILA I UNA COLUMNA"<<endl;
}

int Caselles_Buides(Tauler tauler1){
    //Pre: --
    //Post: Retorna el número de caselles buides que hi ha al tauler
    int buides=0;
    for(int i=2;i<tauler1.columnes+2;i++){
        for(int j=2;j<tauler1.files+2;j++){
            if(tauler1.mapa[i][j]==' ')buides++;
        }
    }
    return buides;
}

void Inicialitzar_Joc(fstream &fitxer, VectorJugador Jugadors, Tauler &tauler1){
    //Pre: --
    //Post: Inicialitza els vectors, el tauler de joc i posa murs i contorns
    fitxer>>tauler1.files>>tauler1.columnes;
    Netejar_mapa(tauler1);
    Inicialitzar_Tupla(Jugadors,tauler1);
    Fer_Contorn(tauler1);
    Posar_Murs(fitxer,tauler1);
    Dibuixar_tauler(tauler1);
}

void Bucle_Joc(VectorJugador Jugadors, Tauler &tauler1){
    //Pre: El vector de jugadors i el tauler inicialitzats
    //Post: Agafa les entrades de posició i processa els torns del joc
    int torn=1;
    char fila, columna, fila_in, columna_in;
    while(!EsPle(tauler1) and torn!=-1){
        if(Jugadors[0].caselles-Jugadors[torn].caselles>Caselles_Buides(tauler1)){
            Jugadors[torn].actiu=false;
            Esborrar_Exercit(Jugadors[torn].lletra,tauler1);
            cout<<"EL JUGADOR "<<Jugadors[torn].lletra<<" ES ELIMINAT DEL JOC"<<endl;
        }
        else{
            do{
                cout<<"JUGADOR "<<Jugadors[torn].lletra<<endl;
                cin>>fila_in>>columna_in;
            }
            while(!Entrada_Correcta(fila_in,columna_in,tauler1));
            fila=fila_in-'a'+2; columna=columna_in-'a'+2;
            if(fila_in=='0' and columna_in=='0'){
                Jugadors[torn].actiu=false;
                Esborrar_Exercit(Jugadors[torn].lletra,tauler1);
            }
            else if(tauler1.mapa[columna][fila]==' '){
                tauler1.mapa[columna][fila]=Jugadors[torn].lletra;
                Jugadors[torn].caselles++;
                Tractar_Adjacents(fila,columna,Jugadors,torn,tauler1);
            }
            Actualitzar_Jugadors(torn,Jugadors,tauler1);
        }
        Dibuixar_tauler(tauler1);
        Escriure_Ranking(Jugadors,tauler1);
        torn=Buscar_Proper_Torn(torn,Jugadors,tauler1);
    }
}

int main()
{
    //Entrada: El nom d'un fitxer de tauler correcte que es trobi al mateix directori,
    //el numero de jugadors que participaràn a la partida i la posició on posarà l'exèrcit cadascún
    //Sortida: El tauler de joc i la llista de jugadors ordenats per assoliments després de cada entrada
    Tauler tauler1;
    VectorJugador Jugadors;
    tauler1.numjugadors=0;
    string nomarxiu;
    fstream fitxer;

    cout<<"BENVINGUTS A OKUPACIO !"<<endl;
    while(tauler1.numjugadors<2 or tauler1.numjugadors>10){
        cout<<"ENTRA NOMBRE DE JUGADORS (2..10):"<<endl;
        cin>>tauler1.numjugadors;
    }
    cout<<"NOM DEL FITXER DEL TAULER:"<<endl;
    cin>>nomarxiu;
    fitxer.open(nomarxiu.c_str(),fstream::in);
    if (fitxer.is_open()){
        Inicialitzar_Joc(fitxer,Jugadors,tauler1);
        Bucle_Joc(Jugadors,tauler1);
        cout<<"GAME OVER"<<endl<<endl;
        cout<<"GUANYADOR: JUGADOR "<<Jugadors[0].lletra<<endl;
        Escriure_Control(tauler1);
    }
    else cout<<"NO ES POT OBRIR EL FITXER"<<endl;
    return 0;
}
