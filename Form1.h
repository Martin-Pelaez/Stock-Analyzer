//#include "smartticker.h"
#pragma once
#include "chartForm.h"
#include "ticker.h"
#include "smartticker.h"
// Martin Pelaez U72640747
namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{

	public:
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker2;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	public:

	private:
		BindingList<SmartCandlestick^>^ tickerList = gcnew BindingList<SmartCandlestick^>();
		BindingList<SmartCandlestick^>^ selectedTickerList = gcnew BindingList<SmartCandlestick^>();
		DateTime startDate;



	private: System::Windows::Forms::Label^ label3;


		   DateTime endDate;
	public:
		Form1(void)
		{
			InitializeComponent();
			//set up the choose file dialogue
			String^ parentDirectory = System::IO::Directory::GetParent(System::IO::Directory::GetCurrentDirectory())->FullName;
			openFileDialog1->InitialDirectory = parentDirectory; // Initial directory when the dialog opens.
			openFileDialog1->Filter = "CSV Files (*.csv)|*.csv|All Files (*.*)|*.*";
			openFileDialog1->FilterIndex = 1;
	

			// Add your recognizers to the list


		}

	protected:

		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// button1
			// 
			this->button1->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button1->Location = System::Drawing::Point(256, 58);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Choose File";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::chooseFile_Click);
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(23, 24);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker1->TabIndex = 1;
			this->dateTimePicker1->Value = System::DateTime(2021, 1, 1, 0, 0, 0, 0);
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Location = System::Drawing::Point(23, 71);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker2->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(20, 8);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Start Date";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(20, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"End Date";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(254, 24);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(460, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Select a start date end date and then select a stock data CSV that you would ike "
				L"to see data for";
			this->label3->Click += gcnew System::EventHandler(this, &Form1::label3_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(756, 114);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dateTimePicker2);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L" ";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}


#pragma endregion


	// creates new form after selecting new file
	private: System::Void chooseFile_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			tickerList->Clear();
			// User selected a file, you can work with the selected file path


			chartForm^ chartFormInstance = gcnew chartForm();
			chartFormInstance->Show();

			String^ selectedFilePath = openFileDialog1->FileName;
			ReadCsvFile(selectedFilePath);
			//String^ stockType = comboBox1->Text;
			chartFormInstance->SetChartData(tickerList);
			/*UpdateCandlestickChart();*/

		}
	}
	// read csv file in and filters by date
	private: void ReadCsvFile(String^ filePath)
	{

		String^ selectedFilePath = openFileDialog1->FileName;

		// Open CSV file
		System::IO::StreamReader^ file = gcnew System::IO::StreamReader(selectedFilePath);

		if (file)
		{
			bool isFirstLine = true;
			String^ line;
			while ((line = file->ReadLine()) != nullptr)
			{
				//skip header
				if (isFirstLine) {
					isFirstLine = false;
					continue;
				}
				// Parse the CSV data and create Ticker objects
				array<String^>^ tokens = line->Split(',');

				if (tokens->Length >= 9)

				{
					String^ dateAdded = tokens[2]->Trim('"') + ", " + tokens[3]->Trim('"');
					DateTime dateCandle = DateTime::ParseExact(dateAdded, "MMM d,  yyyy", nullptr, System::Globalization::DateTimeStyles::None);


					SmartCandlestick^ tickerTemp = gcnew SmartCandlestick(tokens[0]->Trim('"'), tokens[1]->Trim('"'), dateCandle,
						System::Convert::ToDouble(tokens[4]),
						System::Convert::ToDouble(tokens[5]),
						System::Convert::ToDouble(tokens[6]),
						System::Convert::ToDouble(tokens[7]),
						System::Convert::ToDouble(tokens[8]));


					// check if date is within the date time pickers.
					if (dateCandle >= dateTimePicker1->Value && dateCandle <= dateTimePicker2->Value) {
						tickerList->Add(tickerTemp);

					}

				}
			}
			file->Close();
		}

	}



	private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}