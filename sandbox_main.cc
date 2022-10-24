#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::find;
using std::remove;
using std::map;

namespace sandbox{
    class Bottle {
        string title;
        string description;
        double volume;

        public:
            Bottle(string t, string d, double v): title(t), description(d), volume(v){}
            string& getTitle(){
                return title;
            }
            void setTitle(string t){
                title = t;
            }
            string& getDesc(){
                return description;
            }
            void setDesc(string d){
                description = d;
            }
            double getVolume(){
                return volume;
            }
            void setVolume(double d){
                volume = d;
            }
            void printDetails(){
                cout << "Title: " << title << endl;
                cout << "Description: " << description << endl;
                cout << "Volume:  " << volume << endl;
            }
    };
}

using sandbox::Bottle;

bool isShorter (const string& lhs, const string& rhs){
    return lhs.size() < rhs.size();
}

int func(const int& y){
    cout << "Address of y is: " << &y << endl;
    return y;
}

void printStrVec(const vector<string> v){
    for(auto i : v){
        cout << i << ", ";
    }
}

void showMessage(string val){
    cout << endl << val << endl;
}

void printIntVec(const vector<int> v){
    for(auto i : v){
        cout << i << ", ";
    }
}

struct Compare {
    std::string str;
    Compare(const std::string& str) : str(str) {}
};
bool operator==(const std::pair<int, std::string>&p, const Compare& c) {
    return c.str == p.second;
}
bool operator==(const Compare& c, const std::pair<int, std::string>&p) {
    return c.str == p.second;
}


void printMultiMap(const std::pair<string, int>& score){
    cout << "Score: " << score.first << ", " << score.second << endl;
}

int main(){
    int x = 2;
    cout << "Address of x is: " << &x << endl;
    int z = func(x);
    cout << "Address of z is: " << &z << endl;
    const char* helloWorld = "Hello World";
    cout << helloWorld << endl;
    std::string title("Introduction to C++ programming");
    cout << "Number of chars in title: " << title.size()  << endl;
    cout << title << std::endl;
    vector<int> vals {1,2,3,4,5,10,12,14};
    for(auto val : vals){
        cout << val <<  endl;
    }
    Bottle bottle1("Innocent Juice", "Highest Quality", 900);
    bottle1.printDetails();

    string test("Adam Howard");
    string::iterator start = test.begin();

    while(start !=  test.end()){
        cout << *start << endl;
        start++;
    }
    start = test.begin();
    cout << "Iterator in for loop: " << endl;
    for(start; start != test.end(); start++ ){
        cout << *start;
    }
    cout <<endl;
    vector<int> series  = {1, 3, 5, 7, 9, 11};

    auto it = series.begin();
    cout << "Auto deduced iterator: " << endl;
    for(it; it != series.end();++it){
        cout <<*it<< ",";
    }
    cout << endl << "Reverse iterator" << endl;
    auto rit = series.rbegin();
    for(rit; rit != series.rend();++rit){
        cout <<*rit<< ",";
    }
    cout << endl << "Const Reverse iterator" << endl;
    auto crit = series.crbegin();
    for(crit; crit != series.crend();++crit){
        if(crit == (series.crend() - 1)){
            cout <<*crit;
        }else{
            cout <<*crit<< ",";
        }
    
    }
    cout << endl << "Increment each element in series: " << endl;
    for(auto& elem : series){
        ++elem;
        cout << elem;
    }
    cout << endl << "C++17 local if scope variable declartion: " << endl;
    if(auto iter = begin(series); iter != end(series)){
        cout << "First elem of series is: " << *iter << endl;
    }
    
    string firstName("Adam");
    string lastName("Howard");

    cout<< "String concatenation: ";
    string together = firstName + lastName;
    cout << endl << together << endl;
    cout << "Substring: " << together.substr(4) << endl;

    cout << "return index of first occurance find('a'): " << endl;
    cout << together.find('a') << endl;
    cout << "return index of first occurance find('A'): " << endl;
    cout << together.find('A') << endl;


    ifstream ifile{"output.txt"};
   
    if(ifile){
        string content;
        cout << "There is a file" << endl;
        while(ifile >> content){
            cout << content << ", "; 
        }
        cout << endl;
        ifile.close();
    }
    cout << "Second file stream. " << endl; 
    ifstream ifile2{"output.txt"};
    string text;
    if(ifile2){
        while(std::getline(ifile2, text)){
            cout << text << endl;
        }
    }

    ofstream ofile("op.txt");

    if(ofile){
        cout << "There is a ofile. "<< endl;
        ofile << together <<endl;
        ofile.close();
    }

    vector<string> names = {"Jim", "Michael", "Mary", "Darren", "James", "Adam"};
    cout <<  "Before sorting" << endl << endl;
    for(auto name: names){
        cout  <<  name  <<", "<<endl;
    }

    std::sort(std::begin(names), std::end(names));
    cout <<  "After sorting" << endl << endl;
    for(auto name: names){
        cout  <<  name  <<", "<<endl;
    }

     vector<string> namesLength = {"Jim", "Michael", "Mary", "Darren", "James", "Adam"};
    cout <<  "Before sorting by length" << endl << endl;
    for(auto name: namesLength){
        cout  <<  name  <<", "<<endl;
    }

    std::sort(std::begin(namesLength), std::end(namesLength), isShorter);
    cout <<  "After sorting by length" << endl << endl;
    for(auto name: namesLength){
        cout  <<  name  <<", "<<endl;
    }

    vector<int> ages  = {44,31, 90, 54, 82, 12, 59, 23, 44};

    auto firstOdd   =  std::find_if(std::cbegin(ages), std::cend(ages),  
    [](int n){return (n % 2 == 1);}
    );

  
    if(firstOdd  !=  std::cend(ages))
        cout << "First odd element is: " << *firstOdd << endl;

    auto i = ages.begin(), end = ages.end();

    vector<int> odds;
    while(i != end){
        i = std::find_if(i, end, [](int n){return (n % 2 == 1);});
      
        if(i != end)
            odds.push_back(*i++);
        
    }

    for(auto odd : odds){
        cout << odd << endl;
    }

    showMessage("Using print function int vector: ");

    printIntVec(ages);

    auto ri = remove(std::begin(ages), std::end(ages), 44);
    ages.erase(ri, std::end(ages));
    showMessage("Remove 44 int: ");

    printIntVec(ages);

    auto removeEven = std::remove_if(std::begin(ages), std::end(ages), [](int i){ return (i % 2 == 0); });
    ages.erase(removeEven, std::end(ages));
    showMessage("Print after remove even ages: ");
    printIntVec(ages);

    map<int, string> employees;
    //Add entries using make_pair or an anonymous object
    employees.insert(std::make_pair(1, "Adam"));
    employees.insert({2, "Cian"});
    employees.insert(std::make_pair(3, "Adam"));
    employees.insert(std::make_pair(4, "Adam"));
    employees.insert(std::make_pair(5, "Cian"));
    cout<<endl;
    for(auto employee: employees){
        cout << employee.second << " Has ID " << employee.first<< endl;
    }
    for(auto [id, name]: employees){
        cout << name << " Has ID " << id << endl;
    }
    string countVal ("Adam");
    cout << "There are " << std::count(employees.begin(), employees.end(), Compare(countVal)) << " entries with value " << countVal <<endl;

    string countVal2 ("Cian");
    cout << "There are " << std::count(employees.begin(), employees.end(), Compare(countVal2)) << " entries with value " << countVal2 <<endl;

    auto [iter, success] =  employees.insert(std::make_pair(5, "Adam"));
    if(success){
        cout<<  "Successfully inserted new element."<<endl;
    } else  {
        auto [name, score] = *iter;
        cout << "Insert failed. "<<endl;
        cout << "Existing element with name " << name << " and score " << score << endl;
    }
    auto [iter2, success2] =  employees.insert(std::make_pair(6, "Adam"));
    if(success2){
        cout<<  "Successfully inserted new element."<<endl;
    } else  {
        auto [name, score] = *iter2;
        cout << "Insert failed. "<<endl;
        cout << "Existing element with name " << name << " and score " << score << endl;
    }

    auto [iter3, success3] = employees.insert_or_assign(5, "Adam");
     if(success3){
        cout<<  "Successfully inserted new element."<<endl;
    } else  {
        auto [id, name] = *iter3;
        cout << "Insert failed. "<<endl;
        cout << "Existing element with id " << id << " now has been assigned a name of " << name << endl;
    }

    for(auto employee: employees){
        cout << employee.second << " Has ID " << employee.first<< endl;
    }

    std::multimap<string, int> students;
    students.insert({"Mary", 66});
    students.insert({"Jim", 64});
    students.insert({"Mary", 44});
    students.insert({"Jacob", 87});
    students.insert({"Mary", 26});

    for(auto student: students){
        cout << student.first << " - " << student.second << endl;
    }

    auto mary_lower = students.lower_bound("Mary");
    auto mary_upper = students.upper_bound("Mary");

    for(auto it = mary_lower; it != mary_upper; ++it){
         printMultiMap(*it);
    }

    auto result = std::find_if(students.begin(), students.end(), [](std::pair<string, int> p){return p.second == 64;});
    
    if(result != students.end()){
        auto [id, value] = *result;
        cout << id << endl;
        cout << "Found an element with key " << id << " and value " << value <<endl;
    }
        

    

    return 0;
}