#pragma once

namespace Sokoban2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for StartWindow
	/// </summary>
	public ref class StartWindow : public System::Windows::Forms::Form
	{
	public:
		StartWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StartWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(190, 515);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(280, 60);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start game";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// StartWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(645, 664);
			this->Controls->Add(this->button1);
			this->Name = L"StartWindow";
			this->Text = L"StartWindow";
			this->Load += gcnew System::EventHandler(this, &StartWindow::StartWindow_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void StartWindow_Load(System::Object^ sender, System::EventArgs^ e) {
		//MessageBox::Show("Hi bitch!");
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		Level_1^ secondWindowForm = gcnew Level_1();
		secondWindowForm->Show();
	}
	};
}
