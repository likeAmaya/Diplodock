#pragma once

#include "OpenGL.h"

namespace OpenGL_on_a_Windows_Form { ref class Form1; };

namespace OpenGL_on_a_Windows_Form {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;



	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			label1->Text = readme;
			
			//
			//TODO: Add the constructor code here
			//
			OpenGL = gcnew COpenGL(this, 640, 480);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:
	private: System::Windows::Forms::Timer^  timer1;


	private: System::String^ readme = "Q/W A/S Z/X - Translate by X/Y/Z\nE/R D/F C/V - Rotate by X/Y/Z\nT/Y G/H B/N - Scale by X/Y/Z";
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::RadioButton^  radioButton7;
	private: System::Windows::Forms::RadioButton^  radioButton6;
	private: System::Windows::Forms::RadioButton^  radioButton5;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::RadioButton^  radioButton10;
	private: System::Windows::Forms::RadioButton^  radioButton9;
	private: System::Windows::Forms::RadioButton^  radioButton8;
	private: System::Windows::Forms::RadioButton^  radioButton11;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		OpenGLForm::COpenGL ^ OpenGL;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton11 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton10 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton9 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton8 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox2->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			this->timer1->Enabled = true;
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			this->label1->Location = System::Drawing::Point(655, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(296, 102);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Keys";
			this->groupBox2->Controls->Add(this->radioButton4);
			this->groupBox2->Controls->Add(this->radioButton3);
			this->groupBox2->Location = System::Drawing::Point(658, 114);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(293, 66);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Objects";
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(6, 42);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(63, 17);
			this->radioButton4->TabIndex = 1;
			this->radioButton4->Text = L"Triangle";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton3->AutoSize = true;
			this->radioButton3->Checked = true;
			this->radioButton3->Location = System::Drawing::Point(6, 19);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(50, 17);
			this->radioButton3->TabIndex = 0;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Cube";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton3_CheckedChanged);
			this->groupBox4->Controls->Add(this->radioButton11);
			this->groupBox4->Controls->Add(this->radioButton10);
			this->groupBox4->Controls->Add(this->radioButton9);
			this->groupBox4->Controls->Add(this->radioButton8);
			this->groupBox4->Location = System::Drawing::Point(658, 186);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(293, 113);
			this->groupBox4->TabIndex = 3;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Lighters";
			this->radioButton11->AutoSize = true;
			this->radioButton11->Checked = true;
			this->radioButton11->Location = System::Drawing::Point(6, 88);
			this->radioButton11->Name = L"radioButton11";
			this->radioButton11->Size = System::Drawing::Size(77, 17);
			this->radioButton11->TabIndex = 3;
			this->radioButton11->TabStop = true;
			this->radioButton11->Text = L"Выключен";
			this->radioButton11->UseVisualStyleBackColor = true;
			this->radioButton11->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton11_CheckedChanged);
			this->radioButton10->AutoSize = true;
			this->radioButton10->Location = System::Drawing::Point(6, 65);
			this->radioButton10->Name = L"radioButton10";
			this->radioButton10->Size = System::Drawing::Size(111, 17);
			this->radioButton10->TabIndex = 2;
			this->radioButton10->Text = L"Прожектор (spot)";
			this->radioButton10->UseVisualStyleBackColor = true;
			this->radioButton10->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton10_CheckedChanged);
			this->radioButton9->AutoSize = true;
			this->radioButton9->Location = System::Drawing::Point(6, 42);
			this->radioButton9->Name = L"radioButton9";
			this->radioButton9->Size = System::Drawing::Size(149, 17);
			this->radioButton9->TabIndex = 1;
			this->radioButton9->Text = L"Всенаправленный (omni)";
			this->radioButton9->UseVisualStyleBackColor = true;
			this->radioButton9->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton9_CheckedChanged);
			this->radioButton8->AutoSize = true;
			this->radioButton8->Location = System::Drawing::Point(6, 19);
			this->radioButton8->Name = L"radioButton8";
			this->radioButton8->Size = System::Drawing::Size(101, 17);
			this->radioButton8->TabIndex = 0;
			this->radioButton8->Text = L"Параллельный";
			this->radioButton8->UseVisualStyleBackColor = true;
			this->radioButton8->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton8_CheckedChanged);
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(963, 489);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->label1);
			this->KeyPreview = true;
			this->Name = L"Form1";
			this->Text = L"OpenGL on a Windows Form using Managed C++";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 OpenGL->Render();
				 OpenGL->SwapOpenGLBuffers();
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 // bla bla bla
	}
	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 switch (e->KeyCode)
				 {
				 case Keys::Q:
					 if (OpenGL->_isCubeSelected)
						 OpenGL->_xCubeTranslate += 0.1f;
					 else
						 OpenGL->_xTriangleTranslate += 0.1f;
					 break;
				 case Keys::W:
					 if (OpenGL->_isCubeSelected)
						 OpenGL->_xCubeTranslate -= 0.1f;
					 else
						 OpenGL->_xTriangleTranslate -= 0.1f;
					 break;
				 case Keys::A:
					 if (OpenGL->_isCubeSelected)
						 OpenGL->_yCubeTranslate += 0.1f;
					 else
						 OpenGL->_yTriangleTranslate += 0.1f;
					 break;
				 case Keys::S:
					 if (OpenGL->_isCubeSelected)
						 OpenGL->_yCubeTranslate -= 0.1f;
					 else
						 OpenGL->_yTriangleTranslate -= 0.1f;
					 break;
				 case Keys::Z:
					 if (OpenGL->_isCubeSelected)
						 OpenGL->_zCubeTranslate += 0.1f;
					 else
						 OpenGL->_zTriangleTranslate += 0.1f;
					 break;
				 case Keys::X:
					 if (OpenGL->_isCubeSelected)
						 OpenGL->_zCubeTranslate -= 0.1f;
					 else
						 OpenGL->_zTriangleTranslate -= 0.1f;
					 break;
				 case Keys::E:
					 if (OpenGL->_isCubeSelected)
						 OpenGL->_xCubeRotate += 0.2f;
					 else
						 OpenGL->_xTriangleRotate += 0.2f;
					 break;
				 case Keys::R:
					 if (OpenGL->_isCubeSelected)
						 OpenGL->_xCubeRotate -= 0.2f;
					 else
						 OpenGL->_xTriangleRotate -= 0.2f;
					 break;
				 case Keys::D:
					 if (OpenGL->_isCubeSelected)
						 OpenGL->_yCubeRotate += 0.2f;
					 else
						 OpenGL->_yTriangleRotate += 0.2f;
					 break;
				 case Keys::F:
					 if (OpenGL->_isCubeSelected)
						 OpenGL->_yCubeRotate -= 0.2f;
					 else
						 OpenGL->_yTriangleRotate -= 0.2f;
					 break;
				 case Keys::C:
					 if (OpenGL->_isCubeSelected)
						 OpenGL->_zCubeRotate += 0.2f;
					 else
						 OpenGL->_zTriangleRotate += 0.2f;
					 break;
				 case Keys::V:
					 if (OpenGL->_isCubeSelected)
						 OpenGL->_zCubeRotate -= 0.2f;
					 else
						 OpenGL->_zTriangleRotate -= 0.2f;
					 break;

				 case Keys::T:
					 if (OpenGL->_isCubeSelected)
						 OpenGL->_xCubeScale += 0.1f;
					 else
						 OpenGL->_xTriangleScale += 0.1f;
					 break;
				 case Keys::Y:
					 if (OpenGL->_isCubeSelected)
						 OpenGL->_xCubeScale -= 0.1f;
					 else
						 OpenGL->_xTriangleScale -= 0.1f;
					 break;
				 case Keys::G:
					 if (OpenGL->_isCubeSelected)
						 OpenGL->_yCubeScale += 0.1f;
					 else
						 OpenGL->_yTriangleScale += 0.1f;
					 break;
				 case Keys::H:
					 if (OpenGL->_isCubeSelected)
						 OpenGL->_yCubeScale -= 0.1f;
					 else
						 OpenGL->_yTriangleScale -= 0.1f;
					 break;
				 case Keys::B:
					 if (OpenGL->_isCubeSelected)
						 OpenGL->_zCubeScale += 0.1f;
					 else
						 OpenGL->_zTriangleScale += 0.1f;
					 break;
				 case Keys::N:
					 if (OpenGL->_isCubeSelected)
						 OpenGL->_zCubeScale -= 0.1f;
					 else
						 OpenGL->_zTriangleScale -= 0.1f;
					 break;
				 }
				 OpenGL->Render();
				 OpenGL->SwapOpenGLBuffers();
	}
	private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 OpenGL->_isCubeSelected = !OpenGL->_isCubeSelected;
	}
	private: System::Void radioButton5_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {


	}
	private: System::Void radioButton8_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 OpenGL->_currentLighter = LighterType::Parallel;
				 OpenGL->Render();
				 OpenGL->SwapOpenGLBuffers();
	}
	private: System::Void radioButton9_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 OpenGL->_currentLighter = LighterType::Omni;
				 OpenGL->Render();
				 OpenGL->SwapOpenGLBuffers();
	}
	private: System::Void radioButton10_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 OpenGL->_currentLighter = LighterType::Spot;
				 OpenGL->Render();
				 OpenGL->SwapOpenGLBuffers();
	}
	private: System::Void radioButton11_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 OpenGL->_currentLighter = LighterType::No;
				 OpenGL->Render();
				 OpenGL->SwapOpenGLBuffers();
	}
};
}

