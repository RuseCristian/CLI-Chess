#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
//#######################################################################
//##################Joc creat de Ruse Cristian###########################
//#######################################################################

using namespace std;
int x,y,x1,y1,t=1,ui=0,regeT=2,inpt,nrmutari=0;

class piese {
  public:
    int Echipa;
    int ID;
    int PozitieX;
    int PozitieY;
};

piese piesa[66];

int x_y(int y3,int x3){
for(int i=1;i<65;i++)
    if(piesa[i].PozitieY==y3 and piesa[i].PozitieX==x3)
        return i;
}

int desen(int i){
if(i==1 or i==8){
    std::wcout<<L"♜  ";
    return 0;
    }
if(i==2 or i==7){
    std::wcout<<L"♞  ";
    return 0;
    }
if(i==3 or i==6){
    std::wcout<<L"♝  ";
    return 0;
    }
if(i==4){
    std::wcout<<L"♛  ";
    return 0;
    }
if(i==5){
    std::wcout<<L"♚  ";
    return 0;
    }
if(i>8 and i<17){
    std::wcout<<L"♟  ";
    return 0;
    }
if(i==0){
    std::wcout<<"   ";
    return 0;
    }
if(i>48 and i<57){
    std::wcout<<L"♙  ";
    return 0;
    }
if(i==57 or i==64){
    std::wcout<<L"♖  ";
    return 0;
    }
if(i==58 or i==63){
    std::wcout<<L"♘  ";
    return 0;
    }
if(i==59 or i==62){
    std::wcout<<L"♗  ";
    return 0;
    }
if(i==60){
    std::wcout<<L"♕  ";
    return 0;
    }
if(i==61){
    std::wcout<<L"♔  ";
    return 0;
    }
}

int tabla(){
std::wcout<<endl<<"      _____ _____ _____ _____ _____ _____ _____ _____ ";
for(int i=8; i>0; i--){
    if(ui==1)
        std::wcout<<endl<<"     |"<<i<<"1   |"<<i<<"2   |"<<i<<"3   |"<<i<<"4   |"<<i<<"5   |"<<i<<"6   |"<<i<<"7   |"<<i<<"8   |";
    else
        std::wcout<<endl<<"     |     |     |     |     |     |     |     |     |";
    std::wcout<<endl<<"  "<<i<<"  ";
    for(int j=1;j<=8;j++){
        std:wcout<<"|  ";
        desen(piesa[x_y(i,j)].ID);
        }
    std::wcout<<"|"<<endl<<"     |_____|_____|_____|_____|_____|_____|_____|_____|";
        if(i==4)
            std::wcout<<"               Nr. Mutari: "<<nrmutari;
    }
std::wcout<<endl<<endl<<"        1     2     3     4     5     6     7     8   "<<endl<<endl;

}

int transformare(){
int p;
if(t==1){
    std::wcout<<endl<<"In ce piesa vrei sa transformi pionul ?"<<endl<<"Index :"<<endl<<" 1 = tura"<<endl<<" 2 = cal"<<endl<<" 3 = nebun"<<endl<<" 4 = regina"<<endl;
    while(p!=1 and p!=2 and p!=3 and p!=4){
        cin>>p;
        if(p!=1 and p!=2 and p!=3 and p!=4)
            std::wcout<<endl<<"Ai introdus un numar gresit,introdu din nou din numerele alese"<<endl;
        else
            break;}
    piesa[x_y(y,x)].ID=p;
    return 1;
    }
if(t==2){
    std::wcout<<endl<<"In ce piesa vrei sa transformi pionul ?"<<endl<<"Index :"<<endl<< " 57 = tura"<<endl<<" 58 = cal"<<endl<<" 59 = nebun"<<endl<<" 60 = regina"<<endl;
    while(p!=57 and p!=59 and p!=60 and p!=58){
        cin>>p;
        if(p!=57 and p!=58 and p!=59 and p!=60)
            std::wcout<<endl<<"Ai introdus un numar gresit,introdu din nou din numerele alese"<<endl;
        else
            break;
        }
    piesa[x_y(y,x)].ID=p;
    }
}

int pion(){
if(piesa[x_y(y,x)].Echipa==1){
    if(y==2 and y1==4 and x==x1 and piesa[x_y(3,x)].Echipa==3 and piesa[x_y(4,x)].Echipa==3)
        return 1;
    if(y1>y and y1==y+1 and x==x1 and piesa[x_y(y1,x1)].Echipa==3)
        if(y1==8){
            transformare();
            return 1;}
        else
            return 1;
    if(y1>y and y1==y+1 and abs(x-x1)==1 and piesa[x_y(y1,x1)].Echipa==2)
        if(y1==8){
            transformare();
            return 1;}
        else
            return 1;
    }
if(piesa[x_y(y,x)].Echipa==2){
    if(y==7 and y1==5 and x==x1 and piesa[x_y(6,x)].Echipa==3 and piesa[x_y(5,x)].Echipa==3)
        return 1;
    if(y1<y and y1==y-1 and x==x1 and piesa[x_y(y1,x1)].Echipa==3)
        if(y1==1){
            transformare();
            return 1;}
        else
            return 1;
    if(y1<y and y1==y-1 and abs(x-x1)==1 and piesa[x_y(y1,x1)].Echipa==1)
        if(y1==1){
            transformare();
            return 1;}
        else
            return 1;
    }
return 0;

}

int cal(){
if(piesa[x_y(y1,x1)].Echipa!=t and ((abs(y-y1)==2 and abs(x-x1)==1) or (abs(y-y1)==1 and abs(x-x1==2))))
    return 1;
else
    return 0;
}

int rege(){
if((abs(x-x1)==1 or abs(y-y1)==1) and piesa[x_y(y1,x1)].Echipa!=t)
    return 1;
}

int tura(){
if(y!=y1 and x!=x1)
   return 0;
if(x1>x and y==y1)
    for(int i=x+1;i<x1;i++)
        if(piesa[x_y(y,i)].Echipa==1 or piesa[x_y(y,i)].Echipa==2)
            return 0;
if(x>x1 and y==y1)
    for(int i=x-1;i>x1;i--)
        if(piesa[x_y(y,i)].Echipa==1 or piesa[x_y(y,i)].Echipa==2)
            return 0;
if(y>y1 and x1==x)
    for(int i=y-1;i>y1;i--)
        if(piesa[x_y(i,x)].Echipa==1 or piesa[x_y(i,x)].Echipa==2)
            return 0;
if(y1>y and x1==x)
    for(int i=y+1;i<y1;i++)
        if(piesa[x_y(i,x)].Echipa==1 or piesa[x_y(i,x)].Echipa==2)
            return 0;
if(piesa[x_y(y1,x1)].Echipa!=t)
    return 1;
else
    return 0;
}

int nebun(){
if(abs(x-x1)!=abs(y-y1))
   return 0;
if(x1>x and y1>y)
    for(int i=x+1, j=y+1;i<x1;i++,j++)
        if(piesa[x_y(j,i)].Echipa==1 or piesa[x_y(j,i)].Echipa==2)
            return 0;
if(x>x1 and y>y1)
    for(int i=x-1,j=y-1;i>x1;i--,j--)
        if(piesa[x_y(j,i)].Echipa==1 or piesa[x_y(j,i)].Echipa==2)
           return 0;
if(y>y1 and x1>x)
    for(int i=y-1,j=x+1;i>y1;i--,j++)
        if(piesa[x_y(i,j)].Echipa==1 or piesa[x_y(i,j)].Echipa==2)
            return 0;
if(y1>y and x1<x)
    for(int i=y+1,j=x-1;i<y1;i++,j--)
        if(piesa[x_y(i,j)].Echipa==1 or piesa[x_y(i,j)].Echipa==2)
            return 0;
if(piesa[x_y(y1,x1)].Echipa!=t)
    return 1;
else
    return 0;
}

int regina(){
if(x==x1 or y==y1)
    tura();
else
    nebun();
}

void mutare(){
int e=x_y(y,x),u=(x_y(y1,x1));
piesa[u].ID=piesa[e].ID;
piesa[u].Echipa=piesa[e].Echipa;
piesa[e].ID=0;
piesa[e].Echipa=3;
nrmutari++;
if(t==1)
    t=2;
else
    t=1;
std::wcout<<"Mutare valida.";
sleep(1.5);
system("cls");
}

int imposibil(){
std:wcout<<"Mutarea nu este legala!";
sleep(1.5);
system("cls");
}

int verificare(int i){
if((i>8 and i<18) or (i>48 and i<57)){
    return pion()==1;}
if(i==2 or i==7 or i==58 or i==64)
    return cal()==1;
if(i==5 or i==61)
    return rege()==1;
if(i==1 or i==8 or i==57 or i==64)
    return tura()==1;
if(i==3 or i==6 or i==59 or i==62)
    return nebun()==1;
if(i==4 or i==60)
    return regina()==1;
}

int ajutor(){
char et[1];
while(et[0]!='p'){
std::wcout<<endl<<endl<<"Fontul consolei trebuie sa fie SimSun-ExtB pentru a afisa corect caracterele unicode."<<endl<<"Format coodoronate (y,x) ---> (y,x) , exemplu 1725 reprezinta (1,7) ---> (2,5)"<<endl<<endl<<"Alege o Actiune:"<<endl<<endl<<"* q: inchide jocul "<<endl<<"* p: incepe jocul"<<endl<<"* c: arata coodronate in interiorul patratelor "<<endl<<endl;
cin>>et;
if(et[0]=='q')
    return 0;
if(et[0]=='c')
    ui=1;
system("cls");}
}

int main(){
_setmode(_fileno(stdout), 0x00020000);
int lat=1,lon=1;

for(int i=1;i<=64;i++){
    if(i<17)
        piesa[i].Echipa=1;
    if(i>16 and i<49)
        piesa[i].Echipa=3;
    if(i>48)
        piesa[i].Echipa=2;
    if(i>16 and i<49)
        piesa[i].ID=0;
    else
        piesa[i].ID=i;
    piesa[i].PozitieY=lon;
    piesa[i].PozitieX=lat;
    if(i==8 or i==16 or i==24 or i==32 or i==40 or i==48 or i==56){
        lon++;
        lat=1;}
    else
        lat++;
    }
if(ajutor()==0)
    return 0;

while(true){
    for(int i=1;i<33;i++)
        if(piesa[i].ID==5 or piesa[i].ID==61)
            regeT++;
    tabla();
    std::wcout<<"Mutare"<<endl;
    if(t==1)
        std::wcout<<"Echipa Alba: ";
    else
        std::wcout<<"Echipa Neagra: ";
    cin>>inpt;
    x1=inpt%10,inpt=inpt/10,y1=inpt%10,inpt=inpt/10,x=inpt%10,inpt=inpt/10,y=inpt;
    if(x<0 or x>8 or y<0 or y>8 or x1<0 or x1>8 or y1<0 or y1>8 or (x==x1 and y==y1)){
        imposibil();
        continue;}

    if(verificare(piesa[x_y(y,x)].ID)==1 and piesa[x_y(y,x)].Echipa==t)
        mutare();
    else
        imposibil();
    }
if(t==1){
    system("cls");
    std::wcout<<"Echipa Neagra a castigat";
    cin.get();
    return 0;
    }
else{
    system("cls");
    std::wcout<<"Echipa Alba a castigat";
    cin.get();
    return 0;
    }

}


