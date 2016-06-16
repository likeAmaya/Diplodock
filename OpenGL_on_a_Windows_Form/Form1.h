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
	private: System::Windows::Forms::Button^  button1;

	

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			this->timer1->Enabled = true;
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			this->button1->Location = System::Drawing::Point(688, 53);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(795, 489);
			this->Controls->Add(this->button1);
			this->KeyPreview = true;
			this->Name = L"Form1";
			this->Text = L"OpenGL on a Windows Form using Managed C++";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
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
					 OpenGL->_xTranslate += 0.1f;
					 break;
				 case Keys::W:
					 OpenGL->_xTranslate -= 0.1f;
					 break;
				 case Keys::A:
					 OpenGL->_yTranslate += 0.1f;
					 break;
				 case Keys::S:
					 OpenGL->_yTranslate -= 0.1f;
					 break;
				 case Keys::Z:
					 OpenGL->_zTranslate += 0.1f;
					 break;
				 case Keys::X:
					 OpenGL->_zTranslate -= 0.1f;
					 break;

				 case Keys::E:
					 OpenGL->_xRotate += 0.2f;
					 break;
				 case Keys::R:
					 OpenGL->_xRotate -= 0.2f;
					 break;
				 case Keys::D:
					 OpenGL->_yRotate += 0.2f;
					 break;
				 case Keys::F:
					 OpenGL->_yRotate -= 0.2f;
					 break;
				 case Keys::C:
					 OpenGL->_zRotate += 0.2f;
					 break;
				 case Keys::V:
					 OpenGL->_zRotate -= 0.2f;
					 break;

				 case Keys::T:
					 OpenGL->_xScale += 0.1f;
					 break;
				 case Keys::Y:
					 OpenGL->_xScale -= 0.1f;
					 break;
				 case Keys::G:
					 OpenGL->_yScale += 0.1f;
					 break;
				 case Keys::H:
					 OpenGL->_yScale -= 0.1f;
					 break;
				 case Keys::B:
					 OpenGL->_zScale += 0.1f;
					 break;
				 case Keys::N:
					 OpenGL->_zScale -= 0.1f;
					 break;
				 }
				 OpenGL->Render();
				 OpenGL->SwapOpenGLBuffers();
	}
	};
}

