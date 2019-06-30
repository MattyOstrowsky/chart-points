//Mateusz Ostrowski 
//216708
#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <msclr/marshal_cppstd.h>
namespace Wykres {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o Formularz1
	/// </summary>
	public ref class Formularz1 : public System::Windows::Forms::Form
	{
	public:
		Formularz1(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~Formularz1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::PictureBox^  obrazek;
	private: bool wczytano = false;
	private: String ^ sciezka;
	private: int x0 = 90;		//wspó³rzêdne przeciêcia osi uk³adu wspó³rzêdnych 
	private: int y0 = 417;
	private: double x1=0;		//wspó³rzêdne w miejscu przeciêcia osi
	private: double y1=0;
	private: int xskala=1;
	private: int yskala=1;
	private: System::Windows::Forms::Label^  lblx;
	private: System::Windows::Forms::Label^  lbly;
	private: System::Windows::Forms::Label^  lblx_war;
	private: System::Windows::Forms::Label^  lbly_war;


	private: System::Windows::Forms::CheckBox^  logx;
	private: System::Windows::Forms::Label^  lbl_pkt;






	private: System::Windows::Forms::CheckBox^  logy;










	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  C1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  C2;

	private: System::Windows::Forms::SaveFileDialog^  Zapdialog;
	private: System::Windows::Forms::Button^  pic_load;

	private: System::Windows::Forms::Button^  pkt_romove;
	private: System::Windows::Forms::Button^  pkt_save;




	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->obrazek = (gcnew System::Windows::Forms::PictureBox());
			this->lblx = (gcnew System::Windows::Forms::Label());
			this->lbly = (gcnew System::Windows::Forms::Label());
			this->lblx_war = (gcnew System::Windows::Forms::Label());
			this->lbly_war = (gcnew System::Windows::Forms::Label());
			this->logx = (gcnew System::Windows::Forms::CheckBox());
			this->lbl_pkt = (gcnew System::Windows::Forms::Label());
			this->logy = (gcnew System::Windows::Forms::CheckBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->C1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->C2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Zapdialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->pic_load = (gcnew System::Windows::Forms::Button());
			this->pkt_romove = (gcnew System::Windows::Forms::Button());
			this->pkt_save = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->obrazek))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// obrazek
			// 
			this->obrazek->Location = System::Drawing::Point(447, 65);
			this->obrazek->Name = L"obrazek";
			this->obrazek->Size = System::Drawing::Size(557, 501);
			this->obrazek->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->obrazek->TabIndex = 1;
			this->obrazek->TabStop = false;
			this->obrazek->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Formularz1::obrazek_MouseClick);
			this->obrazek->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Formularz1::obrazek_MouseMove);
			// 
			// lblx
			// 
			this->lblx->AutoSize = true;
			this->lblx->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->lblx->Location = System::Drawing::Point(617, 28);
			this->lblx->Name = L"lblx";
			this->lblx->Size = System::Drawing::Size(31, 24);
			this->lblx->TabIndex = 2;
			this->lblx->Text = L"X:";
			// 
			// lbly
			// 
			this->lbly->AutoSize = true;
			this->lbly->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->lbly->Location = System::Drawing::Point(728, 28);
			this->lbly->Name = L"lbly";
			this->lbly->Size = System::Drawing::Size(29, 24);
			this->lbly->TabIndex = 3;
			this->lbly->Text = L"Y:";
			// 
			// lblx_war
			// 
			this->lblx_war->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->lblx_war->Location = System::Drawing::Point(663, 28);
			this->lblx_war->Name = L"lblx_war";
			this->lblx_war->Size = System::Drawing::Size(58, 24);
			this->lblx_war->TabIndex = 4;
			this->lblx_war->Text = L".";
			this->lblx_war->UseCompatibleTextRendering = true;
			// 
			// lbly_war
			// 
			this->lbly_war->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->lbly_war->Location = System::Drawing::Point(778, 28);
			this->lbly_war->Name = L"lbly_war";
			this->lbly_war->Size = System::Drawing::Size(80, 24);
			this->lbly_war->TabIndex = 5;
			this->lbly_war->Text = L".";
			// 
			// logx
			// 
			this->logx->AutoSize = true;
			this->logx->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->logx->Location = System::Drawing::Point(291, 117);
			this->logx->Margin = System::Windows::Forms::Padding(2);
			this->logx->Name = L"logx";
			this->logx->Size = System::Drawing::Size(43, 28);
			this->logx->TabIndex = 6;
			this->logx->Text = L"X";
			this->logx->UseVisualStyleBackColor = true;
			// 
			// lbl_pkt
			// 
			this->lbl_pkt->AutoSize = true;
			this->lbl_pkt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->lbl_pkt->Location = System::Drawing::Point(101, 29);
			this->lbl_pkt->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_pkt->Name = L"lbl_pkt";
			this->lbl_pkt->Size = System::Drawing::Size(66, 24);
			this->lbl_pkt->TabIndex = 10;
			this->lbl_pkt->Text = L"Punkty";
			// 
			// logy
			// 
			this->logy->AutoSize = true;
			this->logy->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->logy->Location = System::Drawing::Point(370, 117);
			this->logy->Margin = System::Windows::Forms::Padding(2);
			this->logy->Name = L"logy";
			this->logy->Size = System::Drawing::Size(41, 28);
			this->logy->TabIndex = 18;
			this->logy->Text = L"Y";
			this->logy->UseVisualStyleBackColor = true;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label7->Location = System::Drawing::Point(265, 91);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(177, 24);
			this->label7->TabIndex = 19;
			this->label7->Text = L"skala logarytmiczna:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->C1, this->C2 });
			this->dataGridView1->Location = System::Drawing::Point(11, 55);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(246, 368);
			this->dataGridView1->TabIndex = 20;
			// 
			// C1
			// 
			this->C1->HeaderText = L"X";
			this->C1->Name = L"C1";
			// 
			// C2
			// 
			this->C2->HeaderText = L"Y";
			this->C2->Name = L"C2";
			// 
			// Zapdialog
			// 
			this->Zapdialog->Filter = L"PIik tekstowy|*txt";
			// 
			// pic_load
			// 
			this->pic_load->Location = System::Drawing::Point(291, 65);
			this->pic_load->Name = L"pic_load";
			this->pic_load->Size = System::Drawing::Size(120, 23);
			this->pic_load->TabIndex = 22;
			this->pic_load->Text = L"Wczytaj wykres";
			this->pic_load->UseVisualStyleBackColor = true;
			this->pic_load->Click += gcnew System::EventHandler(this, &Formularz1::PrzWczyt_Click);
			// 
			// pkt_romove
			// 
			this->pkt_romove->Location = System::Drawing::Point(24, 444);
			this->pkt_romove->Name = L"pkt_romove";
			this->pkt_romove->Size = System::Drawing::Size(98, 23);
			this->pkt_romove->TabIndex = 23;
			this->pkt_romove->Text = L"Usuñ punkt";
			this->pkt_romove->UseVisualStyleBackColor = true;
			this->pkt_romove->Click += gcnew System::EventHandler(this, &Formularz1::przCof_Click);
			// 
			// pkt_save
			// 
			this->pkt_save->Location = System::Drawing::Point(140, 444);
			this->pkt_save->Name = L"pkt_save";
			this->pkt_save->Size = System::Drawing::Size(98, 23);
			this->pkt_save->TabIndex = 24;
			this->pkt_save->Text = L"Zapisz do pliku";
			this->pkt_save->UseVisualStyleBackColor = true;
			this->pkt_save->Click += gcnew System::EventHandler(this, &Formularz1::przeksp_Click);
			// 
			// Formularz1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1037, 577);
			this->Controls->Add(this->pkt_save);
			this->Controls->Add(this->pkt_romove);
			this->Controls->Add(this->pic_load);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->logy);
			this->Controls->Add(this->lbl_pkt);
			this->Controls->Add(this->logx);
			this->Controls->Add(this->lbly_war);
			this->Controls->Add(this->lblx_war);
			this->Controls->Add(this->lbly);
			this->Controls->Add(this->lblx);
			this->Controls->Add(this->obrazek);
			this->Name = L"Formularz1";
			this->Text = L"Formularz1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->obrazek))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void PrzWczyt_Click(System::Object^  sender, System::EventArgs^  e)
	{
		OpenFileDialog^ plik = gcnew OpenFileDialog();
		plik->Title = "Wybierz plik graficzny";
		plik->Filter = "Wszystkie typy plików graficznych|*.jpg;*.jpeg;*.png;*.bmp|" + "JPEG (*.jpg;*.jpeg)|*.jpg;*.jpeg|" + "PNG (*.png)|*.png|" + "BMP (*.bmp)|*.bmp";
		if (plik->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->obrazek->Image = Image::FromFile(plik->FileName);
			wczytano = true;
			sciezka = plik->FileName;
			String ^ nazwaPliku = System::IO::Path::GetFileNameWithoutExtension(sciezka);
			bool czyJest_ = nazwaPliku->Contains("_");
			if (czyJest_)
			{
				array<String^> ^ tablica = gcnew array<String^>(2);
				tablica = nazwaPliku->Split('_', 6); 
				
				x1 = int::Parse(tablica[0]);
				y1 = int::Parse(tablica[1]);
				xskala = int::Parse(tablica[2]);
				yskala = int::Parse(tablica[3]);
			}
			
		}

	}
	private: System::Void obrazek_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		if (wczytano)
		{
			double x = e->X;
			double y = e->Y;
			if (this->logx->Checked)
			{
				x = x1 * pow(10, (x - x0) / xskala);
			}
			else
			{
				x = (x - x0) / xskala + x1;
			}
			if (this->logy->Checked)
			{
				y = pow(10, (y0 - y) / yskala) * y1;
			}
			else
			{
				y = (y0 - y) / yskala + y1;
			}
			this->lblx_war->Text = x.ToString();
			this->lbly_war->Text = y.ToString();
		}
	}
private: System::Void obrazek_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if (wczytano)
	{
		this->dataGridView1->Rows->Add();
		this->dataGridView1->Rows[this->dataGridView1->RowCount - 2]->Cells[0]->Value = this->lblx_war->Text;
		this->dataGridView1->Rows[this->dataGridView1->RowCount - 2]->Cells[1]->Value = this->lbly_war->Text;
	}
}

private: System::Void przCof_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->dataGridView1->Rows->RemoveAt(this->dataGridView1->RowCount - 2);
}
private: System::Void przeksp_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (wczytano)
	{
		this->Zapdialog->ShowDialog();
		int ile = this->dataGridView1->RowCount;
		System::IO::StreamWriter^ wyj = gcnew System::IO::StreamWriter(this->Zapdialog->FileName);
		
		for (int i = 0; i < ile; i++)
		{
			wyj->Write(this->dataGridView1->Rows[i]->Cells[0]->Value);
			wyj->Write(' ');
			wyj->Write(this->dataGridView1->Rows[i]->Cells[1]->Value);
			wyj->Write("\r\n");
		}
		wyj->Close();
	}
}

};
}
