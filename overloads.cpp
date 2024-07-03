using namespace pgm;

bool operator<(const Node& a, const Node& b){
    if(a.name != b.name){
        return a.name < b.name;
    }
    return a.observation < n.observation;
}

bool operator==(const Node& a, const Node& b){
    return a.name == b.name && a.values == b.values;
}