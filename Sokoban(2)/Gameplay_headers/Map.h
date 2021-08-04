#pragma once
#include "Header.h"

ref class Map : Elem{
private:
	array <array <bool>^>^ blocks; 	
public:
	Map() {
		blocks = gcnew array<array< bool >^>(20);
		std::fstream in("Map_files/level" + std::to_string(current_level) + ".bin");
		if (!in.is_open()) {
			MessageBox::Show("File could not opened!");
		}
		for (int i = 0; i < 20; i++) {
			this->blocks[i] = gcnew array< bool >(20);
			for (int j = 0; j < 20; j++) {
				int temp;
				in >> temp;
				if (temp == 1) {
					blocks[i][j] = true;
				}
			}
		}
		in.close();
	}
	virtual void Draw(Graphics^ g) override {
		if (FileExists("Textures/wall-elem2.png")) {
			Bitmap^ img = gcnew Bitmap("Textures/wall-elem2.png");
			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < 20; j++) {
					if (blocks[i][j]) {
						g->DrawImage(img, j * 30, i * 30);
					}
				}
			}
		}
		else {
			//MessageBox::Show("Image files couldn`t found!");
			SolidBrush^ rect = gcnew SolidBrush(Color::DimGray);
			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < 20; j++) {
					if (blocks[i][j]) {
						g->FillRectangle(rect, j * 30 + 10, i * 30 + 10, 20, 20);
					}
				}
			}
		}
		
	}
	bool get_elem(int a , int b) {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (i == a && j == b) return blocks[i][j]; 
			}
		}
		return false; 
	}
};

ref class Target : Elem{
private: 
	array <array <bool>^>^ goals;
public: 
	Target() {
		goals = gcnew array<array< bool >^>(20);
		std::fstream in("Map_files/level" + std::to_string(current_level) + ".bin");
		if (!in.is_open()) {
			MessageBox::Show("File could not opened!");
		}
		for (int i = 0; i < 20; i++) {
			this->goals [i] = gcnew array< bool >(20);
			for (int j = 0; j < 20; j++) {
				int temp;
				in >> temp;
				if (temp == 3) {
					goals[i][j] = true;
				}
			}
		}
		in.close();
	}

	virtual void Draw(Graphics^ g) override{
		SolidBrush^ pen = gcnew SolidBrush(Color::Orange);
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (goals[i][j]) {
					g->FillEllipse(pen, j * 30 + 10,  i * 30 + 10 , 15, 15);
				}
			}
		}
	}

	bool get_elem(int a, int b) {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (i == a && j == b) return goals[i][j];
			}
		}
		return false;
	}
	
};