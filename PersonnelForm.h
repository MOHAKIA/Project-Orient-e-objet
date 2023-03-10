#pragma once
#include"SVC_Gemploye.h" //inclure le service gestion employe

namespace ProjetG4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace Service;
	/// <summary>
	/// Description r?sum?e de PersonnelForm
	/// </summary>
	public ref class PersonnelForm : public System::Windows::Forms::Form
	{
	public:
		Form^ retour;
		PersonnelForm(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
		//contructeur surcharg? qui nous permettra d'utiliser le bouton retours
		PersonnelForm(Form^ r)
		{
			retour = r;
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilis?es.
		/// </summary>
		~PersonnelForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ btn_supprimer;
	private: System::Windows::Forms::Button^ btn_afficher;
	private: System::Windows::Forms::Button^ btn_modifier;
	private: System::Windows::Forms::Button^ btn_creer;
	private: System::Windows::Forms::Label^ lbl_nom;
	private: System::Windows::Forms::Label^ lbl_prenom;
	private: System::Windows::Forms::TextBox^ txtbox_nom;
	private: System::Windows::Forms::DataGridView^ dgviewDB;
	private: System::Windows::Forms::Button^ btn_retour;
	private: System::Windows::Forms::Label^ lbl_id;
	private: System::Windows::Forms::TextBox^ txtbox_prenom;
	private: System::Windows::Forms::TextBox^ txt_msg;
	private: System::Windows::Forms::TextBox^ txtbox_adr;
	private: System::Windows::Forms::Label^ lbl_adresse;
	private: System::Windows::Forms::Label^ lbl_retour;
	private: System::Windows::Forms::Label^ lbl_date;
	private: System::Windows::Forms::Label^ lbl_ville;
	private: System::Windows::Forms::BindingSource^ bindingSource1;
	private: System::ComponentModel::IContainer^ components;
	private: Data::DataTable^ dt;
	private: int index;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::Label^ lbl_sup;
	private: System::Windows::Forms::Label^ lbl_idaffich;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::ComboBox^ boxville;
	private: String^ mode;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: SVC_Gemploye^ gpersonnel = gcnew SVC_Gemploye(); //declarer un objet de type gestion employe
	protected:

	private:
		/// <summary>
		/// Variable n?cessaire au concepteur.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// M?thode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette m?thode avec l'?diteur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PersonnelForm::typeid));
			this->btn_supprimer = (gcnew System::Windows::Forms::Button());
			this->btn_afficher = (gcnew System::Windows::Forms::Button());
			this->btn_modifier = (gcnew System::Windows::Forms::Button());
			this->btn_creer = (gcnew System::Windows::Forms::Button());
			this->lbl_nom = (gcnew System::Windows::Forms::Label());
			this->lbl_prenom = (gcnew System::Windows::Forms::Label());
			this->txtbox_nom = (gcnew System::Windows::Forms::TextBox());
			this->dgviewDB = (gcnew System::Windows::Forms::DataGridView());
			this->btn_retour = (gcnew System::Windows::Forms::Button());
			this->lbl_id = (gcnew System::Windows::Forms::Label());
			this->txtbox_prenom = (gcnew System::Windows::Forms::TextBox());
			this->txt_msg = (gcnew System::Windows::Forms::TextBox());
			this->txtbox_adr = (gcnew System::Windows::Forms::TextBox());
			this->lbl_adresse = (gcnew System::Windows::Forms::Label());
			this->lbl_retour = (gcnew System::Windows::Forms::Label());
			this->lbl_date = (gcnew System::Windows::Forms::Label());
			this->lbl_ville = (gcnew System::Windows::Forms::Label());
			this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->lbl_sup = (gcnew System::Windows::Forms::Label());
			this->lbl_idaffich = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->boxville = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgviewDB))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_supprimer
			// 
			this->btn_supprimer->BackColor = System::Drawing::Color::Transparent;
			this->btn_supprimer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_supprimer->Font = (gcnew System::Drawing::Font(L"Corbel", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->btn_supprimer->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btn_supprimer->Location = System::Drawing::Point(703, 89);
			this->btn_supprimer->Name = L"btn_supprimer";
			this->btn_supprimer->Size = System::Drawing::Size(150, 39);
			this->btn_supprimer->TabIndex = 1;
			this->btn_supprimer->Text = L"Supprimer";
			this->btn_supprimer->UseVisualStyleBackColor = false;
			this->btn_supprimer->Click += gcnew System::EventHandler(this, &PersonnelForm::btn_supprimer_Click);
			// 
			// btn_afficher
			// 
			this->btn_afficher->BackColor = System::Drawing::Color::Transparent;
			this->btn_afficher->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_afficher->Font = (gcnew System::Drawing::Font(L"Corbel", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->btn_afficher->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btn_afficher->Location = System::Drawing::Point(501, 89);
			this->btn_afficher->Name = L"btn_afficher";
			this->btn_afficher->Size = System::Drawing::Size(150, 39);
			this->btn_afficher->TabIndex = 2;
			this->btn_afficher->Text = L"Afficher";
			this->btn_afficher->UseVisualStyleBackColor = false;
			this->btn_afficher->Click += gcnew System::EventHandler(this, &PersonnelForm::btn_afficher_Click);
			// 
			// btn_modifier
			// 
			this->btn_modifier->BackColor = System::Drawing::Color::Transparent;
			this->btn_modifier->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_modifier->Font = (gcnew System::Drawing::Font(L"Corbel", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->btn_modifier->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btn_modifier->Location = System::Drawing::Point(298, 89);
			this->btn_modifier->Name = L"btn_modifier";
			this->btn_modifier->Size = System::Drawing::Size(150, 39);
			this->btn_modifier->TabIndex = 3;
			this->btn_modifier->Text = L"Modifier";
			this->btn_modifier->UseVisualStyleBackColor = false;
			this->btn_modifier->Click += gcnew System::EventHandler(this, &PersonnelForm::btn_modifier_Click);
			// 
			// btn_creer
			// 
			this->btn_creer->BackColor = System::Drawing::Color::Transparent;
			this->btn_creer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_creer->Font = (gcnew System::Drawing::Font(L"Corbel", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->btn_creer->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btn_creer->Location = System::Drawing::Point(95, 89);
			this->btn_creer->Name = L"btn_creer";
			this->btn_creer->Size = System::Drawing::Size(150, 39);
			this->btn_creer->TabIndex = 4;
			this->btn_creer->Text = L"Cr?er";
			this->btn_creer->UseVisualStyleBackColor = false;
			this->btn_creer->Click += gcnew System::EventHandler(this, &PersonnelForm::btn_creer_Click);
			// 
			// lbl_nom
			// 
			this->lbl_nom->AutoSize = true;
			this->lbl_nom->BackColor = System::Drawing::Color::Transparent;
			this->lbl_nom->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lbl_nom->Font = (gcnew System::Drawing::Font(L"Corbel", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->lbl_nom->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lbl_nom->Location = System::Drawing::Point(497, 416);
			this->lbl_nom->Name = L"lbl_nom";
			this->lbl_nom->Size = System::Drawing::Size(41, 19);
			this->lbl_nom->TabIndex = 5;
			this->lbl_nom->Text = L"Nom";
			// 
			// lbl_prenom
			// 
			this->lbl_prenom->AutoSize = true;
			this->lbl_prenom->BackColor = System::Drawing::Color::Transparent;
			this->lbl_prenom->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lbl_prenom->Font = (gcnew System::Drawing::Font(L"Corbel", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->lbl_prenom->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lbl_prenom->Location = System::Drawing::Point(497, 479);
			this->lbl_prenom->Name = L"lbl_prenom";
			this->lbl_prenom->Size = System::Drawing::Size(62, 19);
			this->lbl_prenom->TabIndex = 6;
			this->lbl_prenom->Text = L"Prenom";
			// 
			// txtbox_nom
			// 
			this->txtbox_nom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtbox_nom->Location = System::Drawing::Point(603, 411);
			this->txtbox_nom->Name = L"txtbox_nom";
			this->txtbox_nom->Size = System::Drawing::Size(252, 28);
			this->txtbox_nom->TabIndex = 8;
			// 
			// dgviewDB
			// 
			this->dgviewDB->BackgroundColor = System::Drawing::Color::White;
			this->dgviewDB->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgviewDB->Location = System::Drawing::Point(197, 148);
			this->dgviewDB->MultiSelect = false;
			this->dgviewDB->Name = L"dgviewDB";
			this->dgviewDB->ReadOnly = true;
			this->dgviewDB->RowHeadersVisible = false;
			this->dgviewDB->RowHeadersWidth = 51;
			this->dgviewDB->RowTemplate->Height = 24;
			this->dgviewDB->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgviewDB->Size = System::Drawing::Size(606, 203);
			this->dgviewDB->TabIndex = 9;
			// 
			// btn_retour
			// 
			this->btn_retour->BackColor = System::Drawing::Color::Transparent;
			this->btn_retour->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_retour->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_retour->ForeColor = System::Drawing::Color::White;
			this->btn_retour->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_retour.Image")));
			this->btn_retour->Location = System::Drawing::Point(14, 15);
			this->btn_retour->Name = L"btn_retour";
			this->btn_retour->Size = System::Drawing::Size(48, 53);
			this->btn_retour->TabIndex = 0;
			this->btn_retour->UseVisualStyleBackColor = false;
			this->btn_retour->Click += gcnew System::EventHandler(this, &PersonnelForm::btn_retour_Click);
			// 
			// lbl_id
			// 
			this->lbl_id->AutoSize = true;
			this->lbl_id->BackColor = System::Drawing::Color::Transparent;
			this->lbl_id->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lbl_id->Font = (gcnew System::Drawing::Font(L"Corbel", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->lbl_id->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lbl_id->Location = System::Drawing::Point(512, 370);
			this->lbl_id->Name = L"lbl_id";
			this->lbl_id->Size = System::Drawing::Size(24, 19);
			this->lbl_id->TabIndex = 14;
			this->lbl_id->Text = L"ID";
			// 
			// txtbox_prenom
			// 
			this->txtbox_prenom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtbox_prenom->Location = System::Drawing::Point(601, 473);
			this->txtbox_prenom->Name = L"txtbox_prenom";
			this->txtbox_prenom->Size = System::Drawing::Size(252, 28);
			this->txtbox_prenom->TabIndex = 15;
			// 
			// txt_msg
			// 
			this->txt_msg->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->txt_msg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_msg->Location = System::Drawing::Point(45, 609);
			this->txt_msg->Multiline = true;
			this->txt_msg->Name = L"txt_msg";
			this->txt_msg->ReadOnly = true;
			this->txt_msg->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txt_msg->Size = System::Drawing::Size(758, 98);
			this->txt_msg->TabIndex = 16;
			// 
			// txtbox_adr
			// 
			this->txtbox_adr->BackColor = System::Drawing::Color::White;
			this->txtbox_adr->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtbox_adr->Location = System::Drawing::Point(591, 527);
			this->txtbox_adr->Name = L"txtbox_adr";
			this->txtbox_adr->Size = System::Drawing::Size(264, 28);
			this->txtbox_adr->TabIndex = 18;
			// 
			// lbl_adresse
			// 
			this->lbl_adresse->AutoSize = true;
			this->lbl_adresse->BackColor = System::Drawing::Color::Transparent;
			this->lbl_adresse->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lbl_adresse->Font = (gcnew System::Drawing::Font(L"Corbel", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->lbl_adresse->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lbl_adresse->Location = System::Drawing::Point(495, 536);
			this->lbl_adresse->Name = L"lbl_adresse";
			this->lbl_adresse->Size = System::Drawing::Size(64, 19);
			this->lbl_adresse->TabIndex = 17;
			this->lbl_adresse->Text = L"Adresse";
			// 
			// lbl_retour
			// 
			this->lbl_retour->AutoSize = true;
			this->lbl_retour->BackColor = System::Drawing::Color::Transparent;
			this->lbl_retour->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lbl_retour->Font = (gcnew System::Drawing::Font(L"Corbel", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->lbl_retour->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lbl_retour->Location = System::Drawing::Point(64, 26);
			this->lbl_retour->Name = L"lbl_retour";
			this->lbl_retour->Size = System::Drawing::Size(55, 19);
			this->lbl_retour->TabIndex = 19;
			this->lbl_retour->Text = L"Retour";
			// 
			// lbl_date
			// 
			this->lbl_date->AutoSize = true;
			this->lbl_date->BackColor = System::Drawing::Color::Transparent;
			this->lbl_date->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lbl_date->Font = (gcnew System::Drawing::Font(L"Corbel", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->lbl_date->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lbl_date->Location = System::Drawing::Point(40, 513);
			this->lbl_date->Name = L"lbl_date";
			this->lbl_date->Size = System::Drawing::Size(128, 19);
			this->lbl_date->TabIndex = 20;
			this->lbl_date->Text = L"Date d\'embauche";
			// 
			// lbl_ville
			// 
			this->lbl_ville->AutoSize = true;
			this->lbl_ville->BackColor = System::Drawing::Color::Transparent;
			this->lbl_ville->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lbl_ville->Font = (gcnew System::Drawing::Font(L"Corbel", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->lbl_ville->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lbl_ville->Location = System::Drawing::Point(41, 470);
			this->lbl_ville->Name = L"lbl_ville";
			this->lbl_ville->Size = System::Drawing::Size(39, 19);
			this->lbl_ville->TabIndex = 23;
			this->lbl_ville->Text = L"Ville";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dateTimePicker1->Location = System::Drawing::Point(48, 567);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(349, 26);
			this->dateTimePicker1->TabIndex = 24;
			// 
			// lbl_sup
			// 
			this->lbl_sup->AutoSize = true;
			this->lbl_sup->BackColor = System::Drawing::Color::Transparent;
			this->lbl_sup->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lbl_sup->Font = (gcnew System::Drawing::Font(L"Corbel", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->lbl_sup->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lbl_sup->Location = System::Drawing::Point(640, 574);
			this->lbl_sup->Name = L"lbl_sup";
			this->lbl_sup->Size = System::Drawing::Size(163, 19);
			this->lbl_sup->TabIndex = 26;
			this->lbl_sup->Text = L"Sup?rieur hierarchique";
			// 
			// lbl_idaffich
			// 
			this->lbl_idaffich->AutoSize = true;
			this->lbl_idaffich->BackColor = System::Drawing::Color::Transparent;
			this->lbl_idaffich->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lbl_idaffich->Font = (gcnew System::Drawing::Font(L"Corbel", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->lbl_idaffich->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lbl_idaffich->Location = System::Drawing::Point(610, 370);
			this->lbl_idaffich->Name = L"lbl_idaffich";
			this->lbl_idaffich->Size = System::Drawing::Size(122, 19);
			this->lbl_idaffich->TabIndex = 27;
			this->lbl_idaffich->Text = L"ID s\'affichera ici!";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox1->Location = System::Drawing::Point(619, 579);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(15, 14);
			this->checkBox1->TabIndex = 28;
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// boxville
			// 
			this->boxville->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->boxville->FormattingEnabled = true;
			this->boxville->Location = System::Drawing::Point(104, 470);
			this->boxville->Name = L"boxville";
			this->boxville->Size = System::Drawing::Size(145, 28);
			this->boxville->TabIndex = 29;
			this->boxville->SelectedIndexChanged += gcnew System::EventHandler(this, &PersonnelForm::boxville_SelectedIndexChanged);
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(48, 412);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(349, 28);
			this->comboBox1->TabIndex = 30;
			// 
			// PersonnelForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1101, 723);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->boxville);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->lbl_idaffich);
			this->Controls->Add(this->lbl_sup);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->lbl_ville);
			this->Controls->Add(this->lbl_date);
			this->Controls->Add(this->lbl_retour);
			this->Controls->Add(this->txtbox_adr);
			this->Controls->Add(this->lbl_adresse);
			this->Controls->Add(this->txt_msg);
			this->Controls->Add(this->txtbox_prenom);
			this->Controls->Add(this->lbl_id);
			this->Controls->Add(this->dgviewDB);
			this->Controls->Add(this->txtbox_nom);
			this->Controls->Add(this->lbl_prenom);
			this->Controls->Add(this->lbl_nom);
			this->Controls->Add(this->btn_creer);
			this->Controls->Add(this->btn_modifier);
			this->Controls->Add(this->btn_afficher);
			this->Controls->Add(this->btn_supprimer);
			this->Controls->Add(this->btn_retour);
			this->DoubleBuffered = true;
			this->Font = (gcnew System::Drawing::Font(L"Corbel", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->MaximumSize = System::Drawing::Size(1117, 762);
			this->MinimumSize = System::Drawing::Size(1117, 726);
			this->Name = L"PersonnelForm";
			this->Text = L"Gestion Personnel";
			this->Load += gcnew System::EventHandler(this, &PersonnelForm::PersonnelForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgviewDB))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//bouton retour
	private: System::Void btn_retour_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void PersonnelForm_Load(System::Object^ sender, System::EventArgs^ e);
		   //bouton enregistrer
	private: System::Void btn_enregistrer_Click(System::Object^ sender, System::EventArgs^ e);
		   //bouton creer
	private: System::Void btn_creer_Click(System::Object^ sender, System::EventArgs^ e);
		   //bouton modifier
	private: System::Void btn_modifier_Click(System::Object^ sender, System::EventArgs^ e);
		   //bouton afficher
	private: System::Void btn_afficher_Click(System::Object^ sender, System::EventArgs^ e);
		   //bouton supprimer
	private: System::Void btn_supprimer_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void boxville_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
