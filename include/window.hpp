#pragma once

#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QGroupBox>

namespace spiral::ui {

	class qt_window : public QWidget {
		Q_OBJECT

		using callback = std::function<std::string(std::string, std::string)>;

		public:
			qt_window(callback button_callback, const std::string& title, int width = 300, int height = 200, QWidget* parent = nullptr);

		private slots:
			void clicked();

		private:
			QLineEdit* text_row_input_;
			QLineEdit* text_col_input_;
			QPushButton* button_;
			QTextEdit* output_box_;
			callback button_callback_;

			QGroupBox* create_group_box();
			void create_layout();
	};

}
