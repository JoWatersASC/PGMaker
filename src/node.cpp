#include"..\include\node.h"

namespace pgm{
    Node::Node() : name("Variable"), values({"true", "false"}){}
    Node::Node(std::string name) : name(name), values({"true", "false"}){}

    std::string Node::getName(){
        return name;
    }

    std::vector<std::string>& Node::getValues(){
        return values;
    }
}