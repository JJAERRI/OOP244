//Milestone 2
//Name: Chaerin Yoo
//Seneca Email: cyoo10@myseneca.ca
//ID: 102998234
//Date: 2024-07-08
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "LibApp.h"
#include <iostream>
using namespace std;

namespace seneca {
    LibApp::LibApp()
        : m_changed(false),
        m_mainMenu("Seneca Library Application\n"),
        m_exitMenu("Changes have been made to the data, what would you like to do?\n")
    {
        m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";

        load();
    }

    bool LibApp::confirm(const char* message) {
        Menu confirmMenu(message);
        confirmMenu << "Yes";
        return confirmMenu.run() == 1;
    }

    void LibApp::load() {
        cout << "Loading Data" << endl;
    }

    void LibApp::save() {
        cout << "Saving Data" << endl;
    }

    void LibApp::search() {
        cout << "Searching for publication" << endl;
    }

    void LibApp::returnPub() {
        search();
        cout << "Returning publication" << endl;
        cout << "Publication returned\n" << endl;
        m_changed = true;
    }

    void LibApp::newPublication() {
        cout << "Adding new publication to library" << endl;
        if (confirm("Add this publication to library?\n")) {
            m_changed = true;
            cout << "Publication added\n" << endl;
        }
        cout << "\n";
    }

    void LibApp::removePublication() {
        cout << "Removing publication from library" << endl;
        search();
        if (confirm("Remove this publication from the library?\n")) {
            m_changed = true;
            cout << "Publication removed\n" << endl;
        }
    }

    void LibApp::checkOutPub() {
        search();
        if (confirm("Check out publication?\n")) {
            m_changed = true;
            cout << "Publication checked out\n" << endl;
        }
    }

    void LibApp::run() {
        bool done = false;
        while (!done) {
            unsigned int selection = m_mainMenu.run();
            switch (selection) {
            case 1: newPublication(); break;
            case 2: removePublication(); break;
            case 3: checkOutPub(); break;
            case 4: returnPub(); break;
            case 0:
                if (m_changed) {
                    unsigned int exitSelection = m_exitMenu.run();
                    if (exitSelection == 1) {
                        save();
                        done = true;
                    }
                    else if (exitSelection == 0) {
                        if (confirm("This will discard all the changes are you sure?\n")) {
                            done = true;
                        }
                    }
                    else {
                        cout << "\n";
                    }
                }
                else {
                    done = true;
                }
                break;
            }
        }
        cout << "\n-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
    }
}
