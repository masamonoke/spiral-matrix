#include "window.hpp"

#include <QLabel>
#include <QFormLayout>

namespace spiral::ui {

	qt_window::qt_window(callback button_callback, const std::string& title, int width, int height, QWidget* parent) :
		QWidget(parent),
		text_row_input_(new QLineEdit(this)),
		text_col_input_(new QLineEdit(this)),
		button_(new QPushButton("Go", this)),
		output_box_(new QTextEdit(this)),
		button_callback_(std::move(button_callback))
	{
		output_box_->setReadOnly(true);

		create_layout();

		setWindowTitle(QString::fromStdString(title));
		resize(width, height);

		connect(button_, &QPushButton::clicked, this, &qt_window::clicked);
	}

	QGroupBox* qt_window::create_group_box() {
		auto* formGroupBox = new QGroupBox(tr("Matrix Data"));
		auto* l = new QFormLayout;
		l->addRow(new QLabel(tr("Rows:")), text_row_input_);
		l->addRow(new QLabel(tr("Cols:")), text_col_input_);
		formGroupBox->setLayout(l);
		return formGroupBox;
	}

	void qt_window::create_layout() {
		auto* layout = new QVBoxLayout(this);
		layout->addWidget(create_group_box());
		layout->addWidget(button_);
		layout->addWidget(output_box_);
		setLayout(layout);
	}

	void qt_window::clicked() {
        auto rows_text = text_row_input_->text();
		auto cols_text = text_col_input_->text();
		text_row_input_->clear();
		text_col_input_->clear();
		try {
			auto data = button_callback_(rows_text.toStdString(), cols_text.toStdString());
			output_box_->setText(QString::fromStdString(data));
		} catch (const std::invalid_argument& e) {
			auto msg = "Wrong rows or columns value passed: " + std::string(e.what());
			QMessageBox::critical(this, "Invalid Format Error", QString::fromStdString(msg));
			output_box_->clear();
		} catch (const std::out_of_range& e) {
			auto msg = "Rows or columns number is out of range value: " + std::string(e.what());
			QMessageBox::critical(this, "Out of range Error", QString::fromStdString(msg));
			output_box_->clear();
		}
	}

}
