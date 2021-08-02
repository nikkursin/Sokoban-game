#pragma once

#include "Header.h"


value struct Coords {
	int x;
	int y;
	bool delivered; 
}; 


ref class Box :  Elem {
private: 
	int amount; 
	array< Coords >^ boxes = gcnew array< Coords >(amount); 

public:
	Box() {
		this->amount = 0; 
		std::fstream in("Map_files/level" + std::to_string(current_level) + ".bin");
		if (!in.is_open()) {
			MessageBox::Show("File could not opened!");
		}
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				int temp;
				in >> temp; 
				if (temp == 2) {
					this->push_back(j * 30, i * 30); 
					amount++;
				}
			}
		}
		in.close();
	}

	void push_back( int a, int b) {
		array <Coords>^ temp = gcnew array <Coords>(amount + 1);
		for (int i = 0; i < amount; i++) {
			temp[i].x = boxes[i].x; 
			temp[i].y = boxes[i].y;
		}
		temp[amount].x = a; 
		temp[amount].y = b;
		delete[]boxes;
		boxes = temp; 
	}

	virtual void Draw (Graphics^ g) override {
		SolidBrush^ GreenPen = gcnew SolidBrush(Color::LightGreen);
		SolidBrush^ BrickPen = gcnew SolidBrush(Color::Firebrick);
		Pen^ pen = gcnew Pen(Color::DarkGray, 2);
		for (int i = 0; i < amount; i++){
			if (boxes[i].delivered) {
				if (FileExists("Textures/box3.png")) {
					Bitmap^ img = gcnew Bitmap("Textures/box3.png");
					g->DrawImage(img, boxes[i].x, boxes[i].y);
				}
				else {
					SolidBrush^ box_green = gcnew SolidBrush(Color::SlateGray);
					g->FillRectangle(box_green, boxes[i].x + 5, boxes[i].y + 5, 20, 20);
				} 
			}
			else {
				if (FileExists("Textures/box2.png")) {
					Bitmap^ img = gcnew Bitmap("Textures/box2.png");
					g->DrawImage(img, boxes[i].x, boxes[i].y);
				}
				else {
					SolidBrush^ box_default = gcnew SolidBrush(Color::DimGray);
					g->FillRectangle(box_default, boxes[i].x + 5, boxes[i].y + 5, 20, 20);
				} 
			}
		}
	}

	int get_amount() {
		return amount; 
	}

	int elem_getX(int i) {
		return boxes[i].x; 
	}

	int elem_getY(int i) {
		return boxes[i].y;
	}

	void RunBox(int i) {
		switch (dir)
		{
		case UP:
		{
			boxes[i].y -= CONST_SPEED;
			break;
		}
		case DOWN:
		{
			boxes[i].y += CONST_SPEED;
			break;
		}
		case RIGHT:
		{
			boxes[i].x += CONST_SPEED;
			break;
		}
		case LEFT:
		{
			boxes[i].x -= CONST_SPEED;
			break;
		}
		default:
			break;
		}
	}

	void RunBackBox(int i) {
		switch (dir)
		{
		case UP:
		{
			boxes[i].y += CONST_SPEED;
			break;
		}
		case DOWN:
		{
			boxes[i].y -= CONST_SPEED;
			break;
		}
		case RIGHT:
		{
			boxes[i].x -= CONST_SPEED;
			break;
		}
		case LEFT:
		{
			boxes[i].x += CONST_SPEED;
			break;
		}
		default:
			break;
		}
	}

	bool get_delivered(int i) {
		return boxes[i].delivered;
	}

	void set_delivered(int i) {
		boxes[i].delivered = true; 
	}

	bool targeted() {
		for (int i = 0; i < amount; i++) {
			if (boxes[i].delivered);
			else return false; 
		}
		return true; 
	}
};

