#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main () {
    cout<<"Ile wierzcholkow?";
    int r_;
    cin>>r_;
    int tab[2][r_+1];
    int nodes[r_+1];

    for(int i=0;i<r_+1;i++){
        tab[0][i]=9999;
        tab[1][i]=-1;
        nodes[i]=1;
    }
    tab[0][0]=0;

    int line[254];
    int r=0;
    char c;
    ifstream myfile ("graf.txt");
    if (myfile.is_open())
        while(myfile.get(c)){
            if(isdigit(c)){
                int x=0;
                line[r]=0;
                while(isdigit(c)){
                    line[r]*= pow(10,x);
                    line[r]+=c-48;
                    myfile.get(c);
                    x++;
                }
                myfile.seekg(-1,ios::cur);
                r++;
            }
        }
    else cout << "Unable to open file";
    myfile.close();

    for(int i=0;i<r;i++){
        cout<<line[i]<<" ";
    }
    //#######################################
    for(int i=0;i<r_;i++){
        int min=r_;
        for(int s=0;s<r_;s++){
            if(nodes[s]==1){
                if(tab[0][min]>tab[0][s]){
                    min=s;
                }
            }
        }
        cout<<min<<endl;
        for(int j=0;j<r;j++){
            int pop,nast,waga;
            if(j%3==0 and line[j]==min){
                pop=line[j];
                nast=line[j+1];
                waga=line[j+2];
                cout<<endl<<"---------------------";
                cout<<endl<<pop<<" "<<nast<<" "<<waga<<endl;
                if(tab[0][pop]+waga<tab[0][nast]){
                    tab[0][nast]=tab[0][pop]+waga;
                    tab[1][nast]=pop;
                }
                for(int k=0;k<r_;k++){
                    cout<<tab[0][k]<<" ";
                }
                cout<<endl;
                for(int k=0;k<r_;k++){
                    cout<<tab[1][k]<<" ";
                }
            }
        }
        nodes[min]=0;
    }
    //###################################

    cout<<endl<<"-------WYNIK-------"<<endl<<"V\t    | ";
    for(int k=0;k<r_;k++){
        cout<<k<<" ";
    }
    cout<<endl<<"d[v]\t| ";
    for(int k=0;k<r_;k++){
        cout<<tab[0][k]<<" ";
    }
    cout<<endl<<"p[v]\t|";
    for(int k=0;k<r_;k++){
        cout<<tab[1][k]<<" ";
    }

    return 0;
}
