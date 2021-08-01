#pragma once

#pragma once
#include <Windows.h>
#include <fstream>

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


Direction dir; 

public ref class Elem abstract {
public:
	virtual void Draw(Graphics^ g) {

	}
	virtual void Run() {

	}
};

bool FileExists(const char* fileName)
{
	std::ifstream infile(fileName);
	return infile.good();
}