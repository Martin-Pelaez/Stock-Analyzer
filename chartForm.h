#pragma once
#include "smartticker.h"
#include "patternRecognizer.h"


namespace CppCLRWinformsProjekt {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Windows::Forms::DataVisualization::Charting;

    public ref class chartForm : public System::Windows::Forms::Form
    {
    public:
        chartForm(void)
        {
            InitializeComponent();


            recognizerList = gcnew System::Collections::Generic::List<PatternRecognizer^>();

            // Add your recognizers to the list
            DojiPatternRecognizer^ dojiRecognizer = gcnew DojiPatternRecognizer();
            PeakPatternRecognizer^ peakRecognizer = gcnew PeakPatternRecognizer();
            ValleyPatternRecognizer^ valleyRecognizer = gcnew ValleyPatternRecognizer();
            HammerPatternRecognizer^ hammerRecognizer = gcnew HammerPatternRecognizer();
            MarubozuPatternRecognizer^ marubozuRecognizer = gcnew MarubozuPatternRecognizer();
            EngulfingPatternRecognizer^ engulfingRecognizer = gcnew EngulfingPatternRecognizer();
            HaramiPatternRecognizer^ haramiRecognizer = gcnew HaramiPatternRecognizer();



            recognizerList->Add(dojiRecognizer);
            recognizerList->Add(peakRecognizer);
            recognizerList->Add(valleyRecognizer);
            recognizerList->Add(hammerRecognizer);
            recognizerList->Add(marubozuRecognizer);
            recognizerList->Add(engulfingRecognizer);
            recognizerList->Add(haramiRecognizer);


        }


        // Method to update the chart with data
    protected:
        ~chartForm()
        {
            if (components)

            {
                delete components;
            }
        }

    private:

        //instantiate vars for the class
        System::ComponentModel::Container^ components;
        System::Collections::Generic::List<PatternRecognizer^>^ recognizerList;
        BindingList<SmartCandlestick^>^ tempTickerList = gcnew BindingList<SmartCandlestick^>();
    private: System::Windows::Forms::ComboBox^ comboBox1;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Button^ button1;

    private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart2;


           void InitializeComponent(void)
           {
               System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
               System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
               System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
               System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
               System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
               this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
               this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
               this->label1 = (gcnew System::Windows::Forms::Label());
               this->button1 = (gcnew System::Windows::Forms::Button());
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
               this->SuspendLayout();
               // 
               // chart2
               // 
               chartArea1->Name = L"ChartArea1";
               chartArea2->Name = L"ChartArea2";
               this->chart2->ChartAreas->Add(chartArea1);
               this->chart2->ChartAreas->Add(chartArea2);
               legend1->Name = L"Legend1";
               this->chart2->Legends->Add(legend1);
               this->chart2->Location = System::Drawing::Point(47, 27);
               this->chart2->Margin = System::Windows::Forms::Padding(2);
               this->chart2->Name = L"chart2";
               series1->ChartArea = L"ChartArea1";
               series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Candlestick;
               series1->Legend = L"Legend1";
               series1->Name = L"Candlesticks";
               series1->YValuesPerPoint = 4;
               series2->ChartArea = L"ChartArea2";
               series2->Legend = L"Legend1";
               series2->Name = L"Volume";
               this->chart2->Series->Add(series1);
               this->chart2->Series->Add(series2);
               this->chart2->Size = System::Drawing::Size(923, 549);
               this->chart2->TabIndex = 0;
               this->chart2->Text = L"s";
               // 
               // comboBox1
               // 
               this->comboBox1->FormattingEnabled = true;
               this->comboBox1->Location = System::Drawing::Point(409, 603);
               this->comboBox1->Name = L"comboBox1";
               this->comboBox1->Size = System::Drawing::Size(104, 21);
               this->comboBox1->TabIndex = 1;
               this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &chartForm::button1_Click);
               // 
               // label1
               // 
               this->label1->AutoSize = true;
               this->label1->Location = System::Drawing::Point(148, 603);
               this->label1->Name = L"label1";
               this->label1->Size = System::Drawing::Size(243, 13);
               this->label1->TabIndex = 2;
               this->label1->Text = L"Please Select a Pattern to annotate a pattern type";
               this->label1->Click += gcnew System::EventHandler(this, &chartForm::label1_Click);
               // 
               // button1
               // 
               this->button1->Location = System::Drawing::Point(576, 598);
               this->button1->Name = L"button1";
               this->button1->Size = System::Drawing::Size(181, 35);
               this->button1->TabIndex = 3;
               this->button1->Text = L"Clear Annotations";
               this->button1->UseVisualStyleBackColor = true;
               this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &chartForm::button1_MouseClick);
               // 
               // chartForm
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->ClientSize = System::Drawing::Size(1050, 677);
               this->Controls->Add(this->button1);
               this->Controls->Add(this->label1);
               this->Controls->Add(this->comboBox1);
               this->Controls->Add(this->chart2);
               this->Margin = System::Windows::Forms::Padding(2);
               this->Name = L"chartForm";
               this->Text = L"chartForm";
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
               this->ResumeLayout(false);
               this->PerformLayout();

           }



    //select combobox pattern and update the pattern 
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        int selectedIndex = comboBox1->SelectedIndex;

        if (selectedIndex >= 0 && selectedIndex < recognizerList->Count)
        {
            PatternRecognizer^ selectedRecognizer = recognizerList[selectedIndex];

            String^ recognizerName = selectedRecognizer->getName();
            UpdateChartData(tempTickerList, selectedRecognizer);


        }



    }


    //set the inital chart
    public:
        void chartForm::SetChartData(BindingList<SmartCandlestick^>^ tickerList)
        {
            tempTickerList = tickerList;
            chart2->Series["Candlesticks"]->Points->Clear();
            /*chart2->Annotations->Clear();*/ // Clear existing annotations

            //use bindinglist to connect the data to chart
            chart2->DataSource = tickerList;
            chart2->DataBind(); // Set XValueType to DateTime
            chart2->Series["Candlesticks"]->XValueType = ChartValueType::DateTime;
            chart2->Series["Candlesticks"]->Points->DataBindXY(tickerList, "Date", tickerList, "Low,High,Open,Close");
            chart2->Series["Volume"]->XValueType = ChartValueType::DateTime;
            chart2->Series["Volume"]->Points->DataBindXY(tickerList, "Date", tickerList,  "Volume");


            // populate pattern names in combobox
            for each (PatternRecognizer ^ pR in recognizerList) {
                comboBox1->Items->Add(pR->getName());

            }

            int count = 0;
            //color the candlesticks green and red on the up and downs.
            for each (SmartCandlestick ^ t in tickerList)
            {

                double open = t->Open;
                double close = t->Close;
                if (open < close)
                {
                    // Candlestick is up (green)
                    chart2->Series["Candlesticks"]->Points[count]->Color = Color::Green;
                }
                else if (open > close)
                {
                    // Candlestick is down (red)
                    chart2->Series["Candlesticks"]->Points[count]->Color = Color::Red;
                }
                count++;
                
            }

        }

    
    //function to annotate the chart with each new selection.
    public:
        void chartForm::AnnotateChart(String^ recognizerName, double x, double y)
        {
            RectangleAnnotation^ annotation = gcnew RectangleAnnotation();
            annotation->AxisX = chart2->ChartAreas["ChartArea1"]->AxisX;
            annotation->AxisY = chart2->ChartAreas["ChartArea1"]->AxisY;
            annotation->X = x - 30;
            annotation->Y = y + 20;

            // conditionals to check which recognizer is selected and annotate each individual stock pattern 
            if (recognizerName == "Doji")
            {

                annotation->Width = 5;
                annotation->Height = 4;
                annotation->LineColor = Color::Red;
                annotation->Text = "Doji";

            }
            else if (recognizerName == "Peak")
            {

                annotation->Width = 5;
                annotation->Height = 4;
                annotation->LineColor = Color::Blue;
                annotation->Text = "Peak Pattern";
            }
            else if (recognizerName == "Valley")
            {

                annotation->Width = 5;
                annotation->Height = 4;
                annotation->LineColor = Color::Green;
                annotation->Text = "Valley";
            }
            else if (recognizerName == "Hammer")
            {

                annotation->Width = 5;
                annotation->Height = 4;
                annotation->LineColor = Color::Yellow;
                annotation->Text = "Hammer";
            }
            else if (recognizerName == "Marubozu")
            {

                annotation->Width = 5;
                annotation->Height = 4;
                annotation->LineColor = Color::Turquoise;
                annotation->Text = "Marubozu";
              
            }
            else if (recognizerName == "Engulfing")
            {

                annotation->Width = 5;
                annotation->Height = 4;
                annotation->LineColor = Color::ForestGreen;
                annotation->Text = "Engulfing";
            }
            else if (recognizerName == "Harami")
            {

                annotation->Width = 5;
                annotation->Height = 4;
                annotation->LineColor = Color::Cyan;
                annotation->Text = "Harami";
            }

            

            // Add more conditions for other recognizers if needed

            chart2->Annotations->Add(annotation);
        }


    //update the chart with new annotations using the selection and patternRecognizers.
    public:
        void chartForm::UpdateChartData(BindingList<SmartCandlestick^>^ tickerList, PatternRecognizer^ recognizer)
        {
            tempTickerList = tickerList;
            /*chart2->Annotations->Clear();*/ // Clear existing annotations



            // populate pattern names in combobox


            int count = 0;

                for each (SmartCandlestick ^ t in tickerList)
                {

                    double open = t->Open;
                    double close = t->Close;

                    System::Collections::Generic::List<SmartCandlestick^>^ itemList = gcnew System::Collections::Generic::List<SmartCandlestick^>();

                    // Adjust the pattern size based on the recognizer's requirements
                    int recognizerPatternSize = recognizer->getPatternSize();

                    if (count >= recognizerPatternSize - 1) {
                        for (int i = count - recognizerPatternSize + 1; i <= count; i++) {
                            itemList->Add(tickerList[i]);
                        }

                        // Check if the recognizer supports the size of the list
                        if (recognizer->getPatternSize() == itemList->Count && recognizer->RecognizePattern(itemList))
                        {
                            // Annotate the chart based on the recognizer
                            AnnotateChart(recognizer->getName(), t->Date->ToOADate(), t->High);

                        }
                    }



                    count++;

                    // Add more conditions for other patterns if needed
                }
         }
        
    private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void button1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
    // Clear all annotations
    chart2->Annotations->Clear();
}
};



}