#pragma once
#include"SVC_Gclient.h" 
#include"Adresse.h"
#include"Client.h"
#include"FicheAdresse.h" 

namespace ProjetG4 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Composant;
	using namespace Service;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Description r?sum?e de ClientForm
	/// </summary>
	public ref class ClientForm : public System::Windows::Forms::Form
	{
	public:
		Form^ retour2;
		ClientForm(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
		ClientForm(Form ^r2)
		{
			retour2 = r2;
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilis?es.
		/// </summary>
		~ClientForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_retour;
	private: System::Windows::Forms::DataGridView^ dgViewClient;
	private: System::Windows::Forms::Button^ btn_valider;
	protected:
	private: System::Windows::Forms::Button^ btn_creer;
	private: System::Windows::Forms::Button^ btn_modifier;
	private: System::Windows::Forms::Button^ btn_afficher;
	private: System::Windows::Forms::Button^ btn_supprimer;
	private: System::Windows::Forms::Label^ lbl_prachat;
	private: System::Windows::Forms::Label^ lbl_idclient;
	private: System::Windows::Forms::TextBox^ txt_prenom;
	private: System::Windows::Forms::TextBox^ txt_nom;
	private: System::Windows::Forms::Label^ lbl_prenom;
	private: System::Windows::Forms::Label^ lbl_nom;
	private: System::Windows::Forms::Label^ lblretour;
	private: System::Windows::Forms::Label^ lbl_date_naiss;

	private: System::Windows::Forms::DateTimePicker^ date_naisse;
	private: System::Windows::Forms::DateTimePicker^ date_pr_achat;
	private: System::Windows::Forms::Label^ lbl_idaffich;

	private: Service::SVC_Gclient^ gclient = gcnew SVC_Gclient(); //objet pour la gestion du client
	private: Composant::Client^ client = gcnew 	Client();

	
	private: System::Windows::Forms::Button^ btn_adresse;

	protected:

	private:
		/// <summary>
		/// Variable n?cessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M?thode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette m?thode avec l'?diteur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ClientForm::typeid));
			this->btn_retour = (gcnew System::Windows::Forms::Button());
			this->dgViewClient = (gcnew System::Windows::Forms::DataGridView());
			this->btn_valider = (gcnew System::Windows::Forms::Button());
			this->btn_creer = (gcnew System::Windows::Forms::Button());
			this->btn_modifier = (gcnew System::Windows::Forms::Button());
			this->btn_afficher = (gcnew System::Windows::Forms::Button());
			this->btn_supprimer = (gcnew System::Windows::Forms::Button());
			this->lbl_prachat = (gcnew System::Windows::Forms::Label());
			this->lbl_idclient = (gcnew System::Windows::Forms::Label());
			this->txt_prenom = (gcnew System::Windows::Forms::TextBox());
			this->txt_nom = (gcnew System::Windows::Forms::TextBox());
			this->lbl_prenom = (gcnew System::Windows::Forms::Label());
			this->lbl_nom = (gcnew System::Windows::Forms::Label());
			this->lblretour = (gcnew System::Windows::Forms::Label());
			this->lbl_date_naiss = (gcnew System::Windows::Forms::Label());
			this->date_naisse = (gcnew System::Windows::Forms::DateTimePicker());
			this->date_pr_achat = (gcnew System::Windows::Forms::DateTimePicker());
			this->lbl_idaffich = (gcnew System::Windows::Forms::Label());
			this->btn_adresse = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgViewClient))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_retour
			// 
			this->btn_retour->BackColor = System::Drawing::Color::Transparent;
			this->btn_retour->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_retour->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold));
			this->btn_retour->ForeColor = System::Drawing::Color::White;
			this->btn_retour->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_retour.Image")));
			this->btn_retour->Location = System::Drawing::Point(9, 10);
			this->btn_retour->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn_retour->Name = L"btn_retour";
			this->btn_retour->Size = System::Drawing::Size(32, 36);
			this->btn_retour->TabIndex = 0;
			this->btn_retour->UseVisualStyleBackColor = false;
			this->btn_retour->Click += gcnew System::EventHandler(this, &ClientForm::btn_retour_Click);
			// 
			// dgViewClient
			// 
			this->dgViewClient->BackgroundColor = System::Drawing::Color::White;
			this->dgViewClient->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgViewClient->Location = System::Drawing::Point(299, 182);
			this->dgViewClient->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dgViewClient->MultiSelect = false;
			this->dgViewClient->Name = L"dgViewClient";
			this->dgViewClient->ReadOnly = true;
			this->dgViewClient->RowHeadersVisible = false;
			this->dgViewClient->RowHeadersWidth = 51;
			this->dgViewClient->RowTemplate->Height = 24;
			this->dgViewClient->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgViewClient->Size = System::Drawing::Size(542, 172);
			this->dgViewClient->TabIndex = 13;
			// 
			// btn_valider
			// 
			this->btn_valider->BackColor = System::Drawing::Color::RoyalBlue;
			this->btn_valider->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_valider->Font = (gcnew System::Drawing::Font(L"Corbel", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->btn_valider->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btn_valider->Location = System::Drawing::Point(284, 110);
			this->btn_valider->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn_valider->Name = L"btn_valider";
			this->btn_valider->Size = System::Drawing::Size(389, 41);
			this->btn_valider->TabIndex = 18;
			this->btn_valider->Text = L"Valider";
			this->btn_valider->UseVisualStyleBackColor = false;
			this->btn_valider->Click += gcnew System::EventHandler(this, &ClientForm::btn_valider_Click);
			// 
			// btn_creer
			// 
			this->btn_creer->BackColor = System::Drawing::Color::RoyalBlue;
			this->btn_creer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_creer->Font = (gcnew System::Drawing::Font(L"Corbel", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->btn_creer->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btn_creer->Location = System::Drawing::Point(325, 50);
			this->btn_creer->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn_creer->Name = L"btn_creer";
			this->btn_creer->Size = System::Drawing::Size(100, 41);
			this->btn_creer->TabIndex = 17;
			this->btn_creer->Text = L"Cr?er";
			this->btn_creer->UseVisualStyleBackColor = false;
			this->btn_creer->Click += gcnew System::EventHandler(this, &ClientForm::btn_creer_Click);
			// 
			// btn_modifier
			// 
			this->btn_modifier->BackColor = System::Drawing::Color::RoyalBlue;
			this->btn_modifier->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_modifier->Font = (gcnew System::Drawing::Font(L"Corbel", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->btn_modifier->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btn_modifier->Location = System::Drawing::Point(459, 50);
			this->btn_modifier->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn_modifier->Name = L"btn_modifier";
			this->btn_modifier->Size = System::Drawing::Size(100, 41);
			this->btn_modifier->TabIndex = 16;
			this->btn_modifier->Text = L"Modifier";
			this->btn_modifier->UseVisualStyleBackColor = false;
			this->btn_modifier->Click += gcnew System::EventHandler(this, &ClientForm::btn_modifier_Click);
			// 
			// btn_afficher
			// 
			this->btn_afficher->BackColor = System::Drawing::Color::RoyalBlue;
			this->btn_afficher->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_afficher->Font = (gcnew System::Drawing::Font(L"Corbel", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->btn_afficher->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btn_afficher->Location = System::Drawing::Point(609, 50);
			this->btn_afficher->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn_afficher->Name = L"btn_afficher";
			this->btn_afficher->Size = System::Drawing::Size(100, 41);
			this->btn_afficher->TabIndex = 15;
			this->btn_afficher->Text = L"Afficher";
			this->btn_afficher->UseVisualStyleBackColor = false;
			this->btn_afficher->Click += gcnew System::EventHandler(this, &ClientForm::btn_afficher_Click);
			// 
			// btn_supprimer
			// 
			this->btn_supprimer->BackColor = System::Drawing::Color::RoyalBlue;
			this->btn_supprimer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_supprimer->Font = (gcnew System::Drawing::Font(L"Corbel", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->btn_supprimer->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btn_supprimer->Location = System::Drawing::Point(728, 50);
			this->btn_supprimer->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn_supprimer->Name = L"btn_supprimer";
			this->btn_supprimer->Size = System::Drawing::Size(100, 41);
			this->btn_supprimer->TabIndex = 14;
			this->btn_supprimer->Text = L"Supprimer";
			this->btn_supprimer->UseVisualStyleBackColor = false;
			this->btn_supprimer->Click += gcnew System::EventHandler(this, &ClientForm::btn_supprimer_Click);
			// 
			// lbl_prachat
			// 
			this->lbl_prachat->AutoSize = true;
			this->lbl_prachat->BackColor = System::Drawing::Color::Transparent;
			this->lbl_prachat->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lbl_prachat->Font = (gcnew System::Drawing::Font(L"Corbel", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->lbl_prachat->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lbl_prachat->Location = System::Drawing::Point(6, 286);
			this->lbl_prachat->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_prachat->Name = L"lbl_prachat";
			this->lbl_prachat->Size = System::Drawing::Size(173, 19);
			this->lbl_prachat->TabIndex = 25;
			this->lbl_prachat->Text = L"Date de PREMIER achat";
			// 
			// lbl_idclient
			// 
			this->lbl_idclient->AutoSize = true;
			this->lbl_idclient->BackColor = System::Drawing::Color::Transparent;
			this->lbl_idclient->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lbl_idclient->Font = (gcnew System::Drawing::Font(L"Corbel", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->lbl_idclient->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lbl_idclient->Location = System::Drawing::Point(18, 50);
			this->lbl_idclient->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_idclient->Name = L"lbl_idclient";
			this->lbl_idclient->Size = System::Drawing::Size(24, 19);
			this->lbl_idclient->TabIndex = 23;
			this->lbl_idclient->Text = L"ID";
			// 
			// txt_prenom
			// 
			this->txt_prenom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_prenom->Location = System::Drawing::Point(76, 157);
			this->txt_prenom->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txt_prenom->Name = L"txt_prenom";
			this->txt_prenom->Size = System::Drawing::Size(186, 28);
			this->txt_prenom->TabIndex = 22;
			// 
			// txt_nom
			// 
			this->txt_nom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_nom->Location = System::Drawing::Point(76, 93);
			this->txt_nom->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txt_nom->Name = L"txt_nom";
			this->txt_nom->Size = System::Drawing::Size(186, 28);
			this->txt_nom->TabIndex = 21;
			// 
			// lbl_prenom
			// 
			this->lbl_prenom->AutoSize = true;
			this->lbl_prenom->BackColor = System::Drawing::Color::Transparent;
			this->lbl_prenom->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lbl_prenom->Font = (gcnew System::Drawing::Font(L"Corbel", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->lbl_prenom->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lbl_prenom->Location = System::Drawing::Point(9, 160);
			this->lbl_prenom->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_prenom->Name = L"lbl_prenom";
			this->lbl_prenom->Size = System::Drawing::Size(62, 19);
			this->lbl_prenom->TabIndex = 20;
			this->lbl_prenom->Text = L"Prenom";
			// 
			// lbl_nom
			// 
			this->lbl_nom->AutoSize = true;
			this->lbl_nom->BackColor = System::Drawing::Color::Transparent;
			this->lbl_nom->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lbl_nom->Font = (gcnew System::Drawing::Font(L"Corbel", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->lbl_nom->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lbl_nom->Location = System::Drawing::Point(15, 97);
			this->lbl_nom->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_nom->Name = L"lbl_nom";
			this->lbl_nom->Size = System::Drawing::Size(41, 19);
			this->lbl_nom->TabIndex = 19;
			this->lbl_nom->Text = L"Nom";
			// 
			// lblretour
			// 
			this->lblretour->AutoSize = true;
			this->lblretour->BackColor = System::Drawing::Color::Transparent;
			this->lblretour->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lblretour->Font = (gcnew System::Drawing::Font(L"Corbel", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblretour->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lblretour->Location = System::Drawing::Point(45, 18);
			this->lblretour->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblretour->Name = L"lblretour";
			this->lblretour->Size = System::Drawing::Size(55, 19);
			this->lblretour->TabIndex = 29;
			this->lblretour->Text = L"Retour";
			// 
			// lbl_date_naiss
			// 
			this->lbl_date_naiss->AutoSize = true;
			this->lbl_date_naiss->BackColor = System::Drawing::Color::Transparent;
			this->lbl_date_naiss->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lbl_date_naiss->Font = (gcnew System::Drawing::Font(L"Corbel", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->lbl_date_naiss->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lbl_date_naiss->Location = System::Drawing::Point(15, 201);
			this->lbl_date_naiss->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_date_naiss->Name = L"lbl_date_naiss";
			this->lbl_date_naiss->Size = System::Drawing::Size(135, 19);
			this->lbl_date_naiss->TabIndex = 35;
			this->lbl_date_naiss->Text = L"Date de naissance";
			// 
			// date_naisse
			// 
			this->date_naisse->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->date_naisse->Location = System::Drawing::Point(18, 244);
			this->date_naisse->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->date_naisse->Name = L"date_naisse";
			this->date_naisse->Size = System::Drawing::Size(242, 26);
			this->date_naisse->TabIndex = 39;
			// 
			// date_pr_achat
			// 
			this->date_pr_achat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->date_pr_achat->Location = System::Drawing::Point(21, 328);
			this->date_pr_achat->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->date_pr_achat->Name = L"date_pr_achat";
			this->date_pr_achat->Size = System::Drawing::Size(242, 26);
			this->date_pr_achat->TabIndex = 40;
			// 
			// lbl_idaffich
			// 
			this->lbl_idaffich->AutoSize = true;
			this->lbl_idaffich->BackColor = System::Drawing::Color::Transparent;
			this->lbl_idaffich->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lbl_idaffich->Font = (gcnew System::Drawing::Font(L"Agency FB", 13.8F, System::Drawing::FontStyle::Bold));
			this->lbl_idaffich->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lbl_idaffich->Location = System::Drawing::Point(72, 50);
			this->lbl_idaffich->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_idaffich->Name = L"lbl_idaffich";
			this->lbl_idaffich->Size = System::Drawing::Size(106, 24);
			this->lbl_idaffich->TabIndex = 41;
			this->lbl_idaffich->Text = L"ID s\'affichera ici!";
			// 
			// btn_adresse
			// 
			this->btn_adresse->BackColor = System::Drawing::Color::RoyalBlue;
			this->btn_adresse->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_adresse->Font = (gcnew System::Drawing::Font(L"Corbel", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->btn_adresse->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btn_adresse->Location = System::Drawing::Point(714, 110);
			this->btn_adresse->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn_adresse->Name = L"btn_adresse";
			this->btn_adresse->Size = System::Drawing::Size(127, 41);
			this->btn_adresse->TabIndex = 44;
			this->btn_adresse->Text = L"Adresse Client";
			this->btn_adresse->UseVisualStyleBackColor = false;
			this->btn_adresse->Click += gcnew System::EventHandler(this, &ClientForm::btn_adresse_Click);
			// 
			// ClientForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(866, 493);
			this->Controls->Add(this->btn_adresse);
			this->Controls->Add(this->lbl_idaffich);
			this->Controls->Add(this->date_pr_achat);
			this->Controls->Add(this->date_naisse);
			this->Controls->Add(this->lbl_date_naiss);
			this->Controls->Add(this->lblretour);
			this->Controls->Add(this->lbl_prachat);
			this->Controls->Add(this->lbl_idclient);
			this->Controls->Add(this->txt_prenom);
			this->Controls->Add(this->txt_nom);
			this->Controls->Add(this->lbl_prenom);
			this->Controls->Add(this->lbl_nom);
			this->Controls->Add(this->btn_valider);
			this->Controls->Add(this->btn_creer);
			this->Controls->Add(this->btn_modifier);
			this->Controls->Add(this->btn_afficher);
			this->Controls->Add(this->btn_supprimer);
			this->Controls->Add(this->dgViewClient);
			this->Controls->Add(this->btn_retour);
			this->DoubleBuffered = true;
			this->Font = (gcnew System::Drawing::Font(L"Corbel", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaximumSize = System::Drawing::Size(882, 532);
			this->MinimumSize = System::Drawing::Size(882, 532);
			this->Name = L"ClientForm";
			this->Text = L"ClientForm";
			this->Load += gcnew System::EventHandler(this, &ClientForm::ClientForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgViewClient))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void ClientForm_Load(System::Object^ sender, System::EventArgs^ e);
	   //bouton retour
private: System::Void btn_retour_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		retour2->Show();
}
private: System::Void btn_creer_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btn_modifier_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btn_afficher_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btn_supprimer_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btn_valider_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btn_adresse_Click(System::Object^ sender, System::EventArgs^ e);
public: System::Void set_client(Composant::Client^);

};
}
