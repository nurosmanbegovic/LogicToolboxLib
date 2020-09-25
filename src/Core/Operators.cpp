//
// Created by infloop on 7/16/17.
//

#include "../../include/Operators.h"

bool Ness(World* starting_world, map<World*,bool> results, string m_logic){

    queue<World*> Q;
    vector<World*> children;
    map<World*, bool> visited;

    for(auto i: starting_world->getAdjacentList()) Q.push(i);

    for(auto i: starting_world->getAdjacentList()) Q.push(i);
    if(m_logic == "K4"){
        for(auto i: starting_world->getAdjacentList()){
            for(auto j: i->getAdjacentList()){
                Q.push(j);
            }
        }
    }

    while(!Q.empty()){

        World* t = Q.front();
        Q.pop();

        if(visited.find(t) == visited.end()) visited[t] = true;
        else if(visited[t]) continue;

        if(!results[t]) return false;

        if(m_logic == "D"){

            children = t->getAdjacentList();
            for(auto i : children) Q.push(i);

        }
    }

    return true;
}

bool Poss(World* starting_world, map<World*,bool> results, string m_logic){

    queue<World*> Q;
    vector<World*> children;
    map<World*, bool> visited;

    for(auto i: starting_world->getAdjacentList()) Q.push(i);
    if(m_logic == "K4"){
        for(auto i: starting_world->getAdjacentList()){
            for(auto j: i->getAdjacentList()){
                Q.push(j);
            }
        }
    }

    while(!Q.empty()){

        World* t = Q.front();
        Q.pop();

        if(visited.find(t) == visited.end()) visited[t] = true;
        else if(visited[t]) continue;

        if(results[t]) return true;

        if(m_logic == "D"){

            children = t->getAdjacentList();
            for(auto i : children) Q.push(i);

        }
    }

    return false;
}

bool Next(World* starting_world, map<World*,bool> results, string m_logic) {
    queue<World*> Q;

    for(auto i: starting_world->getAdjacentList()) Q.push(i);
    if(Q.empty()) return true;    

        World* t = Q.front();
        Q.pop();

        if(results[t]) return true;
        else return false;
}

bool All(World* starting_world, map<World*,bool> results, string m_logic) {    
    queue<World*> Q;
    World* it=starting_world;
    Q.push(starting_world);

    while(!(it->getAdjacentList().empty())){
        for(auto i: it->getAdjacentList()){
            Q.push(i);
        }
        it=(it->getAdjacentList())[0];
    }

    while(!Q.empty()){
        World* t = Q.front();
        Q.pop();
        if(!results[t]) return false;
    }

    return true;

}

bool Some(World* starting_world, map<World*,bool> results, string m_logic) {
    queue<World*> Q;
    World* it=starting_world;
    Q.push(starting_world);

    while(!(it->getAdjacentList().empty())){
        for(auto i: it->getAdjacentList()){
            Q.push(i);
        }
        it=(it->getAdjacentList())[0];
    }

    while(!Q.empty()){
        World* t = Q.front();
        Q.pop();
        if(results[t]) return true;
    }
    
    return false;

}

bool Until(World* starting_world, map<World*,bool> leftresult, map<World*,bool> rightresult, string m_logic){
    queue<World*> Q;
    World* it=starting_world;
    Q.push(starting_world);

    while(!(it->getAdjacentList().empty())){
        for(auto i: it->getAdjacentList()){
            Q.push(i);
        }
        it=(it->getAdjacentList())[0];
    }

    while(!Q.empty()){
        World* t = Q.front();
        Q.pop();
        if(!leftresult[t] && rightresult[t]) return true;
        else if((!leftresult[t] && !rightresult[t]) || (leftresult[t] && rightresult[t])) return false;
    }
    
    return false;

}

bool Unless(World* starting_world, map<World*,bool> leftresult, map<World*,bool> rightresult, string m_logic){
    queue<World*> Q;
    World* it=starting_world;
    Q.push(starting_world);

    while(!(it->getAdjacentList().empty())){
        for(auto i: it->getAdjacentList()){
            Q.push(i);
        }
        it=(it->getAdjacentList())[0];
    }

    while(!Q.empty()){
        World* t = Q.front();
        Q.pop();
        if(!leftresult[t] && rightresult[t]) return true;
        else if((!leftresult[t] && !rightresult[t]) || (leftresult[t] && rightresult[t])) return false;
    }
    
    return true;
}

bool Operator(Token op, bool x, bool y) {
    if (op.type != TokenType::BINARY_OP) throw logic_error("Passed token is not binary operator!");
    if (op.value == "AND") return And(x,y);
    if (op.value == "OR") return Or(x,y);
    if (op.value == "NAND") return Nand(x,y);
    if (op.value == "NOR") return Nor(x,y);
    if (op.value == "XOR") return Xor(x,y);
    if (op.value == "IMPL") return Impl(x,y);
    if (op.value == "EQU") return Equ(x,y);
    throw logic_error("Something unexpected happened!");
}


bool Operator(World* world, map<World*, bool> resutls, Token op, string m_logic) {
    if(op.type != TokenType::UNARY_OP || op.value == "NOT") throw logic_error("Passed token is not Poss, Ness, Next, Some or All!");
    if(op.value == "POSS") return Poss(world,resutls,m_logic);
    if(op.value == "NESS") return Ness(world, resutls,m_logic);
    if(op.value == "NEXT") return Next(world, resutls, m_logic);
    if(op.value == "ALL") return All(world, resutls, m_logic);
    if(op.value == "SOME") return Some(world, resutls, m_logic);

    throw logic_error("Something unexpected happened!");
}

bool Operator(World* world, map<World*, bool> leftresult, map<World*, bool> rightresult, Token op, string m_logic){
    if(op.type != TokenType::BINARY_OP_TEMP) throw logic_error("Passed token is not Until or Unless!");
    if(op.value == "UNTIL") return Until(world, leftresult, rightresult, m_logic);
    if(op.value == "UNLESS") return Unless(world, leftresult, rightresult, m_logic);

    throw logic_error("Something unexpected happened!");
}
 