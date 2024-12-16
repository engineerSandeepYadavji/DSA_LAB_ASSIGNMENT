#include <bits/stdc++.h>
using namespace std ;

struct Student{
    int rollNo;
    string name;
    double sgpa;
    Student(int rollNo, string name, double sgpa){
        this->rollNo = rollNo ;
        this->name = name ;
        this->sgpa = sgpa ;
    }
};

void menue(){
     cout<<"--------------------------------------------------------------------------------------"<<endl;
    cout<<"Enter your choice from the given MENU  " <<endl;
    cout<<"Case 1 : Add details of a Student : "<<endl;
    cout<<"Case 2 : search for CGPA " <<endl;
    cout<<"Case 3 : Sort the details on basis of roll no ( bubble sort) "<<endl;
    cout<<"Case 4 : Sort the details on the basis of name (insertion sort) " << endl;
    cout<<"Case 5 : Search name using (Binary Search) "<<endl; 
    cout<<"Case 6 : Sort the details on the basis of sgpa using quick sort (TOP 10 STUDNETS ) " << endl;
    cout<<"Press any other digit to EXIT the program " <<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<"YOUR CHOICE : " ;
}

void add(vector<Student>&Students){
    int rollNo ;
    string name;
    double sgpa;
    cout<<"Roll no : "; cin>>rollNo ;
    cout<<"Name : "; cin>>name ;
    cout<<"SGPA : "; cin>>sgpa ;
    Students.push_back(Student(rollNo,name,sgpa)) ;
}

void searchSgpa(vector<Student>&Students){
    double sgpa;
    cout<<"Enter sgpa to be search : "; cin>>sgpa ;
    bool flag = true ;
    for(int i=0 ; i<Students.size() ; i++ ){
        if((Students[i].sgpa) == sgpa ){
            if(flag){
                flag= false ;
                cout<<"RollNO\tName\tSGPA"<<endl;
            }
            cout<<(Students[i].rollNo)<<"\t"<<(Students[i].name)<<"\t"<<(Students[i].sgpa)<<endl; 
        }
    }
    if(flag) cout<<"NO SUCH RECORD FOUND"<<endl; 
}

void display(vector<Student>&Students, int noOfStudents ){
    if(Students.size()==0){
        cout<<"DataBase is Empty"<<endl ;
        return ;
    }
    cout<<"RollNO\tName\tSGPA"<<endl;
    for(int i=0 ; i<noOfStudents ; i++ ){
        cout<<(Students[i].rollNo)<<"\t"<<(Students[i].name)<<"\t"<<(Students[i].sgpa)<<endl;
    }
}

void sortRollNo(vector<Student>&Students){
    for(int i=0 ; i<Students.size()-1 ; i++ ){
        for(int j=0 ; j<Students.size()-i-1 ; j++ ){
            if(Students[j].rollNo > Students[j+1].rollNo){
                swap(Students[j],Students[j+1]) ;
            }
        }
    }
    display(Students,Students.size()) ;
}

string lowerCase(string str){
    for(char &ch : str){
        ch = (char)tolower(ch) ;
    }
    return str;
}

void sortName(vector<Student>&Students){
    for(int i=1; i<Students.size() ; i++ ){
        int j=i-1 ;
        Student key = Students[i] ;
        while(j>=0 && lowerCase(Students[j].name)>lowerCase(key.name)) {
            Students[j+1] = Students[j] ;
            j-- ;
        }
        Students[j+1] = key;
    }
    display(Students,Students.size()) ;
}

void searchName(vector<Student>&Students){
    string key; 
    cout<<"Enter the name to be search : " ; cin>>key ;
    sortName(Students) ;
    int lo=0, hi=Students.size()-1 , idx=-1;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2 ;
        if(lowerCase(Students[mid].name) > lowerCase(key)){
            hi=mid-1 ;
        }
        else if(lowerCase(Students[mid].name) == lowerCase(key)){
            idx=mid ;
            hi=mid-1 ;
        }
        else{
            lo=mid+1 ;
        }
    }
    if(idx==-1){
        cout<<"No SUCH RECORD FOUND"<<endl; 
        return ;
    }
    cout<<"RollNO\tName\tSGPA"<<endl;
    while(idx<Students.size() && lowerCase(Students[idx].name) == lowerCase(key) ){
        cout<<(Students[idx].rollNo)<<"\t"<<(Students[idx].name)<<"\t"<<(Students[idx].sgpa)<<endl;
        idx++ ;
    }
}

int partition(vector<Student>&Students, int lo, int hi ){
    double pivot = Students[lo].sgpa ;
    int i=lo , j=hi ;

    while(i<=j ){
        while(i<hi && Students[i].sgpa >= pivot ) i++ ;
        while(j>lo && Students[j].sgpa < pivot  ) j-- ;
        if(i<j) swap(Students[i],Students[j]) ;
    }
    if(j>lo) swap(Students[j],Students[lo]) ;
    return j ;
}

void quickSort(vector<Student>&Students, int lo, int hi ){
    if(lo>=hi) return ;
    int pi = partition(Students,lo,hi);
    quickSort(Students, lo,pi-1);
    quickSort(Students,pi+1,hi) ;
}

void sortSgpa(vector<Student>&Students){
    quickSort(Students,0,Students.size()-1) ;
    display(Students,min(10,(int)Students.size())) ;
}

int main(){
    vector<Student>Students ;
    int choice ;
    do{
        menue() ; cin>>choice ;
        switch (choice)
        {
        case 1:
            add(Students) ;
            break;
        case 2:
            searchSgpa(Students) ;
            break;
        case 3:
            sortRollNo(Students) ;
            break ;
        case 4:
            sortName(Students) ;
            break;
        case 5:
            searchName(Students) ;
            break;
        case 6:
            sortSgpa(Students) ;
            break;
        default:
            break;
        }

    }while(choice<=6 &&  choice>=1) ;

    cout<<"PROGRAM EXCITTED SUCCESSFULLY :)" <<endl ;
    return 0 ;
}