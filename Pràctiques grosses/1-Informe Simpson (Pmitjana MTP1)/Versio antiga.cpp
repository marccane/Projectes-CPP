#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//TODO cerca dicotomica a la taula ordenada

typedef double real;
typedef double USD;
const string SHIPMENTS_2014 = "shipments_2014_06am.mtp"; // Fitxer d�enviaments acabat (versi� 6 del mat�)
const string US_CENSUS_2014 = "census_2014.usa"; // Fitxer del cens estatal
const int US_STATES = 51; // Registres del cens est�ndard d�USA: 50 estats + 1 districte
const int QUARTERS = 4; // 1 "Quarter" representa un trimestre d�un any (4 "quarters" x 3 mesos = 12 mesos)
const int WIDTH_STATE_NAME = 21; // Amplada de camp per output nom d�estats
const int WIDTH_STATE_CODE = 3; // Amplada de camp per output codi estats
const int WIDTH = 17; // Amplada de camp est�ndard per outputs gen�rics
const int RATE_PRECISION = 3; // Precisi� decimal per ratis
const int USD_PRECISION = 2; // Precisi� decimal per imports USD (d�lar d�US)

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
    for(int i=0;i<US_STATES+1;i++){
        for(int j=0;j<5;j++){
            estats[i].unitats_venudes[j]=0;
            estats[i].nombre_enviaments[j]=0;
            estats[i].Import[j]=0;
        }
    }
}

bool ObrirFitxer(fstream &arxiu, string nom){
    arxiu.open(nom.c_str(),fstream::in);
    if (!arxiu.is_open()){
        cout << "ERROR OBRINT FITXER" << endl;
    }
    return arxiu.is_open();
}

DadesEstat LlegirCens(fstream &f_cens){
    DadesEstat entrada;
    f_cens>>entrada.nom>>entrada.codi>>entrada.poblacio;
    return entrada;
}

void EscriureCapcalera(string nomfitxer, int entrades, char informe, string tipusinforme){
        cout<<"File "<<nomfitxer<<" loaded [ "<<entrades<<" records ]"<<endl<<endl;
        cout<<"=====[ Report "<<informe<<": "<<tipusinforme<<" <Begin> ]====="<<endl<<endl;
}

void EscriurePeu(char informe, string ){
    //cout<<endl<<"=====[ Report S: Census states <End> ]====="<<endl<<endl;
    cout<<endl<<"=====[ Report "<<": Census states <End> ]====="<<endl<<endl;
}

void desplacar_dreta(DadesEstat estats[], int estats_registrats, int posicio_inicial){
    for(int i=estats_registrats;i>posicio_inicial;i--){
        estats[i]=estats[i-1];
    }
}

void Inserir_Cens_Ordenat(DadesEstat estats[], DadesEstat entrada, int &estats_registrats){
    bool inserit=false;
    //! CANVIAR PER UN WHILE
    for(int i=0;i<estats_registrats and !inserit;i++){
        if(entrada.codi<estats[i].codi){
            desplacar_dreta(estats, estats_registrats, i);
            estats[i]=entrada;
            inserit=true;
        }
    }
    if(!inserit){
        estats[estats_registrats]=entrada;
    }
    estats_registrats++;
}

void Escriure_Cens(DadesEstat estats[]){
    cout<<setw(WIDTH_STATE_CODE)<<left<<"PC"<<setw(WIDTH_STATE_NAME)<<"State"<<setw(WIDTH)<<right<<"Population"<<endl;
	cout<<setw(WIDTH_STATE_CODE)<<left<<"US"<<setw(WIDTH_STATE_NAME)<<"United States"<<setw(WIDTH)<<right<<"aqui va la us population"<<endl;
    for(int i=0;i<US_STATES;i++){
        cout<<setw(WIDTH_STATE_CODE)<<left<<estats[i].codi<<setw(WIDTH_STATE_NAME)<<estats[i].nom<<setw(WIDTH)<<right<<estats[i].poblacio<<endl;
    }
}

DadesEnviaments Llegir_Enviaments(fstream &arxiu){
    DadesEnviaments entrada;
    arxiu>>entrada.data>>entrada.codi>>entrada.unitats>>entrada.preu;
    return entrada;
}

void Intercanviar(DadesEstat &a, DadesEstat &b){
    DadesEstat temp=a;
    a=b;
    b=temp;
}

void Ordenar(DadesEstat estats[], int mode){
    bool hacanviat=true;
    acci� ordena(e/s a: VectorE; e n: enter)
{Pre: n>0 i n<=M�XIM i a=A}
{Post: a[1..n] est� ordenat i �s una
permutaci� de A[1..n]}
var i,j: enter fvar
 per i:= 1 fins n-1 fer
 per j:= n fins i+1, pas -1, fer
 si a[j]<a[j-1] llavors
 intercanviar(a[j],a[j-1])
 fsi
 fper
 fper
facci�



        while(hacanviat and){
            hacanviat=false;
            for(int i=0;i<US_STATES-1;i++){
                if(estats[i+1].Import[0]>estats[i].Import[0]){
                    Intercanviar(estats[i+1],estats[i]);
                    hacanviat=true;
}

int Cercar_Estat(DadesEstat estats[], string codi){
    bool trobat=false;
    int resultat;
    for(int i=0;i<US_STATES;i++){
        if(codi==estats[i].codi){
            resultat=i;
            trobat=true;
        }
    }
    if(!trobat) resultat=-1;
    return resultat;
}

int Determinar_trimestre(int data){
//Pre: Data correcte en format ISO-8601
//Post: Retorna el trimestre al qual correspon la data
    int trimestre;
    data%=10000;
    if(data<=331)trimestre=1;
    else if(data<=631)trimestre=2;
    else if(data<=930)trimestre=3;
    else if(data<=1231)trimestre=4; //no bounds check si l'entrada �s correcte, pot provocar escriptura fora de mem�ria
    return trimestre;
}

void Tractar_Entrada(DadesEstat estats[], DadesEnviaments entrada, int &ship_num, int &ship_err){
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

void Buscar_Totals(DadesEstat estats[]){
    for(int i=0;i<US_STATES;i++){
        for(int j=1;j<3;j++){
            estats[i].Import[0]+=estats[i].Import[j];
            estats[i].nombre_enviaments[0]+=estats[i].nombre_enviaments[j];
            estats[i].unitats_venudes[0]+=estats[i].unitats_venudes[j];
        }
    }
}

void Escriure_Informe(DadesEstat estats[], int mode){
     switch(mode){
    case 1:
        cout<<"=====[ Report A: Quarter values ]====="<<endl<<endl;
        //cout<<
        double popval;
        cout<<setprecision(USD_PRECISION)<<fixed;
        for(int i=0;i<US_STATES;i++){
            popval=estats[i].poblacio/estats[i].Import[0];
            cout<<estats[i].nom<<" "<<estats[i].poblacio<<" "<<setprecision(USD_PRECISION)<<estats[i].Import[0]<<" "<<estats[i].Import[1]<<" "<<estats[i].Import[2]<<" "<<estats[i].Import[3]<<" "<<estats[i].Import[4]<<" "<<setprecision(RATE_PRECISION)<<popval<<endl;
        }
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    }
}

void debug(DadesEstat estats[]){
    static int a;
    cout<<"pas a="<<a<<"val= "<<estats[0].Import[4]<<endl;
    a++;
}


int main()
{

    fstream f_cens, f_ship;
    string nomarxiu;
    DadesEstat estats[US_STATES+1], entrada;
    DadesEnviaments enviaments_entrada;
    int estats_registrats=0, shipment_num=0, shipment_erors=0, mode=1;

    if(ObrirFitxer(f_cens,US_CENSUS_2014))
    {
        EscriureCapcalera(US_CENSUS_2014,US_STATES,'S',"Census states");
        while(!f_cens.eof())
        {
            entrada=LlegirCens(f_cens);
            Inserir_Cens_Ordenat(estats, entrada, estats_registrats);
        }
        Escriure_Cens(estats);
        EscriurePeu();
        f_cens.close();

        NetejarTaules(estats);
        cout<<"USER INPUT: File name of shipments?"<<endl;
        nomarxiu=SHIPMENTS_2014; //cin>>nomarxiu;
        if (ObrirFitxer(f_ship,nomarxiu))
        {
            enviaments_entrada=Llegir_Enviaments(f_ship);
            while(not f_ship.eof())
            {
                //enviaments_entrada=Llegir_Enviaments(f_ship);
                // if(f_ship.eof())break;
                Tractar_Entrada(estats,enviaments_entrada,shipment_num,shipment_erors);
                enviaments_entrada=Llegir_Enviaments(f_ship);
            }

            cout<<"File "<<nomarxiu<<" loaded [ "<<shipment_num<<" records loaded with "<<shipment_erors<<" records omitted by error = "<<shipment_num-shipment_erors<<" ]"<<endl<<endl;
            cout<<"=====[ Report 2014 Video-Games Springfield <Begin> ]====="<<endl<<endl;
            //cout<<"
            Buscar_Totals(estats);
            Ordenar(estats,mode);
            Escriure_Informe(estats,mode);
        }
    }
    return 0;
}

