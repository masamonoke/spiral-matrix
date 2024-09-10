#pragma once

#include <QApplication>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

namespace spiral::ui
{

	class QtWindow : public QWidget
	{
		Q_OBJECT

		using Callback = std::function<std::string(std::string, std::string)>;

		public:
			QtWindow(Callback ButtonCallback, const std::string& title, int width = 300, int height = 200,
			         QWidget* Parent = nullptr);

		private slots:
			void clicked(); // NOLINT

		private:
			QLineEdit*   m_TextRowInput;
			QLineEdit*   m_TextColInput;
			QPushButton* m_Button;
			QTextEdit*   m_OutputBox;
			Callback     m_ButtonCallback;

			QGroupBox* CreateGroupBox();
			void       CreateLayout();
	};

} // namespace spiral::ui
