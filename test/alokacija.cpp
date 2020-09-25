#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include "../include/World.h"
#include "../include/Variable.h"
#include "../include/Universe.h"
#include "../include/CoreEvaluator.h"
#include "../include/ResultTree.h"
bool valid (false);
std::vector<Variable> varijable;


enum class GroundRobot {Gore, Dolje, Lijevo, Desno, GoreLijevo, GoreDesno, DoljeLijevo, DoljeDesno};
enum class FlyingRobot {Gore, Dolje, Lijevo, Desno};

bool DozvoljenKorak(int x, int iteracija ){
    std::string izraz;
    if(iteracija==1) izraz="<a";
    else if(iteracija==2) izraz="a>*b";
    else if(iteracija==3) izraz="(a>*b)>*c";
    else if(iteracija==4) izraz=("((a>*b)>*c)>*d");

    varijable[x-1].setValue(true);

    World* w1= new World("w1");
    w1->setVariables(varijable);
    World* w2= new World("w2");
    w2->setVariables(varijable);
    World* w3= new World("w3");
    w3->setVariables(varijable);
    World* w4= new World("w4");
    w4->setVariables(varijable);
    
    w1->addAdjacent(w2);
    w2->addAdjacent(w3);
    w3->addAdjacent(w4);

    std::vector<World*> worlds;
    worlds.push_back(w1);
    worlds.push_back(w2);
    worlds.push_back(w3);
    worlds.push_back(w4);

    Universe* univerzum = new Universe("univerzum");
    std::vector<string> variablenames = {"a", "b", "c", "d"};
    univerzum->setWorlds(worlds);
    univerzum->setVariableNames(variablenames);

    ResultTree* resultTree = new ResultTree(univerzum, izraz);
    map<World*, bool> results = resultTree->getFinalResult(); 

    for(int i(0); i<worlds.size();i++){
        if(!(results[worlds[i]])) {
            varijable[x-1].setValue(false);
            std::cout<<"Nije moguce obaviti task " + to_string(x);
            return false;
        }
    }

    std::cout<<"moguce je obaviti task" + to_string(x);

    if(iteracija==4) {
        std::cout<<"izvrsen je cetvrti zadatak";
        valid= true;
        }
    
    return true;
}




void Simulation() {
    std::vector<std::vector<int>> Ploca(8);
    for(int i(0); i<8; i++) Ploca.resize(8);
    int xg(0);
    int yg(7);
    int xf(0);
    int yf(0);
    int dodatakxg=1;
    int dodatakyg=1;
    int dodatakxf=1;
    int dodatakyf=1;
    int iteracija(0);

    Variable* prvi = new Variable("a");
    prvi->setValue(false);
    Variable* drugi = new Variable("b");
    drugi->setValue(false);
    Variable* treci= new Variable("c");
    treci->setValue(false);
    Variable* cetvrti= new Variable("d");
    cetvrti->setValue(false);

    varijable.push_back(*prvi);
    varijable.push_back(*drugi);
    varijable.push_back(*treci);
    varijable.push_back(*cetvrti);
    
    for(int i(0); i<8; i++){
        for(int j(0); j<8; j++) {
            if(i==2 && j==2) Ploca[i][j]=1;
            else if(i==2 && j==5) Ploca[i][j]=2;
            else if(i==5 && j==2) Ploca[i][j]=3;
            else if(i==5 && j==5) Ploca[i][j]=4;
            else Ploca[i][j]=0;
        }
    }
    
    while(!valid){
        if(xg+dodatakxg>7 || xg+dodatakxg<0) dodatakxg=dodatakxg*(-1);
        if(yg+dodatakyg>7 || yg+dodatakyg<0) dodatakyg=dodatakyg*(-1);
        if(Ploca[xg+dodatakxg][yg+dodatakyg]==0 || Ploca[xg+dodatakxg][yg+dodatakyg]<=iteracija){
            xg=+dodatakxg;
            yg=+dodatakyg;
        }
        else{
            if(DozvoljenKorak(Ploca[xg+dodatakxg][yg+dodatakyg], iteracija+1)){
                xg=+dodatakxg;
                yg=+dodatakyg;
                iteracija++;
            }
            else{
                xg=+(dodatakxg*2);
                yg=+(dodatakyg*2);
            }
        }
        if(xf+dodatakxf>7 || xf+dodatakxf<0) dodatakxf=dodatakxf*(-1);
        if(yf+dodatakyf>7 || yf+dodatakyf<0) dodatakyf=dodatakyf*(-1);
        if(Ploca[xf+dodatakxf][yg+dodatakyf]==0 || Ploca[xf+dodatakxf][yf+dodatakyf]<=iteracija){
            xf=+dodatakxf;
            yf=+dodatakyf;
        }
        else{
            if(DozvoljenKorak(Ploca[xf+dodatakxf][yf+dodatakyf], iteracija+1)){
                xf=+dodatakxf;
                yf=+dodatakyf;
                iteracija++;
            }
            else{
                xf=+(dodatakxf*2);
                yf=+(dodatakyf*2);
            }
        }
        
    }
}

