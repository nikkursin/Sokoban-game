#pragma once

#include "Field.h"

namespace Sokoban2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Level_1
	/// </summary>
	

	public ref class Level_1 : public System::Windows::Forms::Form
	{
	public:
		Level_1(void)
		{
			InitializeComponent();
			game = gcnew Field(pictureBox1); 
			Reset();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Level_1()
		{
			if (components)
			{
				delete components;
			}
		}
		private: System::Windows::Forms::PictureBox^ pictureBox1;
		private: System::Windows::Forms::Timer^ mainTimer;
		private: System::ComponentModel::IContainer^ components;
		private: System::Windows::Forms::PictureBox^ pictureBox2;
		private: System::Windows::Forms::Label^ label1;



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Field^ game; 



		   double Time = 0.0;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Level_1::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->mainTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(26, 55);
			this->pictureBox1->MaximumSize = System::Drawing::Size(600, 600);
			this->pictureBox1->MinimumSize = System::Drawing::Size(600, 600);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(600, 600);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// mainTimer
			// 
			this->mainTimer->Interval = 70;
			this->mainTimer->Tick += gcnew System::EventHandler(this, &Level_1::mainGameTimer);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(602, 9);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(40, 40);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &Level_1::pictureBox2_Click_1);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"SF UI Text", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(112, 29);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Timer: 0";
			// 
			// Level_1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(645, 694);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(661, 733);
			this->MinimumSize = System::Drawing::Size(661, 733);
			this->Name = L"Level_1";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->StartPosition = System::Windows::Forms::FormStartPosition::WindowsDefaultBounds;
			this->Text = L"Sokoban";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Level_1::Level_1_FormClosing);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Level_1::keyisdown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Level_1::keyisup);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Level_1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: Void mainGameTimer(System::Object^ sender, System::EventArgs^ e) {
		Time += 0.001 * mainTimer->Interval;
		label1->Text = "Timer: " + String::Format("{0:F2}", Time);
		game->Draw(); 
		game->Run(); 
		if (game->winned()) {  
			mainTimer->Stop();
			MessageBox::Show("\tYOU WON!\n\tTime: " + String::Format("{0:F2}", Time)); 
			Application::Exit();
		} ;
	}
	private : void Reset() {
		mainTimer->Start();
		
	}
	private: System::Void keyisdown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Up)	dir = UP; 
		if (e->KeyCode == Keys::Down)dir = DOWN;
		if (e->KeyCode == Keys::Left) {
			side_val = false; 
			dir = LEFT;
		} 
		if (e->KeyCode == Keys::Right) {
			side_val = true;
			dir = RIGHT;
		} 
		if (e->KeyCode == Keys::W)	dir = UP;
		if (e->KeyCode == Keys::S) dir = DOWN;
		if (e->KeyCode == Keys::A)	{
			side_val = false;
			dir = LEFT;
		}
		if (e->KeyCode == Keys::D) {
			side_val = true;
			dir = RIGHT;
		}
	}
	private: System::Void keyisup(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Up) dir = zero;
		if (e->KeyCode == Keys::Down) dir = zero;
		if (e->KeyCode == Keys::Left) dir = zero;
		if (e->KeyCode == Keys::Right)dir = zero;
		if (e->KeyCode == Keys::W) dir = zero;
		if (e->KeyCode == Keys::S) dir = zero;
		if (e->KeyCode == Keys::A) dir = zero;
		if (e->KeyCode == Keys::D) dir = zero;
	}
	private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
		/*MessageBox::Show("RUN!"); 
		Application::Run(gcnew Level_1()); */
	}
	private: System::Void pictureBox2_Click_1(System::Object^ sender, System::EventArgs^ e) {
		//MessageBox::Show("RESTART!");
		game = gcnew Field(pictureBox1);
		//Application::Restart();
	}
	private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void Level_1_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		Application::Exit();
	}
};
}
