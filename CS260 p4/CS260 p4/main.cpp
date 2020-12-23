#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

class GradeBook {
private:
    double grades[100];
    int classSize;
    
public:
    GradeBook();
    GradeBook(int, double [100]);
    GradeBook(bool);
    void printAll();
    bool linearSearch(double);
    bool binarySearch(double);
    double absoluteMin();
    double absoluteMax();
    double minButGreaterThan(double);
    double maxButLessThan(double);
    double classAverage();
    void bubbleSort();
    void selectionSort();
    void enterGrades();
    void sizeUsingFile();
    void usingFile();
};

int main() {
    GradeBook gradebook;
    
label1: int choice = 0;
    cout<<endl;
    cout<<"1) Enter grades manually"<<endl;
    cout<<"2) Enter grades using file “Grades.txt”"<<endl;
    cout<<"3) Enter grades using file “Grades.txt”"<<endl;
    cout<<"4) Print All Grades"<<endl;
    cout<<"5) Search for a grade using sequential search"<<endl;
    cout<<"6) Search for a grade using binary search"<<endl;
    cout<<"7) Sort Grades in descending order using bubble sort"<<endl;
    cout<<"8) Sort Grades in ascending order using selection sort"<<endl;
    cout<<"9) Get maximum grade"<<endl;
    cout<<"10) Get minimum grade"<<endl;
    cout<<"11) Get class average"<<endl;
    cout<<"12) Exit"<<endl;
    
    cin>>choice;
    
    double grade = 0;

    switch (choice) {
            
        case 1:
            gradebook.enterGrades();
            goto label1;
        case 2:
            gradebook.sizeUsingFile();
            goto label1;
        case 3:
            gradebook.usingFile();
            goto label1;
        case 4:
            gradebook.printAll();
            goto label1;
        case 5:
            cout<<"Entert the grade plz."<<endl;
            cin>>grade;
            gradebook.linearSearch(grade);
            goto label1;
        case 6:
            cout<<"Entert the grade plz."<<endl;
            cin>>grade;
            gradebook.binarySearch(grade);
            goto label1;
        case 7:
            gradebook.bubbleSort();
            goto label1;
        case 8:
            gradebook.selectionSort();
            goto label1;
        case 9:
            cout<<"Max is: "<<gradebook.absoluteMax()<<endl;
            goto label1;
        case 10:
            cout<<"Min is: "<<gradebook.absoluteMin()<<endl;
            goto label1;
        case 11:
            cout<<"Average is: "<<gradebook.classAverage()<<endl;
            goto label1;
        case 12:
            return 0;
            break;

    }
    return 0;
}

GradeBook::GradeBook() {
    classSize = 0;
}
GradeBook::GradeBook(int a, double grades[]) {
    classSize = a;
    grades[classSize];
}
GradeBook::GradeBook(bool sizeIncludedInFile) {
    ifstream myfile;
    if (sizeIncludedInFile==true) {
        myfile.open("Grades.txt");
        myfile>>classSize;
        myfile.close();
    } else {
        cin>>classSize;
    }
}
void GradeBook::printAll() {
    cout<<"Start printing all grades."<<endl;
    for(int i=0;i<classSize;i++) {
        cout<<grades[i]<<"\t";
    }
}
bool GradeBook::linearSearch(double grade) {
    int i;
    for(i=0;i<classSize;i++) {
        if(grades[i]==grade) {
            cout<<"grades["<<i<<"] has the grade."<<endl;
            break;
        }
    }
    
    if(grades[i]==grade) {
        return true;
    } else {
        return false;
    }
}
bool GradeBook::binarySearch(double grade) {
    selectionSort();// ascending order
    double low = 0, high = classSize-1; int middle = (int)((low+high) /2);
    while (low<=high) {
        if(grades[middle]==grade) {
            cout<<"grades["<<middle<<"] has the grade."<<endl;
            break;
        } else if(grades[middle]>grade) {
            cout<<"grades[middle]>grade"<<endl;
            high = middle - 1;
            middle = (int)((low+high) /2);
        } else if(grades[middle]<grade) {
            cout<<"grades[middle]<grade"<<endl;
            low = middle + 1;
            middle = (int)((low+high) /2);
        } else {
            cout<<"Can't find."<<endl;
        }
        if(low>high) {
            cout<<"Can't find."<<endl;
            break;
        }
    }
    
    if (grades[middle]==grade) {
        return true;
    } else {
        return false;
    }
    
}
double GradeBook::absoluteMin() {
    double absoluteMin = grades[0];
    for(int i=0; i<classSize; i++) {
        if(grades[i]<absoluteMin) {
            absoluteMin = grades[i];
        }
    }
    return absoluteMin;
}
double GradeBook::absoluteMax() {
    double absoluteMax = grades[0];
    for(int i=0; i<classSize; i++) {
        if(grades[i]>absoluteMax) {
            absoluteMax = grades[i];
        }
    }
    return absoluteMax;
}
double GradeBook::minButGreaterThan(double grade) {
    double minButGreaterThan = 0;
    for(int i=0;i<classSize;i++) {
        if((grades[i]>grade)&&(grades[i]<grades[i+1])) {
            minButGreaterThan = grades[i];
        }
    }
    return minButGreaterThan;
}
double GradeBook::maxButLessThan(double grade) {
    double maxButLessThan = 0;
    for(int i=0;i<classSize;i++) {
        if((grades[i]<grade)&&(grades[i]>grades[i+1])) {
            maxButLessThan = grades[i];
        }
    }
    return maxButLessThan;
}
double GradeBook::classAverage() {
    double sum = 0, classAverage = 0;
    for(int i=0;i<classSize;i++) {
        sum += grades[i];
    }
    classAverage = (sum/classSize);
    return classAverage;
}
void GradeBook::bubbleSort() {
    cout<<"Start bubble sort (descending oreder)."<<endl;
    for(int i=0;i<classSize-1;i++) {
        for(int j=0;j<classSize-1;j++) {
            if(grades[j]<grades[j+1]) {
                swap(grades[j], grades[j+1]);
            }
        }
    }
    for(int i=0;i<classSize;i++) {
        cout<<grades[i]<<"\t";
    }
    cout<<endl;
}
void GradeBook::selectionSort() { // ascending order.
    cout<<"Start selection sort (ascending order)."<<endl;
    int min = 0;
    for(int i=0;i<classSize-1;i++) {
        min = i;
        for(int j=i+1;j<classSize;j++) {
            if(grades[j]<grades[min]) {
                min = j;
            }
        }
        if(min!=i) {
            swap(grades[i], grades[min]);
        }
    }
    for(int i=0; i<classSize;i++) {
        cout<<grades[i]<<"\t";
    }
    cout<<endl;
}
void GradeBook::enterGrades() {
    cout<<"Enter a students number."<<endl;
    cin>>classSize;
    for(int i=0;i<classSize;i++) {
        cout<<"Enter the "<<i<<"'s grades: ";
        cin>>grades[i];
        cout<<endl;
    }
}
void GradeBook::sizeUsingFile() {
    ifstream myfile;
    int classSize = 0, i=0;
    myfile.open("Grades.txt");
    myfile>>classSize;
    while(!myfile.eof()) {
        myfile>>grades[i];
        i++;
    }
    myfile.close();
}
void GradeBook::usingFile() {
    ifstream myfile;
    int i=0;
    myfile.open("Grades.txt");
    while(!myfile.eof()) {
        myfile>>grades[i];
        i++;
    }
    myfile.close();
}
