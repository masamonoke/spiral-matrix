#include "window.hpp"

#include <QFormLayout>
#include <QLabel>

namespace spiral::ui
{

	QtWindow::QtWindow(Callback ButtonCallback, const std::string& title, int width, int height, QWidget* Parent)
	    : QWidget(Parent),
	      m_TextRowInput(new QLineEdit(this)),
	      m_TextColInput(new QLineEdit(this)),
	      m_Button(new QPushButton("Go", this)),
	      m_OutputBox(new QTextEdit(this)),
	      m_ButtonCallback(std::move(ButtonCallback))
	{
		m_OutputBox->setReadOnly(true);

		CreateLayout();

		setWindowTitle(QString::fromStdString(title));
		resize(width, height);

		connect(m_Button, &QPushButton::clicked, this, &QtWindow::clicked);
	}

	QGroupBox* QtWindow::CreateGroupBox()
	{
		auto* formGroupBox = new QGroupBox(tr("Matrix Data"));
		auto* l            = new QFormLayout;
		l->addRow(new QLabel(tr("Rows:")), m_TextRowInput);
		l->addRow(new QLabel(tr("Cols:")), m_TextColInput);
		formGroupBox->setLayout(l);
		return formGroupBox;
	}

	void QtWindow::CreateLayout()
	{
		auto* layout = new QVBoxLayout(this);
		layout->addWidget(CreateGroupBox());
		layout->addWidget(m_Button);
		layout->addWidget(m_OutputBox);
		setLayout(layout);
	}

	void QtWindow::clicked()
	{
		auto rowsText = m_TextRowInput->text();
		auto colsText = m_TextColInput->text();
		m_TextRowInput->clear();
		m_TextColInput->clear();
		try
		{
			auto data = m_ButtonCallback(rowsText.toStdString(), colsText.toStdString());
			m_OutputBox->setText(QString::fromStdString(data));
		}
		catch (const std::invalid_argument& e)
		{
			auto msg = "Wrong rows or columns value passed: " + std::string(e.what());
			QMessageBox::critical(this, "Invalid Format Error", QString::fromStdString(msg));
			m_OutputBox->clear();
		}
		catch (const std::out_of_range& e)
		{
			auto msg = "Rows or columns number is out of range value: " + std::string(e.what());
			QMessageBox::critical(this, "Out of range Error", QString::fromStdString(msg));
			m_OutputBox->clear();
		}
	}

} // namespace spiral::ui
