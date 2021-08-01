#pragma once

#include "Header.h"

ref class Player : public Elem{
private:
	const int size = 30; 
	int x; 
	int y;
public:
	Player() {
		dir = zero;
		std::fstream in("level1.bin");
		if (!in.is_open()) {
			MessageBox::Show("File could not opened!");
		}
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				int temp; 
				in >> temp; 
				if (temp == 4) {
					x = j * 30 ; y = i * 30; 
				}
			}
		}
		in.close();
	}

	virtual void Draw(Graphics^ g) override {
		Bitmap^ img = gcnew Bitmap("perk.png"); 
		g->DrawImage(img, x, y);
	}

	virtual void Run () override {
		switch (dir)
		{
		case UP:
		{
			this->y -= 30; 
			break;
		}
		case DOWN:
		{
			this->y += 30; 
			break;
		}
		case RIGHT:
		{
			this->x += 30; 
			break;
		}
		case LEFT:
		{
			this->x -= 30;
			break;
		}
		default:
			break;
		}
	}	

	void RunBackPlayer() {
		switch (dir)
		{
		case UP:
		{
			this->y += 30;
			break;
		}
		case DOWN:
		{
			this->y -= 30;
			break;
		}
		case RIGHT:
		{
			this->x -= 30;
			break;
		}
		case LEFT:
		{
			this->x += 30;
			break;
		}
		default:
			break;
		}
	}

	int getX() {
		return this->x; 
	}

	int getY() {
		return this->y; 
	}
};