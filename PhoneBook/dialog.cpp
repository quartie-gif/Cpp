#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    std::vector<std::string> countries = { "United States", "Canada", "Afghanistan", "Albania", "Algeria", "American Samoa", "Andorra", "Angola", "Anguilla", "Antarctica", "Antigua and/or Barbuda", "Argentina", "Armenia", "Aruba", "Australia", "Austria", "Azerbaijan", "Bahamas", "Bahrain", "Bangladesh", "Barbados", "Belarus", "Belgium", "Belize", "Benin", "Bermuda", "Bhutan", "Bolivia", "Bosnia and Herzegovina", "Botswana", "Bouvet Island", "Brazil", "British Indian Ocean Territory", "Brunei Darussalam", "Bulgaria", "Burkina Faso", "Burundi", "Cambodia", "Cameroon", "Cape Verde", "Cayman Islands", "Central African Republic", "Chad", "Chile", "China", "Christmas Island", "Cocos (Keeling) Islands", "Colombia", "Comoros", "Congo", "Cook Islands", "Costa Rica", "Croatia (Hrvatska)", "Cuba", "Cyprus", "Czech Republic", "Denmark", "Djibouti", "Dominica", "Dominican Republic", "East Timor", "Ecudaor", "Egypt", "El Salvador", "Equatorial Guinea", "Eritrea", "Estonia", "Ethiopia", "Falkland Islands (Malvinas)", "Faroe Islands", "Fiji", "Finland", "France", "France, Metropolitan", "French Guiana", "French Polynesia", "French Southern Territories", "Gabon", "Gambia", "Georgia", "Germany", "Ghana", "Gibraltar", "Greece", "Greenland", "Grenada", "Guadeloupe", "Guam", "Guatemala", "Guinea", "Guinea-Bissau", "Guyana", "Haiti", "Heard and Mc Donald Islands", "Honduras", "Hong Kong", "Hungary", "Iceland", "India", "Indonesia", "Iran (Islamic Republic of)", "Iraq", "Ireland", "Israel", "Italy", "Ivory Coast", "Jamaica", "Japan", "Jordan", "Kazakhstan", "Kenya", "Kiribati", "Korea, Democratic People's Republic of", "Korea, Republic of", "Kosovo", "Kuwait", "Kyrgyzstan", "Lao People's Democratic Republic", "Latvia", "Lebanon", "Lesotho", "Liberia", "Libyan Arab Jamahiriya", "Liechtenstein", "Lithuania", "Luxembourg", "Macau", "Macedonia", "Madagascar", "Malawi", "Malaysia", "Maldives", "Mali", "Malta", "Marshall Islands", "Martinique", "Mauritania", "Mauritius", "Mayotte", "Mexico", "Micronesia, Federated States of", "Moldova, Republic of", "Monaco", "Mongolia", "Montserrat", "Morocco", "Mozambique", "Myanmar", "Namibia", "Nauru", "Nepal", "Netherlands", "Netherlands Antilles", "New Caledonia", "New Zealand", "Nicaragua", "Niger", "Nigeria", "Niue", "Norfork Island", "Northern Mariana Islands", "Norway", "Oman", "Pakistan", "Palau", "Panama", "Papua New Guinea", "Paraguay", "Peru", "Philippines", "Pitcairn", "Poland", "Portugal", "Puerto Rico", "Qatar", "Reunion", "Romania", "Russian Federation", "Rwanda", "Saint Kitts and Nevis", "Saint Lucia", "Saint Vincent and the Grenadines", "Samoa", "San Marino", "Sao Tome and Principe", "Saudi Arabia", "Senegal", "Seychelles", "Sierra Leone", "Singapore", "Slovakia", "Slovenia", "Solomon Islands", "Somalia", "South Africa", "South Georgia South Sandwich Islands", "South Sudan", "Spain", "Sri Lanka", "St. Helena", "St. Pierre and Miquelon", "Sudan", "Suriname", "Svalbarn and Jan Mayen Islands", "Swaziland", "Sweden", "Switzerland", "Syrian Arab Republic", "Taiwan", "Tajikistan", "Tanzania, United Republic of", "Thailand", "Togo", "Tokelau", "Tonga", "Trinidad and Tobago", "Tunisia", "Turkey", "Turkmenistan", "Turks and Caicos Islands", "Tuvalu", "Uganda", "Ukraine", "United Arab Emirates", "United Kingdom", "United States minor outlying islands", "Uruguay", "Uzbekistan", "Vanuatu", "Vatican City State", "Venezuela", "Vietnam", "Virigan Islands (British)", "Virgin Islands (U.S.)", "Wallis and Futuna Islands", "Western Sahara", "Yemen", "Yugoslavia", "Zaire", "Zambia", "Zimbabwe"};

    for(auto &it: countries)
    {
        ui->Nationality_comboBox->addItem(QString::fromStdString(it));
    }

    m_persons.reserve(100);
}

Dialog::~Dialog()
{
    this->updateFile();
    delete ui;
}



void Dialog::on_Add_pushButton_clicked()
{
    bool isWoman = true;
    QRegExp re("^[0-9]*$");
    bool noErrors = true;

    if (ui->Male_checkBox->isChecked())
        isWoman = false;

    if (ui->Phone_lineEdit->text().size() != 9 )
    {
        noErrors = false;
        if(ui->Phone_lineEdit->text().size() > 9)
        {
            QMessageBox::information(this, tr("ERROR"),tr("Too many numbers, try again!"));
        }
        if(ui->Phone_lineEdit->text().size() < 9)
        {
            QMessageBox::information(this, tr("ERROR"),tr("Not enough numbers, try again!"));
        }
    }

    if(ui->Surname_lineEdit->text().isEmpty())
    {
        noErrors = false;
        QMessageBox::information(this, tr("ERROR"),tr("You didn't fill information about surname!"));
    }

    if(ui->Name_lineEdit->text().isEmpty())
    {
        QMessageBox::information(this, tr("ERROR"),tr("You didn't fill information about name!"));
        noErrors = false;
    }

    if (!re.exactMatch(ui->Phone_lineEdit->text()))
    {
        QMessageBox::information(this, tr("ERROR"),tr("Use only numbers!"));
        noErrors = false;
    }

    if (noErrors)
        m_persons.push_back(Person(ui->Name_lineEdit->text(), ui->Surname_lineEdit->text(), ui->Phone_lineEdit->text(), ui->Nationality_comboBox->currentText(), isWoman));


}

void Dialog::updateFile() const
{
    QString filename="/Users/apple/GUI_Projects/PhonebookGUI/Data.txt";
    QFile file( filename );

    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );
        for(auto &it: m_persons)
        {
            stream << it.data();
        }
    }
}

void Dialog::on_exit_pushButton_clicked()
{
    this->close();
}

