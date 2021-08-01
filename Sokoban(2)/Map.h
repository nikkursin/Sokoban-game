#pragma once
#include "Header.h"

ref class Map : Elem{
private:
	array <array <bool>^>^ blocks; 	
public:
	Map() {
		blocks = gcnew array<array< bool >^>(20);
		std::fstream in("level1.bin");
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
		Bitmap^ img = gcnew Bitmap("wall-elem2.png");
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (blocks[i][j]){
					
					g->DrawImage(img, j * 30, i * 30);
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
		std::fstream in("level1.bin");
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