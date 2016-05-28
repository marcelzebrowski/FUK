#include "charakterform.h"
#include "fertigkeitform.h"
#include "ui_charakterform.h"

CharakterForm::CharakterForm(QDialog *parent, CharakterManager* charakterManager) :
    QDialog(parent),charakterManager(charakterManager),
    ui(new Ui::charakterform){
    ui->setupUi(this);

    connect(ui->weiterButton,SIGNAL(clicked()),this,SLOT(startGenerierung()));
    connect(ui->abbrechenButton,SIGNAL(clicked()),this,SLOT(abbrechenGenerierung()));

    fertigkeitForm = new FertigkeitForm(this,charakterManager);
    fertigkeitForm->setModal(true);
}

CharakterForm::~CharakterForm(){
    delete fertigkeitForm;
    delete ui;
}


void CharakterForm::startGenerierung(){
    QString name = ui->lineEditName->text();
    QString beschreibung = ui->labelBeschreibung->text();
    charakterManager->addCharakterBeschreibung(name,beschreibung);
    fertigkeitForm->show();
}

void CharakterForm::abbrechenGenerierung(){

    // Alle Fälder wieder löschen
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
        widget->clear();
    }

    foreach(QTextEdit *widget, this->findChildren<QTextEdit*>()) {
        widget->clear();
    }

    // Im Speicher könnte noch ein Charakter sein, den wir löschen.
    charakterManager->deleteCurrentCharakter();
    this->close();
}
