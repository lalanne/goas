
#include "Relation.hpp"
#include "Record.hpp"

#include <iostream>
#include <algorithm>

using namespace std;

bool Relation::operator==(const Relation& y) const{
    cout<<"size: "<<records.size()<<endl;
    cout<<"size y: "<<y.records.size()<<endl;

    return records == y.records;
}

void Relation::add_record(Record rec){
    this->records.push_back(rec);
}

/*is returning a pointer because other classes store
 * a pointer to a unique meta object, this is the more
 * performant option that I found, not a nice design though*/
Meta Relation::get_meta(){
    return meta;        
}

void Relation::set_size(){
    records.reserve(meta.rows());    
}

void Relation::print() const{
    meta.print();
    cout<<endl;
    
    for(auto& i:records){
        i.print();    
    }
    cout<<"("<<meta.rows()<<" rows)"<<endl;
}



