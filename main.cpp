#include <iostream>
#include <string>
#include <limits>
#include <sstream>
using namespace std;

/*
GROUP NAMES AND IDS:
FARIDA ASHRAF    221000407
FARIDA NASRAT    221000214
MARIEM AHMED     221000806
MENNA TAMER      221001541
*/

//function to ensure user does not enter string in int - complexity O(x)
int getIntegerInput(const string& prompt) {
    int number;

    while (true) {
        cout << prompt;
        if (cin >> number) {
            break; 
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer." << endl;
        }
    }

    return number;
}

//function to ensure user does not enter string in float - complexity O(x)
float getFloatInput(const string& prompt) {
    float number;

    while (true) {
        cout << prompt;
        if (cin >> number) {
            break; // Input is valid, break out of the loop
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a floating-point number." << endl;
        }
    }

    return number;
}


template <class T>
class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* right;
    Node<T>* left;

    Node(T e){ //complexity - O(1)
        data = e;
        next = right = left = NULL;
    }
};

class Supplier;

class SpareParts {
    private:
        string partName;
        int partNumber;
        float cost;
    public:
        SpareParts() : partName(""), partNumber(0), cost(0.0), supplierHead(nullptr) {} //complexity - O(1)
        SpareParts(string pn, int pnum, float c) : partName(pn), partNumber(pnum), cost(c), supplierHead(nullptr) {} //complexity - O(1)
        Node<Supplier>* supplierHead;

    // Setters - complexity O(1) per each
    void setPartName(string name) {
        partName = name;
    }

    void setPartNumber(int number) {
        partNumber = number;
    }

    void setCost(float mCost) {
        cost = mCost;
    }

    // Getters - complexity O(1) per each
    string getPartName() {
        return partName;
    }

    int getPartNumber() {
        return partNumber;
    }

    float getCost() {
        return cost;
    }

    //Function to return code by overriding - complexity O(1)
    int getKey(){
        return partNumber;
    }

    //Display part details - complexity O(1)
    void Display(){
        cout << "Display Part " << partNumber << " details" << endl;
        cout << "Part Name: " << partName << endl;
        cout << "Part Number: " << partNumber << endl;
        cout << "Part Cost: " << cost << endl;
        cout  << "------------------------" << endl;
    }

    void ModifyData(){ //complexity - O(1)
        cout << "Choose which data to modify: " << endl;
        cout << "1. Part Name" << endl;
        cout << "2. Part Cost"<< endl;
        cout  << "------------------------" << endl;
        int mChoice = getIntegerInput("");
        if(mChoice == 1){
            cout << "Enter new name: " << endl;
            string nn;
            cin>> nn;
            partName = nn;
        }
        else if(mChoice == 2){
            float nc = getFloatInput("Enter new cost: ");
            cost = nc;
        }
        else{
            cout << "Invalid Input." << endl;
            cout << "------------------------" << endl;
        }
    }

    // //Initiaize Insert all suppliers that supply this SparePart
    void addSupplierOfSparePart(Supplier e);

    // //initialize print function
    void printSuppliersOfSpareParts();
    
    //Initialize function to search all suppliers of spare parts
    Node<Supplier>* searchSuppliersOfSpareParts(int cd);

    //Initialize function to delete suppliers of spare part
    void deleteSuppliersOfSpareParts(int cd);
};

class Supplier {
    private:
        string supplierName, address, email;
        int supplierCode, telephone;

    public:
        Supplier() : supplierName(""), address(""), email(""), supplierCode(0), telephone(0), sparePartsHead(nullptr) {} //complexity O(1)
        Supplier(string sn, string ad, string e, int sc, int t)
        : supplierName(sn), address(ad), email(e), supplierCode(sc), telephone(t), sparePartsHead(nullptr)  {} //complexity O(1)

    // Setters- complexity O(1) per each
    void setSupplierName(string name) {
        supplierName = name;
    }

    void setAddress(string add) {
        address = add;
    }

    void setEmail(string mail) {
        email = mail;
    }

    void setSupplierCode(int code) {
        supplierCode = code;
    }

    void setTelephone(int phone) {
        telephone = phone;
    }

    // Getters- complexity O(1) per each
    string getSupplierName() {
        return supplierName;
    }

    string getAddress() {
        return address;
    }

    string getEmail() {
        return email;
    }

    int getSupplierCode() {
        return supplierCode;
    }

    int getTelephone() {
        return telephone;
    }

    int getKey(){
        return supplierCode;
    }

    //Display supplier details - complexity O(1)
    void Display(){
        cout << "Display supplier " << supplierCode << " details" << endl;
        cout << "Supplier Name: " << supplierName << endl;
        cout << "Supplier Address: " << address << endl;
        cout << "Supplier Email: " << email << endl;
        cout << "Supplier Code: " << supplierCode << endl;
        cout << "Supplier Telephone: " << telephone << endl;
        cout  << "------------------------" << endl;
    }

    //Modify Supplier detail - complexity O(1)
    void ModifyData(){
        cout << "Choose which data to modify: " << endl;
        cout << "1. Supplier Name" << endl;
        cout << "2. Supplier Address"<< endl;
        cout << "3. Supplier Email " <<  endl;
        cout << "4. Supplier Telephone " << endl;
        cout  << "------------------------" << endl;
        int mChoice;
        cin >> mChoice;
        if(mChoice == 1){
            cout << "Enter new name: " << endl;
            string nn;
            cin>> nn;
            supplierName = nn;
        }
        else if(mChoice == 2){
            cout << "Enter new address: " << endl;
            string nad;
            cin>> nad;
            address = nad;
        }
        else if(mChoice == 3){
            cout << "Enter new email: " << endl;
            string ne;
            cin>> ne;
            email = ne;
        }
        else if(mChoice == 4){
            int nt = getIntegerInput("Enter new telephone: ");
            telephone = nt;
        }
        else{
            cout << "Invalid Input." << endl;
            cout << "------------------------" << endl;
        }
    }

    //Insert all spareparts of this supplier - complexity O(n)
    Node<SpareParts>* sparePartsHead;
    void addSparePartOfSupplier(SpareParts e){
        Node<SpareParts>* newSupplier = new Node<SpareParts>(e);
        if (sparePartsHead == nullptr) {
            sparePartsHead = newSupplier;
        } else {
            Node<SpareParts>* temp = sparePartsHead;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newSupplier;
        }
    }

    //print function of spareparts of supplier - complexity O(n)
    void printSparePartOfSupplier(){
        cout << "Spare Parts of Supplier: " << endl;
        Node<SpareParts>* temp = sparePartsHead;
        while (temp != nullptr) {
            cout << "All Spare Parts added: " << endl;
            cout << "Part Name: " << temp->data.getPartName() << endl;
            cout << "Part Number: " << temp->data.getPartNumber() << endl;
            cout << "Cost: " << temp->data.getCost() << endl;
            cout << "------------------------" << endl;
            temp = temp->next;
        }
    }

    //search spare parts of supplier - complexity O(n)
    Node<SpareParts>* searchSparePartsOfSupplier(int cd){
        Node<SpareParts>* temp = sparePartsHead;
        while (temp != nullptr) {
            if(temp->data.getPartNumber() == cd){
                return temp;
            }

            temp = temp->next;
        }

        return NULL;
    }

    //delete spare part of supplier - complexity O(n)
    void deleteSparePartsOfSupplier(int cd) {
        Node<SpareParts>* current = sparePartsHead;
        Node<SpareParts>* prev = nullptr;

        while (current != nullptr) {
            if (current->data.getPartNumber() == cd) {
                if (prev == nullptr) {
                    sparePartsHead = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return; 
            }
        prev = current;
        current = current->next;
    }
}

};

    //add suppliers of spare part - complexity O(n)
    void SpareParts::addSupplierOfSparePart(Supplier e){
        Node<Supplier>* newSupplier = new Node<Supplier>(e);
        if (supplierHead == nullptr) {
            supplierHead = newSupplier;
        } else {
            Node<Supplier>* temp = supplierHead;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newSupplier;
        }
    }

    //print function of suppliers of sparepart - complexity O(n)
    void SpareParts::printSuppliersOfSpareParts(){
        cout << "Suppliers of Spare Part: " << endl;
        Node<Supplier>* temp = supplierHead;
        while (temp != nullptr) {
            cout << "Supplier Name: " << temp->data.getSupplierName() << endl;
            cout << "Supplier Address: " << temp->data.getAddress() << endl;
            cout << "Supplier Email: " << temp->data.getEmail() << endl;
            cout << "Supplier Code: " << temp->data.getSupplierCode()<< endl;
            cout << "Supplier Telephone: " << temp->data.getTelephone()<< endl;
            cout << "------------------------" << endl;
            temp = temp->next;
        }
    }

    //search for suppliers of spare part - complexity O(n)
    Node<Supplier>* SpareParts::searchSuppliersOfSpareParts(int cd){
        Node<Supplier>* temp = supplierHead;
        while (temp != nullptr) {
            if(temp->data.getSupplierCode() == cd){
                return temp;
            }

            temp = temp->next;
        }

        return NULL;
    }

    //delete supplier of spare part - complexity O(n)
    void SpareParts::deleteSuppliersOfSpareParts(int cd){
        Node<Supplier>* current = supplierHead;
        Node<Supplier>* prev = nullptr;

        while (current != nullptr) {
            if (current->data.getSupplierCode() == cd) {
                if (prev == nullptr) {
                    supplierHead = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return; 
            }
        prev = current;
        current = current->next;
    }        
    }

template <class T>
class BST {
public:
    Node<T>* root;

    BST() : root(nullptr) {} // complexity O(1)

    // complexity O(log(n))
    Node<T>* insert(Node<T>*& root, T v) { 
        Node<T>* newNode = new Node<T>(v);
        if (root == nullptr) {
            root = newNode;
            return root;
        } else if (v.getKey() < root->data.getKey()) {
            root->left = insert(root->left, v);
        } else {
            root->right = insert(root->right, v);
        }
        return root;
    }

    // complexity O(log(n))
    void inorder(Node<T>* root) {
        if (root == nullptr)
            return;
        inorder(root->left);
        root -> data.Display();

        inorder(root->right);
    }

    // complexity O(1*log(n))
    void insert(T &v) {
        root = insert(root, v);
    }

    // complexity O(1*log(n))
    void printInOrder() {
        inorder(root);
    }

    // complexity O(log(n))   
    Node<T>* search(Node<T>* root, int code) {
        if (root == nullptr || root->data.getKey() == code) {
            return root;
        }

        if (code < root->data.getKey()) {
            return search(root->left, code);
        } else {
            return search(root->right, code);
        }
    }

    // complexity O(1*log(n))
    Node<T>* searchByCode(int code) {
        return search(root, code);
    }

    // complexity O(log(n))
    bool deleteNode(Node<T>* &root, int code) {
        if (root == nullptr) {
            return false;
        }

        if (code < root->data.getKey()) {
            return deleteNode(root->left, code);
        } else if (code > root->data.getKey()) {
            return deleteNode(root->right, code);
        } else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                Node<T>* temp = root->right;
                delete root;
                root=temp;
                return true;
            } else if (root->right == nullptr) {
                Node<T>* temp = root->left;
                delete root;
                root=temp;
                return true;
            }

            Node<T>* temp = minValueNode(root->right);
            root->data = temp->data;

            return deleteNode(root->right, temp->data.getKey());
        }
        return true;
    }

    // complexity O(1*log(n))
    void deleteByCode(int code) {
        bool deleted = deleteNode(root, code);

    }

    // complexity O(log(n))
    Node<T>* minValueNode(Node<T>* node) {
        Node<T>* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
    Node<T>* modifyData(Node<T>* root, int code) {
        if (root == nullptr) {
            cout << "Not found. Cannot modify data." << endl;
            return nullptr;
        }

        if (code < root->data.getKey()) {
            root->left = modifyData(root->left, code);
        } else if (code > root->data.getKey()) {
            root->right = modifyData(root->right, code);
        } else {
            // Node found, modify the data
            root->data.ModifyData();
            cout << "Data modified." << endl;
        }

        return root;
    }
    void modify(int code) {
        root = modifyData(root, code);
    }

    //Function to traverse every node in supplier tree for the connected spare part spnum and modify it - complexity O(n+log(n))=O(n)
    void traverseSupplierTreeModify(Node<Supplier>* currentSupplier, int spnum, SpareParts modifiedSparePart) {
    if (currentSupplier == nullptr) {
        return;
    }

    Node<SpareParts>* supplierSparePart = currentSupplier->data.searchSparePartsOfSupplier(spnum);

    if (supplierSparePart != nullptr) {
        supplierSparePart->data = modifiedSparePart;
    }

    traverseSupplierTreeModify(currentSupplier->left, spnum, modifiedSparePart);
    traverseSupplierTreeModify(currentSupplier->right, spnum, modifiedSparePart);
}
    //Function to traverse every node in sparepart tree for the connected supplier sc and modify it - complexity O(n+log(n))=O(n)
    void traverseSparePartTreeModify(Node<SpareParts>* currentSparePart, int sc, Supplier modifiedSupplier) {
        if (currentSparePart == nullptr) {
        return;
    }

        Node<Supplier>* sparePartSupplier = currentSparePart->data.searchSuppliersOfSpareParts(sc);

        if (sparePartSupplier != nullptr) {
            sparePartSupplier->data  = modifiedSupplier;
        }

        traverseSparePartTreeModify(currentSparePart->left, sc, modifiedSupplier);
        traverseSparePartTreeModify(currentSparePart->right, sc, modifiedSupplier);
    }

    //Function to traverse every node in supplier tree for the connected spare part spnum and delete it - complexity O(n+log(n))=O(n)
    void traverseSupplierTreeDelete(Node<Supplier>* currentSupplier, int spnum) {
        if (currentSupplier == nullptr) {
            return;
        }

        Node<SpareParts>* supplierSparePart = currentSupplier->data.searchSparePartsOfSupplier(spnum);

        if (supplierSparePart != nullptr) {
            currentSupplier->data.deleteSparePartsOfSupplier(spnum);
        }

        traverseSupplierTreeDelete(currentSupplier->left, spnum);
        traverseSupplierTreeDelete(currentSupplier->right, spnum);
    }

    //Function to traverse every node in sparepart tree for the connected supplier sc and delete it - complexity O(n+log(n))=O(n)
    void traverseSparePartDelete(Node<SpareParts>* currentSparePart, int sc) {
        if (currentSparePart == nullptr) {
            return;
        }

        Node<Supplier>* sparePartSupplier = currentSparePart->data.searchSuppliersOfSpareParts(sc);

        if (sparePartSupplier != nullptr) {
            currentSparePart->data.deleteSuppliersOfSpareParts(sc);
        }

        traverseSparePartDelete(currentSparePart->left, sc);
        traverseSparePartDelete(currentSparePart->right, sc);
    }


};



class QNode{
    public:
    string data;
    QNode* next;

    QNode(string str) : data(str), next(NULL){} //complexity O(1)
};

class Queue{
    public:
    QNode *front, *rear;
    Queue(){
			front = rear = NULL; //complexity O(1)
		}

    //complexity O(1)
    void enqueue(string str){
        QNode* temp = new QNode(str);
            //check if queue is empty
			if (rear == NULL) {
				front = rear = temp;
				return;
			}
			rear->next = temp;
			rear = temp;
    }

    void dequeue() //complexity O(1)
		{
			// If queue is empty, return NULL.
			if (front == NULL)
				return;

			QNode* temp = front;
			front = front->next;

			if (front == NULL)
				rear = NULL;

			delete (temp);
		}

    bool isEmpty(){ //complexity O(1)
			return front == NULL && rear == NULL;
	}


	string Front(){ //complexity O(1)
			return front->data;
	}

	string Rear(){ //complexity O(1)
			return rear->data;
	}

	int queueSize(){ //complexity O(n)
		QNode *tmp = front;
		int size = 0;
		while(tmp != NULL){
				size ++;
				tmp = tmp->next;
		}
			return size;
		}

    void display() //complexity O(n)
    {
        while (!isEmpty())
        {
            cout << Front() << endl;
            dequeue();
        }
    }

};



template <class T>
class StackNode {
public:
    T data;
    StackNode<T>* next;

    StackNode(T value) : data(value), next(nullptr) {} //complexity O(1)
};

template <class T>
class InteractionLog {
private:
    StackNode<T>* topNode;

public:
    InteractionLog() : topNode(nullptr) {} //complexity O(1)

    bool isEmpty() const { //complexity O(1)
        return topNode == nullptr;
    }

    void push(T item) { //complexity O(1)
        StackNode<T>* newNode = new StackNode<T>(item);
        if (isEmpty()) {
            topNode = newNode;
        } else {
            newNode->next = topNode;
            topNode = newNode;
        }
    }

    void pop() { //complexity O(1)
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        StackNode<T>* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    T top() const { //complexity O(1)
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        }
        return topNode->data;
    }

    void addInteraction(string action) { //complexity O(1)
        T newInteraction(action);  // Create an object of type T (e.g., Interaction) directly
        push(newInteraction);
    }

    void printInteractionsHistory() { //complexity O(n)
        InteractionLog temp;
        while (!isEmpty()) {
            temp.push(top());
            cout << top() << endl;
            pop();
        }
        while(!temp.isEmpty()){
            push(temp.top());
            temp.pop();
        }
    }

};


int main(){
Queue spare_part_processing;
Queue supplier_processing;
BST<Supplier> supplier_tree;
BST<SpareParts> spare_part_tree;
InteractionLog<string> interactionLog;
cout << "Welcome to the Inventory Management System" << endl;
int spSize = 0, supSize = 0;
    while(true){
        cout << "Choose one of the following: " << endl;
        cout << "1. Insert Spare Part" << endl;
        cout << "2. Insert Supplier" << endl;
        cout << "3. Operations" << endl;
        cout  << "------------------------" << endl;
        int inChoice = getIntegerInput("");
        if(inChoice == 1){
            int n = getIntegerInput("Please enter number of Spare Parts to be inserted: ");
            if(spSize+n > 100){
                int n = getIntegerInput("Inventory size cannot exceed 100. Please enter a number below: " + to_string(101-spSize));
            }
            for(int i = 1; i <= n; i++){
                string pn;


                cout << "Insert Spare Part details: " << endl;

                cout << "Part Name: ";
                cin >> pn;

                int pc = getIntegerInput("Part Number: ");


                Node<SpareParts>* SPFound = spare_part_tree.searchByCode(pc);
                while(SPFound){
                    pc = getIntegerInput("Code duplicated.\nInsert another code: ");
                    SPFound = spare_part_tree.searchByCode(pc);

                }
                float c = getFloatInput("Part Cost: ");

                cout  << "------------------------" << endl;

                spSize++;
                SpareParts newPart(pn, pc, c);
                spare_part_tree.insert(newPart);
                spare_part_processing.enqueue("Spare Part " + to_string(pc) + " data processing in progress.");
                interactionLog.addInteraction("Added Spare Part " + to_string(pc));
            }
            spare_part_processing.display();
        } else if(inChoice == 2){
            int n = getIntegerInput("Please enter number of Suppliers to be inserted: ");
            if(supSize+n> 20){
                n = getIntegerInput("Inventory size cannot exceed 20. Please enter a number below: " + to_string(21-supSize));
            }
            for(int i = 1; i <= n; i++){
                string sn, ad, mail;

                cout << "Supplier Name: ";
                cin >> sn;
                cout << "Supplier Address: ";
                cin >> ad;
                cout << "Supplier Email: ";
                cin >> mail;

                int sc = getIntegerInput("Supplier code: ");

                Node<Supplier>* SFound = supplier_tree.searchByCode(sc);
                while(SFound){
                    sc = getIntegerInput("Code duplicated.\nInsert another code: ");
                    SFound = supplier_tree.searchByCode(sc);
                }

                int tel = getIntegerInput("Supplier Telephone: ");

                cout << "------------------------" << endl;

                supSize++;
                Supplier newSupplier(sn, ad, mail, sc, tel);
                supplier_tree.insert(newSupplier);
                supplier_processing.enqueue("Supplier " + to_string(sc) + " data processing in progress.");
                interactionLog.addInteraction("Added Supplier " + to_string(sc));
            }
            supplier_processing.display();
        } else if(inChoice == 3){
            while(true){
                cout << "Enter choice for the following Operations" << endl;
                cout << "1. Connections" << endl; //link spare parts and suppliers
                cout << "2. Delete" << endl;
                cout << "3. Modify" << endl;
                cout << "4. Search" << endl; //search for and print supplier/spareparts and its connections
                cout << "5. Print Tree" << endl;
                cout << "6. History" << endl;
                cout << "7. Return" << endl; //return to insert page
                cout << "------------------------" << endl;
                int opChoice = getIntegerInput("");
                if(opChoice == 1){
                    cout << "Enter your choice" << endl;
                    cout << "1. Add Suppliers of a Spare Part" << endl;
                    cout << "2. Add Spare Parts of a Supplier" << endl;
                    cout << "------------------------" << endl;

                    int conChoice = getIntegerInput("");

                    if(conChoice == 1){
                        int spnum = getIntegerInput("Insert Spare Part Number: ");
                        //check if spare part exists
                        Node<SpareParts>* SPFound = spare_part_tree.searchByCode(spnum);
                        while(!SPFound){
                            spnum = getIntegerInput("Spare Part not found. Insert a valid Spare Part number: ");
                            SPFound = spare_part_tree.searchByCode(spnum);
                        }

                        int n = getIntegerInput("Insert number of Suppliers: ");
                        for(int i=0; i<n; i++){
                            int snum = getIntegerInput("Insert Supplier Code: ");
                            //search if supplier exists
                            Node<Supplier>* SFoundNode = supplier_tree.searchByCode(snum);
                        if (SFoundNode) {
                            Supplier SFound = SFoundNode->data;
                            //check if supplier has been added before
                            if(!SPFound->data.searchSuppliersOfSpareParts(SFound.getSupplierCode())){

                            //add supplier to spare parts and vice versa
                            SpareParts SPF= SPFound->data;
                            SPFound->data.addSupplierOfSparePart(SFound);
                            SFoundNode->data.addSparePartOfSupplier(SPF);
                            spare_part_processing.enqueue("Connecting supplier " + to_string(snum) + " to Spare Part " + to_string(spnum));
                            interactionLog.addInteraction("Connected supplier " + to_string(snum) + " with Spare Part " + to_string(spnum));
                            } else {
                                snum = getIntegerInput("Supplier already connected. Please enter another one: ");
                                SFoundNode = supplier_tree.searchByCode(snum);
                            }

                        } else {
                            while(!SFoundNode){
                            snum = getIntegerInput("Supplier not found. Enter a valid Supplier code: ");
                            SFoundNode = supplier_tree.searchByCode(snum);
                                }
                            }
                        }
                    } else if(conChoice == 2){
                            int sc = getIntegerInput("Insert Supplier Code: ");
                            //check if supplier exists
                            Node<Supplier>* SFound = supplier_tree.searchByCode(sc);
                            while(!SFound){
                                sc = getIntegerInput("Supplier not found. Insert a valid Supplier code: ");
                                SFound = supplier_tree.searchByCode(sc);
                            }

                            int n = getIntegerInput("Insert number of Spare Parts: ");

                            for(int i=0; i<n; i++){
                            int spnum = getIntegerInput("Insert Spare Part Number: ");
                            //check if spare part exists
                            Node<SpareParts>* SPFoundNode = spare_part_tree.searchByCode(spnum);
                            if (SPFoundNode) {
                            SpareParts SPFound = SPFoundNode->data;
                            //check if spare part has already been added before
                            if(!SFound->data.searchSparePartsOfSupplier(SPFound.getPartNumber())){
                            //Add spare part to supplier and vice versa
                            Supplier SF= SFound->data;
                            SFound->data.addSparePartOfSupplier(SPFound);
                            SPFoundNode->data.addSupplierOfSparePart(SF);

                            supplier_processing.enqueue("Connecting Spare Part " + to_string(spnum) + " to Supplier " + to_string(sc));
                            interactionLog.addInteraction("Connected Spare Part " + to_string(spnum) + " with Supplier " + to_string(sc));
                            } else{
                                spnum= getIntegerInput("Spare Part already connected. Please enter another one: ");
                                SPFoundNode = spare_part_tree.searchByCode(spnum);
                            }

                        } else {
                            while(!SPFoundNode){
                            spnum= getIntegerInput("Spare Part not found. Enter a valid Spare Part number: ");
                            SPFoundNode = spare_part_tree.searchByCode(spnum);
                                }
                            }
                            }
                    } else {
                        cout << "Invalid Input. Please select a number from 1-2" << endl;
                        cout << "------------------------" << endl;
                    }
                    spare_part_processing.display();
                    supplier_processing.display();
                } else if(opChoice == 2) {
                    cout << "Enter your choice" << endl;
                    cout << "1. Delete Spare Part" << endl;
                    cout << "2. Delete Supplier" << endl;
                    cout << "------------------------" << endl;

                    int delChoice = getIntegerInput("");
                    if(delChoice == 1){
                        int spnum = getIntegerInput("Insert code of Spare Part to be deleted: ");
                        Node<SpareParts>* SPFound = spare_part_tree.searchByCode(spnum);
                        while(!SPFound){
                            spnum = getIntegerInput("Spare Part not found. Insert a valid Spare Part number: ");
                            SPFound = spare_part_tree.searchByCode(spnum);
                        }

                        //delete from tree
                        spare_part_tree.deleteByCode(spnum);
                        //delete from associated suppliers
                        supplier_tree.traverseSupplierTreeDelete(supplier_tree.root, spnum);

                        spare_part_processing.enqueue("Deleting spare part " + to_string(spnum) + " in progress.");
                        interactionLog.addInteraction("Deleted Spare Part " + to_string(spnum));
                        spare_part_processing.display();
                    }
                    else if (delChoice == 2){
                            int sc = getIntegerInput("Insert Supplier Code to be deleted: ");
                            Node<Supplier>* SFound = supplier_tree.searchByCode(sc);
                            while(!SFound){
                                sc = getIntegerInput("Supplier not found. Insert a valid Supplier code: ");
                                SFound = supplier_tree.searchByCode(sc);
                            }

                            //delete from tree
                            supplier_tree.deleteByCode(sc);
                            //delete from associated spare parts
                            spare_part_tree.traverseSparePartDelete(spare_part_tree.root, sc);
                            supplier_processing.enqueue(("Deleting Supplier " + to_string(sc) + " in progress."));
                            interactionLog.addInteraction("Deleted Supplier " + to_string(sc));
                            supplier_processing.display();
                    }
                    else {
                        cout << "Invalid Input. Please select a number from 1-2" << endl;
                        cout << "------------------------" << endl;
                    }
                } else if(opChoice == 3) {
                    cout << "Enter your choice" << endl;
                    cout << "1. Modify Spare Part" << endl;
                    cout << "2. Modify Supplier" << endl;
                    cout << "------------------------" << endl;
                    int modChoice = getIntegerInput("");
                    if(modChoice == 1){
                        int spnum = getIntegerInput("Insert code of Spare Part to be modified: ");
                        Node<SpareParts>* SPFound = spare_part_tree.searchByCode(spnum);
                        while(!SPFound){
                            spnum = getIntegerInput("Spare Part not found. Insert a valid Spare Part number: ");
                            SPFound = spare_part_tree.searchByCode(spnum);
                        }

                        //modify in tree and associated suppliers
                        spare_part_tree.modify(spnum);
                        supplier_tree.traverseSupplierTreeModify(supplier_tree.root, spnum, SPFound->data);

                        spare_part_processing.enqueue("Modifying Spare Part " + to_string(spnum) + " in progress.");
                        interactionLog.addInteraction("Modified Spare Part " + to_string(spnum));
                        spare_part_processing.display();
                    }
                    else if (modChoice == 2){
                            int sc = getIntegerInput("Insert Supplier Code to be modified: ");
                            Node<Supplier>* SFound = supplier_tree.searchByCode(sc);
                            while(!SFound){
                                sc = getIntegerInput("Supplier not found. Insert a valid Supplier code: ");
                                SFound = supplier_tree.searchByCode(sc);
                            }

                            //modify in tree and associated spare parts
                            supplier_tree.modify(sc);
                            spare_part_tree.traverseSparePartTreeModify(spare_part_tree.root, sc, SFound->data);


                            supplier_processing.enqueue(("Modifying Supplier " + to_string(sc) + " in progress."));
                            interactionLog.addInteraction("Modified Supplier " + to_string(sc));
                            supplier_processing.display();
                    }
                    else {
                        cout << "Invalid Input. Please select a number from 1-2" << endl;
                        cout << "------------------------" << endl;
                    }
                } else if(opChoice == 4) {
                    cout << "Enter your choice" << endl;
                    cout << "1. Search Spare Part" << endl;
                    cout << "2. Search Supplier" << endl;
                    cout << "------------------------" << endl;
                    int serChoice = getIntegerInput("");
                    if(serChoice == 1){
                        int spnum = getIntegerInput("Insert code of Spare Part to search for: ");
                        spare_part_processing.enqueue("Searching for Spare Part " + to_string(spnum) + " in progress.");
                        spare_part_processing.display();
                        Node<SpareParts>* SPFound = spare_part_tree.searchByCode(spnum);
                        while(!SPFound){
                            spnum = getIntegerInput("Spare Part not found. Insert a valid Spare Part number: ");
                            SPFound = spare_part_tree.searchByCode(spnum);

                            spare_part_processing.enqueue("Searching for Spare Part " + to_string(spnum) + " in progress.");
                            interactionLog.addInteraction("Searched for Spare Part " + to_string(spnum));
                            spare_part_processing.display();
                        }
                        SPFound->data.Display();
                        SPFound->data.printSuppliersOfSpareParts();
                    }
                    else if (serChoice == 2){
                            int sc = getIntegerInput("Insert Supplier Code to search for: ");
                            supplier_processing.enqueue("Searching for Supplier " + to_string(sc) + " in progress.");
                            supplier_processing.display();
                            Node<Supplier>* SFound = supplier_tree.searchByCode(sc);
                            while(!SFound){
                                sc = getIntegerInput("Supplier not found. Insert a valid Supplier code: ");
                                SFound = supplier_tree.searchByCode(sc);

                                supplier_processing.enqueue("Searching for Supplier " + to_string(sc) + " in progress.");
                                interactionLog.addInteraction("Searched for Supplier " + to_string(sc));
                                supplier_processing.display();
                            }
                            SFound->data.Display();
                            SFound->data.printSparePartOfSupplier();
                    }
                    else {
                        cout << "Invalid Input. Please select a number from 1-2" << endl;
                        cout << "------------------------" << endl;
                    }

                } else if(opChoice==5){
                    cout << "Choose which tree to print: " << endl;
                    cout << "1. Tree of Spare Parts" << endl;
                    cout << "2. Tree of Suppliers" << endl;
                    int prinChoice = getIntegerInput("");
                    if(prinChoice == 1){
                        spare_part_processing.enqueue("Displaying Spare Part tree in progress.");
                        spare_part_processing.display();

                        spare_part_tree.printInOrder();
                        interactionLog.addInteraction("Viewed all Spare Parts in tree.");
                    }
                    else if(prinChoice == 2){
                        supplier_processing.enqueue("Displaying Supplier tree in progress.");
                        supplier_processing.display();

                        supplier_tree.printInOrder();
                        interactionLog.addInteraction("Viewed all Supplier in tree.");
                    }
                    else{
                        cout << "Invalid Input. Please select a number from 1-2" << endl;
                        cout << "------------------------" << endl;
                    }

                } else if(opChoice == 6) {
                    cout << "Printing History: " << endl;
                    interactionLog.printInteractionsHistory();
                    cout << "------------------------" << endl;

                } else if(opChoice == 7) {
                    cout << "Exiting" << endl;
                    cout << "------------------------" << endl;
                    break;
                } else {
                    cout << "Invalid Input. Please select a number from 1-6" << endl;
                    cout << "------------------------" << endl;
                }
            }
        } else{
            cout << "Invalid Input. Please select a number from 1-3" << endl;
            cout << "------------------------" << endl;
        }
    }

    return 0;
}

    //TIME COMPLEXITY OF MAIN
    //1. Insert Spare Part : complexity O(n * log N) or O(n^2) (if the tree is not balanced), n is the number of spare parts to be added
    //2. Insert Supplier : complexity O(n * log N) or O(n^2) (if the tree is not balanced), n is the number of suppliers to be added
    //3. Operations
    //  3.1 Connections
    //      3.1.1 Add Suppliers of a Spare Part : complexity O(n * log N) (where n is the number of connections to be added)
    //      3.1.2 Add Spare Parts of a Supplier : O(n * log N) (where n is the number of connections to be added)
    //  3.2 Delete --
    //      3.2.1 Delete Spare Part : complexity O(log N)
    //      3.2.2 Delete Supplier : complexity O(log N)
    //  3.3 Modify
    //      3.3.1 Modify Spare Part : complexity O(log N)
    //      3.3.2 Modify Supplier : complexity O(log N)
    //  3.4 Search
    //      3.4.1 Search Spare Part : complexity  O(log N)
    //      3.4.2 Search Supplier : complexity  O(log N)
    //  3.5 Print Tree : complexity O(N) (where N is the number of nodes of the tree)
    //  3.6 History : complexity (N) (where N is the number of interactions in the interaction log)