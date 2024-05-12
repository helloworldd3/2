/*Example of Output
Software
--------
Dev-C++
RStudio

Enter 2 software
adobe
microsoft

Software : Pointer of object call
Enter 2 software
android
linux

Hardware
--------
laptop
mouse

Enter 2 hardware
desktop
printer

Hardware:Array of object call
Enter 2 hardware
cable
scanner

Enter 2 hardware
bluetooth
pendrive

Hardware:Copy constructor
mouse pad
headset

Destructor call
desktop and printer are destroyed from hardware
bluetooth and pendrive are destroyed from hardware
cable and scanner are destroyed from hardware
mouse pad and headset are destroyed from hardware
android and linux are destroyed from software
python and matlab are destroyed from software*/


#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Software {
private:
    string name;

public:
    Software() : name("") {}
    Software(const string& n) : name(n) {}
    Software(const Software& other) : name(other.name) {}
    ~Software() {
        cout << name << " is destroyed from software" << endl;
    }
    void setName(const string& n) {
        name = n;
    }
    string getName() const {
        return name;
    }
    friend ostream& operator<<(ostream& os, const Software& s);
    friend istream& operator>>(istream& is, Software& s);
};

ostream& operator<<(ostream& os, const Software& s) {
    os << s.name;
    return os;
}

istream& operator>>(istream& is, Software& s) {
    is >> s.name;
    return is;
}

class Hardware {
private:
    char name[20];

public:
    Hardware() {
        name[0] = '\0';
    }
    Hardware(const char* n) {
        strncpy(name, n, sizeof(name));
    }
    Hardware(const Hardware& other) {
        strncpy(name, other.name, sizeof(name));
    }
    ~Hardware() {
        cout << name << " is destroyed from hardware" << endl;
    }
    void setName(const char* n) {
        strncpy(name, n, sizeof(name));
    }
    const char* getName() const {
        return name;
    }
    friend ostream& operator<<(ostream& os, const Hardware& h);
    friend istream& operator>>(istream& is, Hardware& h);
};

ostream& operator<<(ostream& os, const Hardware& h) {
    os << h.name;
    return os;
}

istream& operator>>(istream& is, Hardware& h) {
    is >> h.name;
    return is;
}

void getData(Software& s, Hardware& h) {
    cout << "Enter 2 software: ";
    cin >> s;
    cout<<endl;
    cout << "Enter 2 hardware: ";
    cin >> h;
}

int main() {
    cout << "Software\n--------" << endl;
    cout << "Dev-C++\nRStudio\n" << endl;

    // Using pointer to create a software object
    
    Software* softwarePtr = new Software();
    Hardware* hardwarePtr = new Hardware();
    getData(*softwarePtr, *hardwarePtr);
    cout << "\nSoftware : Pointer of object call" << endl;
    getData(*softwarePtr, *hardwarePtr);

    // Using array to create hardware objects
    cout << "\nHardware\n--------" << endl;
    cout << "laptop\nmouse" << endl;
    cout << "Enter 2 hardware" << endl;
    Hardware hardwareArr[2] = {Hardware("laptop"), Hardware("mouse")};
    getData(*softwarePtr, hardwareArr[0]);
    cout << "\nHardware:Array of object call" << endl;
    getData(*softwarePtr, hardwareArr[0]);
    cout << "\nEnter 2 hardware" << endl;
    getData(*softwarePtr, hardwareArr[0]);

    // Destructor call
    delete softwarePtr;

    return 0;
}
