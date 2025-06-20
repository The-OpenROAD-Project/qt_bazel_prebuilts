
#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv); // Create a QApplication object

    QWidget window; // Create a basic QWidget (the main window)
    window.setWindowTitle("My Simple Qt App"); // Set the window title
    window.show(); // Show the window

    return app.exec(); // Start the event loop and return when it exits
}
