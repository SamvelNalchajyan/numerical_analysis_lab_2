#pragma once
#include "../Lab2/ЧМ з. 11/boundary_value_problem.h"
#include "../Lab2/ЧМ з. 11/boundary_value_problem.cpp"

namespace Graph {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ZedGraph;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: ZedGraph::ZedGraphControl^ zedGraphControl1;
	private: System::Windows::Forms::Button^ button_Draw;

	private: System::Windows::Forms::DataGridView^ dataGridView1;



































	private: System::Windows::Forms::TextBox^ textBox_z_0;

	private: System::Windows::Forms::Label^ label1;












	private: ZedGraph::ZedGraphControl^ zedGraphControl2;
















	private: System::Windows::Forms::Button^ button_Clear;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ i;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ x_i;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ u_i;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ v_i;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ v2_i;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn7;
	private: System::Windows::Forms::TextBox^ textBox_n;
	private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Button^ button1;
private: System::Windows::Forms::TextBox^ textBox_err_test;
private: System::Windows::Forms::TextBox^ textBox_err_main;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::Label^ label4;


























































	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->zedGraphControl1 = (gcnew ZedGraph::ZedGraphControl());
			this->button_Draw = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->x_i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->u_i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->v_i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBox_z_0 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->zedGraphControl2 = (gcnew ZedGraph::ZedGraphControl());
			this->button_Clear = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->v2_i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBox_n = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox_err_test = (gcnew System::Windows::Forms::TextBox());
			this->textBox_err_main = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// zedGraphControl1
			// 
			this->zedGraphControl1->Location = System::Drawing::Point(38, 30);
			this->zedGraphControl1->Name = L"zedGraphControl1";
			this->zedGraphControl1->ScrollGrace = 0;
			this->zedGraphControl1->ScrollMaxX = 0;
			this->zedGraphControl1->ScrollMaxY = 0;
			this->zedGraphControl1->ScrollMaxY2 = 0;
			this->zedGraphControl1->ScrollMinX = 0;
			this->zedGraphControl1->ScrollMinY = 0;
			this->zedGraphControl1->ScrollMinY2 = 0;
			this->zedGraphControl1->Size = System::Drawing::Size(501, 327);
			this->zedGraphControl1->TabIndex = 0;
			this->zedGraphControl1->Load += gcnew System::EventHandler(this, &MyForm::zedGraphControl1_Load);
			// 
			// button_Draw
			// 
			this->button_Draw->Location = System::Drawing::Point(1207, 30);
			this->button_Draw->Name = L"button_Draw";
			this->button_Draw->Size = System::Drawing::Size(142, 29);
			this->button_Draw->TabIndex = 1;
			this->button_Draw->Text = L"Тестовая функция";
			this->button_Draw->UseVisualStyleBackColor = true;
			this->button_Draw->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->i, this->x_i,
					this->u_i, this->v_i, this->Column3
			});
			this->dataGridView1->Location = System::Drawing::Point(549, 30);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(636, 327);
			this->dataGridView1->TabIndex = 2;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// i
			// 
			this->i->HeaderText = L"i";
			this->i->Name = L"i";
			this->i->Width = 50;
			// 
			// x_i
			// 
			this->x_i->HeaderText = L"x_i";
			this->x_i->Name = L"x_i";
			this->x_i->Width = 120;
			// 
			// u_i
			// 
			this->u_i->HeaderText = L"u_i";
			this->u_i->Name = L"u_i";
			this->u_i->Width = 120;
			// 
			// v_i
			// 
			this->v_i->HeaderText = L"v_i";
			this->v_i->Name = L"v_i";
			this->v_i->Width = 120;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"|u_i - v_i|";
			this->Column3->Name = L"Column3";
			this->Column3->Width = 120;
			// 
			// textBox_z_0
			// 
			this->textBox_z_0->Location = System::Drawing::Point(1124, 672);
			this->textBox_z_0->Name = L"textBox_z_0";
			this->textBox_z_0->Size = System::Drawing::Size(61, 20);
			this->textBox_z_0->TabIndex = 26;
			this->textBox_z_0->Text = L"0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1091, 675);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(27, 13);
			this->label1->TabIndex = 27;
			this->label1->Text = L"u\'_0";
			// 
			// zedGraphControl2
			// 
			this->zedGraphControl2->Location = System::Drawing::Point(38, 365);
			this->zedGraphControl2->Name = L"zedGraphControl2";
			this->zedGraphControl2->ScrollGrace = 0;
			this->zedGraphControl2->ScrollMaxX = 0;
			this->zedGraphControl2->ScrollMaxY = 0;
			this->zedGraphControl2->ScrollMaxY2 = 0;
			this->zedGraphControl2->ScrollMinX = 0;
			this->zedGraphControl2->ScrollMinY = 0;
			this->zedGraphControl2->ScrollMinY2 = 0;
			this->zedGraphControl2->Size = System::Drawing::Size(501, 327);
			this->zedGraphControl2->TabIndex = 28;
			// 
			// button_Clear
			// 
			this->button_Clear->Location = System::Drawing::Point(1207, 120);
			this->button_Clear->Name = L"button_Clear";
			this->button_Clear->Size = System::Drawing::Size(142, 29);
			this->button_Clear->TabIndex = 45;
			this->button_Clear->Text = L"Стереть";
			this->button_Clear->UseVisualStyleBackColor = true;
			this->button_Clear->Click += gcnew System::EventHandler(this, &MyForm::button_Clear_Click);
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->v2_i, this->dataGridViewTextBoxColumn7
			});
			this->dataGridView2->Location = System::Drawing::Point(549, 365);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersVisible = false;
			this->dataGridView2->Size = System::Drawing::Size(636, 327);
			this->dataGridView2->TabIndex = 46;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"i";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->Width = 50;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"x_i";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->Width = 120;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"v_i";
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->Width = 120;
			// 
			// v2_i
			// 
			this->v2_i->HeaderText = L"v2_i";
			this->v2_i->Name = L"v2_i";
			this->v2_i->Width = 120;
			// 
			// dataGridViewTextBoxColumn7
			// 
			this->dataGridViewTextBoxColumn7->HeaderText = L"|v_i - v2_i|";
			this->dataGridViewTextBoxColumn7->Name = L"dataGridViewTextBoxColumn7";
			this->dataGridViewTextBoxColumn7->Width = 120;
			// 
			// textBox_n
			// 
			this->textBox_n->Location = System::Drawing::Point(1249, 178);
			this->textBox_n->Name = L"textBox_n";
			this->textBox_n->Size = System::Drawing::Size(100, 20);
			this->textBox_n->TabIndex = 47;
			this->textBox_n->Text = L"100";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(1230, 181);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(13, 13);
			this->label2->TabIndex = 48;
			this->label2->Text = L"n";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1207, 65);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(142, 29);
			this->button1->TabIndex = 49;
			this->button1->Text = L"Основная функция";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// textBox_err_test
			// 
			this->textBox_err_test->Location = System::Drawing::Point(1191, 337);
			this->textBox_err_test->Name = L"textBox_err_test";
			this->textBox_err_test->Size = System::Drawing::Size(148, 20);
			this->textBox_err_test->TabIndex = 50;
			// 
			// textBox_err_main
			// 
			this->textBox_err_main->Location = System::Drawing::Point(1191, 672);
			this->textBox_err_main->Name = L"textBox_err_main";
			this->textBox_err_main->Size = System::Drawing::Size(148, 20);
			this->textBox_err_main->TabIndex = 51;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1191, 321);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(243, 13);
			this->label3->TabIndex = 52;
			this->label3->Text = L"Максимальная погрешность тестовой задачи:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(1191, 656);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(245, 13);
			this->label4->TabIndex = 53;
			this->label4->Text = L"Максимальная погрешность основной задачи:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1468, 722);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox_err_main);
			this->Controls->Add(this->textBox_err_test);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox_n);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->button_Clear);
			this->Controls->Add(this->zedGraphControl2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox_z_0);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button_Draw);
			this->Controls->Add(this->zedGraphControl1);
			this->Name = L"MyForm";
			this->Text = L"Lab 2";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		double f1(double x) {
			return sin(x);
		}

		double f2(double x) {
			return sin(2 * x);
		}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		GraphPane^ panel = zedGraphControl1->GraphPane;
		GraphPane^ panel2 = zedGraphControl2->GraphPane;

		panel->CurveList->Clear();
		panel2->CurveList->Clear();
		//panel3->CurveList->Clear();
		panel->XAxis->Title->Text = "Ось x";
		panel->YAxis->Title->Text = "Ось v";
		panel->Title->Text = "График решения тестовой задачи";
		panel2->XAxis->Title->Text = "Ось x";
		panel2->YAxis->Title->Text = "Ось |u - v|";
		panel2->Title->Text = "График погрешности";
		PointPairList^ f1_list = gcnew ZedGraph::PointPairList();
		PointPairList^ f2_list = gcnew ZedGraph::PointPairList();
		PointPairList^ f3_list = gcnew ZedGraph::PointPairList();

		int n = Convert::ToInt32(textBox_n->Text);
		//double h = 1.0 / n;


		//std::list<std::vector<double>> num_func = numerical_function_task11(x_0, u_0, z_0, h, xmax, n);
		std::list<std::vector<double>> num_func = numerical_test_task(n);
		// Список точек
		dataGridView1->Rows->Clear();
		//dataGridView2->Rows->Clear();
		std::list<std::vector<double>> ::iterator it;
		int i = 0;
		double x = 0;
		/*
		double global_error = 0;
		double global_error_max = 0;
		double global_error_max_x = x_0;

		double max_local_error = 0;
		double max_h = 0;
		int C1_count = 0, C2_count = 0;
		*/
		double max_error = 0;
		double error_x = 0;

		for (it = num_func.begin(); it != num_func.end(); it++)
		{
			x = it->at(0);
			//Добавление на график
			f1_list->Add(x, it->at(1));
			f2_list->Add(x, it->at(2));
			f3_list->Add(x, it->at(3));
			//Поиск максимальной глобальной ошибки
			/*
			global_error = abs(analytical_test_function(x, x_0, u_0) - it->at(1));
			if (global_error > global_error_max) {
				global_error_max = global_error;
				global_error_max_x = x;
			}
			*/

			//Печать в таблицу
			dataGridView1->Rows->Add();
			dataGridView1->Rows[i]->Cells[0]->Value = i;
			dataGridView1->Rows[i]->Cells[1]->Value = x;
			dataGridView1->Rows[i]->Cells[2]->Value = it->at(1);
			dataGridView1->Rows[i]->Cells[3]->Value = it->at(2);
			dataGridView1->Rows[i]->Cells[4]->Value = it->at(3);

			if (it->at(3) > max_error)
			{
				max_error = it->at(3);
				error_x = x;
			}

			i++;
		}

		//textBox_max_GE->Text = Convert::ToString(global_error_max);
		//textBox_max_GE_x->Text = Convert::ToString(global_error_max_x);

		LineItem Curve1 = panel->AddCurve("Analytical", f1_list, Color::Blue, SymbolType::None);
		LineItem Curve2 = panel->AddCurve("Numerical", f2_list, Color::Red, SymbolType::None);
		LineItem Curve3 = panel2->AddCurve("Error", f3_list, Color::MediumSlateBlue, SymbolType::None);

		textBox_err_test->Text = Convert::ToString(max_error);
		//textBox_max_LE->Text = Convert::ToString(max_local_error);

		// Устанавливаем интересующий нас интервал по оси X
		//panel->XAxis->Scale->Min = xmin_limit;
		//panel->XAxis->Scale->Max = xmax_limit;
/*
		// Устанавливаем интересующий нас интервал по оси Y
		panel->YAxis->Scale->Min = ymin_limit;
		panel->YAxis->Scale->Max = ymax_limit;


*/

		panel->XAxis->Scale->MinAuto = true;
		panel->XAxis->Scale->MaxAuto = true;
		panel->YAxis->Scale->MinAuto = true;
		panel->YAxis->Scale->MaxAuto = true;

		panel2->XAxis->Scale->MinAuto = true;
		panel2->XAxis->Scale->MaxAuto = true;
		panel2->YAxis->Scale->MinAuto = true;
		panel2->YAxis->Scale->MaxAuto = true;
// Вызываем метод AxisChange (), чтобы обновить данные об осях. 
// В противном случае на рисунке будет показана только часть графика, 
// которая умещается в интервалы по осям, установленные по умолчанию
		zedGraphControl1->AxisChange();
		// Обновляем график
		zedGraphControl1->Invalidate();
		// которая умещается в интервалы по осям, установленные по умолчанию
		zedGraphControl2->AxisChange();
		// Обновляем график
		zedGraphControl2->Invalidate();


	}
	private: System::Void zedGraphControl1_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		/*
		GraphPane^ panel = zedGraphControl1->GraphPane;
		double xmin = Convert::ToDouble(textBox_x_0->Text);
		double xmax = Convert::ToDouble(textBox_x_max->Text);
		// Устанавливаем интересующий нас интервал по оси X
		panel->XAxis->Scale->Min = xmin;
		panel->XAxis->Scale->Max = xmax;
		panel->YAxis->Scale->Min = xmin;
		panel->YAxis->Scale->Max = xmax;

		// Вызываем метод AxisChange (), чтобы обновить данные об осях.
		// В противном случае на рисунке будет показана только часть графика,
		// которая умещается в интервалы по осям, установленные по умолчанию
		zedGraphControl1->AxisChange();
		// Обновляем график
		zedGraphControl1->Invalidate();
		*/
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button_Clear_Click(System::Object^ sender, System::EventArgs^ e) {
		GraphPane^ panel = zedGraphControl1->GraphPane;
		GraphPane^ panel2 = zedGraphControl2->GraphPane;
		panel->CurveList->Clear();
		panel2->CurveList->Clear();
		// которая умещается в интервалы по осям, установленные по умолчанию
		zedGraphControl1->AxisChange();
		// Обновляем график
		zedGraphControl1->Invalidate();
		// которая умещается в интервалы по осям, установленные по умолчанию
		zedGraphControl2->AxisChange();
		// Обновляем график
		zedGraphControl2->Invalidate();

		dataGridView1->Rows->Clear();
		dataGridView2->Rows->Clear();

		textBox_err_main->Text = "";
		textBox_err_test->Text = "";
	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		GraphPane^ panel = zedGraphControl1->GraphPane;
		GraphPane^ panel2 = zedGraphControl2->GraphPane;

		panel->CurveList->Clear();
		panel2->CurveList->Clear();
		panel->XAxis->Title->Text = "Ось x";
		panel->YAxis->Title->Text = "Ось v";
		panel->Title->Text = "График решения основной задачи";
		panel2->XAxis->Title->Text = "Ось x";
		panel2->YAxis->Title->Text = "Ось |v - v2|";
		panel2->Title->Text = "График погрешности";
		PointPairList^ f1_list = gcnew ZedGraph::PointPairList();
		PointPairList^ f2_list = gcnew ZedGraph::PointPairList();
		PointPairList^ f3_list = gcnew ZedGraph::PointPairList();
		int n = Convert::ToInt32(textBox_n->Text);

		std::list<std::vector<double>> num_func = numerical_main_task(n);
		//dataGridView1->Rows->Clear();
		dataGridView2->Rows->Clear();
		std::list<std::vector<double>> ::iterator it;
		int i = 0;
		double x = 0;

		double max_error = 0;
		double error_x = 0;

		for (it = num_func.begin(); it != num_func.end(); it++)
		{
			x = it->at(0);
			//Добавление на график
			f1_list->Add(x, it->at(1));
			f2_list->Add(x, it->at(2));
			f3_list->Add(x, it->at(3));
			

			//Печать в таблицу
			dataGridView2->Rows->Add();
			dataGridView2->Rows[i]->Cells[0]->Value = i;
			dataGridView2->Rows[i]->Cells[1]->Value = x;
			dataGridView2->Rows[i]->Cells[2]->Value = it->at(1);
			dataGridView2->Rows[i]->Cells[3]->Value = it->at(2);
			dataGridView2->Rows[i]->Cells[4]->Value = it->at(3);

			if (it->at(3) > max_error)
			{
				max_error = it->at(3);
				error_x = x;
			}

			i++;
		}
		LineItem Curve1 = panel->AddCurve("Numerical v", f1_list, Color::Blue, SymbolType::None);
		LineItem Curve2 = panel->AddCurve("Numerical v2", f2_list, Color::Red, SymbolType::None);
		LineItem Curve3 = panel2->AddCurve("Error", f3_list, Color::MediumSlateBlue, SymbolType::None);

		textBox_err_main->Text = Convert::ToString(max_error);

		panel->XAxis->Scale->MinAuto = true;
		panel->XAxis->Scale->MaxAuto = true;
		panel->YAxis->Scale->MinAuto = true;
		panel->YAxis->Scale->MaxAuto = true;

		panel2->XAxis->Scale->MinAuto = true;
		panel2->XAxis->Scale->MaxAuto = true;
		panel2->YAxis->Scale->MinAuto = true;
		panel2->YAxis->Scale->MaxAuto = true;
		// Вызываем метод AxisChange (), чтобы обновить данные об осях. 
		// В противном случае на рисунке будет показана только часть графика, 
		// которая умещается в интервалы по осям, установленные по умолчанию
		zedGraphControl1->AxisChange();
		// Обновляем график
		zedGraphControl1->Invalidate();
		// которая умещается в интервалы по осям, установленные по умолчанию
		zedGraphControl2->AxisChange();
		// Обновляем график
		zedGraphControl2->Invalidate();
	}
};
}