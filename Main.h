#pragma once

namespace integraloop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent();
			equ->DropDownStyle = ComboBoxStyle::DropDownList;
			equ_SelectedIndexChanged(equ, System::EventArgs::Empty);
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ Group1;
	protected:
	private: System::Windows::Forms::NumericUpDown^ accuracy;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::NumericUpDown^ b;
	private: System::Windows::Forms::NumericUpDown^ a;

	private: System::Windows::Forms::Label^ segment;
	private: System::Windows::Forms::ComboBox^ equ;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ result1;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TextBox^ result3;

	private: System::Windows::Forms::TextBox^ result2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart;
	private: System::Windows::Forms::TextBox^ error2;

	private: System::Windows::Forms::TextBox^ error1;



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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Title^ title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			this->Group1 = (gcnew System::Windows::Forms::GroupBox());
			this->accuracy = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->b = (gcnew System::Windows::Forms::NumericUpDown());
			this->a = (gcnew System::Windows::Forms::NumericUpDown());
			this->segment = (gcnew System::Windows::Forms::Label());
			this->equ = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->result1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->error2 = (gcnew System::Windows::Forms::TextBox());
			this->error1 = (gcnew System::Windows::Forms::TextBox());
			this->result3 = (gcnew System::Windows::Forms::TextBox());
			this->result2 = (gcnew System::Windows::Forms::TextBox());
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->Group1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->accuracy))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->b))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->a))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
			this->SuspendLayout();
			// 
			// Group1
			// 
			this->Group1->Controls->Add(this->accuracy);
			this->Group1->Controls->Add(this->label6);
			this->Group1->Controls->Add(this->label5);
			this->Group1->Controls->Add(this->label4);
			this->Group1->Controls->Add(this->b);
			this->Group1->Controls->Add(this->a);
			this->Group1->Controls->Add(this->segment);
			this->Group1->Controls->Add(this->equ);
			this->Group1->Controls->Add(this->label1);
			this->Group1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Group1->Location = System::Drawing::Point(9, 8);
			this->Group1->Name = L"Group1";
			this->Group1->Size = System::Drawing::Size(399, 90);
			this->Group1->TabIndex = 1;
			this->Group1->TabStop = false;
			this->Group1->Text = L"Уравнения для интегрирования";
			// 
			// accuracy
			// 
			this->accuracy->DecimalPlaces = 4;
			this->accuracy->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->accuracy->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 262144 });
			this->accuracy->Location = System::Drawing::Point(322, 53);
			this->accuracy->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->accuracy->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 262144 });
			this->accuracy->Name = L"accuracy";
			this->accuracy->Size = System::Drawing::Size(71, 26);
			this->accuracy->TabIndex = 12;
			this->accuracy->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->accuracy->ValueChanged += gcnew System::EventHandler(this, &Main::accuracy_ValueChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(238, 55);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(80, 20);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Точность";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(219, 55);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(13, 20);
			this->label5->TabIndex = 10;
			this->label5->Text = L"]";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(156, 57);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(13, 18);
			this->label4->TabIndex = 9;
			this->label4->Text = L";";
			// 
			// b
			// 
			this->b->DecimalPlaces = 1;
			this->b->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->b->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->b->Location = System::Drawing::Point(171, 53);
			this->b->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->b->Name = L"b";
			this->b->Size = System::Drawing::Size(47, 26);
			this->b->TabIndex = 7;
			this->b->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->b->ValueChanged += gcnew System::EventHandler(this, &Main::b_ValueChanged);
			// 
			// a
			// 
			this->a->DecimalPlaces = 1;
			this->a->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->a->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->a->Location = System::Drawing::Point(103, 53);
			this->a->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->a->Name = L"a";
			this->a->Size = System::Drawing::Size(53, 26);
			this->a->TabIndex = 6;
			this->a->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, System::Int32::MinValue });
			this->a->ValueChanged += gcnew System::EventHandler(this, &Main::a_ValueChanged);
			// 
			// segment
			// 
			this->segment->AutoSize = true;
			this->segment->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->segment->Location = System::Drawing::Point(23, 55);
			this->segment->Name = L"segment";
			this->segment->Size = System::Drawing::Size(81, 20);
			this->segment->TabIndex = 4;
			this->segment->Text = L"Отрезок [";
			// 
			// equ
			// 
			this->equ->DisplayMember = L"1";
			this->equ->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->equ->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->equ->FormattingEnabled = true;
			this->equ->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"y=sin(x)", L"y=cos(x)", L"y=2*x²", L"y=x", L"y=5ᵡ",
					L"y=1/5²+x²", L"y=eᵡ", L"y=(x+2)³"
			});
			this->equ->Location = System::Drawing::Point(218, 18);
			this->equ->Name = L"equ";
			this->equ->Size = System::Drawing::Size(121, 28);
			this->equ->TabIndex = 2;
			this->equ->Text = L"y=sin(x)";
			this->equ->SelectedIndexChanged += gcnew System::EventHandler(this, &Main::equ_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(23, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(168, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Выберите уравнение";
			// 
			// result1
			// 
			this->result1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->result1->HideSelection = false;
			this->result1->Location = System::Drawing::Point(173, 33);
			this->result1->Margin = System::Windows::Forms::Padding(2);
			this->result1->MaximumSize = System::Drawing::Size(120, 24);
			this->result1->MinimumSize = System::Drawing::Size(120, 24);
			this->result1->Name = L"result1";
			this->result1->ReadOnly = true;
			this->result1->Size = System::Drawing::Size(120, 26);
			this->result1->TabIndex = 13;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(32, 35);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(136, 20);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Метод трапеций\r\n";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(32, 81);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(129, 20);
			this->label3->TabIndex = 15;
			this->label3->Text = L"Метод прямоуг.";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(32, 130);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(139, 20);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Метод Симпсона";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->error2);
			this->groupBox1->Controls->Add(this->error1);
			this->groupBox1->Controls->Add(this->result3);
			this->groupBox1->Controls->Add(this->result2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->result1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(9, 103);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(399, 180);
			this->groupBox1->TabIndex = 17;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Результат интегрирования";
			// 
			// error2
			// 
			this->error2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->error2->HideSelection = false;
			this->error2->Location = System::Drawing::Point(303, 81);
			this->error2->Margin = System::Windows::Forms::Padding(2);
			this->error2->MaximumSize = System::Drawing::Size(90, 24);
			this->error2->MinimumSize = System::Drawing::Size(90, 24);
			this->error2->Name = L"error2";
			this->error2->ReadOnly = true;
			this->error2->Size = System::Drawing::Size(90, 26);
			this->error2->TabIndex = 20;
			// 
			// error1
			// 
			this->error1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->error1->HideSelection = false;
			this->error1->Location = System::Drawing::Point(303, 33);
			this->error1->Margin = System::Windows::Forms::Padding(2);
			this->error1->MaximumSize = System::Drawing::Size(90, 24);
			this->error1->MinimumSize = System::Drawing::Size(90, 24);
			this->error1->Name = L"error1";
			this->error1->ReadOnly = true;
			this->error1->Size = System::Drawing::Size(90, 26);
			this->error1->TabIndex = 19;
			// 
			// result3
			// 
			this->result3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->result3->HideSelection = false;
			this->result3->Location = System::Drawing::Point(173, 127);
			this->result3->Margin = System::Windows::Forms::Padding(2);
			this->result3->MinimumSize = System::Drawing::Size(172, 24);
			this->result3->Name = L"result3";
			this->result3->ReadOnly = true;
			this->result3->Size = System::Drawing::Size(220, 26);
			this->result3->TabIndex = 18;
			// 
			// result2
			// 
			this->result2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->result2->HideSelection = false;
			this->result2->Location = System::Drawing::Point(173, 81);
			this->result2->Margin = System::Windows::Forms::Padding(2);
			this->result2->MaximumSize = System::Drawing::Size(120, 24);
			this->result2->MinimumSize = System::Drawing::Size(120, 24);
			this->result2->Name = L"result2";
			this->result2->ReadOnly = true;
			this->result2->Size = System::Drawing::Size(120, 26);
			this->result2->TabIndex = 17;
			// 
			// chart
			// 
			chartArea1->IsSameFontSizeForAllAxes = true;
			chartArea1->Name = L"ChartArea1";
			this->chart->ChartAreas->Add(chartArea1);
			legend1->Alignment = System::Drawing::StringAlignment::Center;
			legend1->BackImageAlignment = System::Windows::Forms::DataVisualization::Charting::ChartImageAlignmentStyle::Center;
			legend1->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Bottom;
			legend1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			legend1->IsTextAutoFit = false;
			legend1->Name = L"y1";
			this->chart->Legends->Add(legend1);
			this->chart->Location = System::Drawing::Point(413, 8);
			this->chart->MinimumSize = System::Drawing::Size(85, 83);
			this->chart->Name = L"chart";
			this->chart->Size = System::Drawing::Size(529, 275);
			this->chart->TabIndex = 19;
			this->chart->Text = L"chart";
			title1->Name = L"График";
			this->chart->Titles->Add(title1);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(954, 303);
			this->Controls->Add(this->chart);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->Group1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(970, 342);
			this->Name = L"Main";
			this->Text = L"Интеграл";
			this->Group1->ResumeLayout(false);
			this->Group1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->accuracy))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->b))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->a))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: 
		System::Void equ_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void data_manager(equation);

	    System::Void a_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
			equ_SelectedIndexChanged(equ, System::EventArgs::Empty);
		}
        System::Void b_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
			equ_SelectedIndexChanged(equ, System::EventArgs::Empty);
		}
		System::Void accuracy_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
			equ_SelectedIndexChanged(equ, System::EventArgs::Empty);
		}

};
}
