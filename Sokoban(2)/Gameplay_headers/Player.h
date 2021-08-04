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
		side_val = true; 
		std::fstream in("Map_files/level" + std::to_string(current_level) + ".bin");
		if (!in.is_open()) {
			MessageBox::Show("File could not opened!");
		}
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				int temp; 
				in >> temp; 
				if (temp == 4) {
					x = j * 30;
					y = i * 30;
				}
			}
		}
		in.close();
	}

	virtual void Draw(Graphics^ g) override {		
		if (FileExists("Textures/character.png") && FileExists("Textures/character_reversed.png")){
			//System::String^ temp = gcnew System::String(texture_img.c_str()); 
			Bitmap^ img;
			if (side_val) {
				Bitmap^ tmp = gcnew Bitmap("Textures/character.png");
				img = gcnew Bitmap(tmp, 30, 30);
			}
			else if (!side_val) {
				Bitmap^ tmp = gcnew Bitmap("Textures/character_reversed.png");
				img = gcnew Bitmap(tmp, 30, 30);
			}	
			g->DrawImage(img, x, y);
		}
		else {
			//MessageBox::Show("Character picture couldn`t found!");
			SolidBrush^ character = gcnew SolidBrush(Color::DimGray);
			g->FillEllipse(character, x + 10 , y + 5, 20, 20);
		}
	}

	virtual void Run () override {
		switch (dir)
		{
		case UP:
		{
			this->y -= CONST_SPEED;
			break;
		}
		case DOWN:
		{
			this->y += CONST_SPEED;
			break;
		}
		case RIGHT:
		{
			this->x += CONST_SPEED;
			break;
		}
		case LEFT:
		{
			this->x -= CONST_SPEED;
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
			this->y += CONST_SPEED;
			break;
		}
		case DOWN:
		{
			this->y -= CONST_SPEED;
			break;
		}
		case RIGHT:
		{
			this->x -= CONST_SPEED;
			break;
		}
		case LEFT:
		{
			this->x += CONST_SPEED;
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