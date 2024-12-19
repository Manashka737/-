#pragma once
#include <fstream>
#include <string>
#include <Windows.h>
#include <iostream>
#include <vector>
#include <msclr/marshal_cppstd.h>




namespace Кулькулятор {
	using namespace System::IO;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	/// 
	/// 
	/// 
	
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		// Делегат для обновления суммы
		delegate void UpdateSumHandler(long long totalSum);
		event UpdateSumHandler^ OnUpdateSum;
	
		
		public:
		   MyForm(void)
		   {
			   InitializeComponent();
			   
			   expenses = gcnew System::Collections::Generic::List<Ex^>();
			   

		   }
		   public:
		ref struct Ex {
			System::String^category;
			long long sum;
			System::String^description;
			
		};
	private:System::Collections::Generic::List<Ex^>^ expenses;


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}

		}
	
	
	private: System::Windows::Forms::Button^ button_exit;
	private: System::Windows::Forms::ComboBox^ Категории;
	private: System::Windows::Forms::Label^ label1;






	public: System::Windows::Forms::TextBox^ textBox_summ;
	private: System::Windows::Forms::TextBox^ textBox_des;
	public:
	private:

	private:

	private:


	private: System::Windows::Forms::Label^ label_summ;
	private: System::Windows::Forms::Label^ description;
	private: System::Windows::Forms::Button^ ok_add;

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
		
		
		void InitializeComponent(void)
		{
			this->Категории = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox_summ = (gcnew System::Windows::Forms::TextBox());
			this->textBox_des = (gcnew System::Windows::Forms::TextBox());
			this->label_summ = (gcnew System::Windows::Forms::Label());
			this->description = (gcnew System::Windows::Forms::Label());
			this->ok_add = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Категории
			// 
			this->Категории->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->Категории->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->Категории->BackColor = System::Drawing::Color::Gray;
			this->Категории->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Категории->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Категории->FormattingEnabled = true;
			this->Категории->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Еда", L"Красота", L"Покупки", L"Развлечения",
					L"Транспорт"
			});
			this->Категории->Location = System::Drawing::Point(202, 79);
			this->Категории->Name = L"Категории";
			this->Категории->Size = System::Drawing::Size(229, 31);
			this->Категории->TabIndex = 6;
			this->Категории->Tag = L"";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(72, 83);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(117, 27);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Категория :";
			// 
			// textBox_summ
			// 
			this->textBox_summ->Location = System::Drawing::Point(202, 157);
			this->textBox_summ->Multiline = true;
			this->textBox_summ->Name = L"textBox_summ";
			this->textBox_summ->Size = System::Drawing::Size(229, 37);
			this->textBox_summ->TabIndex = 13;
			// 
			// textBox_des
			// 
			this->textBox_des->Location = System::Drawing::Point(202, 223);
			this->textBox_des->Multiline = true;
			this->textBox_des->Name = L"textBox_des";
			this->textBox_des->Size = System::Drawing::Size(229, 62);
			this->textBox_des->TabIndex = 13;
			// 
			// label_summ
			// 
			this->label_summ->AutoSize = true;
			this->label_summ->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_summ->Location = System::Drawing::Point(72, 157);
			this->label_summ->Name = L"label_summ";
			this->label_summ->Size = System::Drawing::Size(85, 27);
			this->label_summ->TabIndex = 14;
			this->label_summ->Text = L"Сумма :";
			// 
			// description
			// 
			this->description->AutoSize = true;
			this->description->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->description->Location = System::Drawing::Point(58, 223);
			this->description->Name = L"description";
			this->description->Size = System::Drawing::Size(99, 27);
			this->description->TabIndex = 15;
			this->description->Text = L"Заметка :";
			// 
			// ok_add
			// 
			this->ok_add->BackColor = System::Drawing::Color::Transparent;
			this->ok_add->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ok_add->Location = System::Drawing::Point(441, 343);
			this->ok_add->Name = L"ok_add";
			this->ok_add->Size = System::Drawing::Size(80, 39);
			this->ok_add->TabIndex = 16;
			this->ok_add->Text = L"Ok";
			this->ok_add->UseVisualStyleBackColor = false;
			this->ok_add->Click += gcnew System::EventHandler(this, &MyForm::ok_add_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Gray;
			this->ClientSize = System::Drawing::Size(670, 424);
			this->Controls->Add(this->ok_add);
			this->Controls->Add(this->description);
			this->Controls->Add(this->label_summ);
			this->Controls->Add(this->textBox_des);
			this->Controls->Add(this->textBox_summ);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Категории);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Кулькулятор";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
		
	
	



private: System::Void ok_add_Click(System::Object^ sender, System::EventArgs^ e) {
	
	if (String::IsNullOrWhiteSpace(Категории->Text)) {
		MessageBox::Show("Пожалуйста, заполните поле 'Категория'.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	if (String::IsNullOrWhiteSpace(textBox_summ->Text)) {
		MessageBox::Show("Пожалуйста, заполните поле 'Сумма'.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	if (!String::IsNullOrWhiteSpace(Категории->Text) && !String::IsNullOrWhiteSpace(textBox_summ->Text) ) {
		
		Ex^ expense = gcnew Ex();
		expense->category = Категории->Text;
		try
		{
			expense->sum = Convert::ToInt64(textBox_summ->Text);
		}
		catch (FormatException^) 
		{
			MessageBox::Show("Неверный формат.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		expense->description = textBox_des->Text;

		expenses->Add(expense);
		

		ofstream fs("expenses.txt", ios::app);
		if (fs.is_open()) {
			msclr::interop::marshal_context context;
			fs << "Категория: " << context.marshal_as<std::string>(expense->category) << "\n";
			fs << "Сумма: " << expense->sum << "\n";
			fs << "Описание: " << context.marshal_as<std::string>(expense->description) << "\n";
			fs.close();

		}
		else
		{
			MessageBox::Show("Пожалуйста, заполните все поля.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);

		}
		LoadExpenses();
		
}
}
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

		   
		   OnUpdateSum(totalSum);
	   }
};
}
