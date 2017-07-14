#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef int codi_assignatura;
typedef string alumne;
typedef int dni_al;
typedef int nota;

struct assignatura{
    assignatura(string a, int c, int d=1):nom(a),num_credits(c){num_grups=d;};
    string nom;
    int num_credits, num_grups;
};

//! a millorar: metode const, const_it, .find()->first en comptes de []

void llistarMaria(map<codi_assignatura, assignatura> &assignatures,
    map<dni_al,map<codi_assignatura, nota> > &mat_alumnes){
    int total, aprovats, mitjana; //total matriculats/aprovats en una assignatura

    for(map<codi_assignatura, assignatura>::iterator i=assignatures.begin();i!=assignatures.end();i++){
        total=aprovats=mitjana=0;
        for(map<dni_al,map<codi_assignatura, nota> >::iterator i2=mat_alumnes.begin();i2!=mat_alumnes.end();i2++){
            map<codi_assignatura, nota>::iterator nota_ass=i2->second.find(i->first);
            if(nota_ass!=i2->second.end() and nota_ass->second>=50){
                mitjana+=nota_ass->second;
                aprovats++;
            }
            total++; //només s'ha de fer si l'alumne està realment inscrit en l'assignatura
        }
        if((float)aprovats/total>0.8){
            cout<<i->first<<" "<<i->second.nom<<" "<<i->second.num_credits<<endl;
            cout<<total<<" "<<(float)mitjana/total<<endl;
        }
    }
}

void mostrarOverbooking(codi_assignatura c, map<dni_al,alumne> &alumnes,
    map<codi_assignatura, assignatura> &assignatures,
    map<dni_al,map<codi_assignatura, nota> > &mat_alumnes){
    int numalumnes=0;
    vector<alumne> alums;
    map<codi_assignatura, assignatura>::iterator f=assignatures.find(c);

    for(map<dni_al,alumne>::iterator i=alumnes.begin();i!=alumnes.end();i++){
        map<codi_assignatura, nota>::iterator trobat = mat_alumnes[i->first].find(c);
        if(trobat!=mat_alumnes[i->first].end()){
            numalumnes++;
            alums.push_back(i->second);
        }
    }
    if(numalumnes/f->second.num_grups>3){
        cout<<f->second.nom<<" "<<f->second.num_grups<<endl;
        for(vector<alumne>::iterator i=alums.begin();i!=alums.end();i++)
            cout<<*i<<endl;
    }
    else cout<<"L'assignatura no te overbooking"<<endl;
}

int main()
{
    map<dni_al,alumne> alumnes;
    map<codi_assignatura, assignatura> assignatures;
    map<dni_al,map<codi_assignatura, nota> > mat_alumnes;

    alumnes.insert(pair<dni_al,alumne>(123,"Pere Pi"));
    alumnes.insert(pair<dni_al,alumne>(124,"Manel Font"));
    alumnes.insert(pair<dni_al,alumne>(125,"Ester Boada"));
    alumnes.insert(pair<dni_al,alumne>(126,"Marta Morales"));
    alumnes.insert(pair<dni_al,alumne>(127,"Pau Gasoil"));

    assignatures.insert(pair<codi_assignatura,assignatura>(1,assignatura("EDA",9)));
    assignatures.insert(pair<codi_assignatura,assignatura>(2,assignatura("BD",6)));
    assignatures.insert(pair<codi_assignatura,assignatura>(3,assignatura("SD",6)));
    assignatures.insert(pair<codi_assignatura,assignatura>(4,assignatura("EST",6)));

    map<codi_assignatura, nota> t;

    t.insert(pair<codi_assignatura, nota>(1,70));
    t.insert(pair<codi_assignatura, nota>(2,50));
    t.insert(pair<codi_assignatura, nota>(3,60));
    t.insert(pair<codi_assignatura, nota>(4,80));
    mat_alumnes.insert(pair<dni_al,map<codi_assignatura, nota> >(123,t));

    t.clear();
    t.insert(pair<codi_assignatura, nota>(1,30));
    t.insert(pair<codi_assignatura, nota>(2,20));
    t.insert(pair<codi_assignatura, nota>(3,90));
    t.insert(pair<codi_assignatura, nota>(4,100));
    mat_alumnes.insert(pair<dni_al,map<codi_assignatura, nota> >(124,t));

    t.clear();
    t.insert(pair<codi_assignatura, nota>(4,60));
    mat_alumnes.insert(pair<dni_al,map<codi_assignatura, nota> >(125,t));

    t.clear();
    t.insert(pair<codi_assignatura, nota>(4,70));
    mat_alumnes.insert(pair<dni_al,map<codi_assignatura, nota> >(126,t));

    t.clear();
    t.insert(pair<codi_assignatura, nota>(4,65));
    mat_alumnes.insert(pair<dni_al,map<codi_assignatura, nota> >(127,t));

    llistarMaria(assignatures,mat_alumnes);
    mostrarOverbooking(4,alumnes,assignatures,mat_alumnes);

    return 0;
}
