#pragma once
#include <vector>
#include <memory>

enum Team{Red,Blue,Green,Yellow,Neutral};

class Node{
public:
	Node();
	std::vector<std::unique_ptr<Node>> neighbours;
	Team team;
};

