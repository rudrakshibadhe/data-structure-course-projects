#include <iostream>
#include <string>
using namespace std;

// ==================== COMPONENT NODE ====================

struct Component {
    int id;
    string name;
    string deviceType;
    string condition;
    string stage;
    string status;

    Component* next;
    Component* prev;
};

// ==================== HISTORY NODE ====================

struct History {
    string action;
    int componentId;
    History* next;
};

// ==================== QUEUE NODE ====================

struct QueueNode {
    int componentId;
    QueueNode* next;
};

// ==================== GLOBAL POINTERS ====================

Component* head = nullptr;
Component* tail = nullptr;

History* historyTop = nullptr;

QueueNode* frontNode = nullptr;
QueueNode* rearNode = nullptr;

// ==================== ADD COMPONENT ====================

void addComponent() {
    Component* newComponent = new Component;

    cout << "\nEnter Component ID: ";
    cin >> newComponent->id;

    cin.ignore();

    cout << "Enter Component Name: ";
    getline(cin, newComponent->name);

    cout << "Enter Device Type: ";
    getline(cin, newComponent->deviceType);

    cout << "Enter Condition: ";
    getline(cin, newComponent->condition);

    newComponent->stage = "Collection";
    newComponent->status = "Pending";

    newComponent->next = nullptr;
    newComponent->prev = nullptr;

    if (head == nullptr) {
        head = tail = newComponent;
    } else {
        tail->next = newComponent;
        newComponent->prev = tail;
        tail = newComponent;
    }

    cout << "\nComponent added successfully!\n";
}

// ==================== DISPLAY COMPONENTS ====================

void displayComponents() {
    if (head == nullptr) {
        cout << "\nNo components available.\n";
        return;
    }

    Component* temp = head;

    cout << "\n========== COMPONENT LIST ==========\n";

    while (temp != nullptr) {
        cout << "\nComponent ID   : " << temp->id;
        cout << "\nName           : " << temp->name;
        cout << "\nDevice Type    : " << temp->deviceType;
        cout << "\nCondition      : " << temp->condition;
        cout << "\nCurrent Stage  : " << temp->stage;
        cout << "\nStatus         : " << temp->status;
        cout << "\n------------------------------------";

        temp = temp->next;
    }
}

// ==================== SEARCH COMPONENT ====================

Component* searchComponent(int id) {
    Component* temp = head;

    while (temp != nullptr) {
        if (temp->id == id) {
            return temp;
        }

        temp = temp->next;
    }

    return nullptr;
}

void searchComponentMenu() {
    int id;

    cout << "\nEnter Component ID to search: ";
    cin >> id;

    Component* component = searchComponent(id);

    if (component == nullptr) {
        cout << "\nComponent not found.\n";
        return;
    }

    cout << "\n========== COMPONENT FOUND ==========\n";
    cout << "Component ID  : " << component->id << endl;
    cout << "Name          : " << component->name << endl;
    cout << "Device Type   : " << component->deviceType << endl;
    cout << "Condition     : " << component->condition << endl;
    cout << "Current Stage : " << component->stage << endl;
    cout << "Status        : " << component->status << endl;
}

// ==================== HISTORY STACK ====================

void pushHistory(int componentId, string action) {
    History* newHistory = new History;

    newHistory->componentId = componentId;
    newHistory->action = action;
    newHistory->next = historyTop;

    historyTop = newHistory;
}

void displayHistory() {
    if (historyTop == nullptr) {
        cout << "\nNo processing history available.\n";
        return;
    }

    History* temp = historyTop;

    cout << "\n========== PROCESSING HISTORY ==========\n";

    while (temp != nullptr) {
        cout << "Component ID: " << temp->componentId
             << " | Action: " << temp->action << endl;

        temp = temp->next;
    }
}

void removeLatestHistory() {
    if (historyTop == nullptr) {
        cout << "\nHistory is empty.\n";
        return;
    }

    History* temp = historyTop;

    cout << "\nRemoved latest history: Component ID "
         << temp->componentId << " - "
         << temp->action << endl;

    historyTop = historyTop->next;

    delete temp;
}

// ==================== UPDATE STATUS ====================

void updateStatus() {
    int id;
    int choice;

    cout << "\nEnter Component ID: ";
    cin >> id;

    Component* component = searchComponent(id);

    if (component == nullptr) {
        cout << "\nComponent not found.\n";
        return;
    }

    cout << "\nSelect Processing Stage:\n";
    cout << "1. Inspection\n";
    cout << "2. Classification\n";
    cout << "3. Repair\n";
    cout << "4. Reuse\n";
    cout << "5. Recycling\n";

    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            component->stage = "Inspection";
            component->status = "In Inspection";
            break;

        case 2:
            component->stage = "Classification";
            component->status = "Classified";
            break;

        case 3:
            component->stage = "Repair";
            component->status = "Under Repair";
            break;

        case 4:
            component->stage = "Reuse";
            component->status = "Ready for Reuse";
            break;

        case 5:
            component->stage = "Recycling";
            component->status = "Sent for Recycling";
            break;

        default:
            cout << "\nInvalid choice.\n";
            return;
    }

    pushHistory(id, component->stage);

    cout << "\nComponent status updated successfully!\n";
}

// ==================== DELETE COMPONENT ====================

void deleteComponent() {
    int id;

    cout << "\nEnter Component ID to delete: ";
    cin >> id;

    Component* component = searchComponent(id);

    if (component == nullptr) {
        cout << "\nComponent not found.\n";
        return;
    }

    if (component->prev != nullptr) {
        component->prev->next = component->next;
    } else {
        head = component->next;
    }

    if (component->next != nullptr) {
        component->next->prev = component->prev;
    } else {
        tail = component->prev;
    }

    delete component;

    cout << "\nComponent deleted successfully!\n";
}

// ==================== QUEUE OPERATIONS ====================

void enqueueComponent() {
    int id;

    cout << "\nEnter Component ID to add to processing queue: ";
    cin >> id;

    if (searchComponent(id) == nullptr) {
        cout << "\nComponent not found.\n";
        return;
    }

    QueueNode* newNode = new QueueNode;

    newNode->componentId = id;
    newNode->next = nullptr;

    if (rearNode == nullptr) {
        frontNode = rearNode = newNode;
    } else {
        rearNode->next = newNode;
        rearNode = newNode;
    }

    cout << "\nComponent added to processing queue.\n";
}

void dequeueComponent() {
    if (frontNode == nullptr) {
        cout << "\nProcessing queue is empty.\n";
        return;
    }

    QueueNode* temp = frontNode;

    int id = temp->componentId;

    frontNode = frontNode->next;

    if (frontNode == nullptr) {
        rearNode = nullptr;
    }

    delete temp;

    Component* component = searchComponent(id);

    if (component != nullptr) {
        component->status = "Processing";
        pushHistory(id, "Component processed from queue");
    }

    cout << "\nComponent ID " << id
         << " processed successfully.\n";
}

void displayQueue() {
    if (frontNode == nullptr) {
        cout << "\nProcessing queue is empty.\n";
        return;
    }

    QueueNode* temp = frontNode;

    cout << "\n========== PROCESSING QUEUE ==========\n";

    while (temp != nullptr) {
        cout << "Component ID: " << temp->componentId << endl;
        temp = temp->next;
    }
}

// ==================== MAIN MENU ====================

void displayMenu() {
    cout << "\n\n============================================\n";
    cout << "   SMART E-WASTE COMPONENT TRACKING SYSTEM\n";
    cout << "============================================\n";
    cout << "1. Add Component\n";
    cout << "2. Display Components\n";
    cout << "3. Search Component\n";
    cout << "4. Update Component Status\n";
    cout << "5. Delete Component\n";
    cout << "6. Add Component to Processing Queue\n";
    cout << "7. Process Component from Queue\n";
    cout << "8. Display Processing Queue\n";
    cout << "9. Display Processing History\n";
    cout << "10. Remove Latest History\n";
    cout << "0. Exit\n";
    cout << "============================================\n";
    cout << "Enter your choice: ";
}

// ==================== MAIN FUNCTION ====================

int main() {
    int choice;

    cout << "\n============================================\n";
    cout << "   SMART E-WASTE DISASSEMBLY & TRACKING\n";
    cout << "============================================\n";

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addComponent();
                break;

            case 2:
                displayComponents();
                break;

            case 3:
                searchComponentMenu();
                break;

            case 4:
                updateStatus();
                break;

            case 5:
                deleteComponent();
                break;

            case 6:
                enqueueComponent();
                break;

            case 7:
                dequeueComponent();
                break;

            case 8:
                displayQueue();
                break;

            case 9:
                displayHistory();
                break;

            case 10:
                removeLatestHistory();
                break;

            case 0:
                cout << "\nThank you for using the system!\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
