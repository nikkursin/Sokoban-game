#include "Player.h"
#include "Map.h"
#include "Box.h"


ref class Field  {
private:
	int width;
	int height;
	Player^ myPlayer;
	Map^ myMap; 
	Box^ myBox; 
	Target^ myTarget;
	PictureBox^ myPb; 
public:
	Field(PictureBox ^pb) {
		myPb = pb;
		width = pb->Width; 
		height = pb->Height; 
		myPlayer = gcnew Player;
		myMap = gcnew Map;
		myTarget = gcnew Target; 
		myBox = gcnew Box; 
	}

	void Draw() {
		Bitmap^ bmp;
		bmp = gcnew Bitmap(width, height);
		Graphics^ g = Graphics::FromImage(bmp);
		myMap->Draw(g); 
		myTarget->Draw(g); 
		myBox->Draw(g);
		myPlayer->Draw(g);	
		myPb->Image = bmp;
	}

	bool winned() {
		return myBox->targeted();
	}

	bool Intersect(Player^ myPlayer , Map^ myMap) {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++ ) {
				if (myMap->get_elem(i, j)) {
					if (j * 30 == myPlayer->getX() && i * 30 == myPlayer->getY()) return true; 
				}
			}
		}
		return false; 
	}

	bool Intersect(Player^ myPlayer, Box^ myBox, int& a) {
		for (int i = 0; i < myBox->get_amount(); i++) {
			if (myPlayer->getX() == myBox->elem_getX(i) && myPlayer->getY() == myBox->elem_getY(i)) {
				a = i; 
				return true;
			} 
		}
		return false;
	}

	bool Intersect(Map^ MyMap, Box^ myBox, int& a) {
		a = 0;
		for (int k = 0; k < myBox->get_amount(); k++) {
			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < 20; j++) {
					if (myMap->get_elem(i, j)) {
						if (j * 30 == myBox->elem_getX(k) && i * 30 == myBox->elem_getY(k)) {
							a = k;
							return true;
						}
					}
				}
			}
		}
		return false; 
	}

	bool Intersect(Box^ myBox, int &a) {
		a = 0; 
		for (int i = 0; i < myBox->get_amount(); i++) {
			for (int j = 0; j < myBox->get_amount(); j++) {
				if (myBox->elem_getX(i) == myBox->elem_getX(j) && myBox->elem_getY(i) == myBox->elem_getY(j) && i != j) {
					a = j; 
					return true;
				}
			}
		}
		return false; 
	}

	bool Intersect(Box^ myBox, Target^ myTarget, int& a) {
		a = 0; 
		for (int k = 0; k < myBox->get_amount(); k++) {
			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < 20; j++) {
					if (myTarget->get_elem(i, j)) {
						if (j * 30 == myBox->elem_getX(k) && i * 30 == myBox->elem_getY(k) && !myBox->get_delivered(k)) {
							a = k;
							//MessageBox::Show("Target done!"); 
							return true;
						}
					}
				}
			}
		}
		return false;
	}
	//}
	void Run(){
		myPlayer->Run();
		if (Intersect(myPlayer, myMap)) myPlayer->RunBackPlayer(); 
		int a;
		if (Intersect(myPlayer, myBox, a)) {
			myBox->RunBox(a);
			myPlayer->RunBackPlayer();
		}
		if (Intersect(myMap, myBox, a)) myBox->RunBackBox(a);
		if (Intersect(myBox, a)) {
			//myPlayer->RunBackPlayer();
			myBox->RunBackBox(a);
		}
		if (Intersect(myBox, myTarget, a)) {
			myBox->set_delivered(a);
			//score++; 
		}
	}
	
};
