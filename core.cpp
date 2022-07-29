#include "equation.h" 
#include "Main.h"



System::Void integraloop::Main::equ_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{

	equation equation(Convert::ToInt32(equ->SelectedIndex), Convert::ToDouble(a->Value), Convert::ToDouble(b->Value), Convert::ToDouble(accuracy->Value));

	equation.trapezoidalIntegral();
	equation.centralrectanglesIntegral();
	equation.SimpsonIntegral();
	data_manager(equation);
	
}

System::Void integraloop::Main::data_manager(equation equation) {

	result1->Text = equation.result_trapezoidalIntegral.ToString("F10");
	result2->Text = equation.result_centralrectanglesIntegral[equation.size - 1].ToString("F10");
	result3->Text = equation.result_SimpsonIntegral.ToString("F10");

	error1->Text = "±" + equation.error_trapezoidalIntegral.ToString("F6");
	error2->Text = "±" + equation.error_centralrectanglesIntegral.ToString("F6");

	String^ equ_name = equ->Text;
	String^ equ_dx = equ->Text + " dx";
	chart->Series->Clear();
	System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
	System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
	series1->BorderWidth = 3;
	series1->ChartArea = L"ChartArea1";
	series1->Legend = L"y1";
	series1->Name = equ_dx;
	series2->BackSecondaryColor = System::Drawing::Color::Red;
	series2->BorderColor = System::Drawing::Color::Red;
	series2->BorderWidth = 3;
	series2->ChartArea = L"ChartArea1";
	series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
	series2->Color = System::Drawing::Color::Red;
	series2->Legend = L"y1";
	series2->Name = equ_name;
	this->chart->Series->Add(series1);
	this->chart->Series->Add(series2);

	chart->Series[equ_dx]->Points->Clear();
	chart->Series[equ_name]->Points->Clear();

	for (int i = 0; i < equation.size; i++) {
		chart->Series[equ_dx]->Points->AddXY(equation.x[i], equation.result_centralrectanglesIntegral[i]);
		chart->Series[equ_name]->Points->AddXY(equation.x[i], equation.y[i]);
	}

}