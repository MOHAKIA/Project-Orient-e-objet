#include "PersonnelForm.h"

//permet de retourner ? la page d'acceuil
System::Void ProjetG4::PersonnelForm::btn_retour_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();
	retour->Show();
}

System::Void ProjetG4::PersonnelForm::PersonnelForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	this->txt_msg->Text = "Bienvenue ? la gestion du personnel";
	//chargement de la liste du personnel dans la datagridView
	dgviewDB->DataSource = this->gpersonnel->listeemploye();
	this->comboBox1->DataSource = this->gpersonnel->cad->getRows("SELECT Id_personnel, CONCAT(nom_P,' ',prenom_P) as employe from personnel");
	this->comboBox1->ValueMember = "Id_personnel";
	this->comboBox1->DisplayMember = "Employe";
	//combobox ville
	this->boxville->DataSource = this->gpersonnel->liste_ville();
	this->boxville->ValueMember = "Id_Ville";
	this->boxville->DisplayMember = "Nom_Ville";
}

System::Void ProjetG4::PersonnelForm::btn_enregistrer_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
System::Void ProjetG4::PersonnelForm::btn_afficher_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->gpersonnel->afficher(Convert::ToInt32(dgviewDB->SelectedRows[0]->Cells[0]->Value));
	this->gpersonnel->cad->getRows(gpersonnel->personnel->SELECTbyid());
	this->lbl_idaffich->Text = Convert::ToString(gpersonnel->personnel->get_id());
	this->txtbox_nom->Text= gpersonnel->personnel->get_nom();
	this->txtbox_prenom->Text = gpersonnel->personnel->get_prenom();
	DateTime^ date = gpersonnel->personnel->get_date_embauche();
	this->dateTimePicker1->Value = DateTime(date->Year, date->Month, date->Day);
	this->txtbox_adr->Text = this->gpersonnel->adresse->getAdresse();
	this->boxville->SelectedValue = gpersonnel->ville->getIdVille();
	PersonnelForm_Load(sender, e);
	//chiraz heba hlawa
}

System::Void ProjetG4::PersonnelForm::btn_creer_Click(System::Object^ sender, System::EventArgs^ e)
{
	
	if ((txtbox_nom->Text == "") || (txtbox_prenom->Text == "") || (txtbox_adr->Text == ""))
	{
		System::Windows::Forms::MessageBox::Show("Vous ne pouvez creer un employe avec des champs vides \n \n Try again", "Oups!", MessageBoxButtons::OK);
	}
	else if (checkBox1->Checked) {
		
		this->gpersonnel->ajouter(txtbox_nom->Text, txtbox_prenom->Text, dateTimePicker1->Value, txtbox_adr->Text, boxville->Text, Convert::ToInt32(comboBox1->SelectedValue));
	}
	else {
		//ajout d'un nouvel employ? sans superviseur
		this->gpersonnel->ajouter(txtbox_nom->Text, txtbox_prenom->Text, dateTimePicker1->Value, txtbox_adr->Text, boxville->Text);
	}
	PersonnelForm_Load(sender, e);
}

System::Void ProjetG4::PersonnelForm::btn_modifier_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (checkBox1->Checked) {
		//modifier un employ? avec superieur
		this->gpersonnel->modifier(Convert::ToInt32(lbl_idaffich->Text), txtbox_nom->Text, txtbox_prenom->Text, dateTimePicker1->Value, txtbox_adr->Text, boxville->Text, Convert::ToInt32(comboBox1->SelectedValue));
	}
	else {
		//modifier un employ?
		this->gpersonnel->modifier(Convert::ToInt32(lbl_idaffich->Text), txtbox_nom->Text, txtbox_prenom->Text, dateTimePicker1->Value, txtbox_adr->Text, boxville->Text);
	}
	PersonnelForm_Load(sender, e);
	
}

System::Void ProjetG4::PersonnelForm::btn_supprimer_Click(System::Object^ sender, System::EventArgs^ e)
{
	//supprimer un employ?
	gpersonnel->afficher(Convert::ToInt32(dgviewDB->SelectedRows[0]->Cells[0]->Value));
	System::Windows::Forms::DialogResult r = MessageBox::Show("Etes vous sur de vouloir supprimer l'employe " + this->gpersonnel->personnel->get_nom() + " " + this->gpersonnel->personnel->get_prenom() + "?", "Suppression d'un employe", MessageBoxButtons::OKCancel);
	if (r == System::Windows::Forms::DialogResult::OK) {
		this->gpersonnel->supprimer(Convert::ToInt32(dgviewDB->SelectedRows[0]->Cells[0]->Value));
		PersonnelForm_Load(sender, e);
	}
}

