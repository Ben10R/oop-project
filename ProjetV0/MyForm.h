#pragma once
#include "CL_svc_gestionPersonnes.h"
#include "CL_svc_gestionClients.h"
#include "CL_svc_gestionCommandes.h"
#include "Services_Stocks.h"
#include "CL_svc_STATS.h"
#include <cliext/vector>

namespace ProjetV0 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form Projet Cpp 
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	protected:
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txt_message;

		   //Objets et variables utiles
	private: NS_Svc::CL_svc_gestionPersonnes^ processusPersonnes;
	private: NS_Svc::CL_svc_gestionClients^ processusClient;
	private: NS_Svc::CL_svc_STATS^ processusStats;
	private: DataSet^ ds;
	private: DataSet^ ds2;
	private: DataSet^ dsClient;
	private: int indexPersonnel;
	private: int indexClient;
	private: String^ mode;
	private: String^ classe;
	private: bool rbactif; //radiobuttonClient


	   // STATS 
	private: System::Windows::Forms::DataGridView^ dgv_req_stat;
	protected:
	private: System::Windows::Forms::Button^ btn_ok_stat;
	private: System::Windows::Forms::TextBox^ txt_IdClient_stat;
	protected:
	private: System::Windows::Forms::TextBox^ txt_prenomClient_stat;
	private: System::Windows::Forms::TextBox^ txt_nomClient_stat;
	private: System::Windows::Forms::Label^ lbl_nomClient_stat;
	private: System::Windows::Forms::Label^ lbl_IdClient_stat;
	private: System::Windows::Forms::Label^ lbl_prenomClient_stat;
	private: System::Windows::Forms::ComboBox^ cb_req_stat;
	private: System::Windows::Forms::GroupBox^ gp_InfosClients_stat;
	private: System::Windows::Forms::GroupBox^ gp_InfoDate_stat;
	private: System::Windows::Forms::ComboBox^ cb_year_stat;
	private: System::Windows::Forms::ComboBox^ cb_month_stat;
	private: System::Windows::Forms::Label^ lbl_year_stat;
	private: System::Windows::Forms::Label^ lbl_month_stat;
	private: System::Windows::Forms::Label^ lbl_titleSelect_stat;
	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::GroupBox^ gb_statistiques;

private: System::Windows::Forms::TextBox^ txt_stats_result;
private: System::Windows::Forms::Label^ lbl_stats_result;
private: System::Windows::Forms::Button^ btn_stats_calculer;
private: System::Windows::Forms::Label^ lbl_stats_variationValeurStock;
private: System::Windows::Forms::Label^ lbl_stats_margeCommerciale;
private: System::Windows::Forms::Label^ lbl_stats_remiseCommerciale;
private: System::Windows::Forms::Label^ lbl_stats_demarqueInconnue;
private: System::Windows::Forms::Label^ lbl_stats_TVA;
private: System::Windows::Forms::TextBox^ txt_stats_demarqueInconnue;
private: System::Windows::Forms::TextBox^ txt_stats_remiseCommerciale;
private: System::Windows::Forms::TextBox^ txt_stats_margeCommerciale;
private: System::Windows::Forms::TextBox^ txt_stats_TVA;
private: System::Windows::Forms::TabPage^ tabPage3;
private: System::Windows::Forms::GroupBox^ groupBoxStock;
private: System::Windows::Forms::Button^ buttonClearTVA;
private: System::Windows::Forms::Button^ buttonClearNature;
private: System::Windows::Forms::Button^ buttonClearArticle;
private: System::Windows::Forms::Button^ buttonDernierNature;
private: System::Windows::Forms::Button^ buttonPremierNature;
private: System::Windows::Forms::TextBox^ textBoxTauxTVA;
private: System::Windows::Forms::Button^ buttonSuivantNature;
private: System::Windows::Forms::TextBox^ textBoxIdTVA;
private: System::Windows::Forms::Button^ buttonPrecedentNature;
private: System::Windows::Forms::Button^ buttonDernierTVA;
private: System::Windows::Forms::Label^ labelIdTVA;
private: System::Windows::Forms::Button^ buttonDernierArticle;
private: System::Windows::Forms::Button^ buttonPremierTVA;
private: System::Windows::Forms::Button^ buttonPremierArticle;
private: System::Windows::Forms::Label^ labelTauxTVA;
private: System::Windows::Forms::Button^ buttonSuivantArticle;
private: System::Windows::Forms::Button^ buttonSuivantTVA;
private: System::Windows::Forms::Button^ buttonPrecedentArticle;
private: System::Windows::Forms::Button^ buttonPrecedentTVA;
private: System::Windows::Forms::Button^ buttonAjouterArticle;
private: System::Windows::Forms::Button^ buttonUpdateArticle;
private: System::Windows::Forms::Button^ buttonDeleteArticle;
private: System::Windows::Forms::Label^ labelNature;
private: System::Windows::Forms::TextBox^ textBoxNature;
private: System::Windows::Forms::Label^ labelQuantiteStockArticle;
private: System::Windows::Forms::TextBox^ textBoxQuantiteStockArticle;
private: System::Windows::Forms::Label^ labelSeuilReapro;
private: System::Windows::Forms::TextBox^ textBoxSeuilReapro;
private: System::Windows::Forms::Label^ labelDesignationArticle;
private: System::Windows::Forms::TextBox^ textBoxDesignationArticle;
private: System::Windows::Forms::Label^ labelNomArticle;
private: System::Windows::Forms::TextBox^ textBoxNomArticle;
private: System::Windows::Forms::Label^ labelIdNature;
private: System::Windows::Forms::TextBox^ textBoxIdNature;
private: System::Windows::Forms::Label^ labelIdArticle;
private: System::Windows::Forms::TextBox^ textBoxIdArticle;
private: System::Windows::Forms::TabPage^ tabPage2;
private: System::Windows::Forms::GroupBox^ gb_client;
private: System::Windows::Forms::Button^ btn_previous_client;
private: System::Windows::Forms::Button^ btn_first_client;
private: System::Windows::Forms::Button^ btn_next_client;
private: System::Windows::Forms::Button^ btn_end_client;
private: System::Windows::Forms::DateTimePicker^ datePremAchatPicker;
private: System::Windows::Forms::DateTimePicker^ dateNaissancePicker;
private: System::Windows::Forms::TextBox^ txt_datepremierachat;
private: System::Windows::Forms::TextBox^ txt_datenaissance;
private: System::Windows::Forms::Label^ lbl_premier_achat;
private: System::Windows::Forms::Label^ lbl_datenaissance;
private: System::Windows::Forms::Button^ btn_supprimer_client;
private: System::Windows::Forms::Button^ btn_modifier_client;
private: System::Windows::Forms::Button^ btn_enregistrer_client;
private: System::Windows::Forms::Button^ btn_nouveau_client;
private: System::Windows::Forms::TextBox^ txt_PrenomClient;
private: System::Windows::Forms::TextBox^ txt_NomClient;
private: System::Windows::Forms::Label^ lbl_PrenomClient;
private: System::Windows::Forms::Label^ lbl_idNomClient;
private: System::Windows::Forms::TextBox^ txt_idClient;
private: System::Windows::Forms::Label^ lbl_idClient;
private: System::Windows::Forms::RadioButton^ rb_livraison;
private: System::Windows::Forms::RadioButton^ rb_facturation;
private: System::Windows::Forms::DataGridView^ dataGridView1;
private: System::Windows::Forms::TabPage^ tabPage1;
private: System::Windows::Forms::GroupBox^ gb_personnel;
private: System::Windows::Forms::TextBox^ txt_dateEmbauche;
private: System::Windows::Forms::DataGridView^ ListeEmployes;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ NoRue;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Adresse;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Ville;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ CP;
private: System::Windows::Forms::Button^ btn_nouveau_personnel;
private: System::Windows::Forms::Label^ lbl_dateembauche;
private: System::Windows::Forms::Button^ btn_modifier_personnel;
private: System::Windows::Forms::DateTimePicker^ dateEmbauchePicker;
private: System::Windows::Forms::Button^ btn_supprimer_personnel;
private: System::Windows::Forms::Button^ btn_enregistrer_personnel;
private: System::Windows::Forms::Button^ btn_previous_personnel;
private: System::Windows::Forms::Button^ btn_first_personnel;
private: System::Windows::Forms::Button^ btn_next_personnel;
private: System::Windows::Forms::Button^ btn_end_personnel;
private: System::Windows::Forms::TextBox^ txt_prenom;
private: System::Windows::Forms::TextBox^ txt_nom;
private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::TextBox^ txt_idPersonne;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::TabControl^ tabControl1;
private: System::Windows::Forms::TabPage^ tabPage5;

	private: NS_Svc::CL_svc_gestionCommandes^ processusCommandes;
	private: Data::DataSet^ dsCom;
	private: System::Windows::Forms::TabPage^ tp_commandes;
	private: System::Windows::Forms::RadioButton^ rb_ParRef_Com;
	private: System::Windows::Forms::RadioButton^ rb_ParDate_Com;
	private: System::Windows::Forms::RadioButton^ rb_ParClient_Com;
	private: System::Windows::Forms::Label^ lbl_Rechercher_Com;
	private: System::Windows::Forms::DataGridView^ dgv_Com;
	private: System::Windows::Forms::GroupBox^ gb_RechercherRef_Com;
	private: System::Windows::Forms::Button^ bnt_RechercherRef_Com;
	private: System::Windows::Forms::Label^ lbl_Ref_Com;
	private: System::Windows::Forms::TextBox^ txt_Ref_Com;
	private: System::Windows::Forms::GroupBox^ gb_RechercherDate_Com;
	private: System::Windows::Forms::ComboBox^ cb_Annee_Com;
	private: System::Windows::Forms::ComboBox^ cb_Mois_Com;
	private: System::Windows::Forms::Button^ bnt_RechercherDate_Com;
	private: System::Windows::Forms::ComboBox^ cb_Jour_Com;
	private: System::Windows::Forms::GroupBox^ gb_RechercheCli_COM;
	private: System::Windows::Forms::TextBox^ txt_IdClient_Com;
	private: System::Windows::Forms::TextBox^ txt_PrenomClient_Com;
	private: System::Windows::Forms::Button^ btn_RechercherCli_Com;
	private: System::Windows::Forms::TextBox^ txt_NomClient_Com;
	private: System::Windows::Forms::Label^ lbl_IdClient_Com;
	private: System::Windows::Forms::Label^ lbl_PrenomClient_Com;
	private: System::Windows::Forms::Label^ lbl_NomClient_Com;
	private: System::Windows::Forms::TextBox^ txt_AddIdCli_Com;
	private: System::Windows::Forms::TextBox^ txt_AddRef_Com;

	private: System::Windows::Forms::RadioButton^ rb_Del_Com;
	private: System::Windows::Forms::RadioButton^ rb_Up_Com;
	private: System::Windows::Forms::RadioButton^ rb_Add_Com;
	private: System::Windows::Forms::RadioButton^ rb_Aff_Com;
	private: System::Windows::Forms::GroupBox^ gb_Add_Com;

	private: System::Windows::Forms::Button^ btn_Add_Com;

	private: System::Windows::Forms::TextBox^ txt_AddTVA_Com;

	private: System::Windows::Forms::TextBox^ txt_AddHT_Com;

	private: System::Windows::Forms::TextBox^ txt_AddTTC_Com;
	private: System::Windows::Forms::Label^ lbl_AddDatePaiementRec_Com;
	private: System::Windows::Forms::Label^ AddDateEmission_Com;
	private: System::Windows::Forms::Label^ lbl_AddDate_Com;
	private: System::Windows::Forms::DateTimePicker^ dtp_AddDatePaiementRec_Com;
	private: System::Windows::Forms::DateTimePicker^ dtp_AddDateEmission_Com;
	private: System::Windows::Forms::DateTimePicker^ dtp_AddDate_Com;
	private: System::Windows::Forms::Label^ lbl_AddTVA_Com;
	private: System::Windows::Forms::Label^ lbl_AddTTC_Com;
	private: System::Windows::Forms::Label^ lbl_AddHT_Com;
	private: System::Windows::Forms::Label^ lbl_AddRef_Com;
	private: System::Windows::Forms::Label^ lbl_AddIdCli_Com;


	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur
		/// </summary>
		void InitializeComponent(void)
		{
			this->tp_commandes = (gcnew System::Windows::Forms::TabPage());
			this->gb_Add_Com = (gcnew System::Windows::Forms::GroupBox());
			this->lbl_AddDatePaiementRec_Com = (gcnew System::Windows::Forms::Label());
			this->AddDateEmission_Com = (gcnew System::Windows::Forms::Label());
			this->lbl_AddDate_Com = (gcnew System::Windows::Forms::Label());
			this->dtp_AddDatePaiementRec_Com = (gcnew System::Windows::Forms::DateTimePicker());
			this->dtp_AddDateEmission_Com = (gcnew System::Windows::Forms::DateTimePicker());
			this->dtp_AddDate_Com = (gcnew System::Windows::Forms::DateTimePicker());
			this->lbl_AddTVA_Com = (gcnew System::Windows::Forms::Label());
			this->lbl_AddTTC_Com = (gcnew System::Windows::Forms::Label());
			this->lbl_AddHT_Com = (gcnew System::Windows::Forms::Label());
			this->lbl_AddRef_Com = (gcnew System::Windows::Forms::Label());
			this->lbl_AddIdCli_Com = (gcnew System::Windows::Forms::Label());
			this->btn_Add_Com = (gcnew System::Windows::Forms::Button());
			this->txt_AddTVA_Com = (gcnew System::Windows::Forms::TextBox());
			this->txt_AddHT_Com = (gcnew System::Windows::Forms::TextBox());
			this->txt_AddTTC_Com = (gcnew System::Windows::Forms::TextBox());
			this->txt_AddIdCli_Com = (gcnew System::Windows::Forms::TextBox());
			this->txt_AddRef_Com = (gcnew System::Windows::Forms::TextBox());
			this->rb_Del_Com = (gcnew System::Windows::Forms::RadioButton());
			this->rb_Up_Com = (gcnew System::Windows::Forms::RadioButton());
			this->rb_Add_Com = (gcnew System::Windows::Forms::RadioButton());
			this->rb_Aff_Com = (gcnew System::Windows::Forms::RadioButton());
			this->rb_ParRef_Com = (gcnew System::Windows::Forms::RadioButton());
			this->rb_ParDate_Com = (gcnew System::Windows::Forms::RadioButton());
			this->rb_ParClient_Com = (gcnew System::Windows::Forms::RadioButton());
			this->lbl_Rechercher_Com = (gcnew System::Windows::Forms::Label());
			this->gb_RechercherRef_Com = (gcnew System::Windows::Forms::GroupBox());
			this->bnt_RechercherRef_Com = (gcnew System::Windows::Forms::Button());
			this->lbl_Ref_Com = (gcnew System::Windows::Forms::Label());
			this->txt_Ref_Com = (gcnew System::Windows::Forms::TextBox());
			this->dgv_Com = (gcnew System::Windows::Forms::DataGridView());
			this->gb_RechercherDate_Com = (gcnew System::Windows::Forms::GroupBox());
			this->cb_Annee_Com = (gcnew System::Windows::Forms::ComboBox());
			this->cb_Mois_Com = (gcnew System::Windows::Forms::ComboBox());
			this->bnt_RechercherDate_Com = (gcnew System::Windows::Forms::Button());
			this->cb_Jour_Com = (gcnew System::Windows::Forms::ComboBox());
			this->gb_RechercheCli_COM = (gcnew System::Windows::Forms::GroupBox());
			this->txt_IdClient_Com = (gcnew System::Windows::Forms::TextBox());
			this->txt_PrenomClient_Com = (gcnew System::Windows::Forms::TextBox());
			this->btn_RechercherCli_Com = (gcnew System::Windows::Forms::Button());
			this->txt_NomClient_Com = (gcnew System::Windows::Forms::TextBox());
			this->lbl_IdClient_Com = (gcnew System::Windows::Forms::Label());
			this->lbl_PrenomClient_Com = (gcnew System::Windows::Forms::Label());
			this->lbl_NomClient_Com = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txt_message = (gcnew System::Windows::Forms::TextBox());
			this->dgv_req_stat = (gcnew System::Windows::Forms::DataGridView());
			this->btn_ok_stat = (gcnew System::Windows::Forms::Button());
			this->txt_IdClient_stat = (gcnew System::Windows::Forms::TextBox());
			this->txt_prenomClient_stat = (gcnew System::Windows::Forms::TextBox());
			this->txt_nomClient_stat = (gcnew System::Windows::Forms::TextBox());
			this->lbl_nomClient_stat = (gcnew System::Windows::Forms::Label());
			this->lbl_IdClient_stat = (gcnew System::Windows::Forms::Label());
			this->lbl_prenomClient_stat = (gcnew System::Windows::Forms::Label());
			this->gp_InfosClients_stat = (gcnew System::Windows::Forms::GroupBox());
			this->gp_InfoDate_stat = (gcnew System::Windows::Forms::GroupBox());
			this->lbl_year_stat = (gcnew System::Windows::Forms::Label());
			this->lbl_month_stat = (gcnew System::Windows::Forms::Label());
			this->lbl_titleSelect_stat = (gcnew System::Windows::Forms::Label());
			this->cb_year_stat = (gcnew System::Windows::Forms::ComboBox());
			this->cb_month_stat = (gcnew System::Windows::Forms::ComboBox());
			this->cb_req_stat = (gcnew System::Windows::Forms::ComboBox());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->gb_statistiques = (gcnew System::Windows::Forms::GroupBox());
			this->txt_stats_result = (gcnew System::Windows::Forms::TextBox());
			this->lbl_stats_result = (gcnew System::Windows::Forms::Label());
			this->btn_stats_calculer = (gcnew System::Windows::Forms::Button());
			this->lbl_stats_variationValeurStock = (gcnew System::Windows::Forms::Label());
			this->lbl_stats_margeCommerciale = (gcnew System::Windows::Forms::Label());
			this->lbl_stats_remiseCommerciale = (gcnew System::Windows::Forms::Label());
			this->lbl_stats_demarqueInconnue = (gcnew System::Windows::Forms::Label());
			this->lbl_stats_TVA = (gcnew System::Windows::Forms::Label());
			this->txt_stats_demarqueInconnue = (gcnew System::Windows::Forms::TextBox());
			this->txt_stats_remiseCommerciale = (gcnew System::Windows::Forms::TextBox());
			this->txt_stats_margeCommerciale = (gcnew System::Windows::Forms::TextBox());
			this->txt_stats_TVA = (gcnew System::Windows::Forms::TextBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->groupBoxStock = (gcnew System::Windows::Forms::GroupBox());
			this->buttonClearTVA = (gcnew System::Windows::Forms::Button());
			this->buttonClearNature = (gcnew System::Windows::Forms::Button());
			this->buttonClearArticle = (gcnew System::Windows::Forms::Button());
			this->buttonDernierNature = (gcnew System::Windows::Forms::Button());
			this->buttonPremierNature = (gcnew System::Windows::Forms::Button());
			this->textBoxTauxTVA = (gcnew System::Windows::Forms::TextBox());
			this->buttonSuivantNature = (gcnew System::Windows::Forms::Button());
			this->textBoxIdTVA = (gcnew System::Windows::Forms::TextBox());
			this->buttonPrecedentNature = (gcnew System::Windows::Forms::Button());
			this->buttonDernierTVA = (gcnew System::Windows::Forms::Button());
			this->labelIdTVA = (gcnew System::Windows::Forms::Label());
			this->buttonDernierArticle = (gcnew System::Windows::Forms::Button());
			this->buttonPremierTVA = (gcnew System::Windows::Forms::Button());
			this->buttonPremierArticle = (gcnew System::Windows::Forms::Button());
			this->labelTauxTVA = (gcnew System::Windows::Forms::Label());
			this->buttonSuivantArticle = (gcnew System::Windows::Forms::Button());
			this->buttonSuivantTVA = (gcnew System::Windows::Forms::Button());
			this->buttonPrecedentArticle = (gcnew System::Windows::Forms::Button());
			this->buttonPrecedentTVA = (gcnew System::Windows::Forms::Button());
			this->buttonAjouterArticle = (gcnew System::Windows::Forms::Button());
			this->buttonUpdateArticle = (gcnew System::Windows::Forms::Button());
			this->buttonDeleteArticle = (gcnew System::Windows::Forms::Button());
			this->labelNature = (gcnew System::Windows::Forms::Label());
			this->textBoxNature = (gcnew System::Windows::Forms::TextBox());
			this->labelQuantiteStockArticle = (gcnew System::Windows::Forms::Label());
			this->textBoxQuantiteStockArticle = (gcnew System::Windows::Forms::TextBox());
			this->labelSeuilReapro = (gcnew System::Windows::Forms::Label());
			this->textBoxSeuilReapro = (gcnew System::Windows::Forms::TextBox());
			this->labelDesignationArticle = (gcnew System::Windows::Forms::Label());
			this->textBoxDesignationArticle = (gcnew System::Windows::Forms::TextBox());
			this->labelNomArticle = (gcnew System::Windows::Forms::Label());
			this->textBoxNomArticle = (gcnew System::Windows::Forms::TextBox());
			this->labelIdNature = (gcnew System::Windows::Forms::Label());
			this->textBoxIdNature = (gcnew System::Windows::Forms::TextBox());
			this->labelIdArticle = (gcnew System::Windows::Forms::Label());
			this->textBoxIdArticle = (gcnew System::Windows::Forms::TextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->gb_client = (gcnew System::Windows::Forms::GroupBox());
			this->btn_previous_client = (gcnew System::Windows::Forms::Button());
			this->btn_first_client = (gcnew System::Windows::Forms::Button());
			this->btn_next_client = (gcnew System::Windows::Forms::Button());
			this->btn_end_client = (gcnew System::Windows::Forms::Button());
			this->datePremAchatPicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateNaissancePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->txt_datepremierachat = (gcnew System::Windows::Forms::TextBox());
			this->txt_datenaissance = (gcnew System::Windows::Forms::TextBox());
			this->lbl_premier_achat = (gcnew System::Windows::Forms::Label());
			this->lbl_datenaissance = (gcnew System::Windows::Forms::Label());
			this->btn_supprimer_client = (gcnew System::Windows::Forms::Button());
			this->btn_modifier_client = (gcnew System::Windows::Forms::Button());
			this->btn_enregistrer_client = (gcnew System::Windows::Forms::Button());
			this->btn_nouveau_client = (gcnew System::Windows::Forms::Button());
			this->txt_PrenomClient = (gcnew System::Windows::Forms::TextBox());
			this->txt_NomClient = (gcnew System::Windows::Forms::TextBox());
			this->lbl_PrenomClient = (gcnew System::Windows::Forms::Label());
			this->lbl_idNomClient = (gcnew System::Windows::Forms::Label());
			this->txt_idClient = (gcnew System::Windows::Forms::TextBox());
			this->lbl_idClient = (gcnew System::Windows::Forms::Label());
			this->rb_livraison = (gcnew System::Windows::Forms::RadioButton());
			this->rb_facturation = (gcnew System::Windows::Forms::RadioButton());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->gb_personnel = (gcnew System::Windows::Forms::GroupBox());
			this->txt_dateEmbauche = (gcnew System::Windows::Forms::TextBox());
			this->ListeEmployes = (gcnew System::Windows::Forms::DataGridView());
			this->NoRue = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Adresse = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Ville = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CP = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btn_nouveau_personnel = (gcnew System::Windows::Forms::Button());
			this->lbl_dateembauche = (gcnew System::Windows::Forms::Label());
			this->btn_modifier_personnel = (gcnew System::Windows::Forms::Button());
			this->dateEmbauchePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->btn_supprimer_personnel = (gcnew System::Windows::Forms::Button());
			this->btn_enregistrer_personnel = (gcnew System::Windows::Forms::Button());
			this->btn_previous_personnel = (gcnew System::Windows::Forms::Button());
			this->btn_first_personnel = (gcnew System::Windows::Forms::Button());
			this->btn_next_personnel = (gcnew System::Windows::Forms::Button());
			this->btn_end_personnel = (gcnew System::Windows::Forms::Button());
			this->txt_prenom = (gcnew System::Windows::Forms::TextBox());
			this->txt_nom = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txt_idPersonne = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->gb_Add_Com->SuspendLayout();
			this->gb_RechercherRef_Com->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_Com))->BeginInit();
			this->gb_RechercherDate_Com->SuspendLayout();
			this->gb_RechercheCli_COM->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_req_stat))->BeginInit();
			this->gp_InfosClients_stat->SuspendLayout();
			this->gp_InfoDate_stat->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->gb_statistiques->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->groupBoxStock->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->gb_client->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabPage1->SuspendLayout();
			this->gb_personnel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ListeEmployes))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage5->SuspendLayout();
			this->SuspendLayout();
			// 
			// tp_commandes
			// 
			this->tp_commandes->Location = System::Drawing::Point(0, 0);
			this->tp_commandes->Name = L"tp_commandes";
			this->tp_commandes->Size = System::Drawing::Size(200, 100);
			this->tp_commandes->TabIndex = 0;
			// 
			// gb_Add_Com
			// 
			this->gb_Add_Com->Controls->Add(this->lbl_AddDatePaiementRec_Com);
			this->gb_Add_Com->Controls->Add(this->AddDateEmission_Com);
			this->gb_Add_Com->Controls->Add(this->lbl_AddDate_Com);
			this->gb_Add_Com->Controls->Add(this->dtp_AddDatePaiementRec_Com);
			this->gb_Add_Com->Controls->Add(this->dtp_AddDateEmission_Com);
			this->gb_Add_Com->Controls->Add(this->dtp_AddDate_Com);
			this->gb_Add_Com->Controls->Add(this->lbl_AddTVA_Com);
			this->gb_Add_Com->Controls->Add(this->lbl_AddTTC_Com);
			this->gb_Add_Com->Controls->Add(this->lbl_AddHT_Com);
			this->gb_Add_Com->Controls->Add(this->lbl_AddRef_Com);
			this->gb_Add_Com->Controls->Add(this->lbl_AddIdCli_Com);
			this->gb_Add_Com->Controls->Add(this->btn_Add_Com);
			this->gb_Add_Com->Controls->Add(this->txt_AddTVA_Com);
			this->gb_Add_Com->Controls->Add(this->txt_AddHT_Com);
			this->gb_Add_Com->Controls->Add(this->txt_AddTTC_Com);
			this->gb_Add_Com->Controls->Add(this->txt_AddIdCli_Com);
			this->gb_Add_Com->Controls->Add(this->txt_AddRef_Com);
			this->gb_Add_Com->Location = System::Drawing::Point(635, 293);
			this->gb_Add_Com->Name = L"gb_Add_Com";
			this->gb_Add_Com->Size = System::Drawing::Size(474, 179);
			this->gb_Add_Com->TabIndex = 13;
			this->gb_Add_Com->TabStop = false;
			// 
			// lbl_AddDatePaiementRec_Com
			// 
			this->lbl_AddDatePaiementRec_Com->AutoSize = true;
			this->lbl_AddDatePaiementRec_Com->Location = System::Drawing::Point(245, 104);
			this->lbl_AddDatePaiementRec_Com->Name = L"lbl_AddDatePaiementRec_Com";
			this->lbl_AddDatePaiementRec_Com->Size = System::Drawing::Size(100, 17);
			this->lbl_AddDatePaiementRec_Com->TabIndex = 28;
			this->lbl_AddDatePaiementRec_Com->Text = L"Date paiement";
			// 
			// AddDateEmission_Com
			// 
			this->AddDateEmission_Com->AutoSize = true;
			this->AddDateEmission_Com->Location = System::Drawing::Point(245, 59);
			this->AddDateEmission_Com->Name = L"AddDateEmission_Com";
			this->AddDateEmission_Com->Size = System::Drawing::Size(98, 17);
			this->AddDateEmission_Com->TabIndex = 27;
			this->AddDateEmission_Com->Text = L"Date Emission";
			// 
			// lbl_AddDate_Com
			// 
			this->lbl_AddDate_Com->AutoSize = true;
			this->lbl_AddDate_Com->Location = System::Drawing::Point(245, 14);
			this->lbl_AddDate_Com->Name = L"lbl_AddDate_Com";
			this->lbl_AddDate_Com->Size = System::Drawing::Size(111, 17);
			this->lbl_AddDate_Com->TabIndex = 26;
			this->lbl_AddDate_Com->Text = L"Date commande";
			// 
			// dtp_AddDatePaiementRec_Com
			// 
			this->dtp_AddDatePaiementRec_Com->CustomFormat = L"yyyy-MM-dd";
			this->dtp_AddDatePaiementRec_Com->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dtp_AddDatePaiementRec_Com->Location = System::Drawing::Point(248, 128);
			this->dtp_AddDatePaiementRec_Com->Name = L"dtp_AddDatePaiementRec_Com";
			this->dtp_AddDatePaiementRec_Com->Size = System::Drawing::Size(108, 22);
			this->dtp_AddDatePaiementRec_Com->TabIndex = 25;
			// 
			// dtp_AddDateEmission_Com
			// 
			this->dtp_AddDateEmission_Com->CustomFormat = L"yyyy-MM-dd";
			this->dtp_AddDateEmission_Com->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dtp_AddDateEmission_Com->Location = System::Drawing::Point(248, 79);
			this->dtp_AddDateEmission_Com->Name = L"dtp_AddDateEmission_Com";
			this->dtp_AddDateEmission_Com->Size = System::Drawing::Size(108, 22);
			this->dtp_AddDateEmission_Com->TabIndex = 24;
			// 
			// dtp_AddDate_Com
			// 
			this->dtp_AddDate_Com->CustomFormat = L"yyyy-MM-dd";
			this->dtp_AddDate_Com->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dtp_AddDate_Com->Location = System::Drawing::Point(248, 36);
			this->dtp_AddDate_Com->Name = L"dtp_AddDate_Com";
			this->dtp_AddDate_Com->Size = System::Drawing::Size(108, 22);
			this->dtp_AddDate_Com->TabIndex = 23;
			// 
			// lbl_AddTVA_Com
			// 
			this->lbl_AddTVA_Com->AutoSize = true;
			this->lbl_AddTVA_Com->Location = System::Drawing::Point(4, 108);
			this->lbl_AddTVA_Com->Name = L"lbl_AddTVA_Com";
			this->lbl_AddTVA_Com->Size = System::Drawing::Size(90, 17);
			this->lbl_AddTVA_Com->TabIndex = 22;
			this->lbl_AddTVA_Com->Text = L"Montant TVA";
			// 
			// lbl_AddTTC_Com
			// 
			this->lbl_AddTTC_Com->AutoSize = true;
			this->lbl_AddTTC_Com->Location = System::Drawing::Point(115, 62);
			this->lbl_AddTTC_Com->Name = L"lbl_AddTTC_Com";
			this->lbl_AddTTC_Com->Size = System::Drawing::Size(90, 17);
			this->lbl_AddTTC_Com->TabIndex = 21;
			this->lbl_AddTTC_Com->Text = L"Montant TTC";
			// 
			// lbl_AddHT_Com
			// 
			this->lbl_AddHT_Com->AutoSize = true;
			this->lbl_AddHT_Com->Location = System::Drawing::Point(115, 12);
			this->lbl_AddHT_Com->Name = L"lbl_AddHT_Com";
			this->lbl_AddHT_Com->Size = System::Drawing::Size(82, 17);
			this->lbl_AddHT_Com->TabIndex = 20;
			this->lbl_AddHT_Com->Text = L"Montant HT";
			// 
			// lbl_AddRef_Com
			// 
			this->lbl_AddRef_Com->AutoSize = true;
			this->lbl_AddRef_Com->Location = System::Drawing::Point(4, 60);
			this->lbl_AddRef_Com->Name = L"lbl_AddRef_Com";
			this->lbl_AddRef_Com->Size = System::Drawing::Size(103, 17);
			this->lbl_AddRef_Com->TabIndex = 19;
			this->lbl_AddRef_Com->Text = L"Ref commande";
			// 
			// lbl_AddIdCli_Com
			// 
			this->lbl_AddIdCli_Com->AutoSize = true;
			this->lbl_AddIdCli_Com->Location = System::Drawing::Point(3, 12);
			this->lbl_AddIdCli_Com->Name = L"lbl_AddIdCli_Com";
			this->lbl_AddIdCli_Com->Size = System::Drawing::Size(60, 17);
			this->lbl_AddIdCli_Com->TabIndex = 18;
			this->lbl_AddIdCli_Com->Text = L"ID Client";
			// 
			// btn_Add_Com
			// 
			this->btn_Add_Com->Location = System::Drawing::Point(367, 42);
			this->btn_Add_Com->Name = L"btn_Add_Com";
			this->btn_Add_Com->Size = System::Drawing::Size(91, 102);
			this->btn_Add_Com->TabIndex = 17;
			this->btn_Add_Com->Text = L"Valider commande";
			this->btn_Add_Com->UseVisualStyleBackColor = true;
			this->btn_Add_Com->Click += gcnew System::EventHandler(this, &MyForm::btn_Add_Com_Click);
			// 
			// txt_AddTVA_Com
			// 
			this->txt_AddTVA_Com->Location = System::Drawing::Point(7, 127);
			this->txt_AddTVA_Com->Name = L"txt_AddTVA_Com";
			this->txt_AddTVA_Com->Size = System::Drawing::Size(100, 22);
			this->txt_AddTVA_Com->TabIndex = 15;
			// 
			// txt_AddHT_Com
			// 
			this->txt_AddHT_Com->Location = System::Drawing::Point(118, 31);
			this->txt_AddHT_Com->Name = L"txt_AddHT_Com";
			this->txt_AddHT_Com->Size = System::Drawing::Size(100, 22);
			this->txt_AddHT_Com->TabIndex = 14;
			// 
			// txt_AddTTC_Com
			// 
			this->txt_AddTTC_Com->Location = System::Drawing::Point(116, 80);
			this->txt_AddTTC_Com->Name = L"txt_AddTTC_Com";
			this->txt_AddTTC_Com->Size = System::Drawing::Size(100, 22);
			this->txt_AddTTC_Com->TabIndex = 13;
			// 
			// txt_AddIdCli_Com
			// 
			this->txt_AddIdCli_Com->Location = System::Drawing::Point(6, 31);
			this->txt_AddIdCli_Com->Name = L"txt_AddIdCli_Com";
			this->txt_AddIdCli_Com->Size = System::Drawing::Size(100, 22);
			this->txt_AddIdCli_Com->TabIndex = 12;
			// 
			// txt_AddRef_Com
			// 
			this->txt_AddRef_Com->Location = System::Drawing::Point(6, 80);
			this->txt_AddRef_Com->Name = L"txt_AddRef_Com";
			this->txt_AddRef_Com->Size = System::Drawing::Size(100, 22);
			this->txt_AddRef_Com->TabIndex = 11;
			// 
			// rb_Del_Com
			// 
			this->rb_Del_Com->AutoSize = true;
			this->rb_Del_Com->Location = System::Drawing::Point(932, 27);
			this->rb_Del_Com->Name = L"rb_Del_Com";
			this->rb_Del_Com->Size = System::Drawing::Size(94, 21);
			this->rb_Del_Com->TabIndex = 10;
			this->rb_Del_Com->TabStop = true;
			this->rb_Del_Com->Text = L"Supprimer";
			this->rb_Del_Com->UseVisualStyleBackColor = true;
			// 
			// rb_Up_Com
			// 
			this->rb_Up_Com->AutoSize = true;
			this->rb_Up_Com->Location = System::Drawing::Point(525, 27);
			this->rb_Up_Com->Name = L"rb_Up_Com";
			this->rb_Up_Com->Size = System::Drawing::Size(62, 17);
			this->rb_Up_Com->TabIndex = 9;
			this->rb_Up_Com->TabStop = true;
			this->rb_Up_Com->Text = L"Modifier";
			this->rb_Up_Com->UseVisualStyleBackColor = true;
			// 
			// rb_Add_Com
			// 
			this->rb_Add_Com->AutoSize = true;
			this->rb_Add_Com->Location = System::Drawing::Point(515, 27);
			this->rb_Add_Com->Name = L"rb_Add_Com";
			this->rb_Add_Com->Size = System::Drawing::Size(74, 21);
			this->rb_Add_Com->TabIndex = 8;
			this->rb_Add_Com->TabStop = true;
			this->rb_Add_Com->Text = L"Ajouter";
			this->rb_Add_Com->UseVisualStyleBackColor = true;
			this->rb_Add_Com->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rb_Add_Com_CheckedChanged);
			// 
			// rb_Aff_Com
			// 
			this->rb_Aff_Com->AutoSize = true;
			this->rb_Aff_Com->Location = System::Drawing::Point(113, 27);
			this->rb_Aff_Com->Name = L"rb_Aff_Com";
			this->rb_Aff_Com->Size = System::Drawing::Size(77, 21);
			this->rb_Aff_Com->TabIndex = 7;
			this->rb_Aff_Com->TabStop = true;
			this->rb_Aff_Com->Text = L"Afficher";
			this->rb_Aff_Com->UseVisualStyleBackColor = true;
			// 
			// rb_ParRef_Com
			// 
			this->rb_ParRef_Com->AutoSize = true;
			this->rb_ParRef_Com->Location = System::Drawing::Point(139, 286);
			this->rb_ParRef_Com->Name = L"rb_ParRef_Com";
			this->rb_ParRef_Com->Size = System::Drawing::Size(115, 21);
			this->rb_ParRef_Com->TabIndex = 6;
			this->rb_ParRef_Com->Text = L"par référence";
			this->rb_ParRef_Com->UseVisualStyleBackColor = true;
			this->rb_ParRef_Com->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rb_ParRef_Com_CheckedChanged);
			// 
			// rb_ParDate_Com
			// 
			this->rb_ParDate_Com->AutoSize = true;
			this->rb_ParDate_Com->Location = System::Drawing::Point(269, 286);
			this->rb_ParDate_Com->Name = L"rb_ParDate_Com";
			this->rb_ParDate_Com->Size = System::Drawing::Size(82, 21);
			this->rb_ParDate_Com->TabIndex = 5;
			this->rb_ParDate_Com->Text = L"par date";
			this->rb_ParDate_Com->UseVisualStyleBackColor = true;
			this->rb_ParDate_Com->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rb_ParDate_Com_CheckedChanged);
			// 
			// rb_ParClient_Com
			// 
			this->rb_ParClient_Com->AutoSize = true;
			this->rb_ParClient_Com->Location = System::Drawing::Point(21, 286);
			this->rb_ParClient_Com->Name = L"rb_ParClient_Com";
			this->rb_ParClient_Com->Size = System::Drawing::Size(87, 21);
			this->rb_ParClient_Com->TabIndex = 4;
			this->rb_ParClient_Com->Text = L"par client";
			this->rb_ParClient_Com->UseVisualStyleBackColor = true;
			this->rb_ParClient_Com->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rb_ParClient_Com_CheckedChanged);
			// 
			// lbl_Rechercher_Com
			// 
			this->lbl_Rechercher_Com->AutoSize = true;
			this->lbl_Rechercher_Com->Location = System::Drawing::Point(18, 260);
			this->lbl_Rechercher_Com->Name = L"lbl_Rechercher_Com";
			this->lbl_Rechercher_Com->Size = System::Drawing::Size(191, 17);
			this->lbl_Rechercher_Com->TabIndex = 3;
			this->lbl_Rechercher_Com->Text = L"Rechercher une commande :";
			// 
			// gb_RechercherRef_Com
			// 
			this->gb_RechercherRef_Com->Controls->Add(this->bnt_RechercherRef_Com);
			this->gb_RechercherRef_Com->Controls->Add(this->lbl_Ref_Com);
			this->gb_RechercherRef_Com->Controls->Add(this->txt_Ref_Com);
			this->gb_RechercherRef_Com->Location = System::Drawing::Point(93, 324);
			this->gb_RechercherRef_Com->Name = L"gb_RechercherRef_Com";
			this->gb_RechercherRef_Com->Size = System::Drawing::Size(200, 119);
			this->gb_RechercherRef_Com->TabIndex = 1;
			this->gb_RechercherRef_Com->TabStop = false;
			this->gb_RechercherRef_Com->Visible = false;
			// 
			// bnt_RechercherRef_Com
			// 
			this->bnt_RechercherRef_Com->Location = System::Drawing::Point(26, 75);
			this->bnt_RechercherRef_Com->Name = L"bnt_RechercherRef_Com";
			this->bnt_RechercherRef_Com->Size = System::Drawing::Size(142, 30);
			this->bnt_RechercherRef_Com->TabIndex = 6;
			this->bnt_RechercherRef_Com->Text = L"Rechercher Commande";
			this->bnt_RechercherRef_Com->UseVisualStyleBackColor = true;
			this->bnt_RechercherRef_Com->Click += gcnew System::EventHandler(this, &MyForm::bnt_RechercherRef_Com_Click);
			// 
			// lbl_Ref_Com
			// 
			this->lbl_Ref_Com->AutoSize = true;
			this->lbl_Ref_Com->Location = System::Drawing::Point(23, 21);
			this->lbl_Ref_Com->Name = L"lbl_Ref_Com";
			this->lbl_Ref_Com->Size = System::Drawing::Size(155, 17);
			this->lbl_Ref_Com->TabIndex = 7;
			this->lbl_Ref_Com->Text = L"Référence commande :";
			// 
			// txt_Ref_Com
			// 
			this->txt_Ref_Com->Location = System::Drawing::Point(20, 47);
			this->txt_Ref_Com->Name = L"txt_Ref_Com";
			this->txt_Ref_Com->Size = System::Drawing::Size(158, 22);
			this->txt_Ref_Com->TabIndex = 4;
			// 
			// dgv_Com
			// 
			this->dgv_Com->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_Com->Cursor = System::Windows::Forms::Cursors::Default;
			this->dgv_Com->Location = System::Drawing::Point(113, 71);
			this->dgv_Com->Name = L"dgv_Com";
			this->dgv_Com->ReadOnly = true;
			this->dgv_Com->RowHeadersWidth = 51;
			this->dgv_Com->Size = System::Drawing::Size(913, 182);
			this->dgv_Com->TabIndex = 2;
			// 
			// gb_RechercherDate_Com
			// 
			this->gb_RechercherDate_Com->Controls->Add(this->cb_Annee_Com);
			this->gb_RechercherDate_Com->Controls->Add(this->cb_Mois_Com);
			this->gb_RechercherDate_Com->Controls->Add(this->bnt_RechercherDate_Com);
			this->gb_RechercherDate_Com->Controls->Add(this->cb_Jour_Com);
			this->gb_RechercherDate_Com->Location = System::Drawing::Point(49, 329);
			this->gb_RechercherDate_Com->Name = L"gb_RechercherDate_Com";
			this->gb_RechercherDate_Com->Size = System::Drawing::Size(302, 110);
			this->gb_RechercherDate_Com->TabIndex = 1;
			this->gb_RechercherDate_Com->TabStop = false;
			this->gb_RechercherDate_Com->Visible = false;
			// 
			// cb_Annee_Com
			// 
			this->cb_Annee_Com->FormattingEnabled = true;
			this->cb_Annee_Com->Items->AddRange(gcnew cli::array< System::Object^  >(32) {
				L"1999", L"2000", L"2001", L"2002", L"2003",
					L"2004", L"2005", L"2006", L"2007", L"2008", L"2009", L"2010", L"2011", L"2012", L"2013", L"2014", L"2015", L"2016", L"2017",
					L"2018", L"2019", L"2020", L"2021", L"2022", L"2023", L"2024", L"2025", L"2026", L"2027", L"2028", L"2029", L"2030"
			});
			this->cb_Annee_Com->Location = System::Drawing::Point(196, 27);
			this->cb_Annee_Com->Name = L"cb_Annee_Com";
			this->cb_Annee_Com->Size = System::Drawing::Size(91, 24);
			this->cb_Annee_Com->TabIndex = 5;
			this->cb_Annee_Com->Text = L"Année";
			// 
			// cb_Mois_Com
			// 
			this->cb_Mois_Com->FormattingEnabled = true;
			this->cb_Mois_Com->Items->AddRange(gcnew cli::array< System::Object^  >(13) {
				L"Mois", L"Janvier", L"Février", L"Mars", L"Avril",
					L"Mai", L"Juin", L"Juillet", L"Août", L"Septembre", L"Octobre", L"Novembre", L"Décembre"
			});
			this->cb_Mois_Com->Location = System::Drawing::Point(90, 27);
			this->cb_Mois_Com->Name = L"cb_Mois_Com";
			this->cb_Mois_Com->Size = System::Drawing::Size(88, 24);
			this->cb_Mois_Com->TabIndex = 6;
			this->cb_Mois_Com->Text = L"Mois";
			// 
			// bnt_RechercherDate_Com
			// 
			this->bnt_RechercherDate_Com->Location = System::Drawing::Point(74, 67);
			this->bnt_RechercherDate_Com->Name = L"bnt_RechercherDate_Com";
			this->bnt_RechercherDate_Com->Size = System::Drawing::Size(144, 27);
			this->bnt_RechercherDate_Com->TabIndex = 5;
			this->bnt_RechercherDate_Com->Text = L"Rechercher commande";
			this->bnt_RechercherDate_Com->UseVisualStyleBackColor = true;
			this->bnt_RechercherDate_Com->Click += gcnew System::EventHandler(this, &MyForm::bnt_RechercherDate_Com_Click);
			// 
			// cb_Jour_Com
			// 
			this->cb_Jour_Com->FormattingEnabled = true;
			this->cb_Jour_Com->Items->AddRange(gcnew cli::array< System::Object^  >(30) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"23", L"24", L"25", L"26", L"27",
					L"28", L"29", L"30", L"31"
			});
			this->cb_Jour_Com->Location = System::Drawing::Point(17, 27);
			this->cb_Jour_Com->Name = L"cb_Jour_Com";
			this->cb_Jour_Com->Size = System::Drawing::Size(58, 24);
			this->cb_Jour_Com->TabIndex = 4;
			this->cb_Jour_Com->Text = L"Jour";
			// 
			// gb_RechercheCli_COM
			// 
			this->gb_RechercheCli_COM->Controls->Add(this->txt_IdClient_Com);
			this->gb_RechercheCli_COM->Controls->Add(this->txt_PrenomClient_Com);
			this->gb_RechercheCli_COM->Controls->Add(this->btn_RechercherCli_Com);
			this->gb_RechercheCli_COM->Controls->Add(this->txt_NomClient_Com);
			this->gb_RechercheCli_COM->Controls->Add(this->lbl_IdClient_Com);
			this->gb_RechercheCli_COM->Controls->Add(this->lbl_PrenomClient_Com);
			this->gb_RechercheCli_COM->Controls->Add(this->lbl_NomClient_Com);
			this->gb_RechercheCli_COM->Location = System::Drawing::Point(75, 305);
			this->gb_RechercheCli_COM->Name = L"gb_RechercheCli_COM";
			this->gb_RechercheCli_COM->Size = System::Drawing::Size(261, 160);
			this->gb_RechercheCli_COM->TabIndex = 0;
			this->gb_RechercheCli_COM->TabStop = false;
			this->gb_RechercheCli_COM->Visible = false;
			// 
			// txt_IdClient_Com
			// 
			this->txt_IdClient_Com->Location = System::Drawing::Point(6, 30);
			this->txt_IdClient_Com->Name = L"txt_IdClient_Com";
			this->txt_IdClient_Com->Size = System::Drawing::Size(100, 22);
			this->txt_IdClient_Com->TabIndex = 5;
			// 
			// txt_PrenomClient_Com
			// 
			this->txt_PrenomClient_Com->Location = System::Drawing::Point(6, 80);
			this->txt_PrenomClient_Com->Name = L"txt_PrenomClient_Com";
			this->txt_PrenomClient_Com->Size = System::Drawing::Size(100, 22);
			this->txt_PrenomClient_Com->TabIndex = 6;
			// 
			// btn_RechercherCli_Com
			// 
			this->btn_RechercherCli_Com->Location = System::Drawing::Point(125, 30);
			this->btn_RechercherCli_Com->Name = L"btn_RechercherCli_Com";
			this->btn_RechercherCli_Com->Size = System::Drawing::Size(126, 118);
			this->btn_RechercherCli_Com->TabIndex = 4;
			this->btn_RechercherCli_Com->Text = L"Rechercher commande";
			this->btn_RechercherCli_Com->UseVisualStyleBackColor = true;
			this->btn_RechercherCli_Com->Click += gcnew System::EventHandler(this, &MyForm::btn_RechercherCli_Com_Click);
			// 
			// txt_NomClient_Com
			// 
			this->txt_NomClient_Com->Location = System::Drawing::Point(6, 128);
			this->txt_NomClient_Com->Name = L"txt_NomClient_Com";
			this->txt_NomClient_Com->Size = System::Drawing::Size(100, 22);
			this->txt_NomClient_Com->TabIndex = 7;
			// 
			// lbl_IdClient_Com
			// 
			this->lbl_IdClient_Com->AutoSize = true;
			this->lbl_IdClient_Com->Location = System::Drawing::Point(3, 14);
			this->lbl_IdClient_Com->Name = L"lbl_IdClient_Com";
			this->lbl_IdClient_Com->Size = System::Drawing::Size(60, 17);
			this->lbl_IdClient_Com->TabIndex = 4;
			this->lbl_IdClient_Com->Text = L"ID Client";
			// 
			// lbl_PrenomClient_Com
			// 
			this->lbl_PrenomClient_Com->AutoSize = true;
			this->lbl_PrenomClient_Com->Location = System::Drawing::Point(3, 64);
			this->lbl_PrenomClient_Com->Name = L"lbl_PrenomClient_Com";
			this->lbl_PrenomClient_Com->Size = System::Drawing::Size(96, 17);
			this->lbl_PrenomClient_Com->TabIndex = 6;
			this->lbl_PrenomClient_Com->Text = L"Prenom Client";
			// 
			// lbl_NomClient_Com
			// 
			this->lbl_NomClient_Com->AutoSize = true;
			this->lbl_NomClient_Com->Location = System::Drawing::Point(3, 112);
			this->lbl_NomClient_Com->Name = L"lbl_NomClient_Com";
			this->lbl_NomClient_Com->Size = System::Drawing::Size(76, 17);
			this->lbl_NomClient_Com->TabIndex = 5;
			this->lbl_NomClient_Com->Text = L"Nom Client";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 560);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(65, 17);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Message";
			// 
			// txt_message
			// 
			this->txt_message->AcceptsReturn = true;
			this->txt_message->AllowDrop = true;
			this->txt_message->Location = System::Drawing::Point(12, 584);
			this->txt_message->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txt_message->Multiline = true;
			this->txt_message->Name = L"txt_message";
			this->txt_message->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txt_message->Size = System::Drawing::Size(1137, 90);
			this->txt_message->TabIndex = 7;
			// 
			// dgv_req_stat
			// 
			this->dgv_req_stat->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_req_stat->Location = System::Drawing::Point(250, 65);
			this->dgv_req_stat->Name = L"dgv_req_stat";
			this->dgv_req_stat->RowHeadersWidth = 51;
			this->dgv_req_stat->Size = System::Drawing::Size(817, 197);
			this->dgv_req_stat->TabIndex = 0;
			// 
			// btn_ok_stat
			// 
			this->btn_ok_stat->Location = System::Drawing::Point(28, 65);
			this->btn_ok_stat->Name = L"btn_ok_stat";
			this->btn_ok_stat->Size = System::Drawing::Size(196, 82);
			this->btn_ok_stat->TabIndex = 0;
			this->btn_ok_stat->Text = L"Valider";
			this->btn_ok_stat->UseVisualStyleBackColor = true;
			this->btn_ok_stat->Click += gcnew System::EventHandler(this, &MyForm::btn_ok_Click);
			// 
			// txt_IdClient_stat
			// 
			this->txt_IdClient_stat->Location = System::Drawing::Point(20, 48);
			this->txt_IdClient_stat->Name = L"txt_IdClient_stat";
			this->txt_IdClient_stat->Size = System::Drawing::Size(156, 22);
			this->txt_IdClient_stat->TabIndex = 0;
			// 
			// txt_prenomClient_stat
			// 
			this->txt_prenomClient_stat->Location = System::Drawing::Point(20, 187);
			this->txt_prenomClient_stat->Name = L"txt_prenomClient_stat";
			this->txt_prenomClient_stat->Size = System::Drawing::Size(156, 22);
			this->txt_prenomClient_stat->TabIndex = 0;
			// 
			// txt_nomClient_stat
			// 
			this->txt_nomClient_stat->Location = System::Drawing::Point(20, 118);
			this->txt_nomClient_stat->Name = L"txt_nomClient_stat";
			this->txt_nomClient_stat->Size = System::Drawing::Size(156, 22);
			this->txt_nomClient_stat->TabIndex = 0;
			// 
			// lbl_nomClient_stat
			// 
			this->lbl_nomClient_stat->AutoSize = true;
			this->lbl_nomClient_stat->Location = System::Drawing::Point(17, 95);
			this->lbl_nomClient_stat->Name = L"lbl_nomClient_stat";
			this->lbl_nomClient_stat->Size = System::Drawing::Size(37, 17);
			this->lbl_nomClient_stat->TabIndex = 0;
			this->lbl_nomClient_stat->Text = L"Nom";
			// 
			// lbl_IdClient_stat
			// 
			this->lbl_IdClient_stat->AutoSize = true;
			this->lbl_IdClient_stat->Location = System::Drawing::Point(17, 24);
			this->lbl_IdClient_stat->Name = L"lbl_IdClient_stat";
			this->lbl_IdClient_stat->Size = System::Drawing::Size(60, 17);
			this->lbl_IdClient_stat->TabIndex = 0;
			this->lbl_IdClient_stat->Text = L"ID Client";
			// 
			// lbl_prenomClient_stat
			// 
			this->lbl_prenomClient_stat->AutoSize = true;
			this->lbl_prenomClient_stat->Location = System::Drawing::Point(17, 166);
			this->lbl_prenomClient_stat->Name = L"lbl_prenomClient_stat";
			this->lbl_prenomClient_stat->Size = System::Drawing::Size(57, 17);
			this->lbl_prenomClient_stat->TabIndex = 0;
			this->lbl_prenomClient_stat->Text = L"Prenom";
			// 
			// gp_InfosClients_stat
			// 
			this->gp_InfosClients_stat->Controls->Add(this->txt_nomClient_stat);
			this->gp_InfosClients_stat->Controls->Add(this->lbl_nomClient_stat);
			this->gp_InfosClients_stat->Controls->Add(this->lbl_prenomClient_stat);
			this->gp_InfosClients_stat->Controls->Add(this->txt_prenomClient_stat);
			this->gp_InfosClients_stat->Controls->Add(this->txt_IdClient_stat);
			this->gp_InfosClients_stat->Controls->Add(this->lbl_IdClient_stat);
			this->gp_InfosClients_stat->Location = System::Drawing::Point(28, 153);
			this->gp_InfosClients_stat->Name = L"gp_InfosClients_stat";
			this->gp_InfosClients_stat->Size = System::Drawing::Size(196, 237);
			this->gp_InfosClients_stat->TabIndex = 0;
			this->gp_InfosClients_stat->TabStop = false;
			this->gp_InfosClients_stat->Visible = false;
			// 
			// gp_InfoDate_stat
			// 
			this->gp_InfoDate_stat->Controls->Add(this->lbl_year_stat);
			this->gp_InfoDate_stat->Controls->Add(this->lbl_month_stat);
			this->gp_InfoDate_stat->Controls->Add(this->lbl_titleSelect_stat);
			this->gp_InfoDate_stat->Controls->Add(this->cb_year_stat);
			this->gp_InfoDate_stat->Controls->Add(this->cb_month_stat);
			this->gp_InfoDate_stat->Location = System::Drawing::Point(241, 268);
			this->gp_InfoDate_stat->Name = L"gp_InfoDate_stat";
			this->gp_InfoDate_stat->Size = System::Drawing::Size(292, 122);
			this->gp_InfoDate_stat->TabIndex = 0;
			this->gp_InfoDate_stat->TabStop = false;
			this->gp_InfoDate_stat->Visible = false;
			// 
			// lbl_year_stat
			// 
			this->lbl_year_stat->AutoSize = true;
			this->lbl_year_stat->Location = System::Drawing::Point(160, 51);
			this->lbl_year_stat->Name = L"lbl_year_stat";
			this->lbl_year_stat->Size = System::Drawing::Size(49, 17);
			this->lbl_year_stat->TabIndex = 0;
			this->lbl_year_stat->Text = L"Année";
			// 
			// lbl_month_stat
			// 
			this->lbl_month_stat->AutoSize = true;
			this->lbl_month_stat->Location = System::Drawing::Point(6, 51);
			this->lbl_month_stat->Name = L"lbl_month_stat";
			this->lbl_month_stat->Size = System::Drawing::Size(37, 17);
			this->lbl_month_stat->TabIndex = 0;
			this->lbl_month_stat->Text = L"Mois";
			// 
			// lbl_titleSelect_stat
			// 
			this->lbl_titleSelect_stat->AutoSize = true;
			this->lbl_titleSelect_stat->Location = System::Drawing::Point(6, 18);
			this->lbl_titleSelect_stat->Name = L"lbl_titleSelect_stat";
			this->lbl_titleSelect_stat->Size = System::Drawing::Size(201, 17);
			this->lbl_titleSelect_stat->TabIndex = 0;
			this->lbl_titleSelect_stat->Text = L"Selectionner le mois et l\'année";
			// 
			// cb_year_stat
			// 
			this->cb_year_stat->FormattingEnabled = true;
			this->cb_year_stat->Items->AddRange(gcnew cli::array< System::Object^  >(31) {
				L"2000", L"2001", L"2002", L"2003", L"2004",
					L"2005", L"2006", L"2007", L"2008", L"2009", L"2010", L"2011", L"2012", L"2013", L"2014", L"2015", L"2016", L"2017", L"2018",
					L"2019", L"2020", L"2021", L"2022", L"2023", L"2024", L"2025", L"2026", L"2027", L"2028", L"2029", L"2030"
			});
			this->cb_year_stat->Location = System::Drawing::Point(163, 71);
			this->cb_year_stat->Name = L"cb_year_stat";
			this->cb_year_stat->Size = System::Drawing::Size(121, 24);
			this->cb_year_stat->TabIndex = 0;
			this->cb_year_stat->Text = L"Year";
			// 
			// cb_month_stat
			// 
			this->cb_month_stat->FormattingEnabled = true;
			this->cb_month_stat->Items->AddRange(gcnew cli::array< System::Object^  >(13) {
				L"Mois", L"Janvier", L"Fevrier", L"Mars", L"Avril",
					L"Mai", L"Juin", L"Juillet", L"Août", L"Septembre", L"Octobre", L"Novembre", L"Decembre"
			});
			this->cb_month_stat->Location = System::Drawing::Point(9, 71);
			this->cb_month_stat->Name = L"cb_month_stat";
			this->cb_month_stat->Size = System::Drawing::Size(121, 24);
			this->cb_month_stat->TabIndex = 0;
			this->cb_month_stat->Text = L"Mois";
			// 
			// cb_req_stat
			// 
			this->cb_req_stat->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->cb_req_stat->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->cb_req_stat->FormattingEnabled = true;
			this->cb_req_stat->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"Calculer le panier moyen (après remise)", L"Calculer le chiffre d’affaire sur un mois en particulier",
					L"Identifier les produits sous le seuil de réapprovisionnement", L"Calculer le montant total des achats pour un client", L"Identifier les 10 articles les plus vendus",
					L"Identifier les 10 articles les moins vendus", L"Calculer la valeur commerciale du stock", L"Calculer la valeur d’achat du stock",
					L"Simuler des variations de valeurs commerciales pour en déduire la valeur du stock"
					L""
			});
			this->cb_req_stat->Location = System::Drawing::Point(28, 35);
			this->cb_req_stat->Name = L"cb_req_stat";
			this->cb_req_stat->Size = System::Drawing::Size(1039, 24);
			this->cb_req_stat->TabIndex = 0;
			this->cb_req_stat->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::cb_req_SelectedIndexChanged);
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->gb_statistiques);
			this->tabPage4->Location = System::Drawing::Point(4, 25);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(1133, 516);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Statistiques";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// gb_statistiques
			// 
			this->gb_statistiques->Controls->Add(this->txt_stats_result);
			this->gb_statistiques->Controls->Add(this->btn_ok_stat);
			this->gb_statistiques->Controls->Add(this->cb_req_stat);
			this->gb_statistiques->Controls->Add(this->gp_InfosClients_stat);
			this->gb_statistiques->Controls->Add(this->dgv_req_stat);
			this->gb_statistiques->Controls->Add(this->gp_InfoDate_stat);
			this->gb_statistiques->Controls->Add(this->lbl_stats_result);
			this->gb_statistiques->Controls->Add(this->btn_stats_calculer);
			this->gb_statistiques->Controls->Add(this->lbl_stats_variationValeurStock);
			this->gb_statistiques->Controls->Add(this->lbl_stats_margeCommerciale);
			this->gb_statistiques->Controls->Add(this->lbl_stats_remiseCommerciale);
			this->gb_statistiques->Controls->Add(this->lbl_stats_demarqueInconnue);
			this->gb_statistiques->Controls->Add(this->lbl_stats_TVA);
			this->gb_statistiques->Controls->Add(this->txt_stats_demarqueInconnue);
			this->gb_statistiques->Controls->Add(this->txt_stats_remiseCommerciale);
			this->gb_statistiques->Controls->Add(this->txt_stats_margeCommerciale);
			this->gb_statistiques->Controls->Add(this->txt_stats_TVA);
			this->gb_statistiques->Location = System::Drawing::Point(0, 0);
			this->gb_statistiques->Name = L"gb_statistiques";
			this->gb_statistiques->Size = System::Drawing::Size(1276, 510);
			this->gb_statistiques->TabIndex = 30;
			this->gb_statistiques->TabStop = false;
			this->gb_statistiques->Text = L"Statistiques";
			// 
			// txt_stats_result
			// 
			this->txt_stats_result->Location = System::Drawing::Point(822, 469);
			this->txt_stats_result->Name = L"txt_stats_result";
			this->txt_stats_result->Size = System::Drawing::Size(245, 22);
			this->txt_stats_result->TabIndex = 11;
			// 
			// lbl_stats_result
			// 
			this->lbl_stats_result->AutoSize = true;
			this->lbl_stats_result->Location = System::Drawing::Point(819, 439);
			this->lbl_stats_result->Name = L"lbl_stats_result";
			this->lbl_stats_result->Size = System::Drawing::Size(125, 17);
			this->lbl_stats_result->TabIndex = 10;
			this->lbl_stats_result->Text = L"Résultat variations";
			// 
			// btn_stats_calculer
			// 
			this->btn_stats_calculer->Location = System::Drawing::Point(720, 460);
			this->btn_stats_calculer->Name = L"btn_stats_calculer";
			this->btn_stats_calculer->Size = System::Drawing::Size(78, 34);
			this->btn_stats_calculer->TabIndex = 9;
			this->btn_stats_calculer->Text = L"Calculer";
			this->btn_stats_calculer->UseVisualStyleBackColor = true;
			this->btn_stats_calculer->Click += gcnew System::EventHandler(this, &MyForm::btn_stats_calculer_Click);
			// 
			// lbl_stats_variationValeurStock
			// 
			this->lbl_stats_variationValeurStock->AutoSize = true;
			this->lbl_stats_variationValeurStock->Location = System::Drawing::Point(40, 411);
			this->lbl_stats_variationValeurStock->Name = L"lbl_stats_variationValeurStock";
			this->lbl_stats_variationValeurStock->Size = System::Drawing::Size(205, 17);
			this->lbl_stats_variationValeurStock->TabIndex = 8;
			this->lbl_stats_variationValeurStock->Text = L"Variations des valeurs du stock";
			// 
			// lbl_stats_margeCommerciale
			// 
			this->lbl_stats_margeCommerciale->AutoSize = true;
			this->lbl_stats_margeCommerciale->Location = System::Drawing::Point(165, 439);
			this->lbl_stats_margeCommerciale->Name = L"lbl_stats_margeCommerciale";
			this->lbl_stats_margeCommerciale->Size = System::Drawing::Size(157, 17);
			this->lbl_stats_margeCommerciale->TabIndex = 7;
			this->lbl_stats_margeCommerciale->Text = L"Marge commerciale (%)";
			// 
			// lbl_stats_remiseCommerciale
			// 
			this->lbl_stats_remiseCommerciale->AutoSize = true;
			this->lbl_stats_remiseCommerciale->Location = System::Drawing::Point(341, 439);
			this->lbl_stats_remiseCommerciale->Name = L"lbl_stats_remiseCommerciale";
			this->lbl_stats_remiseCommerciale->Size = System::Drawing::Size(164, 17);
			this->lbl_stats_remiseCommerciale->TabIndex = 6;
			this->lbl_stats_remiseCommerciale->Text = L"Remise commerciale (%)";
			// 
			// lbl_stats_demarqueInconnue
			// 
			this->lbl_stats_demarqueInconnue->AutoSize = true;
			this->lbl_stats_demarqueInconnue->Location = System::Drawing::Point(527, 439);
			this->lbl_stats_demarqueInconnue->Name = L"lbl_stats_demarqueInconnue";
			this->lbl_stats_demarqueInconnue->Size = System::Drawing::Size(162, 17);
			this->lbl_stats_demarqueInconnue->TabIndex = 5;
			this->lbl_stats_demarqueInconnue->Text = L"Démarque inconnue (%)";
			// 
			// lbl_stats_TVA
			// 
			this->lbl_stats_TVA->AutoSize = true;
			this->lbl_stats_TVA->Location = System::Drawing::Point(37, 439);
			this->lbl_stats_TVA->Name = L"lbl_stats_TVA";
			this->lbl_stats_TVA->Size = System::Drawing::Size(61, 17);
			this->lbl_stats_TVA->TabIndex = 4;
			this->lbl_stats_TVA->Text = L"TVA (%)";
			// 
			// txt_stats_demarqueInconnue
			// 
			this->txt_stats_demarqueInconnue->Location = System::Drawing::Point(530, 469);
			this->txt_stats_demarqueInconnue->Name = L"txt_stats_demarqueInconnue";
			this->txt_stats_demarqueInconnue->Size = System::Drawing::Size(159, 22);
			this->txt_stats_demarqueInconnue->TabIndex = 3;
			this->txt_stats_demarqueInconnue->Text = L"0";
			// 
			// txt_stats_remiseCommerciale
			// 
			this->txt_stats_remiseCommerciale->Location = System::Drawing::Point(344, 469);
			this->txt_stats_remiseCommerciale->Name = L"txt_stats_remiseCommerciale";
			this->txt_stats_remiseCommerciale->Size = System::Drawing::Size(161, 22);
			this->txt_stats_remiseCommerciale->TabIndex = 2;
			this->txt_stats_remiseCommerciale->Text = L"0";
			// 
			// txt_stats_margeCommerciale
			// 
			this->txt_stats_margeCommerciale->Location = System::Drawing::Point(168, 469);
			this->txt_stats_margeCommerciale->Name = L"txt_stats_margeCommerciale";
			this->txt_stats_margeCommerciale->Size = System::Drawing::Size(154, 22);
			this->txt_stats_margeCommerciale->TabIndex = 1;
			this->txt_stats_margeCommerciale->Text = L"0";
			// 
			// txt_stats_TVA
			// 
			this->txt_stats_TVA->Location = System::Drawing::Point(40, 469);
			this->txt_stats_TVA->Name = L"txt_stats_TVA";
			this->txt_stats_TVA->Size = System::Drawing::Size(111, 22);
			this->txt_stats_TVA->TabIndex = 0;
			this->txt_stats_TVA->Text = L"0";
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->groupBoxStock);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(1133, 516);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Stocks";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// groupBoxStock
			// 
			this->groupBoxStock->Controls->Add(this->buttonClearTVA);
			this->groupBoxStock->Controls->Add(this->buttonClearNature);
			this->groupBoxStock->Controls->Add(this->buttonClearArticle);
			this->groupBoxStock->Controls->Add(this->buttonDernierNature);
			this->groupBoxStock->Controls->Add(this->buttonPremierNature);
			this->groupBoxStock->Controls->Add(this->textBoxTauxTVA);
			this->groupBoxStock->Controls->Add(this->buttonSuivantNature);
			this->groupBoxStock->Controls->Add(this->textBoxIdTVA);
			this->groupBoxStock->Controls->Add(this->buttonPrecedentNature);
			this->groupBoxStock->Controls->Add(this->buttonDernierTVA);
			this->groupBoxStock->Controls->Add(this->labelIdTVA);
			this->groupBoxStock->Controls->Add(this->buttonDernierArticle);
			this->groupBoxStock->Controls->Add(this->buttonPremierTVA);
			this->groupBoxStock->Controls->Add(this->buttonPremierArticle);
			this->groupBoxStock->Controls->Add(this->labelTauxTVA);
			this->groupBoxStock->Controls->Add(this->buttonSuivantArticle);
			this->groupBoxStock->Controls->Add(this->buttonSuivantTVA);
			this->groupBoxStock->Controls->Add(this->buttonPrecedentArticle);
			this->groupBoxStock->Controls->Add(this->buttonPrecedentTVA);
			this->groupBoxStock->Controls->Add(this->buttonAjouterArticle);
			this->groupBoxStock->Controls->Add(this->buttonUpdateArticle);
			this->groupBoxStock->Controls->Add(this->buttonDeleteArticle);
			this->groupBoxStock->Controls->Add(this->labelNature);
			this->groupBoxStock->Controls->Add(this->textBoxNature);
			this->groupBoxStock->Controls->Add(this->labelQuantiteStockArticle);
			this->groupBoxStock->Controls->Add(this->textBoxQuantiteStockArticle);
			this->groupBoxStock->Controls->Add(this->labelSeuilReapro);
			this->groupBoxStock->Controls->Add(this->textBoxSeuilReapro);
			this->groupBoxStock->Controls->Add(this->labelDesignationArticle);
			this->groupBoxStock->Controls->Add(this->textBoxDesignationArticle);
			this->groupBoxStock->Controls->Add(this->labelNomArticle);
			this->groupBoxStock->Controls->Add(this->textBoxNomArticle);
			this->groupBoxStock->Controls->Add(this->labelIdNature);
			this->groupBoxStock->Controls->Add(this->textBoxIdNature);
			this->groupBoxStock->Controls->Add(this->labelIdArticle);
			this->groupBoxStock->Controls->Add(this->textBoxIdArticle);
			this->groupBoxStock->Location = System::Drawing::Point(6, 6);
			this->groupBoxStock->Name = L"groupBoxStock";
			this->groupBoxStock->Size = System::Drawing::Size(653, 429);
			this->groupBoxStock->TabIndex = 71;
			this->groupBoxStock->TabStop = false;
			this->groupBoxStock->Text = L"Gestion Stock";
			// 
			// buttonClearTVA
			// 
			this->buttonClearTVA->Location = System::Drawing::Point(387, 139);
			this->buttonClearTVA->Name = L"buttonClearTVA";
			this->buttonClearTVA->Size = System::Drawing::Size(75, 23);
			this->buttonClearTVA->TabIndex = 73;
			this->buttonClearTVA->Text = L"Clear";
			this->buttonClearTVA->UseVisualStyleBackColor = true;
			this->buttonClearTVA->Click += gcnew System::EventHandler(this, &MyForm::buttonClearTVA_Click);
			// 
			// buttonClearNature
			// 
			this->buttonClearNature->Location = System::Drawing::Point(250, 139);
			this->buttonClearNature->Name = L"buttonClearNature";
			this->buttonClearNature->Size = System::Drawing::Size(75, 23);
			this->buttonClearNature->TabIndex = 72;
			this->buttonClearNature->Text = L"Clear";
			this->buttonClearNature->UseVisualStyleBackColor = true;
			this->buttonClearNature->Click += gcnew System::EventHandler(this, &MyForm::buttonClearNature_Click);
			// 
			// buttonClearArticle
			// 
			this->buttonClearArticle->Location = System::Drawing::Point(51, 247);
			this->buttonClearArticle->Name = L"buttonClearArticle";
			this->buttonClearArticle->Size = System::Drawing::Size(75, 23);
			this->buttonClearArticle->TabIndex = 71;
			this->buttonClearArticle->Text = L"Clear";
			this->buttonClearArticle->UseVisualStyleBackColor = true;
			this->buttonClearArticle->Click += gcnew System::EventHandler(this, &MyForm::buttonClearArticle_Click);
			// 
			// buttonDernierNature
			// 
			this->buttonDernierNature->Location = System::Drawing::Point(329, 168);
			this->buttonDernierNature->Name = L"buttonDernierNature";
			this->buttonDernierNature->Size = System::Drawing::Size(28, 28);
			this->buttonDernierNature->TabIndex = 70;
			this->buttonDernierNature->Text = L">>";
			this->buttonDernierNature->UseVisualStyleBackColor = true;
			this->buttonDernierNature->Click += gcnew System::EventHandler(this, &MyForm::buttonDernierNature_Click);
			// 
			// buttonPremierNature
			// 
			this->buttonPremierNature->Location = System::Drawing::Point(227, 168);
			this->buttonPremierNature->Name = L"buttonPremierNature";
			this->buttonPremierNature->Size = System::Drawing::Size(28, 28);
			this->buttonPremierNature->TabIndex = 67;
			this->buttonPremierNature->Text = L"<<";
			this->buttonPremierNature->UseVisualStyleBackColor = true;
			this->buttonPremierNature->Click += gcnew System::EventHandler(this, &MyForm::buttonPremierNature_Click);
			// 
			// textBoxTauxTVA
			// 
			this->textBoxTauxTVA->Location = System::Drawing::Point(357, 109);
			this->textBoxTauxTVA->Name = L"textBoxTauxTVA";
			this->textBoxTauxTVA->Size = System::Drawing::Size(130, 22);
			this->textBoxTauxTVA->TabIndex = 54;
			// 
			// buttonSuivantNature
			// 
			this->buttonSuivantNature->Location = System::Drawing::Point(295, 168);
			this->buttonSuivantNature->Name = L"buttonSuivantNature";
			this->buttonSuivantNature->Size = System::Drawing::Size(28, 28);
			this->buttonSuivantNature->TabIndex = 69;
			this->buttonSuivantNature->Text = L">";
			this->buttonSuivantNature->UseVisualStyleBackColor = true;
			this->buttonSuivantNature->Click += gcnew System::EventHandler(this, &MyForm::buttonSuivantNature_Click);
			// 
			// textBoxIdTVA
			// 
			this->textBoxIdTVA->Location = System::Drawing::Point(357, 40);
			this->textBoxIdTVA->Name = L"textBoxIdTVA";
			this->textBoxIdTVA->Size = System::Drawing::Size(130, 22);
			this->textBoxIdTVA->TabIndex = 42;
			// 
			// buttonPrecedentNature
			// 
			this->buttonPrecedentNature->Location = System::Drawing::Point(261, 168);
			this->buttonPrecedentNature->Name = L"buttonPrecedentNature";
			this->buttonPrecedentNature->Size = System::Drawing::Size(28, 28);
			this->buttonPrecedentNature->TabIndex = 68;
			this->buttonPrecedentNature->Text = L"<";
			this->buttonPrecedentNature->UseVisualStyleBackColor = true;
			this->buttonPrecedentNature->Click += gcnew System::EventHandler(this, &MyForm::buttonPrecedentNature_Click);
			// 
			// buttonDernierTVA
			// 
			this->buttonDernierTVA->Location = System::Drawing::Point(465, 168);
			this->buttonDernierTVA->Name = L"buttonDernierTVA";
			this->buttonDernierTVA->Size = System::Drawing::Size(28, 28);
			this->buttonDernierTVA->TabIndex = 66;
			this->buttonDernierTVA->Text = L">>";
			this->buttonDernierTVA->UseVisualStyleBackColor = true;
			this->buttonDernierTVA->Click += gcnew System::EventHandler(this, &MyForm::buttonDernierTVA_Click);
			// 
			// labelIdTVA
			// 
			this->labelIdTVA->AutoSize = true;
			this->labelIdTVA->Location = System::Drawing::Point(354, 24);
			this->labelIdTVA->Name = L"labelIdTVA";
			this->labelIdTVA->Size = System::Drawing::Size(50, 17);
			this->labelIdTVA->TabIndex = 43;
			this->labelIdTVA->Text = L"Id TVA";
			// 
			// buttonDernierArticle
			// 
			this->buttonDernierArticle->Location = System::Drawing::Point(125, 274);
			this->buttonDernierArticle->Name = L"buttonDernierArticle";
			this->buttonDernierArticle->Size = System::Drawing::Size(28, 28);
			this->buttonDernierArticle->TabIndex = 62;
			this->buttonDernierArticle->Text = L">>";
			this->buttonDernierArticle->UseVisualStyleBackColor = true;
			this->buttonDernierArticle->Click += gcnew System::EventHandler(this, &MyForm::buttonDernierArticle_Click);
			// 
			// buttonPremierTVA
			// 
			this->buttonPremierTVA->Location = System::Drawing::Point(363, 168);
			this->buttonPremierTVA->Name = L"buttonPremierTVA";
			this->buttonPremierTVA->Size = System::Drawing::Size(28, 28);
			this->buttonPremierTVA->TabIndex = 63;
			this->buttonPremierTVA->Text = L"<<";
			this->buttonPremierTVA->UseVisualStyleBackColor = true;
			this->buttonPremierTVA->Click += gcnew System::EventHandler(this, &MyForm::buttonPremierTVA_Click);
			// 
			// buttonPremierArticle
			// 
			this->buttonPremierArticle->Location = System::Drawing::Point(23, 274);
			this->buttonPremierArticle->Name = L"buttonPremierArticle";
			this->buttonPremierArticle->Size = System::Drawing::Size(28, 28);
			this->buttonPremierArticle->TabIndex = 59;
			this->buttonPremierArticle->Text = L"<<";
			this->buttonPremierArticle->UseVisualStyleBackColor = true;
			this->buttonPremierArticle->Click += gcnew System::EventHandler(this, &MyForm::buttonPremierArticle_Click);
			// 
			// labelTauxTVA
			// 
			this->labelTauxTVA->AutoSize = true;
			this->labelTauxTVA->Location = System::Drawing::Point(354, 85);
			this->labelTauxTVA->Name = L"labelTauxTVA";
			this->labelTauxTVA->Size = System::Drawing::Size(70, 17);
			this->labelTauxTVA->TabIndex = 55;
			this->labelTauxTVA->Text = L"Taux TVA";
			// 
			// buttonSuivantArticle
			// 
			this->buttonSuivantArticle->Location = System::Drawing::Point(91, 274);
			this->buttonSuivantArticle->Name = L"buttonSuivantArticle";
			this->buttonSuivantArticle->Size = System::Drawing::Size(28, 28);
			this->buttonSuivantArticle->TabIndex = 61;
			this->buttonSuivantArticle->Text = L">";
			this->buttonSuivantArticle->UseVisualStyleBackColor = true;
			this->buttonSuivantArticle->Click += gcnew System::EventHandler(this, &MyForm::buttonSuivantArticle_Click);
			// 
			// buttonSuivantTVA
			// 
			this->buttonSuivantTVA->Location = System::Drawing::Point(431, 168);
			this->buttonSuivantTVA->Name = L"buttonSuivantTVA";
			this->buttonSuivantTVA->Size = System::Drawing::Size(28, 28);
			this->buttonSuivantTVA->TabIndex = 65;
			this->buttonSuivantTVA->Text = L">";
			this->buttonSuivantTVA->UseVisualStyleBackColor = true;
			this->buttonSuivantTVA->Click += gcnew System::EventHandler(this, &MyForm::buttonSuivantTVA_Click);
			// 
			// buttonPrecedentArticle
			// 
			this->buttonPrecedentArticle->Location = System::Drawing::Point(57, 274);
			this->buttonPrecedentArticle->Name = L"buttonPrecedentArticle";
			this->buttonPrecedentArticle->Size = System::Drawing::Size(28, 28);
			this->buttonPrecedentArticle->TabIndex = 60;
			this->buttonPrecedentArticle->Text = L"<";
			this->buttonPrecedentArticle->UseVisualStyleBackColor = true;
			this->buttonPrecedentArticle->Click += gcnew System::EventHandler(this, &MyForm::buttonPrecedentArticle_Click);
			// 
			// buttonPrecedentTVA
			// 
			this->buttonPrecedentTVA->Location = System::Drawing::Point(397, 168);
			this->buttonPrecedentTVA->Name = L"buttonPrecedentTVA";
			this->buttonPrecedentTVA->Size = System::Drawing::Size(28, 28);
			this->buttonPrecedentTVA->TabIndex = 64;
			this->buttonPrecedentTVA->Text = L"<";
			this->buttonPrecedentTVA->UseVisualStyleBackColor = true;
			this->buttonPrecedentTVA->Click += gcnew System::EventHandler(this, &MyForm::buttonPrecedentTVA_Click);
			// 
			// buttonAjouterArticle
			// 
			this->buttonAjouterArticle->Location = System::Drawing::Point(183, 364);
			this->buttonAjouterArticle->Name = L"buttonAjouterArticle";
			this->buttonAjouterArticle->Size = System::Drawing::Size(75, 34);
			this->buttonAjouterArticle->TabIndex = 56;
			this->buttonAjouterArticle->Text = L"Ajouter";
			this->buttonAjouterArticle->UseVisualStyleBackColor = true;
			this->buttonAjouterArticle->Click += gcnew System::EventHandler(this, &MyForm::buttonAjouterArticle_Click);
			// 
			// buttonUpdateArticle
			// 
			this->buttonUpdateArticle->Location = System::Drawing::Point(264, 364);
			this->buttonUpdateArticle->Name = L"buttonUpdateArticle";
			this->buttonUpdateArticle->Size = System::Drawing::Size(75, 34);
			this->buttonUpdateArticle->TabIndex = 57;
			this->buttonUpdateArticle->Text = L"Update";
			this->buttonUpdateArticle->UseVisualStyleBackColor = true;
			this->buttonUpdateArticle->Click += gcnew System::EventHandler(this, &MyForm::buttonUpdateArticle_Click);
			// 
			// buttonDeleteArticle
			// 
			this->buttonDeleteArticle->Location = System::Drawing::Point(345, 364);
			this->buttonDeleteArticle->Name = L"buttonDeleteArticle";
			this->buttonDeleteArticle->Size = System::Drawing::Size(96, 34);
			this->buttonDeleteArticle->TabIndex = 58;
			this->buttonDeleteArticle->Text = L"Supprimer";
			this->buttonDeleteArticle->UseVisualStyleBackColor = true;
			this->buttonDeleteArticle->Click += gcnew System::EventHandler(this, &MyForm::buttonDeleteArticle_Click);
			// 
			// labelNature
			// 
			this->labelNature->AutoSize = true;
			this->labelNature->Location = System::Drawing::Point(218, 85);
			this->labelNature->Name = L"labelNature";
			this->labelNature->Size = System::Drawing::Size(51, 17);
			this->labelNature->TabIndex = 53;
			this->labelNature->Text = L"Nature";
			// 
			// textBoxNature
			// 
			this->textBoxNature->Location = System::Drawing::Point(221, 109);
			this->textBoxNature->Name = L"textBoxNature";
			this->textBoxNature->Size = System::Drawing::Size(130, 22);
			this->textBoxNature->TabIndex = 52;
			// 
			// labelQuantiteStockArticle
			// 
			this->labelQuantiteStockArticle->AutoSize = true;
			this->labelQuantiteStockArticle->Location = System::Drawing::Point(20, 200);
			this->labelQuantiteStockArticle->Name = L"labelQuantiteStockArticle";
			this->labelQuantiteStockArticle->Size = System::Drawing::Size(144, 17);
			this->labelQuantiteStockArticle->TabIndex = 51;
			this->labelQuantiteStockArticle->Text = L"Quantite Stock Article";
			// 
			// textBoxQuantiteStockArticle
			// 
			this->textBoxQuantiteStockArticle->Location = System::Drawing::Point(23, 221);
			this->textBoxQuantiteStockArticle->Name = L"textBoxQuantiteStockArticle";
			this->textBoxQuantiteStockArticle->Size = System::Drawing::Size(130, 22);
			this->textBoxQuantiteStockArticle->TabIndex = 50;
			// 
			// labelSeuilReapro
			// 
			this->labelSeuilReapro->AutoSize = true;
			this->labelSeuilReapro->Location = System::Drawing::Point(6, 157);
			this->labelSeuilReapro->Name = L"labelSeuilReapro";
			this->labelSeuilReapro->Size = System::Drawing::Size(173, 17);
			this->labelSeuilReapro->TabIndex = 49;
			this->labelSeuilReapro->Text = L"Seuil Reaprovisionnement";
			// 
			// textBoxSeuilReapro
			// 
			this->textBoxSeuilReapro->Location = System::Drawing::Point(23, 176);
			this->textBoxSeuilReapro->Name = L"textBoxSeuilReapro";
			this->textBoxSeuilReapro->Size = System::Drawing::Size(130, 22);
			this->textBoxSeuilReapro->TabIndex = 48;
			// 
			// labelDesignationArticle
			// 
			this->labelDesignationArticle->AutoSize = true;
			this->labelDesignationArticle->Location = System::Drawing::Point(20, 110);
			this->labelDesignationArticle->Name = L"labelDesignationArticle";
			this->labelDesignationArticle->Size = System::Drawing::Size(126, 17);
			this->labelDesignationArticle->TabIndex = 47;
			this->labelDesignationArticle->Text = L"Designation Article";
			// 
			// textBoxDesignationArticle
			// 
			this->textBoxDesignationArticle->Location = System::Drawing::Point(23, 128);
			this->textBoxDesignationArticle->Name = L"textBoxDesignationArticle";
			this->textBoxDesignationArticle->Size = System::Drawing::Size(130, 22);
			this->textBoxDesignationArticle->TabIndex = 46;
			// 
			// labelNomArticle
			// 
			this->labelNomArticle->AutoSize = true;
			this->labelNomArticle->Location = System::Drawing::Point(20, 67);
			this->labelNomArticle->Name = L"labelNomArticle";
			this->labelNomArticle->Size = System::Drawing::Size(80, 17);
			this->labelNomArticle->TabIndex = 45;
			this->labelNomArticle->Text = L"Nom Article";
			// 
			// textBoxNomArticle
			// 
			this->textBoxNomArticle->Location = System::Drawing::Point(23, 84);
			this->textBoxNomArticle->Name = L"textBoxNomArticle";
			this->textBoxNomArticle->Size = System::Drawing::Size(130, 22);
			this->textBoxNomArticle->TabIndex = 44;
			// 
			// labelIdNature
			// 
			this->labelIdNature->AutoSize = true;
			this->labelIdNature->Location = System::Drawing::Point(218, 21);
			this->labelIdNature->Name = L"labelIdNature";
			this->labelIdNature->Size = System::Drawing::Size(66, 17);
			this->labelIdNature->TabIndex = 41;
			this->labelIdNature->Text = L"Id Nature";
			// 
			// textBoxIdNature
			// 
			this->textBoxIdNature->Location = System::Drawing::Point(221, 40);
			this->textBoxIdNature->Name = L"textBoxIdNature";
			this->textBoxIdNature->Size = System::Drawing::Size(130, 22);
			this->textBoxIdNature->TabIndex = 40;
			// 
			// labelIdArticle
			// 
			this->labelIdArticle->AutoSize = true;
			this->labelIdArticle->Location = System::Drawing::Point(20, 21);
			this->labelIdArticle->Name = L"labelIdArticle";
			this->labelIdArticle->Size = System::Drawing::Size(62, 17);
			this->labelIdArticle->TabIndex = 39;
			this->labelIdArticle->Text = L"Id Article";
			// 
			// textBoxIdArticle
			// 
			this->textBoxIdArticle->Location = System::Drawing::Point(23, 40);
			this->textBoxIdArticle->Name = L"textBoxIdArticle";
			this->textBoxIdArticle->Size = System::Drawing::Size(130, 22);
			this->textBoxIdArticle->TabIndex = 38;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->gb_client);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1133, 516);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Clients";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// gb_client
			// 
			this->gb_client->Controls->Add(this->btn_previous_client);
			this->gb_client->Controls->Add(this->btn_first_client);
			this->gb_client->Controls->Add(this->btn_next_client);
			this->gb_client->Controls->Add(this->btn_end_client);
			this->gb_client->Controls->Add(this->datePremAchatPicker);
			this->gb_client->Controls->Add(this->dateNaissancePicker);
			this->gb_client->Controls->Add(this->txt_datepremierachat);
			this->gb_client->Controls->Add(this->txt_datenaissance);
			this->gb_client->Controls->Add(this->lbl_premier_achat);
			this->gb_client->Controls->Add(this->lbl_datenaissance);
			this->gb_client->Controls->Add(this->btn_supprimer_client);
			this->gb_client->Controls->Add(this->btn_modifier_client);
			this->gb_client->Controls->Add(this->btn_enregistrer_client);
			this->gb_client->Controls->Add(this->btn_nouveau_client);
			this->gb_client->Controls->Add(this->txt_PrenomClient);
			this->gb_client->Controls->Add(this->txt_NomClient);
			this->gb_client->Controls->Add(this->lbl_PrenomClient);
			this->gb_client->Controls->Add(this->lbl_idNomClient);
			this->gb_client->Controls->Add(this->txt_idClient);
			this->gb_client->Controls->Add(this->lbl_idClient);
			this->gb_client->Controls->Add(this->rb_livraison);
			this->gb_client->Controls->Add(this->rb_facturation);
			this->gb_client->Controls->Add(this->dataGridView1);
			this->gb_client->Location = System::Drawing::Point(7, 26);
			this->gb_client->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->gb_client->Name = L"gb_client";
			this->gb_client->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->gb_client->Size = System::Drawing::Size(1053, 364);
			this->gb_client->TabIndex = 26;
			this->gb_client->TabStop = false;
			this->gb_client->Text = L"Client";
			// 
			// btn_previous_client
			// 
			this->btn_previous_client->Location = System::Drawing::Point(91, 310);
			this->btn_previous_client->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn_previous_client->Name = L"btn_previous_client";
			this->btn_previous_client->Size = System::Drawing::Size(53, 30);
			this->btn_previous_client->TabIndex = 41;
			this->btn_previous_client->Text = L"<";
			this->btn_previous_client->UseVisualStyleBackColor = true;
			this->btn_previous_client->Click += gcnew System::EventHandler(this, &MyForm::btn_previous_client_Click);
			// 
			// btn_first_client
			// 
			this->btn_first_client->Location = System::Drawing::Point(29, 310);
			this->btn_first_client->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn_first_client->Name = L"btn_first_client";
			this->btn_first_client->Size = System::Drawing::Size(53, 30);
			this->btn_first_client->TabIndex = 40;
			this->btn_first_client->Text = L"<<";
			this->btn_first_client->UseVisualStyleBackColor = true;
			this->btn_first_client->Click += gcnew System::EventHandler(this, &MyForm::btn_first_client_Click);
			// 
			// btn_next_client
			// 
			this->btn_next_client->Location = System::Drawing::Point(149, 310);
			this->btn_next_client->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn_next_client->Name = L"btn_next_client";
			this->btn_next_client->Size = System::Drawing::Size(53, 30);
			this->btn_next_client->TabIndex = 42;
			this->btn_next_client->Text = L">";
			this->btn_next_client->UseVisualStyleBackColor = true;
			this->btn_next_client->Click += gcnew System::EventHandler(this, &MyForm::btn_next_client_Click);
			// 
			// btn_end_client
			// 
			this->btn_end_client->Location = System::Drawing::Point(211, 310);
			this->btn_end_client->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn_end_client->Name = L"btn_end_client";
			this->btn_end_client->Size = System::Drawing::Size(53, 30);
			this->btn_end_client->TabIndex = 43;
			this->btn_end_client->Text = L">>";
			this->btn_end_client->UseVisualStyleBackColor = true;
			this->btn_end_client->Click += gcnew System::EventHandler(this, &MyForm::btn_end_client_Click);
			// 
			// datePremAchatPicker
			// 
			this->datePremAchatPicker->CustomFormat = L"yyyyMMdd";
			this->datePremAchatPicker->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->datePremAchatPicker->Location = System::Drawing::Point(219, 261);
			this->datePremAchatPicker->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->datePremAchatPicker->Name = L"datePremAchatPicker";
			this->datePremAchatPicker->Size = System::Drawing::Size(119, 22);
			this->datePremAchatPicker->TabIndex = 39;
			this->datePremAchatPicker->Value = System::DateTime(2020, 11, 30, 16, 19, 4, 0);
			// 
			// dateNaissancePicker
			// 
			this->dateNaissancePicker->CustomFormat = L"yyyyMMdd";
			this->dateNaissancePicker->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateNaissancePicker->Location = System::Drawing::Point(222, 206);
			this->dateNaissancePicker->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dateNaissancePicker->Name = L"dateNaissancePicker";
			this->dateNaissancePicker->Size = System::Drawing::Size(119, 22);
			this->dateNaissancePicker->TabIndex = 27;
			this->dateNaissancePicker->Value = System::DateTime(2020, 11, 30, 16, 19, 4, 0);
			// 
			// txt_datepremierachat
			// 
			this->txt_datepremierachat->Location = System::Drawing::Point(25, 261);
			this->txt_datepremierachat->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txt_datepremierachat->Name = L"txt_datepremierachat";
			this->txt_datepremierachat->Size = System::Drawing::Size(193, 22);
			this->txt_datepremierachat->TabIndex = 38;
			// 
			// txt_datenaissance
			// 
			this->txt_datenaissance->Location = System::Drawing::Point(25, 208);
			this->txt_datenaissance->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txt_datenaissance->Name = L"txt_datenaissance";
			this->txt_datenaissance->Size = System::Drawing::Size(193, 22);
			this->txt_datenaissance->TabIndex = 37;
			// 
			// lbl_premier_achat
			// 
			this->lbl_premier_achat->AutoSize = true;
			this->lbl_premier_achat->Location = System::Drawing::Point(22, 232);
			this->lbl_premier_achat->Name = L"lbl_premier_achat";
			this->lbl_premier_achat->Size = System::Drawing::Size(129, 17);
			this->lbl_premier_achat->TabIndex = 36;
			this->lbl_premier_achat->Text = L"Date premier achat";
			// 
			// lbl_datenaissance
			// 
			this->lbl_datenaissance->AutoSize = true;
			this->lbl_datenaissance->Location = System::Drawing::Point(22, 182);
			this->lbl_datenaissance->Name = L"lbl_datenaissance";
			this->lbl_datenaissance->Size = System::Drawing::Size(126, 17);
			this->lbl_datenaissance->TabIndex = 35;
			this->lbl_datenaissance->Text = L"Date de naissance";
			// 
			// btn_supprimer_client
			// 
			this->btn_supprimer_client->Location = System::Drawing::Point(297, 144);
			this->btn_supprimer_client->Name = L"btn_supprimer_client";
			this->btn_supprimer_client->Size = System::Drawing::Size(75, 23);
			this->btn_supprimer_client->TabIndex = 34;
			this->btn_supprimer_client->Text = L"Supprimer";
			this->btn_supprimer_client->UseVisualStyleBackColor = true;
			this->btn_supprimer_client->Click += gcnew System::EventHandler(this, &MyForm::btn_supprimer_client_Click);
			// 
			// btn_modifier_client
			// 
			this->btn_modifier_client->Location = System::Drawing::Point(297, 105);
			this->btn_modifier_client->Name = L"btn_modifier_client";
			this->btn_modifier_client->Size = System::Drawing::Size(75, 23);
			this->btn_modifier_client->TabIndex = 33;
			this->btn_modifier_client->Text = L"Modifier";
			this->btn_modifier_client->UseVisualStyleBackColor = true;
			this->btn_modifier_client->Click += gcnew System::EventHandler(this, &MyForm::btn_modifier_client_Click);
			// 
			// btn_enregistrer_client
			// 
			this->btn_enregistrer_client->Location = System::Drawing::Point(380, 57);
			this->btn_enregistrer_client->Name = L"btn_enregistrer_client";
			this->btn_enregistrer_client->Size = System::Drawing::Size(75, 118);
			this->btn_enregistrer_client->TabIndex = 32;
			this->btn_enregistrer_client->Text = L"ENREGISTRER";
			this->btn_enregistrer_client->UseVisualStyleBackColor = true;
			this->btn_enregistrer_client->Click += gcnew System::EventHandler(this, &MyForm::btn_enregistrer_Click);
			// 
			// btn_nouveau_client
			// 
			this->btn_nouveau_client->Location = System::Drawing::Point(297, 57);
			this->btn_nouveau_client->Name = L"btn_nouveau_client";
			this->btn_nouveau_client->Size = System::Drawing::Size(75, 23);
			this->btn_nouveau_client->TabIndex = 31;
			this->btn_nouveau_client->Text = L"Nouveau";
			this->btn_nouveau_client->UseVisualStyleBackColor = true;
			this->btn_nouveau_client->Click += gcnew System::EventHandler(this, &MyForm::btn_nouveau_client_Click);
			// 
			// txt_PrenomClient
			// 
			this->txt_PrenomClient->Location = System::Drawing::Point(24, 144);
			this->txt_PrenomClient->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txt_PrenomClient->Name = L"txt_PrenomClient";
			this->txt_PrenomClient->Size = System::Drawing::Size(193, 22);
			this->txt_PrenomClient->TabIndex = 30;
			// 
			// txt_NomClient
			// 
			this->txt_NomClient->Location = System::Drawing::Point(24, 98);
			this->txt_NomClient->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txt_NomClient->Name = L"txt_NomClient";
			this->txt_NomClient->Size = System::Drawing::Size(193, 22);
			this->txt_NomClient->TabIndex = 29;
			// 
			// lbl_PrenomClient
			// 
			this->lbl_PrenomClient->AutoSize = true;
			this->lbl_PrenomClient->Location = System::Drawing::Point(21, 124);
			this->lbl_PrenomClient->Name = L"lbl_PrenomClient";
			this->lbl_PrenomClient->Size = System::Drawing::Size(96, 17);
			this->lbl_PrenomClient->TabIndex = 28;
			this->lbl_PrenomClient->Text = L"Prenom Client";
			// 
			// lbl_idNomClient
			// 
			this->lbl_idNomClient->AutoSize = true;
			this->lbl_idNomClient->Location = System::Drawing::Point(21, 78);
			this->lbl_idNomClient->Name = L"lbl_idNomClient";
			this->lbl_idNomClient->Size = System::Drawing::Size(76, 17);
			this->lbl_idNomClient->TabIndex = 27;
			this->lbl_idNomClient->Text = L"Nom Client";
			// 
			// txt_idClient
			// 
			this->txt_idClient->Location = System::Drawing::Point(24, 46);
			this->txt_idClient->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txt_idClient->Name = L"txt_idClient";
			this->txt_idClient->Size = System::Drawing::Size(193, 22);
			this->txt_idClient->TabIndex = 27;
			// 
			// lbl_idClient
			// 
			this->lbl_idClient->AutoSize = true;
			this->lbl_idClient->Location = System::Drawing::Point(21, 25);
			this->lbl_idClient->Name = L"lbl_idClient";
			this->lbl_idClient->Size = System::Drawing::Size(60, 17);
			this->lbl_idClient->TabIndex = 27;
			this->lbl_idClient->Text = L"ID Client";
			// 
			// rb_livraison
			// 
			this->rb_livraison->AutoSize = true;
			this->rb_livraison->Location = System::Drawing::Point(890, 46);
			this->rb_livraison->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->rb_livraison->Name = L"rb_livraison";
			this->rb_livraison->Size = System::Drawing::Size(86, 21);
			this->rb_livraison->TabIndex = 2;
			this->rb_livraison->Text = L"Livraison";
			this->rb_livraison->UseVisualStyleBackColor = true;
			this->rb_livraison->Click += gcnew System::EventHandler(this, &MyForm::rb_livraison_Click);
			// 
			// rb_facturation
			// 
			this->rb_facturation->AutoSize = true;
			this->rb_facturation->Checked = true;
			this->rb_facturation->Location = System::Drawing::Point(720, 47);
			this->rb_facturation->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->rb_facturation->Name = L"rb_facturation";
			this->rb_facturation->Size = System::Drawing::Size(100, 21);
			this->rb_facturation->TabIndex = 1;
			this->rb_facturation->TabStop = true;
			this->rb_facturation->Text = L"Facturation";
			this->rb_facturation->UseVisualStyleBackColor = true;
			this->rb_facturation->Click += gcnew System::EventHandler(this, &MyForm::rb_facturation_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(344, 180);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(703, 174);
			this->dataGridView1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->gb_personnel);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1133, 516);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Personnel";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// gb_personnel
			// 
			this->gb_personnel->Controls->Add(this->txt_dateEmbauche);
			this->gb_personnel->Controls->Add(this->ListeEmployes);
			this->gb_personnel->Controls->Add(this->btn_nouveau_personnel);
			this->gb_personnel->Controls->Add(this->lbl_dateembauche);
			this->gb_personnel->Controls->Add(this->btn_modifier_personnel);
			this->gb_personnel->Controls->Add(this->dateEmbauchePicker);
			this->gb_personnel->Controls->Add(this->btn_supprimer_personnel);
			this->gb_personnel->Controls->Add(this->btn_enregistrer_personnel);
			this->gb_personnel->Controls->Add(this->btn_previous_personnel);
			this->gb_personnel->Controls->Add(this->btn_first_personnel);
			this->gb_personnel->Controls->Add(this->btn_next_personnel);
			this->gb_personnel->Controls->Add(this->btn_end_personnel);
			this->gb_personnel->Controls->Add(this->txt_prenom);
			this->gb_personnel->Controls->Add(this->txt_nom);
			this->gb_personnel->Controls->Add(this->label1);
			this->gb_personnel->Controls->Add(this->txt_idPersonne);
			this->gb_personnel->Controls->Add(this->label2);
			this->gb_personnel->Controls->Add(this->label3);
			this->gb_personnel->Location = System::Drawing::Point(6, 5);
			this->gb_personnel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->gb_personnel->Name = L"gb_personnel";
			this->gb_personnel->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->gb_personnel->Size = System::Drawing::Size(1072, 402);
			this->gb_personnel->TabIndex = 27;
			this->gb_personnel->TabStop = false;
			this->gb_personnel->Text = L"Personnel";
			// 
			// txt_dateEmbauche
			// 
			this->txt_dateEmbauche->Location = System::Drawing::Point(181, 293);
			this->txt_dateEmbauche->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txt_dateEmbauche->Name = L"txt_dateEmbauche";
			this->txt_dateEmbauche->Size = System::Drawing::Size(83, 22);
			this->txt_dateEmbauche->TabIndex = 26;
			// 
			// ListeEmployes
			// 
			this->ListeEmployes->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ListeEmployes->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->NoRue,
					this->Adresse, this->Ville, this->CP
			});
			this->ListeEmployes->Location = System::Drawing::Point(293, 293);
			this->ListeEmployes->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ListeEmployes->MultiSelect = false;
			this->ListeEmployes->Name = L"ListeEmployes";
			this->ListeEmployes->RowHeadersWidth = 51;
			this->ListeEmployes->RowTemplate->Height = 24;
			this->ListeEmployes->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->ListeEmployes->Size = System::Drawing::Size(736, 50);
			this->ListeEmployes->TabIndex = 16;
			// 
			// NoRue
			// 
			this->NoRue->HeaderText = L"NoRue";
			this->NoRue->MinimumWidth = 6;
			this->NoRue->Name = L"NoRue";
			this->NoRue->Width = 125;
			// 
			// Adresse
			// 
			this->Adresse->HeaderText = L"Adresse";
			this->Adresse->MinimumWidth = 6;
			this->Adresse->Name = L"Adresse";
			this->Adresse->Width = 125;
			// 
			// Ville
			// 
			this->Ville->HeaderText = L"Ville";
			this->Ville->MinimumWidth = 6;
			this->Ville->Name = L"Ville";
			this->Ville->Width = 125;
			// 
			// CP
			// 
			this->CP->HeaderText = L"CP";
			this->CP->MinimumWidth = 6;
			this->CP->Name = L"CP";
			this->CP->Width = 125;
			// 
			// btn_nouveau_personnel
			// 
			this->btn_nouveau_personnel->Location = System::Drawing::Point(181, 21);
			this->btn_nouveau_personnel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn_nouveau_personnel->Name = L"btn_nouveau_personnel";
			this->btn_nouveau_personnel->Size = System::Drawing::Size(119, 74);
			this->btn_nouveau_personnel->TabIndex = 12;
			this->btn_nouveau_personnel->Text = L"Nouveau";
			this->btn_nouveau_personnel->UseVisualStyleBackColor = true;
			this->btn_nouveau_personnel->Click += gcnew System::EventHandler(this, &MyForm::btn_nouveau_Click);
			// 
			// lbl_dateembauche
			// 
			this->lbl_dateembauche->AutoSize = true;
			this->lbl_dateembauche->Location = System::Drawing::Point(109, 272);
			this->lbl_dateembauche->Name = L"lbl_dateembauche";
			this->lbl_dateembauche->Size = System::Drawing::Size(108, 17);
			this->lbl_dateembauche->TabIndex = 25;
			this->lbl_dateembauche->Text = L"Date embauche";
			// 
			// btn_modifier_personnel
			// 
			this->btn_modifier_personnel->Location = System::Drawing::Point(181, 106);
			this->btn_modifier_personnel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn_modifier_personnel->Name = L"btn_modifier_personnel";
			this->btn_modifier_personnel->Size = System::Drawing::Size(119, 74);
			this->btn_modifier_personnel->TabIndex = 13;
			this->btn_modifier_personnel->Text = L"Modifier";
			this->btn_modifier_personnel->UseVisualStyleBackColor = true;
			this->btn_modifier_personnel->Click += gcnew System::EventHandler(this, &MyForm::btn_modifier_Click);
			// 
			// dateEmbauchePicker
			// 
			this->dateEmbauchePicker->CustomFormat = L"yyyyMMdd";
			this->dateEmbauchePicker->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateEmbauchePicker->Location = System::Drawing::Point(43, 293);
			this->dateEmbauchePicker->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dateEmbauchePicker->Name = L"dateEmbauchePicker";
			this->dateEmbauchePicker->Size = System::Drawing::Size(119, 22);
			this->dateEmbauchePicker->TabIndex = 23;
			this->dateEmbauchePicker->Value = System::DateTime(2020, 11, 30, 16, 19, 4, 0);
			// 
			// btn_supprimer_personnel
			// 
			this->btn_supprimer_personnel->Location = System::Drawing::Point(181, 190);
			this->btn_supprimer_personnel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn_supprimer_personnel->Name = L"btn_supprimer_personnel";
			this->btn_supprimer_personnel->Size = System::Drawing::Size(119, 76);
			this->btn_supprimer_personnel->TabIndex = 14;
			this->btn_supprimer_personnel->Text = L"Supprimer";
			this->btn_supprimer_personnel->UseVisualStyleBackColor = true;
			this->btn_supprimer_personnel->Click += gcnew System::EventHandler(this, &MyForm::btn_supprimer_Click);
			// 
			// btn_enregistrer_personnel
			// 
			this->btn_enregistrer_personnel->Location = System::Drawing::Point(315, 21);
			this->btn_enregistrer_personnel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn_enregistrer_personnel->Name = L"btn_enregistrer_personnel";
			this->btn_enregistrer_personnel->Size = System::Drawing::Size(121, 245);
			this->btn_enregistrer_personnel->TabIndex = 15;
			this->btn_enregistrer_personnel->Text = L"ENREGISTRER";
			this->btn_enregistrer_personnel->UseVisualStyleBackColor = true;
			this->btn_enregistrer_personnel->Click += gcnew System::EventHandler(this, &MyForm::btn_enregistrer_Click);
			// 
			// btn_previous_personnel
			// 
			this->btn_previous_personnel->Location = System::Drawing::Point(83, 335);
			this->btn_previous_personnel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn_previous_personnel->Name = L"btn_previous_personnel";
			this->btn_previous_personnel->Size = System::Drawing::Size(53, 30);
			this->btn_previous_personnel->TabIndex = 9;
			this->btn_previous_personnel->Text = L"<";
			this->btn_previous_personnel->UseVisualStyleBackColor = true;
			this->btn_previous_personnel->Click += gcnew System::EventHandler(this, &MyForm::btn_previous_personnel_Click);
			// 
			// btn_first_personnel
			// 
			this->btn_first_personnel->Location = System::Drawing::Point(21, 335);
			this->btn_first_personnel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn_first_personnel->Name = L"btn_first_personnel";
			this->btn_first_personnel->Size = System::Drawing::Size(53, 30);
			this->btn_first_personnel->TabIndex = 8;
			this->btn_first_personnel->Text = L"<<";
			this->btn_first_personnel->UseVisualStyleBackColor = true;
			this->btn_first_personnel->Click += gcnew System::EventHandler(this, &MyForm::btn_first_personnel_Click);
			// 
			// btn_next_personnel
			// 
			this->btn_next_personnel->Location = System::Drawing::Point(141, 335);
			this->btn_next_personnel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn_next_personnel->Name = L"btn_next_personnel";
			this->btn_next_personnel->Size = System::Drawing::Size(53, 30);
			this->btn_next_personnel->TabIndex = 10;
			this->btn_next_personnel->Text = L">";
			this->btn_next_personnel->UseVisualStyleBackColor = true;
			this->btn_next_personnel->Click += gcnew System::EventHandler(this, &MyForm::btn_next_personnel_Click);
			// 
			// btn_end_personnel
			// 
			this->btn_end_personnel->Location = System::Drawing::Point(203, 335);
			this->btn_end_personnel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn_end_personnel->Name = L"btn_end_personnel";
			this->btn_end_personnel->Size = System::Drawing::Size(53, 30);
			this->btn_end_personnel->TabIndex = 11;
			this->btn_end_personnel->Text = L">>";
			this->btn_end_personnel->UseVisualStyleBackColor = true;
			this->btn_end_personnel->Click += gcnew System::EventHandler(this, &MyForm::btn_end_personnel_Click);
			// 
			// txt_prenom
			// 
			this->txt_prenom->Location = System::Drawing::Point(43, 146);
			this->txt_prenom->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txt_prenom->Name = L"txt_prenom";
			this->txt_prenom->Size = System::Drawing::Size(83, 22);
			this->txt_prenom->TabIndex = 6;
			// 
			// txt_nom
			// 
			this->txt_nom->Location = System::Drawing::Point(43, 102);
			this->txt_nom->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txt_nom->Name = L"txt_nom";
			this->txt_nom->Size = System::Drawing::Size(83, 22);
			this->txt_nom->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(39, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ID Personne";
			// 
			// txt_idPersonne
			// 
			this->txt_idPersonne->Location = System::Drawing::Point(43, 53);
			this->txt_idPersonne->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txt_idPersonne->Name = L"txt_idPersonne";
			this->txt_idPersonne->Size = System::Drawing::Size(83, 22);
			this->txt_idPersonne->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(39, 79);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(37, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Nom";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(39, 126);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(57, 17);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Prénom";
			// 
			// tabControl1
			// 
			this->tabControl1->AccessibleDescription = L"";
			this->tabControl1->AccessibleName = L"";
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1141, 545);
			this->tabControl1->TabIndex = 73;
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->dgv_Com);
			this->tabPage5->Controls->Add(this->rb_Add_Com);
			this->tabPage5->Controls->Add(this->lbl_Rechercher_Com);
			this->tabPage5->Controls->Add(this->rb_ParClient_Com);
			this->tabPage5->Controls->Add(this->rb_ParDate_Com);
			this->tabPage5->Controls->Add(this->rb_ParRef_Com);
			this->tabPage5->Controls->Add(this->rb_Aff_Com);
			this->tabPage5->Controls->Add(this->rb_Del_Com);
			this->tabPage5->Controls->Add(this->gb_Add_Com);
			this->tabPage5->Controls->Add(this->gb_RechercheCli_COM);
			this->tabPage5->Controls->Add(this->gb_RechercherDate_Com);
			this->tabPage5->Controls->Add(this->gb_RechercherRef_Com);
			this->tabPage5->Location = System::Drawing::Point(4, 25);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Size = System::Drawing::Size(1133, 516);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"Commandes";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1173, 688);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->txt_message);
			this->Controls->Add(this->label4);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->gb_Add_Com->ResumeLayout(false);
			this->gb_Add_Com->PerformLayout();
			this->gb_RechercherRef_Com->ResumeLayout(false);
			this->gb_RechercherRef_Com->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_Com))->EndInit();
			this->gb_RechercherDate_Com->ResumeLayout(false);
			this->gb_RechercheCli_COM->ResumeLayout(false);
			this->gb_RechercheCli_COM->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_req_stat))->EndInit();
			this->gp_InfosClients_stat->ResumeLayout(false);
			this->gp_InfosClients_stat->PerformLayout();
			this->gp_InfoDate_stat->ResumeLayout(false);
			this->gp_InfoDate_stat->PerformLayout();
			this->tabPage4->ResumeLayout(false);
			this->gb_statistiques->ResumeLayout(false);
			this->gb_statistiques->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->groupBoxStock->ResumeLayout(false);
			this->groupBoxStock->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->gb_client->ResumeLayout(false);
			this->gb_client->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tabPage1->ResumeLayout(false);
			this->gb_personnel->ResumeLayout(false);
			this->gb_personnel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ListeEmployes))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage5->ResumeLayout(false);
			this->tabPage5->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		//SET mode et classe pour les différents services
		mode = "RIEN";
		classe = "RIEN";

		//Load data Personnel
		indexPersonnel = 0;
		ds = gcnew DataSet;
		processusPersonnes = gcnew NS_Svc::CL_svc_gestionPersonnes;
		loadData(indexPersonnel);

		//Load data Client
		indexClient = 0;
		ds2 = gcnew DataSet;
		dsClient = gcnew DataSet;
		processusClient = gcnew NS_Svc::CL_svc_gestionClients;
		loadDataClient(indexClient);
		txt_message->Text = "Data chargées";
		
		// Load STATS
		processusStats = gcnew NS_Svc::CL_svc_STATS;
	}


		   // PARTIE CLIENT
	private: void loadDataClient(int indexClient)
	{
		txt_datenaissance->Show();
		txt_datepremierachat->Show();
		dateNaissancePicker->Hide();	//Hide des dateTimePicker réservés à la modification
		datePremAchatPicker->Hide();

		dsClient->Clear();
		dsClient = processusClient->listeClients("liste_client");
		txt_idClient->Text = Convert::ToString(dsClient->Tables["liste_client"]->Rows[indexClient]->ItemArray[0]);
		txt_NomClient->Text = Convert::ToString(dsClient->Tables["liste_client"]->Rows[indexClient]->ItemArray[1]);
		txt_PrenomClient->Text = Convert::ToString(dsClient->Tables["liste_client"]->Rows[indexClient]->ItemArray[2]);
		txt_datenaissance->Text = Convert::ToString(dsClient->Tables["liste_client"]->Rows[indexClient]->ItemArray[3]);
		txt_datepremierachat->Text = Convert::ToString(dsClient->Tables["liste_client"]->Rows[indexClient]->ItemArray[4]);

		//Load Adresses
		if (rb_facturation->Checked){loadAdressesFacturation();}
		else {loadAdressesLivraison();}
		
	}
		   //FCT LOAD ADRESSES
	private: void loadAdressesLivraison(void)
	{
		//Load Livraison Adresses
		ds2->Clear();
		ds2 = processusClient->listeAdressesLivraison("listeAdresse", Convert::ToInt32(txt_idClient->Text));
		dataGridView1->DataSource = ds2->Tables["listeAdresse"];
	}
	private: void loadAdressesFacturation(void)
	{
		//Load Facturation Adresses
		ds2->Clear();
		ds2 = processusClient->listeAdressesFacturation("listeAdresse", Convert::ToInt32(txt_idClient->Text));
		dataGridView1->DataSource = ds2->Tables["listeAdresse"];
	}
		   //BOUTONS CLIENTS
	private: System::Void btn_first_client_Click(System::Object^ sender, System::EventArgs^ e) {
		indexClient = 0;
		loadDataClient(indexClient);
		txt_message->Text = "Enregistrement n°: " + (indexClient + 1);
	}
	private: System::Void btn_previous_client_Click(System::Object^ sender, System::EventArgs^ e) {
		if (indexClient > 0)
		{
			indexClient--;
			loadDataClient(indexClient);
			txt_message->Text = "Enregistrement n°: " + (indexClient + 1);
		}
	}
	private: System::Void btn_next_client_Click(System::Object^ sender, System::EventArgs^ e) {
		if (indexClient < dsClient->Tables["liste_client"]->Rows->Count - 1)
		{
			indexClient++;
			loadDataClient(indexClient);
			txt_message->Text = "Enregistrement n°: " + (indexClient + 1);
		}
	}
	private: System::Void btn_end_client_Click(System::Object^ sender, System::EventArgs^ e) {
		indexClient = dsClient->Tables["liste_client"]->Rows->Count - 1;
		loadDataClient(indexClient);
		txt_message->Text = "Enregistrement n° : " + (indexClient + 1);
	}
		   //BOUTONS INSERT UPDATE DELETE CLIENT
	private: System::Void btn_nouveau_client_Click(System::Object^ sender, System::EventArgs^ e) {
		txt_idClient->Clear();
		txt_NomClient->Clear();
		txt_PrenomClient->Clear();
		//	Show des éléments nécessaires
		txt_datenaissance->Hide();
		txt_datepremierachat->Hide();
		dateNaissancePicker->Show();
		datePremAchatPicker->Show();

		//DataGridView
		for each(DataGridViewRow^ myRow in dataGridView1->Rows)
		{
			myRow->Cells[0]->Value = DBNull::Value;
			myRow->Cells[1]->Value = DBNull::Value;
			myRow->Cells[2]->Value = DBNull::Value;
			myRow->Cells[3]->Value = DBNull::Value;
			myRow->Cells[4]->Value = DBNull::Value;
		}
		mode = "nouv";
		classe = "client";
		txt_message->Text = "Veuillez saisir les information du nouveau client et enregistrer";
	}
	private: System::Void btn_modifier_client_Click(System::Object^ sender, System::EventArgs^ e) {
		mode = "maj";
		classe = "client";
		txt_datenaissance->Hide();
		txt_datepremierachat->Hide();
		dateNaissancePicker->Show();
		datePremAchatPicker->Show();
		txt_message->Text = "Veuillez modifier les information du client et enregistrer.";
	}
	private: System::Void btn_supprimer_client_Click(System::Object^ sender, System::EventArgs^ e) {
		mode = "sup";
		classe = "client";
		txt_message->Text = "Veuillez confirmer la suppression du personnel en cours en enregistrant";
	}

		   //PARTIE PERSONNEL
	private: void loadData(int indexPersonnel) {
		txt_dateEmbauche->Show(); //Hide des champs réservés à la modification
		dateEmbauchePicker->Hide();
		//DS modif
		ds->Clear();
		ds = processusPersonnes->listePersonnes("liste");
		txt_idPersonne->Text = Convert::ToString(ds->Tables["liste"]->Rows[indexPersonnel]->ItemArray[0]);
		txt_nom->Text = Convert::ToString(ds->Tables["liste"]->Rows[indexPersonnel]->ItemArray[1]);
		txt_prenom->Text = Convert::ToString(ds->Tables["liste"]->Rows[indexPersonnel]->ItemArray[2]);
		txt_dateEmbauche->Text = Convert::ToString(ds->Tables["liste"]->Rows[indexPersonnel]->ItemArray[3]);
		//datagridview
		ListeEmployes->Rows[0]->Cells["NoRue"]->Value = Convert::ToString(ds->Tables["liste"]->Rows[indexPersonnel]->ItemArray[4]);
		ListeEmployes->Rows[0]->Cells["Adresse"]->Value = Convert::ToString(ds->Tables["liste"]->Rows[indexPersonnel]->ItemArray[5]);
		ListeEmployes->Rows[0]->Cells["Ville"]->Value = Convert::ToString(ds->Tables["liste"]->Rows[indexPersonnel]->ItemArray[6]);
		ListeEmployes->Rows[0]->Cells["CP"]->Value = Convert::ToString(ds->Tables["liste"]->Rows[indexPersonnel]->ItemArray[7]);
	}
		   //BOUTONS DEPLACER PERSONNEL
	private: System::Void btn_first_personnel_Click(System::Object^ sender, System::EventArgs^ e) {
		indexPersonnel = 0;
		loadData(indexPersonnel);
		txt_message->Text = "Enregistrement n°: " + (indexPersonnel + 1);
	}
	private: System::Void btn_previous_personnel_Click(System::Object^ sender, System::EventArgs^ e) {
		if (indexPersonnel > 0)
		{
			indexPersonnel--;
			loadData(indexPersonnel);
			txt_message->Text = "Enregistrement n°: " + (indexPersonnel + 1);
		}
	}
	private: System::Void btn_next_personnel_Click(System::Object^ sender, System::EventArgs^ e) {
		if (indexPersonnel < ds->Tables["liste"]->Rows->Count - 1)
		{
			indexPersonnel++;
			loadData(indexPersonnel);
			txt_message->Text = "Enregistrement n°: " + (indexPersonnel + 1);
		}
	}
	private: System::Void btn_end_personnel_Click(System::Object^ sender, System::EventArgs^ e) {
		indexPersonnel = ds->Tables["liste"]->Rows->Count - 1;
		loadData(indexPersonnel);
		txt_message->Text = "Enregistrement n° : " + (indexPersonnel + 1);
	}
		   //BOUTONS GESTION  INSERT UPDATE DELETE PERSONNEL
	private: System::Void btn_nouveau_Click(System::Object^ sender, System::EventArgs^ e) {
		txt_idPersonne->Clear();
		txt_nom->Clear();
		txt_prenom->Clear();

		txt_dateEmbauche->Hide(); //Show des champs réservés à la modification
		dateEmbauchePicker->Show();

		mode = "nouv";
		classe = "personnel";
		txt_message->Text = "Veuillez saisir les information du nouveau personnel et enregistrer";
	}
	private: System::Void btn_modifier_Click(System::Object^ sender, System::EventArgs^ e) {
		txt_dateEmbauche->Hide(); //Show des champs réservés à la modification
		dateEmbauchePicker->Show();

		mode = "maj";
		classe = "personnel";
		txt_message->Text = "Veuillez modifier les information du personnel et enregistrer.";
	}
	private: System::Void btn_supprimer_Click(System::Object^ sender, System::EventArgs^ e) {
		mode = "sup";
		classe = "personnel";
		txt_message->Text = "Veuillez confirmer la suppression du personnel en cours en enregistrant";
	}
		   //BOUTON ENREGISTER <--- GESTION DES ACTIONS A FAIRE
	private: System::Void btn_enregistrer_Click(System::Object^ sender, System::EventArgs^ e) {
		if (mode == "nouv")
		{
			if (classe == "personnel")
			{
				int id;
				id = processusPersonnes->ajouter(txt_nom->Text, txt_prenom->Text, dateEmbauchePicker->Text,
					Convert::ToInt32(ListeEmployes->Rows[0]->Cells["NoRue"]->Value),
					Convert::ToString(ListeEmployes->Rows[0]->Cells["Adresse"]->Value),
					Convert::ToString(ListeEmployes->Rows[0]->Cells["Ville"]->Value),
					Convert::ToInt32(ListeEmployes->Rows[0]->Cells["CP"]->Value));
				txt_message->Text = "L'ID généré est le : " + id + ". \r\n";
			}
			else if (classe == "client")
			{
				int id;
				id = processusClient->ajouterClient(txt_NomClient->Text, txt_PrenomClient->Text, dateNaissancePicker->Text, datePremAchatPicker->Text);
				//IMPORT DES ADRESSES
				cliext::vector<String^> adresse;
				for (int i = 0; i < dataGridView1->DisplayedRowCount(true); i++)
				{
					for (int j = 0; j < dataGridView1->DisplayedColumnCount(true); j++)
					{
						String^ elemAdresse = "" + dataGridView1[j, i]->Value;
						if (elemAdresse != "" || elemAdresse != String::Empty)
						{
							adresse.push_back(elemAdresse);
						}
					}
					if (rb_facturation->Checked && !adresse.empty())
					{
						processusClient->ajouterAdresseFacturation(id, Convert::ToInt32(adresse[0]), adresse[1], adresse[2], Convert::ToInt32(adresse[3]));
					}
					else if (rb_livraison->Checked && !adresse.empty())
					{
						processusClient->ajouterAdresseLivraison(id, Convert::ToInt32(adresse[0]), adresse[1], adresse[2], Convert::ToInt32(adresse[3]));
					}
					adresse.clear();
				}
				
			}
		}
		else if (mode == "maj")
		{
			if (classe = "personnel")
			{
				processusPersonnes->modifier(Convert::ToInt32(txt_idPersonne->Text), txt_nom->Text, txt_prenom->Text,
					dateEmbauchePicker->Text, Convert::ToInt32(ListeEmployes->Rows[0]->Cells["NoRue"]->Value),
					Convert::ToString(ListeEmployes->Rows[0]->Cells["Adresse"]->Value),
					Convert::ToString(ListeEmployes->Rows[0]->Cells["Ville"]->Value),
					Convert::ToInt32(ListeEmployes->Rows[0]->Cells["CP"]->Value));
			}
			if (classe = "client")
			{
				processusClient->modifierClient(Convert::ToInt32(txt_idClient->Text),txt_NomClient->Text, txt_PrenomClient->Text, dateNaissancePicker->Text, datePremAchatPicker->Text);
				//MODIFICATION DES ADRESSES
				cliext::vector<String^> adresse;
				for (int i = 0; i < dataGridView1->DisplayedRowCount(true); i++)
				{
					for (int j = 0; j < dataGridView1->DisplayedColumnCount(true); j++)
					{
						String^ elemAdresse = "" + dataGridView1[j, i]->Value;
						if (elemAdresse != "" || elemAdresse != String::Empty)
						{
							adresse.push_back(elemAdresse);
						}
					}
					if (rb_facturation->Checked && !adresse.empty())
					{
						processusClient->modifierAdresseFacturation(Convert::ToInt32(adresse[0]), Convert::ToInt32(adresse[1]), adresse[2], adresse[3], Convert::ToInt32(adresse[4]));
					}
					else if (rb_livraison->Checked && !adresse.empty())
					{
						processusClient->modifierAdresseLivraison(Convert::ToInt32(adresse[0]), Convert::ToInt32(adresse[1]), adresse[2], adresse[3], Convert::ToInt32(adresse[4]));
					}
					adresse.clear();
				}
			}
		}
		else if (mode == "sup")
		{
			if (classe == "personnel")
			{
				processusPersonnes->supprimer(Convert::ToInt32(txt_idPersonne->Text));
			}
			if (classe == "client")
			{
				processusClient->supprimer(Convert::ToInt32(txt_idClient->Text));
			}
		}
		indexPersonnel = 0;
		indexClient = 0;
		loadData(indexPersonnel);
		loadDataClient(indexClient);
		txt_message->Text += "Traitement terminé.";
	}
	private: System::Void rb_facturation_Click(System::Object^ sender, System::EventArgs^ e) {
		loadAdressesFacturation();
		
	}
	//RadioButton pour afficher les adresses de livraison
	private: System::Void rb_livraison_Click(System::Object^ sender, System::EventArgs^ e) {
		loadAdressesLivraison();
	}





//STOCKS =======>
	   void verificationBlank()
	   {

		   if (textBoxIdArticle->Text == "" && textBoxNomArticle->Text == "")
		   {
			   textBoxIdArticle->Text = "0";
			   textBoxNomArticle->Text = "";
			   textBoxDesignationArticle->Text = "";
			   textBoxSeuilReapro->Text = "0";
			   textBoxQuantiteStockArticle->Text = "0";
		   }

		   if (textBoxIdNature->Text == "" && textBoxNature->Text == "")
		   {
			   textBoxIdNature->Text = "0";
			   textBoxNature->Text = "";
		   }

		   if (textBoxIdTVA->Text == "" && textBoxTauxTVA->Text == "")
		   {
			   textBoxIdTVA->Text = "0";
			   textBoxTauxTVA->Text = "0";
		   }
	   }
private: System::Void buttonPremierArticle_Click(System::Object^ sender, System::EventArgs^ e)
{
	NS_Svc::Services_Stocks^ objt = gcnew NS_Svc::Services_Stocks;
	NS_Composants::Stock^ objt1 = gcnew NS_Composants::Stock;
	objt1 = objt->selectPremierArticle("Article");
	textBoxIdArticle->Text = Convert::ToString(objt1->getIdArticle());
	textBoxNomArticle->Text = Convert::ToString(objt1->getNomArticle());
	textBoxDesignationArticle->Text = Convert::ToString(objt1->getDesignationArticle());
	textBoxSeuilReapro->Text = Convert::ToString(objt1->getSeuilReapro());
	textBoxQuantiteStockArticle->Text = Convert::ToString(objt1->getQuantiteStockArticle());
	textBoxIdNature->Text = Convert::ToString(objt1->getIdNature());
	textBoxNature->Text = Convert::ToString(objt1->getNature());
	textBoxIdTVA->Text = Convert::ToString(objt1->getIdTVA());
	textBoxTauxTVA->Text = Convert::ToString(objt1->getTauxTVA());
}
private: System::Void buttonPrecedentArticle_Click(System::Object^ sender, System::EventArgs^ e)
{
	verificationBlank();
	NS_Svc::Services_Stocks^ objt = gcnew NS_Svc::Services_Stocks;
	NS_Composants::Stock^ objt1 = gcnew NS_Composants::Stock;
	objt1 = objt->selectPrecedentArticle(Convert::ToInt32(textBoxIdArticle->Text), Convert::ToInt32(textBoxIdNature->Text), Convert::ToInt32(textBoxIdTVA->Text), "Article");
	textBoxIdArticle->Text = Convert::ToString(objt1->getIdArticle());
	textBoxNomArticle->Text = Convert::ToString(objt1->getNomArticle());
	textBoxDesignationArticle->Text = Convert::ToString(objt1->getDesignationArticle());
	textBoxSeuilReapro->Text = Convert::ToString(objt1->getSeuilReapro());
	textBoxQuantiteStockArticle->Text = Convert::ToString(objt1->getQuantiteStockArticle());
	textBoxIdNature->Text = Convert::ToString(objt1->getIdNature());
	textBoxNature->Text = Convert::ToString(objt1->getNature());
	textBoxIdTVA->Text = Convert::ToString(objt1->getIdTVA());
	textBoxTauxTVA->Text = Convert::ToString(objt1->getTauxTVA());
}

private: System::Void buttonSuivantArticle_Click(System::Object^ sender, System::EventArgs^ e)
{
	verificationBlank();
	NS_Svc::Services_Stocks^ objt = gcnew NS_Svc::Services_Stocks;
	NS_Composants::Stock^ objt1 = gcnew NS_Composants::Stock;
	objt1 = objt->selectSuivantArticle(Convert::ToInt32(textBoxIdArticle->Text), Convert::ToInt32(textBoxIdNature->Text), Convert::ToInt32(textBoxIdTVA->Text), "Article");
	textBoxIdArticle->Text = Convert::ToString(objt1->getIdArticle());
	textBoxNomArticle->Text = Convert::ToString(objt1->getNomArticle());
	textBoxDesignationArticle->Text = Convert::ToString(objt1->getDesignationArticle());
	textBoxSeuilReapro->Text = Convert::ToString(objt1->getSeuilReapro());
	textBoxQuantiteStockArticle->Text = Convert::ToString(objt1->getQuantiteStockArticle());
	textBoxIdNature->Text = Convert::ToString(objt1->getIdNature());
	textBoxNature->Text = Convert::ToString(objt1->getNature());
	textBoxIdTVA->Text = Convert::ToString(objt1->getIdTVA());
	textBoxTauxTVA->Text = Convert::ToString(objt1->getTauxTVA());
}

private: System::Void buttonDernierArticle_Click(System::Object^ sender, System::EventArgs^ e)
{
	verificationBlank();
	NS_Svc::Services_Stocks^ objt = gcnew NS_Svc::Services_Stocks;
	NS_Composants::Stock^ objt1 = gcnew NS_Composants::Stock;
	objt1 = objt->selectDernierArticle("Article");
	textBoxIdArticle->Text = Convert::ToString(objt1->getIdArticle());
	textBoxNomArticle->Text = Convert::ToString(objt1->getNomArticle());
	textBoxDesignationArticle->Text = Convert::ToString(objt1->getDesignationArticle());
	textBoxSeuilReapro->Text = Convert::ToString(objt1->getSeuilReapro());
	textBoxQuantiteStockArticle->Text = Convert::ToString(objt1->getQuantiteStockArticle());
	textBoxIdNature->Text = Convert::ToString(objt1->getIdNature());
	textBoxNature->Text = Convert::ToString(objt1->getNature());
	textBoxIdTVA->Text = Convert::ToString(objt1->getIdTVA());
	textBoxTauxTVA->Text = Convert::ToString(objt1->getTauxTVA());
}

private: System::Void buttonPremierNature_Click(System::Object^ sender, System::EventArgs^ e)
{
	verificationBlank();
	NS_Svc::Services_Stocks^ objt = gcnew NS_Svc::Services_Stocks;
	NS_Composants::Stock^ objt1 = gcnew NS_Composants::Stock;
	objt1 = objt->selectPremierArticle("Nature");
	textBoxIdNature->Text = Convert::ToString(objt1->getIdNature());
	textBoxNature->Text = Convert::ToString(objt1->getNature());
}

private: System::Void buttonPrecedentNature_Click(System::Object^ sender, System::EventArgs^ e)
{
	verificationBlank();
	NS_Svc::Services_Stocks^ objt = gcnew NS_Svc::Services_Stocks;
	NS_Composants::Stock^ objt1 = gcnew NS_Composants::Stock;
	objt1 = objt->selectPrecedentArticle(Convert::ToInt32(textBoxIdArticle->Text), Convert::ToInt32(textBoxIdNature->Text), Convert::ToInt32(textBoxIdTVA->Text), "Nature");
	textBoxIdNature->Text = Convert::ToString(objt1->getIdNature());
	textBoxNature->Text = Convert::ToString(objt1->getNature());
}

private: System::Void buttonSuivantNature_Click(System::Object^ sender, System::EventArgs^ e)
{
	verificationBlank();
	NS_Svc::Services_Stocks^ objt = gcnew NS_Svc::Services_Stocks;
	NS_Composants::Stock^ objt1 = gcnew NS_Composants::Stock;
	objt1 = objt->selectSuivantArticle(Convert::ToInt32(textBoxIdArticle->Text), Convert::ToInt32(textBoxIdNature->Text), Convert::ToInt32(textBoxIdTVA->Text), "Nature");
	textBoxIdNature->Text = Convert::ToString(objt1->getIdNature());
	textBoxNature->Text = Convert::ToString(objt1->getNature());
}

private: System::Void buttonDernierNature_Click(System::Object^ sender, System::EventArgs^ e)
{
	verificationBlank();
	NS_Svc::Services_Stocks^ objt = gcnew NS_Svc::Services_Stocks;
	NS_Composants::Stock^ objt1 = gcnew NS_Composants::Stock;
	objt1 = objt->selectDernierArticle("Nature");
	textBoxIdNature->Text = Convert::ToString(objt1->getIdNature());
	textBoxNature->Text = Convert::ToString(objt1->getNature());
}

private: System::Void buttonPremierTVA_Click(System::Object^ sender, System::EventArgs^ e)
{
	verificationBlank();
	NS_Svc::Services_Stocks^ objt = gcnew NS_Svc::Services_Stocks;
	NS_Composants::Stock^ objt1 = gcnew NS_Composants::Stock;
	objt1 = objt->selectPremierArticle("TVA");
	textBoxIdTVA->Text = Convert::ToString(objt1->getIdTVA());
	textBoxTauxTVA->Text = Convert::ToString(objt1->getTauxTVA());
}

private: System::Void buttonPrecedentTVA_Click(System::Object^ sender, System::EventArgs^ e)
{
	verificationBlank();
	NS_Svc::Services_Stocks^ objt = gcnew NS_Svc::Services_Stocks;
	NS_Composants::Stock^ objt1 = gcnew NS_Composants::Stock;
	objt1 = objt->selectPrecedentArticle(Convert::ToInt32(textBoxIdArticle->Text), Convert::ToInt32(textBoxIdNature->Text), Convert::ToInt32(textBoxIdTVA->Text), "TVA");
	textBoxIdTVA->Text = Convert::ToString(objt1->getIdTVA());
	textBoxTauxTVA->Text = Convert::ToString(objt1->getTauxTVA());
}

private: System::Void buttonSuivantTVA_Click(System::Object^ sender, System::EventArgs^ e)
{
	verificationBlank();
	NS_Svc::Services_Stocks^ objt = gcnew NS_Svc::Services_Stocks;
	NS_Composants::Stock^ objt1 = gcnew NS_Composants::Stock;
	objt1 = objt->selectSuivantArticle(Convert::ToInt32(textBoxIdArticle->Text), Convert::ToInt32(textBoxIdNature->Text), Convert::ToInt32(textBoxIdTVA->Text), "TVA");
	textBoxIdTVA->Text = Convert::ToString(objt1->getIdTVA());
	textBoxTauxTVA->Text = Convert::ToString(objt1->getTauxTVA());
}

private: System::Void buttonDernierTVA_Click(System::Object^ sender, System::EventArgs^ e)
{
	verificationBlank();
	NS_Svc::Services_Stocks^ objt = gcnew NS_Svc::Services_Stocks;
	NS_Composants::Stock^ objt1 = gcnew NS_Composants::Stock;
	objt1 = objt->selectDernierArticle("TVA");
	textBoxIdTVA->Text = Convert::ToString(objt1->getIdTVA());
	textBoxTauxTVA->Text = Convert::ToString(objt1->getTauxTVA());
}

private: System::Void buttonAjouterArticle_Click(System::Object^ sender, System::EventArgs^ e)
{
	verificationBlank();
	NS_Svc::Services_Stocks^ objt = gcnew NS_Svc::Services_Stocks;
	objt->ajouterArticle(textBoxNomArticle->Text, textBoxDesignationArticle->Text, Convert::ToInt32(textBoxSeuilReapro->Text),
		Convert::ToInt32(textBoxQuantiteStockArticle->Text), textBoxNature->Text, Convert::ToInt32(textBoxTauxTVA->Text));
}

private: System::Void buttonUpdateArticle_Click(System::Object^ sender, System::EventArgs^ e)
{
	NS_Svc::Services_Stocks^ objt = gcnew NS_Svc::Services_Stocks;
	objt->modifierArticle(Convert::ToInt32(textBoxIdArticle->Text), textBoxNomArticle->Text, textBoxDesignationArticle->Text, Convert::ToInt32(textBoxSeuilReapro->Text),
		Convert::ToInt32(textBoxQuantiteStockArticle->Text), Convert::ToInt32(textBoxIdNature->Text), textBoxNature->Text,
		Convert::ToInt32(textBoxIdTVA->Text), Convert::ToInt32(textBoxTauxTVA->Text));
}

private: System::Void buttonDeleteArticle_Click(System::Object^ sender, System::EventArgs^ e)
{
	verificationBlank();
	NS_Svc::Services_Stocks^ objt = gcnew NS_Svc::Services_Stocks;
	objt->supprimer(Convert::ToInt32(textBoxIdArticle->Text), Convert::ToInt32(textBoxIdNature->Text), Convert::ToInt32(textBoxIdTVA->Text));
}

private: System::Void buttonClearArticle_Click(System::Object^ sender, System::EventArgs^ e)
{
	textBoxIdArticle->Clear();
	textBoxNomArticle->Clear();
	textBoxDesignationArticle->Clear();
	textBoxSeuilReapro->Clear();
	textBoxQuantiteStockArticle->Clear();
}

private: System::Void buttonClearNature_Click(System::Object^ sender, System::EventArgs^ e)
{
	textBoxIdNature->Clear();
	textBoxNature->Clear();
}

private: System::Void buttonClearTVA_Click(System::Object^ sender, System::EventArgs^ e)
{
	textBoxIdTVA->Clear();
	textBoxTauxTVA->Clear();
}

	   //COMMANDES ===>
		   private: System::Void btn_RechercherCli_Com_Click(System::Object^ sender, System::EventArgs^ e) {
			   processusCommandes = gcnew NS_Svc::CL_svc_gestionCommandes;
			   dsCom = gcnew DataSet;
			   dsCom = processusCommandes->afficherParClient(txt_IdClient_Com->Text, txt_PrenomClient_Com->Text, txt_NomClient_Com->Text);
			   dgv_Com->DataSource = dsCom->Tables["Values"];

		   }
private: System::Void bnt_RechercherDate_Com_Click(System::Object^ sender, System::EventArgs^ e) {
	processusCommandes = gcnew NS_Svc::CL_svc_gestionCommandes;
	dsCom = gcnew DataSet;
	dsCom = processusCommandes->afficherParDate(Convert::ToString(cb_Jour_Com->SelectedIndex), Convert::ToString(cb_Mois_Com->SelectedIndex), Convert::ToString(cb_Annee_Com->SelectedItem));
	dgv_Com->DataSource = dsCom->Tables["Values"];

}
private: System::Void bnt_RechercherRef_Com_Click(System::Object^ sender, System::EventArgs^ e) {
	processusCommandes = gcnew NS_Svc::CL_svc_gestionCommandes;
	dsCom = gcnew DataSet;
	dsCom = processusCommandes->afficherParRef(txt_Ref_Com->Text);
	dgv_Com->DataSource = dsCom->Tables["Values"];
}
private: System::Void rb_ParClient_Com_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (rb_ParClient_Com->Checked == true) {
		gb_RechercheCli_COM->Show();
		gb_RechercherDate_Com->Hide();
		gb_RechercherRef_Com->Hide();
	}
}
private: System::Void rb_ParRef_Com_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (rb_ParRef_Com->Checked == true) {
		gb_RechercheCli_COM->Hide();
		gb_RechercherDate_Com->Hide();
		gb_RechercherRef_Com->Show();
	}
}
private: System::Void rb_ParDate_Com_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (rb_ParDate_Com->Checked == true) {
		gb_RechercheCli_COM->Hide();
		gb_RechercherDate_Com->Show();
		gb_RechercherRef_Com->Hide();
	}
}
private: System::Void btn_Add_Com_Click(System::Object^ sender, System::EventArgs^ e) {
	processusCommandes = gcnew NS_Svc::CL_svc_gestionCommandes;
	processusCommandes->ajouter(txt_AddRef_Com->Text, dtp_AddDate_Com->Value, dtp_AddDateEmission_Com->Value, dtp_AddDatePaiementRec_Com->Value, Convert::ToInt32(txt_AddHT_Com->Text), Convert::ToInt32(txt_AddTTC_Com->Text), Convert::ToString(txt_AddTVA_Com->Text), Convert::ToInt32(txt_AddIdCli_Com->Text));
}
private: System::Void rb_Add_Com_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	gb_Add_Com->Show();
}
	   ///<<=======COMMANDES


	   // STATS ==>
private: System::Void btn_stats_calculer_Click(System::Object^ sender, System::EventArgs^ e) 
{
	txt_stats_result->Text = "" + processusStats->valeurstock(Convert::ToSingle(txt_stats_TVA->Text), Convert::ToSingle(txt_stats_margeCommerciale->Text), Convert::ToSingle(txt_stats_remiseCommerciale->Text), Convert::ToSingle(txt_stats_demarqueInconnue->Text));
}
	   
			private: System::Void btn_ok_Click(System::Object^ sender, System::EventArgs^ e) {
				ds = gcnew DataSet;
				ds = processusStats->afficherReq(cb_req_stat->SelectedIndex, Convert::ToString(cb_month_stat->SelectedIndex), Convert::ToString(cb_year_stat->SelectedItem), txt_nomClient_stat->Text, txt_prenomClient_stat->Text);
				dgv_req_stat->DataSource = ds->Tables["Values"];
			}
private: System::Void cb_req_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (cb_req_stat->SelectedIndex == 3) {
		gp_InfosClients_stat->Visible = true;
	}
	else {
		gp_InfosClients_stat->Visible = false;
	}
	if (cb_req_stat->SelectedIndex == 1) {
		gp_InfoDate_stat->Visible = true;
	}
	else {
		gp_InfoDate_stat->Visible = false;
	}
}
	   // STATS <<====
};
}