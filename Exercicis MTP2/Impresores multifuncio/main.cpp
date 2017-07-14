#include <iostream>

using namespace std;

struct Impresora{
    string model;
    double preu_cost, preu_copia;
    bool color, doblecara, grapat;
};

void Mostrar(Impresora I[], int impr){
    cout<<"- MODEL: "<<I[impr].model<<endl<<
    "- PREU COST: "<<I[impr].preu_cost<<endl<<
    "- PREU PER COPIA: "<<I[impr].preu_copia<<endl<<
    "- COLOR: "<<boolalpha<<I[impr].color<<endl<<
    "- DOBLE CARA: "<<boolalpha<<I[impr].doblecara<<endl<<
    "- GRAPAT: "<<boolalpha<<I[impr].grapat<<endl;
}

void Actualitzar_Dades(bool &alguntrobat, int actual, int &coincidencies, double &cost_minim, double &copia_minim, int  &millor_impr_preu, int &millor_impr_copia, Impresora *p){
    alguntrobat=true;
    coincidencies++;
    if(p->preu_cost<cost_minim){
        cost_minim=p->preu_cost;
        millor_impr_preu=actual;
    }
    if(p->preu_copia<copia_minim){
        copia_minim=p->preu_copia;
        millor_impr_copia=actual;
    }
}

int main()
{
    int num_actual=0, coincidencies=0, millor_impr_preu, millor_impr_copia;
    char funcions_impresora, tempcol, tempcar, tempgrap;
    bool alguntrobat=false;
    double cost_minim=0xFFFF, copia_minim=cost_minim;
    Impresora Impresores[1000], temp, *p;
    cout.setf(ios::fixed);
    cout.precision(2);
    cout<<"ESCOLLIM MILLOR OPCIO SEGONS:"<<endl<<
    "(c) IMPRESSIO EN COLOR"<<endl<<
    "(d) IMPRESSIO A DOBLE CARA"<<endl<<
    "(g) GRAPAT AUTOMATIC"<<endl<<
    "(t) LES TRES COSES"<<endl;
    cin>>funcions_impresora;
    cout<<"ENTRA ESPECIFICACIONS ACABANT AMB MODEL #"<<endl;
    cout<<"MODEL, PREU COST, PREU PER COPIA, s/n COLOR , s/n DOBLE CARA , s/n GRAPAT"<<endl;

    do{
        cin>>temp.model;
        temp.color=false; temp.doblecara=false; temp.grapat=false;
        if(temp.model!="#"){
            cin>>temp.preu_cost>>temp.preu_copia>>tempcol>>tempcar>>tempgrap;
            if(tempcol=='s')temp.color=true;
            if(tempcar=='s')temp.doblecara=true;
            if(tempgrap=='s')temp.grapat=true;
            Impresores[num_actual]=temp;
            num_actual++;
        }
    }while(temp.model!="#");

    for(int i=0;i<num_actual;i++){
        p=&Impresores[i];
        switch(funcions_impresora){
        case 'c':
            if(p->color)
            Actualitzar_Dades(alguntrobat,i,coincidencies,cost_minim,copia_minim,millor_impr_preu,millor_impr_copia,p);
            break;
        case 'd':
            if(p->doblecara)
            Actualitzar_Dades(alguntrobat,i,coincidencies,cost_minim,copia_minim,millor_impr_preu,millor_impr_copia,p);
            break;
        case 'g':
            if(p->grapat)
            Actualitzar_Dades(alguntrobat,i,coincidencies,cost_minim,copia_minim,millor_impr_preu,millor_impr_copia,p);
            break;
        case 't':
            if(p->color && p->doblecara && p->grapat)
            Actualitzar_Dades(alguntrobat,i,coincidencies,cost_minim,copia_minim,millor_impr_preu,millor_impr_copia,p);
            break;
        }
    }

    if(alguntrobat){
        cout<<"S'HAN TROBAT "<<coincidencies<<" MODELS ADIENTS"<<endl;
        cout<<"EL MODEL AMB MILLOR PREU DE COST ES:"<<endl;
        Mostrar(Impresores,millor_impr_preu);
        cout<<"EL MODEL AMB MILLOR PREU PER COPIA ES:"<<endl;
        Mostrar(Impresores,millor_impr_copia);
    }
    else{
        cout<<"NO S'HA TROBAT CAP MULTIFUNCIO AMB LES FUNCIONALITATS REQUERIDES"<<endl;
    }
    return 0;
}
