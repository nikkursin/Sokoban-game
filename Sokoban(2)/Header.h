#pragma once

#pragma once

#include <Windows.h>
#include <fstream>
#include <string>


using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Data;
using namespace System::Collections;


#define CONST_SPEED 30

enum Direction {
	UP,
	DOWN,
	RIGHT,
	LEFT,
	zero
};

int cur_pos_X; 
int cur_pos_Y;

bool side_val; 

Direction dir; 

int current_level;

public ref class Elem abstract {
public:
	virtual void Draw(Graphics^ g) {

	}
	virtual void Run() {

	}

	bool FileExists(const char* fileName)
	{
		std::ifstream infile(fileName);
		return infile.good();
	}
};



