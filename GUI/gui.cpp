#include "gui.h"
#include "ai.hpp"

bool* Ui_MainWindow::train = new bool;
bool* Ui_MainWindow::run = new bool;
bool* Ui_MainWindow::debug = new bool;
int* Ui_MainWindow::limit = new int {20};

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "russian");

    CLI::App app{"CLI tool to train TextChain Markov models"};
    int contextSize = 1;
    *Ui_MainWindow::train = false;
    *Ui_MainWindow::run = false;
    *Ui_MainWindow::debug = false;
    std::string fileName = "";
    app.add_option("-l, --limit", *Ui_MainWindow::limit, "Maximal answer length, default = 20")->check(CLI::PositiveNumber);
    app.add_option("-s, --contextsize", contextSize, "Context size for model")->check(CLI::NonNegativeNumber);
    app.add_option("-f, --trainfile", fileName, "String data file for training model" );
    app.add_flag("-r, --run", *Ui_MainWindow::run, "Run the model");
    app.add_flag("-t, --train", *Ui_MainWindow::train, "Train the model, required to set file name and context size.");
    app.add_flag("-d, --debug", *Ui_MainWindow::debug, "Enable debug messages");
    CLI11_PARSE(app, argc, argv);

    if(*Ui_MainWindow::train) {
        ai::Train(fileName, contextSize);
        return 0;
    } else if(*Ui_MainWindow::run){
        QApplication app(argc, argv);
        QMainWindow main;
        Ui_MainWindow root;
        root.setupUi(&main);
        main.show();
        return app.exec();
    } else {
        std::cout << "Not chosen option" << std::endl;
        return 0;
    }
}

void Ui_MainWindow::ButtonClicked() {
    std::string task;
    bool prompt;
    if(radioButton->isChecked()){
        if(*debug) std::cout << "Debug: Btn 1(prompt) checked" << std::endl;
        prompt = true;
    }

    if(radioButton_2->isChecked()){
        if(*debug) std::cout << "Debug: Btn 2(ask) checked" << std::endl;
        prompt = false;
    }

    if(prompt){
        QFileDialog fileDialog;
        fileDialog.setWindowTitle("Read file");
        fileDialog.setNameFilter(tr("Text files (*.txt)"));
        QString filePath = fileDialog.getOpenFileName();
        if(!filePath.isEmpty()) {
            QFile file(filePath);
            if(file.open(QIODevice::ReadOnly)) {
                QTextStream read (&file);
                task = read.readAll().toStdString();
                file.close();
                if(*debug) std::cout << "DebugText: " << task << std::endl;
            } else {
                std::cout << "Error opening file" << std::endl;
                QMessageBox::critical(nullptr, "Error", "Could not open file!");
            }
        } else {
            std::cout << "File not chosen" << std::endl;
        }
    } else {
        task = QString(textEdit->toPlainText()).toStdString();
        if(*debug) std::cout << "DebugText: " << task << std::endl;
    }

    if(!task.empty()) {
        std::string answer;
        ai::RunAi(task, answer, *Ui_MainWindow::limit);
        QMessageBox::information(nullptr, "Answer", QString::fromStdString(answer));
        std::cout << "DebugAnswer: " << answer << std::endl;
    } else {
        std::cout << "Debug: no answer" << std::endl;
    }
}