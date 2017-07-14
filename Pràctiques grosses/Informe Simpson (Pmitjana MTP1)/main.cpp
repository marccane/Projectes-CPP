#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

const string SHIPMENTS_2014 = "shipments_2014_06am.mtp"; // Fitxer d’enviaments acabat (versió 6 del matí)
const string US_CENSUS_2014 = "census_2014.usa"; // Fitxer del cens estatal
const int US_STATES = 51; // Registres del cens estàndard d’USA: 50 estats + 1 districte
const int QUARTERS = 4; // 1 "Quarter" representa un trimestre d’un any (4 "quarters" x 3 mesos = 12 mesos)
const int WIDTH_STATE_NAME = 21; // Amplada de camp per output nom d’estats
const int WIDTH_STATE_CODE = 3; // Amplada de camp per output codi estats
const int WIDTH = 17; // Amplada de camp estàndard per outputs genèrics
const int RATE_PRECISION = 3; // Precisió decimal per ratis
const int USD_PRECISION = 2; // Precisió decimal per imports USD (dòlar d’US)

struct DadesEstat{
    string codi, nom;
    int unitats_venudes[5], nombre_enviaments[5], poblacio;
    double Import[5];
};

struct DadesEnviaments{
    int data, unitats;
    string codi;
    double preu;
};

void NetejarTaules(DadesEstat estats[]){
//Pre: -
//Post: Les taules inicialitzades
    for(int i=0;i<US_STATES+1;i++){
        for(int j=0;j<5;j++){
            estats[i].unitats_venudes[j]=0;
            estats[i].nombre_enviaments[j]=0;
            estats[i].Import[j]=0;
        }
    }
}

bool ObrirFitxer(fstream &arxiu, string nom){
//Pre: -
//Post: Obre el fitxer amb el nom especificat i ens retorna si s'ha obert correctament
    arxiu.open(nom.c_str(),fstream::in);
    if (!arxiu.is_open()){
        cout << "ERROR OBRINT FITXER" << endl;
    }
    return arxiu.is_open();
}

DadesEstat LlegirCens(fstream &f_cens){
//Pre: -
//Post: Llegeix un cens des de fitxer
    DadesEstat entrada;
    f_cens>>entrada.nom>>entrada.codi>>entrada.poblacio;
    return entrada;
}

void desplacar_dreta(DadesEstat estats[], int estats_registrats, int posicio_inicial){
//Pre: Posicio_inicial<estats_registrats
//Post: La taula entrada desplaçada un lloc cap a la dreta a parttir d eposicio_inicial
    for(int i=estats_registrats;i>posicio_inicial;i--){
        estats[i]=estats[i-1];
    }
}

void Inserir_Cens_Ordenat(DadesEstat estats[], DadesEstat entrada, int &estats_registrats){
//Pre: Un estat del cens
//Post: Ordena l'estat al seu lloc corresponent a al taula
    bool inserit=false;
    int i=0;
    while(i<estats_registrats and !inserit){
        if(entrada.codi<estats[i].codi){
            desplacar_dreta(estats, estats_registrats, i);
            estats[i]=entrada;
            inserit=true;
        }
        i++;
    }
    if(!inserit) estats[estats_registrats]=entrada;
    estats_registrats++;
}

void Escriure_Cens(DadesEstat estats[]){
//Pre: La taula amb les dades del cens a escriure
//Post: Escriu per pantalla les dades del cens
    cout<<setw(WIDTH_STATE_CODE)<<left<<"PC"<<setw(WIDTH_STATE_NAME)<<"State"<<setw(WIDTH)<<right<<"Population"<<endl;
	cout<<setw(WIDTH_STATE_CODE)<<left<<"US"<<setw(WIDTH_STATE_NAME)<<"United States"<<setw(WIDTH)<<right<<estats[US_STATES].poblacio<<endl;
    for(int i=0;i<US_STATES;i++){
        cout<<setw(WIDTH_STATE_CODE)<<left<<estats[i].codi<<setw(WIDTH_STATE_NAME)<<estats[i].nom<<setw(WIDTH)<<right<<estats[i].poblacio<<endl;
    }
}

DadesEnviaments Llegir_Enviaments(fstream &arxiu){
//Pre:
//Post:
    DadesEnviaments entrada;
    arxiu>>entrada.data>>entrada.codi>>entrada.unitats>>entrada.preu;
    return entrada;
}

void Intercanviar(DadesEstat &a, DadesEstat &b){
//Pre: -
//Post: S'intercanvien les dades de posicio
    DadesEstat temp=a;
    a=b;
    b=temp;
}

bool Comparar(DadesEstat estats[], int j, int mode){
//Pre: Una posicio correcta de la taula
//Post: Retorna la condicio que correspon a cada cas en
//funció del mode perquè la taula s'ordeni correctament
    bool resultat;
    switch(mode){
    case 1:
        resultat=estats[j].Import[0]>estats[j-1].Import[0];
        break;
    case 2:
        resultat=estats[j].unitats_venudes[0]>estats[j-1].unitats_venudes[0];
        break;
    case 3:
        resultat=estats[j].nombre_enviaments[0]>estats[j-1].nombre_enviaments[0];
        break;
    case 4:
        resultat=estats[j].nom<estats[j-1].nom;
        break;
    case 6:
        resultat=estats[j].codi<estats[j-1].codi;
        break;
    case 11:
        resultat=estats[j].Import[0]==estats[j-1].Import[0];
        break;
    case 12:
        resultat=estats[j].unitats_venudes[0]==estats[j-1].unitats_venudes[0];
        break;
    case 13:
        resultat=estats[j].nombre_enviaments[0]==estats[j-1].nombre_enviaments[0];
        break;
    case 14:
        resultat=false;
        break;
    case 16:
        resultat=false;
        break;
    }
    return resultat;
}

void Ordenar(DadesEstat estats[], int mode){
//Pre: n>0 i n<=MÀXIM i a=A
//Post: a[1..n] està ordenat i és una permutació de A[1..n]}
    for(int i=0;i<US_STATES;i++){
        for(int j=US_STATES-1;j>i;j--){
            if(Comparar(estats,j,mode))
                Intercanviar(estats[j],estats[j-1]);
            else if(Comparar(estats,j,10+mode)){
                if(estats[j].nom<estats[j-1].nom) Intercanviar(estats[j],estats[j-1]);
            }
        }
    }
}

int Cercar_Estat(DadesEstat estats[], string codi){
//Pre: Codi d'estat correcte
//Post: Retorna la posicio de la taula que conté l'estat amb el codi entrat
    bool trobat=false;
    int resultat=-1,i=0;
    while(i<US_STATES and !trobat){
        if(codi==estats[i].codi){
            resultat=i;
            trobat=true;
        }
        i++;
    }
    return resultat;
}

int Determinar_trimestre(int data){
//Pre: Data correcte en format ISO-8601
//Post: Retorna el trimestre al qual correspon la data
    int trimestre=4;
    data%=10000;
    if(data<=331)trimestre=1;
    else if(data<=630)trimestre=2;
    else if(data<=930)trimestre=3;
    else if(data<=1231)trimestre=4;
    return trimestre;
}

void Tractar_Entrada(DadesEstat estats[], DadesEnviaments entrada, int &ship_num, int &ship_err){
//Pre: -
//Post: La dada entrada es guarda a la taula d'estats si el codi de l'estat és correcte
    int pos_estat=Cercar_Estat(estats, entrada.codi), trimestre=Determinar_trimestre(entrada.data);
    ship_num++;
    if(pos_estat==-1){
        cout<<"ERROR: Invalid state code: "<<entrada.codi<<" [ shipment "<<ship_num<<" omitted ]."<<endl;
        ship_err++;
    }
    else{
        estats[pos_estat].Import[trimestre]+=entrada.preu;
        estats[pos_estat].nombre_enviaments[trimestre]++;
        estats[pos_estat].unitats_venudes[trimestre]+=entrada.unitats;
    }
}

void Sumar_Totals(DadesEstat estats[]){
//Pre: -
//Post: Emplena la posicio 0 de cadascuna de les taules de dades amb la suma dels trimestres
    for(int i=0;i<US_STATES;i++){
        for(int j=1;j<=QUARTERS;j++){
            estats[i].Import[0]+=estats[i].Import[j];
            estats[i].nombre_enviaments[0]+=estats[i].nombre_enviaments[j];
            estats[i].unitats_venudes[0]+=estats[i].unitats_venudes[j];
        }
    }
}

void Emplenar_US(DadesEstat estats[]){
//Pre: -
//Post: Emplena la posicio 51 de la taula amb la suma de tots els totals
    estats[US_STATES].nom="United States";
    for(int i=0;i<US_STATES;i++){
        for(int j=0;j<QUARTERS+1;j++){
            estats[US_STATES].nombre_enviaments[j]+=estats[i].nombre_enviaments[j];
            estats[US_STATES].unitats_venudes[j]+=estats[i].unitats_venudes[j];
            estats[US_STATES].Import[j]+=estats[i].Import[j];
        }
    }
}

double Dividir(double a, double b){
//Pre: Dos nombres reals
//Post: El cocient de a/b expecte si b=0 que donarà 0
    double resultat;
    if(b==0)resultat=0;
    else resultat=a/b;
    return resultat;
}

double Buscar_Maxim(DadesEstat estats[], int iteracions){
//Pre: -
//Post: Retorna l'import de l'estat que més ha venut
    double valor_maxim=0;
    for(int i=0;i<iteracions;i++){
        if(estats[i].Import[0]>valor_maxim){
            valor_maxim=estats[i].Import[0];
        }
    }
    return valor_maxim;
}

void Fer_Asteriscs(int num){
//Pre: n>0
//Post: Escriu per pantalla el nombre d'asteriscs entrat
    for(int i=0;i<num;i++){
        cout<<"*";
    }
}

void Escriure_Informe(DadesEstat e[], int mode){
//Pre: Un enter n que ha de ser un número de l'1 al 7
//Post: Escriu en pantalla l'informe n
    const int U=US_STATES;
    double popval;
    switch(mode){
    case 1:
        popval = e[US_STATES].poblacio/e[US_STATES].Import[0];
        cout<<"=====[ Report 2014 Video-Games Springfield <Begin> ]====="<<endl<<endl;
        cout<<"=====[ Report A: Quarter values ]====="<<endl<<endl;
        cout<<left<<setw(WIDTH_STATE_NAME)<<"State"<<setw(WIDTH)<<right<<"Population"<<setw(WIDTH);
        cout<<setw(WIDTH)<<"Anual"<<setw(WIDTH)<<"1Q"<<setw(WIDTH)<<"2Q"<<setprecision(USD_PRECISION)<<fixed;
        cout<<setw(WIDTH)<<"3Q"<<setw(WIDTH)<<"4Q"<<setw(WIDTH)<<"Population/Value"<<endl;
        cout<<left<<setw(WIDTH_STATE_NAME)<<e[U].nom<<setw(WIDTH)<<right<<e[U].poblacio<<setprecision(USD_PRECISION);
        cout<<setw(WIDTH)<<e[U].Import[0]<<setw(WIDTH)<<e[U].Import[1]<<setw(WIDTH)<<e[U].Import[2];
        cout<<setw(WIDTH)<<e[U].Import[3]<<setw(WIDTH)<<e[U].Import[4]<<setw(WIDTH)<<setprecision(RATE_PRECISION)<<popval<<endl;
        for(int i=0;i<US_STATES;i++){
            popval=Dividir(e[i].poblacio,e[i].Import[0]);
            cout<<left<<setw(WIDTH_STATE_NAME)<<e[i].nom<<setw(WIDTH)<<right<<e[i].poblacio<<setprecision(USD_PRECISION);
            cout<<setw(WIDTH)<<e[i].Import[0]<<setw(WIDTH)<<e[i].Import[1]<<setw(WIDTH)<<e[i].Import[2];
            cout<<setw(WIDTH)<<e[i].Import[3]<<setw(WIDTH)<<e[i].Import[4]<<setw(WIDTH)<<setprecision(RATE_PRECISION)<<popval<<endl;
        }
        cout<<endl;
        break;
    case 2:
        /*STUB*/
        break;
    case 3:
		/*STUB*/
        break;
    case 4:
        double uniship,valuni;
        uniship=Dividir(e[U].unitats_venudes[0],e[U].nombre_enviaments[0]);
        valuni=Dividir(e[U].Import[0],e[U].unitats_venudes[0]);
        cout<<"=====[ Report D: Anual shipments rates ]====="<<endl<<endl;
        cout<<left<<setw(WIDTH_STATE_NAME)<<"State"<<right<<setw(WIDTH)<<"Shipments"<<setw(WIDTH)<<"Units"<<setw(WIDTH)<<"Value";
        cout<<setw(WIDTH)<<"Units/Shipment"<<setw(WIDTH)<<"Value/Unit"<<endl;
        cout<<left<<setw(WIDTH_STATE_NAME)<<e[U].nom<<setw(WIDTH)<<right<<e[U].nombre_enviaments[0]<<setw(WIDTH)<<e[U].unitats_venudes[0];
        cout<<setprecision(USD_PRECISION)<<setw(WIDTH)<<e[U].Import[0]<<setprecision(RATE_PRECISION)<<setw(WIDTH)<<uniship<<setw(WIDTH)<<valuni<<endl;
        for(int i=0;i<US_STATES;i++){
            uniship=Dividir(e[i].unitats_venudes[0],e[i].nombre_enviaments[0]);
            valuni=Dividir(e[i].Import[0],e[i].unitats_venudes[0]);
            cout<<left<<setw(WIDTH_STATE_NAME)<<e[i].nom<<setw(WIDTH)<<right<<e[i].nombre_enviaments[0]<<setw(WIDTH)<<e[i].unitats_venudes[0];
            cout<<setprecision(USD_PRECISION)<<setw(WIDTH)<<e[i].Import[0]<<setprecision(RATE_PRECISION)<<setw(WIDTH)<<uniship<<setw(WIDTH)<<valuni<<endl;
        }
        cout<<endl;
        break;
    case 5:
        double percent;
        percent=Dividir(e[U].Import[0]*100,e[U].Import[0]);
        cout<<"=====[ Report E: Value-Weight by state ]====="<<endl<<endl;
        cout<<left<<setw(WIDTH_STATE_NAME)<<"State"<<right<<setw(WIDTH)<<"Value"<<setw(WIDTH)<<"Percent"<<endl;
        cout<<left<<setw(WIDTH_STATE_NAME)<<e[U].nom<<right<<setw(WIDTH)<<setprecision(USD_PRECISION)<<e[U].Import[0];
        cout<<setprecision(RATE_PRECISION)<<setw(WIDTH)<<percent<<endl;
        for(int i=0;i<US_STATES;i++){
            percent=Dividir(e[i].Import[0]*100,e[U].Import[0]);
            cout<<left<<setw(WIDTH_STATE_NAME)<<e[i].nom<<right<<setw(WIDTH)<<setprecision(USD_PRECISION)<<e[i].Import[0];
            cout<<setprecision(RATE_PRECISION)<<setw(WIDTH)<<percent<<endl;
        }
        cout<<endl;
        break;
    case 6:
        double asterisc;
        asterisc=Buscar_Maxim(e,US_STATES);
        asterisc/=100;
        cout<<"=====[ Report F: Histogram by anual value ]===== [ One * is "<<setprecision(RATE_PRECISION)<<asterisc<<" USD ] ***"<<endl<<endl;
        cout<<setprecision(USD_PRECISION);
        for(int i=0;i<US_STATES;i++){
            cout<<left<<e[i].codi<<" |";
            Fer_Asteriscs(round(e[i].Import[0]/asterisc));
            cout<<" [ "<<e[i].Import[0]<<" ]"<<endl;
        }
        cout<<endl;
        break;
    case 7:
        double asterisc2, maxim;
        maxim=0;
        for(int i=1;i<=4;i++){
            if(e[US_STATES].unitats_venudes[i]>maxim)
                maxim=e[US_STATES].unitats_venudes[i];
        }
        asterisc2=maxim/100;
        cout<<"=====[ Report G: Histogram by global quarter units ]===== [ One * is "<<setprecision(RATE_PRECISION)<<maxim/100<<" units ] ***"<<endl<<endl;
        for(int i=1;i<5;i++){
            cout<<i<<"Q |";
            Fer_Asteriscs(round(e[US_STATES].unitats_venudes[i]/asterisc2));
            cout<<" [ "<<e[US_STATES].unitats_venudes[i]<<" ]"<<endl;
        }
        cout<<endl<<"=====[ Report 2014 Video-Games Springfield <End> ]=====";
        break;
    }
}

void SumaPoblacio(DadesEstat estats[]){
//Pre: -
//Post: La posicio 51 de la taula amb la suma de les poblacions
    estats[US_STATES].poblacio=0;
    for(int i=0;i<US_STATES;i++){
        estats[US_STATES].poblacio+=estats[i].poblacio;
    }
}

int main(){

    fstream f_cens, f_ship;
    string nomarxiu;
    DadesEstat estats[US_STATES+1], entrada;
    DadesEnviaments enviaments_entrada;
    int estats_registrats=0, shipment_num=0, shipment_erors=0;

    if(ObrirFitxer(f_cens,US_CENSUS_2014)){
        cout<<"File "<<US_CENSUS_2014<<" loaded [ "<<US_STATES<<" records ]"<<endl<<endl;
        cout<<"=====[ Report S: Census states <Begin> ]====="<<endl<<endl;
        while(!f_cens.eof()){
            entrada=LlegirCens(f_cens);
            Inserir_Cens_Ordenat(estats, entrada, estats_registrats);
        }
        SumaPoblacio(estats);
        Escriure_Cens(estats);
        cout<<endl<<"=====[ Report S: Census states <End> ]====="<<endl<<endl;
        f_cens.close();

        NetejarTaules(estats);
        cout<<"USER INPUT: File name of shipments?"<<endl;
        cin>>nomarxiu;
        if (ObrirFitxer(f_ship,nomarxiu)){
            enviaments_entrada=Llegir_Enviaments(f_ship);
            while(!f_ship.eof()){
                Tractar_Entrada(estats,enviaments_entrada,shipment_num,shipment_erors);
                enviaments_entrada=Llegir_Enviaments(f_ship);
            }
            cout<<"File "<<nomarxiu<<" loaded [ "<<shipment_num<<" records loaded with "<<shipment_erors<<" records omitted by error = "<<shipment_num-shipment_erors<<" ]"<<endl<<endl;
            Sumar_Totals(estats);
            Emplenar_US(estats);
            for(int i=0;i<=7;i++){
                if(i!=5)Ordenar(estats,i);
                Escriure_Informe(estats,i);
            }
        }
    }
    return 0;
}
