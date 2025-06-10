#include <iostream>
#include <set>

using namespace std;

// Template function to print set elements

void printSet(const set<int>& s) {
    for (const auto& i : s) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    set<int> s;
    s.insert(1);
    s.insert(6);
    s.insert(1);
    s.insert(5);
    s.insert(2);

    set<int, greater<int>> s1;
    s1.insert(4);
    s1.insert(6);
    s1.insert(3);
    s1.insert(7);
    s1.insert(2);

    // Print size
    cout << "Size of s: " << s.size() << endl;

    // Print using printSet
    cout << "Elements in s (ascending): ";
    printSet(s);

    // Using iterator
    cout << "Using iterator: ";
    for (auto i = s.begin(); i != s.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;

    // Reverse print
    cout << "Reverse order: ";
    for (auto i = s.rbegin(); i != s.rend(); ++i) {
        cout << *i << " ";
    }
    cout << endl;

    // Remove element
    s.erase(5);
    cout << "After erasing 5: ";
    for (auto i = s.rbegin(); i != s.rend(); ++i) {
        cout << *i << " ";
    }
    cout << endl;

    // Clear set
    s.clear();
    cout << "After clearing s: ";
    printSet(s);

    // Descending order print (s1)
    cout << "Elements in s1 (descending): ";
    for(auto i= s1.begin();i!=s1.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    //again filling set as it has been cleared
    
    s.insert(1);
    s.insert(3);
    s.insert(5);
    s.insert(7);


    cout << "\nLower and Upper Bound in set<int> (ascending):\n";
    int key = 3;
    auto lb = s.lower_bound(key); // First element >= key
    auto ub = s.upper_bound(key); // First element > key

    cout << "Set: ";
    printSet(s);
    cout << "lower_bound(" << key << ") = ";
    if (lb != s.end()) cout << *lb << endl;
    else cout << "Not found\n";

    cout << "upper_bound(" << key << ") = ";
    if (ub != s.end()) cout << *ub << endl;
    else cout << "Not found\n";


    return 0;
}
