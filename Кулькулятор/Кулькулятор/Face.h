#pragma once

#include "MyForm.h"
#include <thread>
#include <chrono>
#include <Windows.h>
#include <map>


namespace Кулькулятор {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Face
	/// </summary>
	public ref class Face : public System::Windows::Forms::Form
	{
	private:MyForm^ fromo123;
		
	public:
		Face(MyForm^ form)
		{
			
			InitializeComponent();
			LoadExpenses();
			
			fromo123 = form;
			fromo123->OnUpdateSum += gcnew MyForm::UpdateSumHandler(this, &Face::UpdateLabelSum);
		
			//
			//TODO: добавьте код конструктора
			//
			
		}
	private:
		void LoadExpenses() {
			std::ifstream fs("expenses.txt");
			std::string line;
			long long totalSum = 0;

			while (std::getline(fs, line)) {
				if (line.find("Сумма:") != std::string::npos) {
					std::string sumStr = line.substr(line.find(":") + 1);
					totalSum += std::stoll(sumStr);
				}
			}

			fs.close();

			result_summ->Text = "Общие расходы: " + totalSum.ToString("C");
		}
	public:void UpChart()
	{
		
		this->chart1->Series[0]->Points->Clear();

		
		std::ifstream fs("expenses.txt");
		std::string line;

		
		std::map<std::string, double> expensesMap;

		while (std::getline(fs, line)) {
			if (line.find("Категория:") != std::string::npos) {
				std::string category = line.substr(line.find(":") + 1);
				std::getline(fs, line); 
				if (line.find("Сумма:") != std::string::npos) {
					std::string sumStr = line.substr(line.find(":") + 1);
					double sum = std::stod(sumStr);
					expensesMap[category] += sum; 
				}
			}
		}

		fs.close();

		
		for (const auto& entry : expensesMap) {
			this->chart1->Series[0]->Points->AddXY(gcnew String(entry.first.c_str()), entry.second);
		}

		
		long long totalSum = 0;
		for (const auto& entry : expensesMap) {
			totalSum += entry.second;
		}
		result_summ->Text = "Общие расходы: " + totalSum.ToString("C");
	}
	
	private:
		void UpdateLabelSum(long long totalSum) {
			result_summ->Text = "Общие расходы: " + totalSum.ToString("C");
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Face()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ add_expenses;
	private: System::Windows::Forms::Button^ buyyon_exit;
	private: System::Windows::Forms::Label^ result_summ;


	private: System::Windows::Forms::Button^ sgow_expenses;
	private: System::Windows::Forms::Button^ button_exit;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;


	protected:

	protected:

	protected:

	protected:


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		/// 
		/// 
		/// 

		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->add_expenses = (gcnew System::Windows::Forms::Button());
			this->result_summ = (gcnew System::Windows::Forms::Label());
			this->sgow_expenses = (gcnew System::Windows::Forms::Button());
			this->button_exit = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// add_expenses
			// 
			this->add_expenses->BackColor = System::Drawing::Color::Transparent;
			this->add_expenses->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->add_expenses->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->add_expenses->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->add_expenses->Location = System::Drawing::Point(506, 585);
			this->add_expenses->Name = L"add_expenses";
			this->add_expenses->Size = System::Drawing::Size(98, 40);
			this->add_expenses->TabIndex = 0;
			this->add_expenses->Text = L"Добавить";
			this->add_expenses->UseVisualStyleBackColor = false;
			this->add_expenses->Click += gcnew System::EventHandler(this, &Face::add_expenses_Click);
			// 
			// result_summ
			// 
			this->result_summ->BackColor = System::Drawing::Color::Transparent;
			this->result_summ->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI Light", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->result_summ->ForeColor = System::Drawing::Color::Black;
			this->result_summ->Location = System::Drawing::Point(99, 474);
			this->result_summ->Name = L"result_summ";
			this->result_summ->Size = System::Drawing::Size(353, 35);
			this->result_summ->TabIndex = 2;
			this->result_summ->Text = L"Общие расходы : 0";
			// 
			// sgow_expenses
			// 
			this->sgow_expenses->BackColor = System::Drawing::Color::Transparent;
			this->sgow_expenses->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->sgow_expenses->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sgow_expenses->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->sgow_expenses->Location = System::Drawing::Point(47, 585);
			this->sgow_expenses->Name = L"sgow_expenses";
			this->sgow_expenses->Size = System::Drawing::Size(98, 40);
			this->sgow_expenses->TabIndex = 3;
			this->sgow_expenses->Text = L"Расходы";
			this->sgow_expenses->UseVisualStyleBackColor = false;
			// 
			// button_exit
			// 
			this->button_exit->FlatAppearance->BorderSize = 0;
			this->button_exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_exit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_exit->ForeColor = System::Drawing::SystemColors::Control;
			this->button_exit->Location = System::Drawing::Point(599, -1);
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(60, 50);
			this->button_exit->TabIndex = 4;
			this->button_exit->Text = L"X";
			this->button_exit->UseVisualStyleBackColor = true;
			this->button_exit->Click += gcnew System::EventHandler(this, &Face::button_exit_Click);
			// 
			// chart1
			// 
			chartArea1->BackColor = System::Drawing::Color::Gray;
			chartArea1->BorderColor = System::Drawing::Color::Transparent;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->Location = System::Drawing::Point(103, 92);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Doughnut;
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(573, 364);
			this->chart1->TabIndex = 5;
			this->chart1->Text = L"chart";
			
			// 
			// Face
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Gray;
			this->ClientSize = System::Drawing::Size(793, 653);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->button_exit);
			this->Controls->Add(this->sgow_expenses);
			this->Controls->Add(this->result_summ);
			this->Controls->Add(this->add_expenses);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Face";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Face";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}


#pragma endregion
	private:double a, b, h;
	private: double x, y;


private: System::Void button_exit_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}



	   private: System::Void add_expenses_Click(System::Object^ sender, System::EventArgs^ e);

	   

};
}
