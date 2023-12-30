// CPP program to implement hashing with chaining
#include<bits/stdc++.h>
#include<math.h>
#include<string>
using namespace std;

class Hash
{
	int BUCKET; // No. of buckets

	// Pointer to an array containing buckets
	list<string> *table;
public:
	Hash(int V); // Constructor

	// inserts a key into hash table
	void insertItem(string x);

	// deletes a key from hash table
	void deleteItem(string key);

	// hash function to map values to key
	int hashFunction(string x) {
	    int stringLength = x.length();
	    long int hashValue = 0;
        for (int i = 0; i < stringLength; i++)
            hashValue += x[stringLength - i - 1] * pow(37, i);
        hashValue = hashValue % 7;
        return hashValue;
	}

	void displayHash();
};

Hash::Hash(int b)
{
	this->BUCKET = b;
	table = new list<string>[BUCKET];
}

void Hash::insertItem(string key)
{
	int index = hashFunction(key);
	table[index].push_back(key);
}

void Hash::deleteItem(string key)
{
// get the hash index of key
int index = hashFunction(key);

// find the key in (index)th list
list <string> :: iterator i;
for (i = table[index].begin();
		i != table[index].end(); i++) {
	if (*i == key)
	break;
}

// if key is found in hash table, remove it
if (i != table[index].end())
	table[index].erase(i);
}

// function to display hash table
void Hash::displayHash() {
for (int i = 0; i < BUCKET; i++) {
	cout << i;
	for (auto x : table[i])
	cout << " --> " << x;
	cout << endl;
}
}

// Driver program
int main()
{
// array that contains keys to be mapped
string a[] = {"data", "ali", "play", "stop", "key"};
int n = sizeof(a)/sizeof(a[0]);

// insert the keys into the hash table
Hash h(7); // 7 is count of buckets in
			// hash table
for (int i = 0; i < n; i++)
	h.insertItem(a[i]);

// delete 12 from hash table
h.deleteItem("stop");

// display the Hash table
h.displayHash();

return 0;
}
