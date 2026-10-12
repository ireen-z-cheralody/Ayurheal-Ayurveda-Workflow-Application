
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 1. Create the main window
    QWidget window;
    window.setWindowTitle("Ayurheal | Login");
    window.resize(900, 650);
    window.setMinimumSize(600, 500);

    // 2. Create the main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(&window);
    mainLayout->setAlignment(Qt::AlignCenter);
    mainLayout->setContentsMargins(30, 30, 30, 30);

    // 3. Create the login card
    QWidget *card = new QWidget();
    card->setObjectName("loginCard");
    card->setMaximumWidth(420);

    QVBoxLayout *cardLayout = new QVBoxLayout(card);
    cardLayout->setContentsMargins(40, 35, 40, 35);
    cardLayout->setSpacing(14);

    // 4. App name
    QLabel *appName = new QLabel("Ayurheal");
    appName->setObjectName("appName");
    appName->setAlignment(Qt::AlignCenter);

    // 5. Welcome heading and subtitle
    QLabel *heading = new QLabel("Welcome back");
    heading->setObjectName("heading");
    heading->setAlignment(Qt::AlignCenter);

    QLabel *subtitle = new QLabel(
        "Sign in to continue to your workspace"
    );
    subtitle->setObjectName("subtitle");
    subtitle->setAlignment(Qt::AlignCenter);
    subtitle->setWordWrap(true);

    // 6. Username input
    QLabel *usernameLabel = new QLabel("Username");

    QLineEdit *usernameInput = new QLineEdit();
    usernameInput->setPlaceholderText("Enter your username");
    usernameInput->setMinimumHeight(42);

    // 7. Password input
    QLabel *passwordLabel = new QLabel("Password");

    QLineEdit *passwordInput = new QLineEdit();
    passwordInput->setPlaceholderText("Enter your password");
    passwordInput->setEchoMode(QLineEdit::Password);
    passwordInput->setMinimumHeight(42);

    // 8. Show/hide password checkbox
    QCheckBox *showPassword = new QCheckBox("Show password");

    QObject::connect(
        showPassword,
        &QCheckBox::toggled,
        [passwordInput](bool checked) {
            passwordInput->setEchoMode(
                checked
                    ? QLineEdit::Normal
                    : QLineEdit::Password
            );
        }
    );

    // 9. Login button
    QPushButton *loginButton = new QPushButton("Log in");
    loginButton->setObjectName("loginButton");
    loginButton->setMinimumHeight(46);
    loginButton->setCursor(Qt::PointingHandCursor);

    // 10. Handle login button clicks
    QObject::connect(
        loginButton,
        &QPushButton::clicked,
        [&window, usernameInput, passwordInput]() {
            QString username = usernameInput->text().trimmed();
            QString password = passwordInput->text();

            if (username.isEmpty() || password.isEmpty()) {
                QMessageBox::warning(
                    &window,
                    "Missing information",
                    "Please enter both your username and password."
                );
                return;
            }

            QMessageBox::information(
                &window,
                "Login",
                "The fields are filled in!\n"
                "Real authentication has not been implemented yet."
            );
        }
    );

    // 11. Arrange all components in the login card
    cardLayout->addWidget(appName);
    cardLayout->addSpacing(8);
    cardLayout->addWidget(heading);
    cardLayout->addWidget(subtitle);
    cardLayout->addSpacing(12);
    cardLayout->addWidget(usernameLabel);
    cardLayout->addWidget(usernameInput);
    cardLayout->addWidget(passwordLabel);
    cardLayout->addWidget(passwordInput);
    cardLayout->addWidget(showPassword);
    cardLayout->addSpacing(8);
    cardLayout->addWidget(loginButton);

    // 12. Add the card to the main window
    mainLayout->addWidget(card, 0, Qt::AlignCenter);

    // 13. Style the application
    window.setStyleSheet(R"(
        QWidget {
            font-family: "Segoe UI";
            color: #263b32;
        }

        QWidget#loginCard {
            background-color: white;
            border-radius: 16px;
        }

        QLabel#appName {
            color: #34785a;
            font-size: 27px;
            font-weight: bold;
        }

        QLabel#heading {
            font-size: 24px;
            font-weight: bold;
        }

        QLabel#subtitle {
            color: #78857e;
            font-size: 13px;
        }

        QLineEdit {
            border: 1px solid #d6dfd9;
            border-radius: 7px;
            padding: 0 12px;
            background-color: #ffffff;
            font-size: 14px;
        }

        QLineEdit:focus {
            border: 2px solid #438665;
        }

        QCheckBox {
            color: #64736a;
            spacing: 8px;
        }

        QPushButton#loginButton {
            background-color: #34785a;
            color: white;
            border: none;
            border-radius: 7px;
            font-size: 15px;
            font-weight: bold;
        }

        QPushButton#loginButton:hover {
            background-color: #286447;
        }

        QPushButton#loginButton:pressed {
            background-color: #204f38;
        }
    )");

    // Set the background color of the main window
    window.setStyleSheet(
        window.styleSheet() +
        " QWidget#loginCard {"
        " background-color: white;"
        " }"
        " QWidget {"
        " background-color: #f1f5f1;"
        " }"
        " QWidget#loginCard QWidget {"
        " background-color: transparent;"
        " }"
    );

    // 14. Display the window
    window.show();

    return app.exec();
}