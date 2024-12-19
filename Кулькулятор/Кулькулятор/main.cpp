#include "Face.h"
#include <map>
using namespace std;
using namespace System;
using namespace System::Windows::Forms;

using namespace Кулькулятор;
[STAThreadAttribute]

int main (cli::array<String^> ^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
   
	MyForm^ fromo123 = gcnew MyForm();
	
	Application::Run(gcnew Face(fromo123));


	return 0;
}

System::Void Face::add_expenses_Click(System::Object^ sender, System::EventArgs^ e)
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

  
    MyForm^ newForm = gcnew MyForm();
    newForm->Show();

}

