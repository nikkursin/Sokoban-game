#pragma once

#pragma once
#include <Windows.h>
#include <fstream>

using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Data;
using namespace System::Collections;


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